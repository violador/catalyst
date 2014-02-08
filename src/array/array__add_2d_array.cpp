// ../src/array/array__add_2d_array.cpp ===================================================== //
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
// ../src/array/array__add_2d_array.cpp ----------------------------------------------------- //
//
// This file is part of Catalyst lib.
//
// Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
// of the GNU General Public License as published by the Free Software Foundation, either 
// version 3 of the License, or (at your option) any later version.
//
// Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst lib. 
// If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
//
//
//
/// @author Humberto Jr.
//
/// @date 01/2014
//
/// @param[in] b A real number.
//
/// @brief A private helper function to add the factor @c b to all 
///        the elements of the current 2D array.
//
/// @return None. 
//
/// @cite gsl
//
inline void add_2d_array(const double &b)
{
//
/// @warning Make sure to invoke this function only when the current 
///          array is a 2D type.
//
    gsl_matrix_add_constant(&gsl_2d_view.matrix, b);
};
//
//
/// @author Humberto Jr.
//
/// @date 01/2014
//
/// @param[in] b A 2D array.
//
/// @brief A private helper function to add the given array, @c b, to 
///        the current one if they are both 2D type and its dimension 
///        sizes fits.
//
/// @return None. 
//
/// @cite cblas
//
inline void add_2d_array(const array &b)
{
//
/// @note Notice this function uses the CBLAS library to take advantage
///       of its performance.
//
/// @warning Make sure to invoke this function only when the current 
///          array and @c b are both 2D type.
//
    switch(this -> sizeof_row == b.sizeof_row
           and (this -> sizeof_column == b.sizeof_column))
    {
        case true:
        cblas_daxpy((this -> sizeof_row)*(this -> sizeof_column),
                    1.0,
                    b.user_2d_array,
                    1,
                    this -> user_2d_array,
                    1);
        break;
    }
};
//
//
//
/// @author Humberto Jr.
//
/// @date 01/2014
//
/// @param[in] b A real number.
//
//  @param[in] a The array to have its elements added.
//
/// @brief A private helper function to add the factor @c b to all 
///        the elements of the given 2D array.
//
/// @return None. 
//
/// @cite gsl
//
inline void add_2d_array(array &a, const double &b)
{
//
/// @warning Make sure to invoke this function only when the given 
///          array @c a is a 2D type. Also notice that the content 
///          of @c a is going to be modified.
//
    gsl_matrix_add_constant(&a.gsl_2d_view.matrix, b);
};
//
//
/// @author Humberto Jr.
//
/// @date 01/2014
//
/// @param[in] b A 2D array.
//
/// @param[in] a A 2D array.
//
/// @brief A private helper function to add the given array, @c b, to 
///        the given @c a if they are both 2D type and its dimension 
///        sizes fits.
//
/// @return None. 
//
/// @cite cblas
//
inline void add_2d_array(array &a, const array &b)
{
//
/// @note Notice this function uses the CBLAS library to take advantage
///       of its performance.
//
/// @warning Make sure to invoke this function only when the current 
///          array and @c b are both 2D type. Also notice that the 
///          content of @c a is going to be modified.
//
    switch(a.sizeof_row == b.sizeof_row
           and a.sizeof_column == b.sizeof_column)
    {
        case true:
        cblas_daxpy(a.sizeof_row*a.sizeof_column,
                    1.0,
                    b.user_2d_array,
                    1,
                    a.user_2d_array,
                    1);
        break;
    }
};