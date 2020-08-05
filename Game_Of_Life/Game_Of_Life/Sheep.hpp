#ifndef _SHEEP_HPP_
#define _SHEEP_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Animal.hpp"

namespace Creature
{
	class Sheep :
		public Animal
	{
	private:

	public:
		Sheep();
		Sheep(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator);
		Sheep(const Sheep& Object);

		virtual void Move_Forwards();
		virtual void Move_Backwards();
		virtual void Move_Upwards();
		virtual void Move_Downwards();

		Sheep& operator=(const Sheep& rhs);	

		virtual ~Sheep();
	};
}

#endif /* _SHEEP_HPP_ */