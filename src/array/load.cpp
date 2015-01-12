//
//
//
	inline int load(const std::string &txt_filename)
	{
		switch(data == NULL)
		{
			case true:
			txt_file.std::fstream::open(txt_filename.std::string::c_str(), std::fstream::in);
			switch(txt_file.std::fstream::is_open() && txt_file.std::fstream::good())
			{
				case true:
				//
				std::string type_name;
				txt_file >> type_name;
				switch(typeid(data_type).name() != type_name)
				{
					case true: return EXIT_FAILURE;
				}
				std::string bin_filename;
				txt_file >> bin_filename;
			}
		}
		return EXIT_FAILURE;
	};
