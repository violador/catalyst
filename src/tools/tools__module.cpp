// ../src/tools/tools__module.cpp ----------------------------------------------------------- //
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
/// @date 06/2013
//
/// @return The absolute value of the difference 
///         between the given @f$ a @f$ and 
///         @f$ b @f$, @f$ \|a - b\| @f$.
//
/// @cite
//
template<typename data_type> 
inline data_type module(const data_type &a, 
                        const data_type &b)
{
    switch((a - b) >= 0.0)
    {
        case false: return -1.0*(a - b); break;
        case  true: return a - b; break;
    }
};
