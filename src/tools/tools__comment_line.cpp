// ../src/tools/tools__comment_line.cpp ----------------------------------------------------- //
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
/// @return @c true if the given @c pattern is tagged as 
///         a comment line, and @c false otherwise. The 
///         current tag to recognise the comment line is 
///         @c #.
//
/// @cite
//
inline bool comment_line(const std::string &pattern)
{
    switch((bool) pattern.std::string::compare(0, 1, "#"))
    {
        case false: return  true; break;
        case  true: return false; break;
    }
};
