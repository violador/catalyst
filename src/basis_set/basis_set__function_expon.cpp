// ../src/basis_set/basis_set__function_expon.cpp ------------------------------------------- //
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
//
//
//
/// @author Humberto Jr. 
//
/// @date 10/2013
//
/// @return The exponent value of the given primitive function.
///         It returns zero, if the given primitive function is 
///         out of the current size set. 
//
/// @cite
//
inline double &function_expon(const unsigned int &primitive)
{
    switch(primitive <= current_set_size)
    {
        case false: return expon[0]; break;
        case  true: return expon[primitive]; break;
    }
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 01/2014
//
/// @return The exponent value of the primitive function given 
///         by the internal iterator. 
//
/// @cite
//
inline double &function_expon()
{
    return expon[iter];
}
