// ../src/tools/tools__byte_to_megabyte.cpp ------------------------------------------------- //
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
/// @return The factor for conversions from bytes to megabytes. 
//
/// @cite
//
inline const double byte_to_megabyte()
{
    return 0.000000954;
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 01/2014
//
/// @return The @c input (in bytes) multiplied by the factor 
///         for conversions from bytes to megabytes.
//
/// @cite
//
template<typename data_type>
inline double byte_to_megabyte(const data_type &input)
{
    return input*0.000000954;
};
