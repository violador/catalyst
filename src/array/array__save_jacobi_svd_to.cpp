// ../src/array/array__save_jacobi_svd_to.cpp =============================================== //
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
//
//
//
inline void save_jacobi_svd_to(array &u_matrix, array &eigenvalues)
{
    if(is_2d_array and (not deleted_array))
    {
        gsl_linalg_SV_decomp_jacobi(&gsl_2d_view.matrix, &u_matrix.gsl_2d_view.matrix, &eigenvalues.gsl_1d_view.vector);
    }
    else
    {
        global_log::file.write_debug_msg("array::save_jacobi_svd_to(): Array ID = ",
                                         array_id,
                                         ", was not possible to work. Maybe the current array is either not a 2D type or it is deleted!");
    }
};