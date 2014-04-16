//
//
//
inline double my_size()
{
	return sizeof(file) + sizeof(path)
	                    + sizeof(filename)
	                    + sizeof(root_path)
	                    + sizeof(parent_path)
	                    + sizeof(relative_path)
	                    + sizeof(file_extension)
	                    + sizeof(file_status)
	                    + sizeof(path_status)
	                    + sizeof(disk_space)
	                    + sizeof(stream_ready);
};
