#ifndef _WOLF_HPP_
#define _WOLF_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Animal.hpp"

namespace Creature
{
	class Wolf :
		public Animal
	{
	private:

	public:
		Wolf();
		Wolf(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator);
		Wolf(const Wolf& Object);

		virtual void Move_Forwards();
		virtual void Move_Backwards();
		virtual void Move_Upwards();
		virtual void Move_Downwards();

		Wolf& operator=(const Wolf& rhs);

		virtual ~Wolf();
	};
}

#endif /* _WOLF_HPP_ */