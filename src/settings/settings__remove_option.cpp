// ../src/settings/settings__remove_option.cpp ---------------------------------------------- //
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
/// @return None. Changes the given @c line from the config file, 
///         removing the @c option part. What remains should be
///         the key. The pattern used is @c option @c = @c key.
//
/// @cite
//          
inline void remove_option(std::string &line,
                          const std::string &option) 
{
//
/// @warning The content of the given @c line will be modified.
    line.std::string::erase(0, tools::pattern_length(option));
};
