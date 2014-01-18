// ../src/settings/settings__check_current_hostname.cpp ------------------------------------- //
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
/// @date 07/2013
//
/// @return The current host ID. 
//
/// @cite
//
inline int check_current_hostname()
{
//
//  The Linux version:
    #if defined(LINUX)
    return gethostid();
    #endif
//
//  The Microsoft Windows version:
    #if defined(WIN32)
    return 0;
    #endif
//
//  The Apple OS-X version:
    #if defined(OS_X)
    return 0;
    #endif
};
