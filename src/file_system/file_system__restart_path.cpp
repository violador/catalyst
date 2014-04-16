//
//
//
/// @brief Changes the current path and updates the internal data.
//
/// @return None.
//
void inline restart_path(const std::string &given_pathname)
{
	input = init_path(given_pathname);
	#pragma omp parallel sections num_threads(8)
	{
		#pragma omp section
		{
			filename = path.boost::filesystem::path::filename();
		}
		#pragma omp section
		{
			root_path = path.boost::filesystem::path::root_path();
		}
		#pragma omp section
		{
			parent_path = path.boost::filesystem::path::parent_path();
		}
		#pragma omp section
		{
			relative_path = path.boost::filesystem::path::relative_path();
		}
		#pragma omp section
		{
			file_extension = path.boost::filesystem::path::extension();
		}
		#pragma omp section
		{
			file_status = boost::filesystem::status(file);
		}
		#pragma omp section
		{
			path_status = boost::filesystem::status(path);
		}
		#pragma omp section
		{
			disk_space = boost::filesystem::space(path);
		}
	}
};
