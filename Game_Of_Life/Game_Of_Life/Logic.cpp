#include "Logic.hpp"

void Engine::Logic::Draw_Objects()
{
	Sheep_Resources.lock();
	for (typename std::unordered_set< std::unique_ptr<Creature::Animal*>>::const_iterator set_iter = this->m_Sheeps.begin(); set_iter != this->m_Sheeps.end(); ++set_iter)
	{
		Draw.Draw_Object((*(set_iter)->get())->Get_Pos_X(), (*(set_iter)->get())->Get_Pos_Y(), 'o');
	}
	Sheep_Resources.unlock();
	Wolf_Resources.lock();
	Draw.Draw_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y(), '>');
	Wolf_Resources.unlock();
}

void Engine::Logic::Key()
{
	while (is_not_end)
	{
		if (Key_Event.Detect_Key(Keyboard_Event::Keys::ESC) == true)
		{
			is_not_end = false;
		}
		else if (Key_Event.Detect_Key(Keyboard_Event::Keys::W) == true)
		{
			Wolf_Resources.lock();
			Draw.Clear_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y());
			m_Wolf->Move_Downwards();
			Draw.Draw_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y(), '>');
			Wolf_Resources.unlock();
		}
		else if (Key_Event.Detect_Key(Keyboard_Event::Keys::S) == true)
		{
			Wolf_Resources.lock();
			Draw.Clear_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y());
			m_Wolf->Move_Upwards();
			Draw.Draw_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y(), '>');
			Wolf_Resources.unlock();
		}
		else if (Key_Event.Detect_Key(Keyboard_Event::Keys::A) == true)
		{
			Wolf_Resources.lock();
			Draw.Clear_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y());
			m_Wolf->Move_Backwards();
			Draw.Draw_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y(), '>');
			Wolf_Resources.unlock();
		}
		else if (Key_Event.Detect_Key(Keyboard_Event::Keys::D) == true)
		{
			Wolf_Resources.lock();
			Draw.Clear_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y());
			m_Wolf->Move_Forwards();
			Draw.Draw_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y(), '>');
			Wolf_Resources.unlock();
		}
	}
}

void Engine::Logic::Add_Sheep()
{
	std::mt19937 rng(rand());
	std::uniform_int_distribution<int> uid_width(0, this->Draw.Get_Width() - 1);
	std::uniform_int_distribution<int> uid_height(0, this->Draw.Get_Height() - 1);
	Sheep_Resources.lock();
	this->m_Sheeps.insert(std::move(std::make_unique<Creature::Animal*>((new Creature::Sheep("Dolly", uid_width(rng), uid_height(rng), "Sheep", false)))));
	Sheep_Resources.unlock();
}

void Engine::Logic::Game_Draw()
{
	while (is_not_end)
	{
		Draw_Objects();
		Sheep_Resources.lock();
		Draw.Draw_Object(30, 15, "Current sheep amount %d", this->m_Sheeps.size());
		Sheep_Resources.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Engine::Logic::Game_Logic()
{
	std::mt19937 rng(rand());
	std::uniform_int_distribution<int> uid(0, 5);
	while (is_not_end)
	{
		if (uid(rng) == 3)
		{
			Add_Sheep();
		}
		Diffusion();
		Collision();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Engine::Logic::Diffusion()
{
	Wolf_Resources.lock();
	if (this->m_Wolf->Get_Pos_Y() < 0)
	{
		this->m_Wolf->Set_Pos_Y(this->Draw.Get_Height() - 1);
	}
	else if (this->m_Wolf->Get_Pos_Y() > this->Draw.Get_Height() - 1)
	{
		this->m_Wolf->Set_Pos_Y(static_cast<int32_t>(0));
	}
	else if (this->m_Wolf->Get_Pos_X() < 0)
	{
		this->m_Wolf->Set_Pos_X(this->Draw.Get_Width() - 1);
	}
	else if (this->m_Wolf->Get_Pos_X() > this->Draw.Get_Width() - 1)
	{
		this->m_Wolf->Set_Pos_X(static_cast<int32_t>(0));
	}
	Wolf_Resources.unlock();
}

void Engine::Logic::Collision()
{
	Sheep_Resources.lock();
	for (typename std::unordered_set<std::unique_ptr<Creature::Animal*>>::const_iterator set_iter = this->m_Sheeps.begin(); set_iter != this->m_Sheeps.end(); ++set_iter)
	{
		if ((**set_iter)->Get_Pos_X() == this->m_Wolf->Get_Pos_X() && (**set_iter)->Get_Pos_Y() == this->m_Wolf->Get_Pos_Y())
		{
			set_iter = this->m_Sheeps.erase(set_iter);
		}
	}
	Sheep_Resources.unlock();
}

Engine::Logic::Logic(const int32_t width, const int32_t height) :
	Draw(width, height),
	Key_Event()
{
	m_Wolf = new Creature::Wolf("Wolf", static_cast<int32_t>(0), static_cast<int32_t>(this->Draw.Get_Height() / 2), "Wolf", true);
}

Engine::Logic::Logic(const Logic& Object) :
	Draw(Object.Draw),
	Key_Event(Object.Key_Event),
	m_Wolf(new Creature::Wolf)
{
	this->m_Wolf = Object.m_Wolf;
}

void Engine::Logic::Run_Game()
{
	std::thread t1(&Logic::Key, this);
	std::thread t2(&Logic::Game_Draw, this);
	std::thread t3(&Logic::Game_Logic, this);

	t1.join();
	t2.join();
	t3.join();

	Draw.Clear_Area();
}

Engine::Logic::~Logic()
{
	this->m_Sheeps.clear();
	delete m_Wolf;
}