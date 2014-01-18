// ../src/tools/tools__kilobyte_to_gigabyte.cpp --------------------------------------------- //
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
/// @return The conversion factor from kilobytes to gigabytes.
//
/// @cite
//
inline const double kilobyte_to_gigabyte()
{
    return 0.000000953674316;
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 01/2014
//
/// @return The @c input (in kilobytes) multiplied by the factor 
///         for conversions from kilobytes to gigabytes.
//
/// @cite
//
template<typename data_type>
inline double kilobyte_to_gigabyte(const data_type &input)
{
    return input*0.000000953674316;
};
