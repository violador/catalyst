// ../src/tools/tools__lower_case.cpp ------------------------------------------------------- //
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
/// @return None. Changes the given @c pattern 
///         into its lower case form, if any 
///         uppercase is found.
//
/// @cite
//
inline void lower_case(std::string &pattern)
{
//
/// @warning The content of the given @c pattern 
///          may or may not be modified.
    std::transform(pattern.std::string::begin(),
                   pattern.std::string::end(),
                   pattern.std::string::begin(),
                   std::ptr_fun(tolower));
};
