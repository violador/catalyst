//
//
//
/// @brief Changes the current file and updates the internal data.
//
/// @return None.
//
void inline restart_file(const std::string &given_pathname,
						 const std::string &given_filename)
{
	init_file(given_filename, given_pathname);
	#pragma omp parallel sections num_threads(4)
	{
		#pragma omp section
		{
			filename = file.boost::filesystem::path::filename();
		}
		#pragma omp section
		{
			file_extension = file.boost::filesystem::path::extension();
		}
		#pragma omp section
		{
			relative_path = file.boost::filesystem::path::relative_path();
		}
		#pragma omp section
		{
			file_status = boost::filesystem::status(file);
		}
	}
};
