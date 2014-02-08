// ../src/array/array__function_call.cpp ==================================================== //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
// ../src/array/array__function_call.cpp ---------------------------------------------------- //
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
/// @return The current value in the @f$ A_i @f$ element.
//
/// @cite
//
inline double &operator ()(const unsigned int &i) 
{
//
/// @note Notice that it is valid for 1D arrays only.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    return user_1d_array[i - 1];
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return None. Sets the given @c value in the @f$ A_i
///         @f$ element.
//
/// @cite
//
inline void operator ()(const unsigned int &i, 
                        const double &value) 
{
//
/// @note Notice that it is valid for non-constant 
///       and 1D arrays.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    switch(is_const_array)
    {
        case false: 
	user_1d_array[i - 1] = value; 
	break;
    }
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return The current @c value in the @f$ A_i,j @f$
///         element.
//
/// @cite
//
inline double &operator ()(const unsigned int &i, 
                           const unsigned int &j) 
{
//
/// @note Notice that it is valid for 2D arrays only.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    return user_2d_array[(i - 1)*sizeof_row + (j - 1)];
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return None. Sets the given @c value in the @f$ A_i,j 
///         @f$ element.
//
/// @cite
//
inline void operator ()(const unsigned int &i, 
                        const unsigned int &j, 
                        const double &value) 
{
//
/// @note Notice that it is valid for non-constant 
///       and 2D arrays.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    switch(is_const_array)
    {
        case false: 
	user_2d_array[(i - 1)*sizeof_row + (j - 1)] = value; 
	break;
    }
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return The current value in the @f$ A_i,j,m @f$ element.
//
/// @cite
//
inline double &operator ()(const unsigned int &i, 
                           const unsigned int &j, 
                           const unsigned int &m) 
{
//
/// @note Notice that it is valid for 3D arrays only.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    return user_3d_array[i - 1][j - 1][m - 1];
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return None. Sets the given @c value in the @f$ A_i,j,m 
///         @f$ element.
//
/// @cite
//
inline void operator ()(const unsigned int &i, 
                        const unsigned int &j, 
                        const unsigned int &m, 
                        const double &value) 
{
//
/// @note Notice that it is valid for non-constant 
///       and 3D arrays.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    switch(is_const_array)
    {
        case false: 
	user_3d_array[i - 1][j - 1][m - 1] = value; 
	break;
    }
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return The current value in the @f$ A_i,j,m,n @f$ element.
//
/// @cite
//
inline double &operator ()(const unsigned int &i, 
                           const unsigned int &j, 
                           const unsigned int &m, 
                           const unsigned int &n) 
{
//
/// @note Notice that it is valid for 3D arrays only.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    return user_4d_array[i - 1][j - 1][m - 1][n - 1];
};
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return None. Sets the given @c value in the @f$ A_i,j,m,n 
///         @f$ element.
//
/// @cite
//
inline void operator ()(const unsigned int &i, 
                        const unsigned int &j, 
                        const unsigned int &m, 
                        const unsigned int &n, 
                        const double &value) 
{
//
/// @note Notice that it is valid for non-constant 
///       and 4D arrays.
//
//
/// @warning This function do not checks the array bounds. 
///          If the given element is out of range, it 
///          throws the standard C/C++ out of range error.
//
    switch(is_const_array)
    {
        case false: 
	user_4d_array[i - 1][j - 1][m - 1][n - 1] = value; 
	break;
    }
};