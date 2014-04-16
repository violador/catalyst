// ../src/array/array__book_data.cpp ======================================================== //
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
#include "array.hpp"
//
//
//
/// @brief A help private function used to save the current array content
///        in a binary file using the private @c input object, which
///        defines the location to save the file.
//
/// @return None.
//
void array::book_data()
{
	#pragma omp parallel sections num_threads(4)
	{
		#pragma omp section
		{
			switch(is_1d_array and (not deleted_array))
			{
				case true:
				FILE *file = NULL;
				input.file_system::open_bin_output(file);
				gsl_vector_fwrite(file, &gsl_1d_view.vector);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d_array and (not deleted_array))
			{
				case true:
				FILE *file = NULL;
				input.file_system::open_bin_output(file);
				gsl_matrix_fwrite(file, &gsl_2d_view.matrix);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_3d_array and (not deleted_array))
			{
				case true:
				std::fstream file;
				input.file_system::open_bin_output(file);
				for(unsigned int i = 0; i < sizeof_row; ++i)
				{
					for(unsigned int j = 0; j < sizeof_column; ++j)
					{
						for(unsigned int m = 0; m < sizeof_1st_layer; ++m)
						{
							file.std::fstream::write((char*) &user_3d_array[i][j][m],
																	   sizeof(double));
						}
					}
				}
				input.file_system::close(file);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d_array and (not deleted_array))
			{
				case true:
				std::fstream file;
				input.file_system::open_bin_output(file);
				for(unsigned int i = 0; i < sizeof_row; ++i)
				{
					for(unsigned int j = 0; j < sizeof_column; ++j)
					{
						for(unsigned int m = 0; m < sizeof_1st_layer; ++m)
						{
							for(unsigned int n = 0; n < sizeof_2nd_layer; ++n)
							{
								file.std::fstream::write((char*) &user_4d_array[i][j][m][n],
																	 		  sizeof(double));
							}
						}
					}
				}
				input.file_system::close(file);
				break;
			}
		}
	}
	global_log::file.write_debug_msg("array::book_data(): Array ID = ",
									 array_id,
									 ", file = ",
									 input.file_system::full_name());
};
