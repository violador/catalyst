// ../src/basis_set/basis_set__check_sto3g_size.cpp ----------------------------------------- //
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
#include "basis_set.hpp"
//
//
//
/// @author Humberto Jr. 
//
/// @date 10/2013
//
/// @return The default number of primitive functions per set 
///         for the STO-3G basis set. From H to I elements.
//
/// @cite
//
const unsigned int basis_set::check_sto3g_size()
{
    switch(current_element)
    {
        case  1: return  3; break;
        case  2: return  3; break;
        case  3: return  9; break;
        case  4: return  9; break;
        case  5: return  9; break;
        case  6: return  9; break;
        case  7: return  9; break;
        case  8: return  9; break;
        case  9: return  9; break;
        case 10: return  9; break;
        case 11: return 15; break;
        case 12: return 15; break;
        case 13: return 15; break;
        case 14: return 15; break;
        case 15: return 15; break;
        case 16: return 15; break;
        case 17: return 15; break;
        case 18: return 15; break;
        case 19: return 21; break;
        case 20: return 21; break;
        case 21: return 24; break;
        case 22: return 24; break;
        case 23: return 24; break;
        case 24: return 24; break;
        case 25: return 24; break;
        case 26: return 24; break;
        case 27: return 24; break;
        case 28: return 24; break;
        case 29: return 24; break;
        case 30: return 24; break;
        case 31: return 24; break;
        case 32: return 24; break;
        case 33: return 24; break;
        case 34: return 24; break;
        case 35: return 24; break;
        case 36: return 24; break;
        case 37: return 30; break;
        case 38: return 30; break;
        case 39: return 33; break;
        case 40: return 33; break;
        case 41: return 33; break;
        case 42: return 33; break;
        case 43: return 33; break;
        case 44: return 33; break;
        case 45: return 33; break;
        case 46: return 33; break;
        case 47: return 33; break;
        case 48: return 33; break;
        case 49: return 33; break;
        case 50: return 33; break;
        case 51: return 33; break;
        case 52: return 33; break;
        case 53: return 33; break;
        default: return  0; break;
    }
}
