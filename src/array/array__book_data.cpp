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
			switch(is_1d() and (not is_deleted()))
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
			switch(is_2d() and (not is_deleted()))
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
			switch(is_3d() and (not is_deleted()))
			{
				case true:
				std::fstream file;
				input.file_system::open_bin_output(file);
				for(unsigned int i = 0; i < rank1; ++i)
				{
					for(unsigned int j = 0; j < rank2; ++j)
					{
						for(unsigned int m = 0; m < rank3; ++m)
						{
							file.std::fstream::write((char*) &data3[i][j][m],
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
			switch(is_4d() and (not is_deleted()))
			{
				case true:
				std::fstream file;
				input.file_system::open_bin_output(file);
				for(unsigned int i = 0; i < rank1; ++i)
				{
					for(unsigned int j = 0; j < rank2; ++j)
					{
						for(unsigned int m = 0; m < rank3; ++m)
						{
							for(unsigned int n = 0; n < rank4; ++n)
							{
								file.std::fstream::write((char*) &data4[i][j][m][n],
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
									 data_id,
									 ", file = ",
									 input.file_system::full_name());
};
