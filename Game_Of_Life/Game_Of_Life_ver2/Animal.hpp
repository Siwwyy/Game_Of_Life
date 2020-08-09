#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include "Creature.hpp"

namespace Creature
{

	class Animal :
		public Creature
	{
	private:
		bool m_is_predator;
	public:
		Animal();
		Animal(const std::string& name, const int32_t pos_x, const int32_t pos_y, const bool is_predator);
		Animal(const Animal& Object);

		void Set_Is_Predator(const bool is_predator);

		virtual void Move_Forwards();
		virtual void Move_Backwards();
		virtual void Move_Upwards();
		virtual void Move_Downwards();
		void Print() const;

		Animal& operator=(const Animal& rhs);

		const bool Get_Is_Predator() const;

		virtual ~Animal() {};
	};

}

#endif /* _ANIMAL_HPP_ */