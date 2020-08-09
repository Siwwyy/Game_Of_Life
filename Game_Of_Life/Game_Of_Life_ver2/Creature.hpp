#ifndef _CREATURE_HPP_
#define _CREATURE_HPP_

#include <string>
#include <iostream>
#include <cstdint>

namespace Creature
{
	
	class Creature
	{
	protected:
		std::string m_name;
		int32_t m_pos_x;
		int32_t m_pos_y;

		Creature();
		Creature(const std::string& name);
		Creature(const std::string& name, const int32_t pos_x, const int32_t pos_y);
		Creature(const Creature& Object);

		Creature& operator=(const Creature& rhs);

		virtual ~Creature() {};

	public:

		void Set_Name(const std::string& name);
		void Set_Pos_X(const int32_t pos_x);
		void Set_Pos_Y(const int32_t pos_y);

		const std::string& Get_Name() const;
		const int32_t Get_Pos_X() const;
		const int32_t Get_Pos_Y() const;

		virtual void Move_Forwards() = 0;
		virtual void Move_Backwards() = 0;
		virtual void Move_Upwards() = 0;
		virtual void Move_Downwards() = 0;
		virtual void Print() const;

	};

}

#endif /* _CREATURE_HPP_ */