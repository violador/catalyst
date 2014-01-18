// ../src/tools/tools_kronecker_delta.cpp --------------------------------------------------- //
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
/// @date 12/2013
//
/// @return One if @c a and @c b are equal and zero otherwise.
//
/// @cite
//
template<typename data_type> 
inline data_type kronecker_delta(const data_type &a, 
                                 const data_type &b)
{
    switch(a == b)
    {
        case false: return (data_type) 0.0; break;
        case  true: return (data_type) 1.0; break;
    }
};
