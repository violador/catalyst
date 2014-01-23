// ../src/basis_set/basis_set__increment.cpp ------------------------------------------------ //
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
/// @date 01/2014
//
/// @return None. Increments the internal iterator. 
//
/// @cite
//
inline void operator ++()
{
    switch(iter < current_set_size)
    {
        case true: ++iter; break;
    }
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 01/2014
//
/// @return None. Increments the internal iterator.
//
/// @cite
//
inline void operator ++(int)
{
    switch(iter < current_set_size)
    {
        case true: ++iter; break;
    }
};
