#include "Logic.hpp"

void Engine::Logic::Draw_Objects()
{
	std::lock_guard<std::mutex> mtx1_lock(Sheep_Resources);
	{
		std::lock_guard<std::mutex> mtx2_lock(Wolf_Resources);
		{
			for (typename std::unordered_set<Creature::Animal*>::const_iterator vec_iter = this->m_Sheeps.begin(); vec_iter != this->m_Sheeps.end(); ++vec_iter)
			{
				Draw.Draw_Object((*vec_iter)->Get_Pos_X(), (*vec_iter)->Get_Pos_Y(), 'o');
			}
			Draw.Draw_Object(m_Wolf->Get_Pos_X(), m_Wolf->Get_Pos_Y(), '>');
		}
	}
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
	m_Sheeps.insert(new Creature::Sheep("Dolly", uid_width(rng), uid_height(rng), "Sheep", false));
	Sheep_Resources.unlock();
}

void Engine::Logic::Game_Draw()
{
	while (is_not_end)
	{
		Draw_Objects();
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
	for (typename std::unordered_set<Creature::Animal*>::const_iterator vec_iter = this->m_Sheeps.begin(); vec_iter != this->m_Sheeps.end(); ++vec_iter)
	{
		if ((*vec_iter)->Get_Pos_X() == this->m_Wolf->Get_Pos_X() && (*vec_iter)->Get_Pos_Y() == this->m_Wolf->Get_Pos_Y())
		{
			vec_iter = this->m_Sheeps.erase(vec_iter);
		}
	}
	Sheep_Resources.unlock();
}

Engine::Logic::Logic(const int32_t width, const int32_t height) :
	Draw(width, height),
	Key_Event(),
	m_Wolf(new Creature::Wolf("Wolf", static_cast<int32_t>(0), static_cast<int32_t>(this->Draw.Get_Height() / 2), "Wolf", true))
{

}

Engine::Logic::Logic(const Logic& Object) :
	Draw(Object.Draw),
	Key_Event(Object.Key_Event)
{
	m_Wolf = new Creature::Wolf;
	m_Wolf = Object.m_Wolf;
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
}