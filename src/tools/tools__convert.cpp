// ../src/tools/tools__convert.cpp ---------------------------------------------------------- //
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
/// @date 09/2013
//
/// @return The @c input as the given return type.
//
/// @cite
//
template <typename data_type0, typename data_type1> 
inline data_type0 convert(const data_type1 &input)
{
//
/// @note Notice the desired return type should be 
///       specified in the function call by the 
///       @c class::function<output>(input) layout.
    return boost::lexical_cast<data_type0>(input);
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 09/2013
//
/// @return The @c input as the given return type. 
//
/// @cite
//
template <typename data_type0>
inline data_type0 convert(const std::string &input)
{
//
/// @note Notice the desired return type should be 
///       specified in the function call by the 
///       @c class::function<output>(input) layout.
    return boost::lexical_cast<data_type0>(input);
};
