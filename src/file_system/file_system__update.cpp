//
//
//
/// @brief A help function used to update the internal data when the
///        paths are changed.
//
/// @return None.
//
void inline update()
{
	#pragma omp parallel sections num_threads(8)
	{
		#pragma omp section
		{
			filename = file.boost::filesystem::path::filename();
		}
		#pragma omp section
		{
			root_path = file.boost::filesystem::path::root_path();
		}
		#pragma omp section
		{
			parent_path = file.boost::filesystem::path::parent_path();
		}
		#pragma omp section
		{
			relative_path = file.boost::filesystem::path::relative_path();
		}
		#pragma omp section
		{
			file_extension = file.boost::filesystem::path::extension();
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
