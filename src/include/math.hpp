// ../src/include/math.hpp ----------------------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms
//  of the GNU General Public License as published by the Free Software Foundation, either
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib.
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
#ifndef __MATH_HPP
	#define __MATH_HPP
	#include "globals.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 02/2014
//
/// @brief Generic math functions for general tasks.
//
/// @details The aiming is to group under the scope of 'math' all the functions
///          for general tasks of math and that does not belong to any class or
///          struct. All the members are of public access by any client and the
///          only requirement is that its header file should be included where
///          it is needed. Also notice that the math namespace works just as an
///          interface for third math libraries used such as the GSL library.
//
/// @cite gsl
//
namespace math
{
	#include "math__module.cpp"
	#include "math__square_module.cpp"
	#include "math__factorial.cpp"
	#include "math__double_factorial.cpp"
	#include "math__binomial_coeff.cpp"
	#include "math__point_distance.cpp"
	#include "math__gamma_function.cpp"
	#include "math__incomplete_gamma_function.cpp"
	#include "math__error_function.cpp"
	#include "math__random_number.cpp"
	#include "math__kronecker_delta.cpp"
	#include "math__exp.cpp"
};
#endif
