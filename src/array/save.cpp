//
//
//
std::string save(const std::string &dir, const std::string &comment = "")
{
	std::fstream txt_file, bin_file;
	std::string filename = dir + build_filename();
	std::string txt_filename = filename + TXT_FILE_EXTENSION;
	std::string bin_filename = filename + BIN_FILE_EXTENSION;
	txt_file.std::fstream::open(txt_filename.std::string::c_str(), std::fstream::out);
	bin_file.std::fstream::open(bin_filename.std::string::c_str(), std::fstream::out | std::ios::binary);
	switch(txt_file.std::fstream::is_open() && txt_file.std::fstream::good()
	       && bin_file.std::fstream::is_open() && bin_file.std::fstream::good())
	{
		case true:
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				bin_file.std::fstream::write((char*) &data + rank1, sizeof(data_type));
				bin_file.std::fstream::close();
			}
			#pragma omp section
			{
				txt_file << typeid(data_type).name() // 1) The data type
				         << std::endl
				         << bin_filename             // 2) The bin filename
				         << std::endl
				         << data_length()            // 3) The real internal length
				         << std::endl
				         << rank()                   // 4) The rank
				         << std::endl
				         << comment;                 // 5) A optional comment
/*
					txt_file << "\ndata    = " << bin_filename
					         << "\nsize    = " << data_length()
					         << "\nrank    = " << rank()
					         << "\ntype    = " << typeid(data_type).name()
					         << "\ncomment = " << comment;
*/
				txt_file.std::fstream::close();
			}
		}
		return txt_filename;
	}
	txt_file.std::fstream::close();
	bin_file.std::fstream::close();
	return "";
};
