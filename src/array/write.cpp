//
//
//
/// @param [out] file A stream file open previously.
//
/// @param [in] comment An optional comment (an empty string by default if not given).
//
/// @param [in] num_length The data precision (8 digits by default if not given).
//
/// @brief Write out the content in the given file, only if the current rank two array was previously
/// initialized either by construction or the array::create() member function. Otherwise nothing is
/// done. The stream file must be opened and checked by the caller. Optional arguments, namely a
/// comment as string and the precision of the written data, can be given in order to customize its
/// usage. An empty string as comment and a precision of 8 digits is used by default if not specified.
/// The operation is carried out by the master thread only.
//
/// @return None.
//
#if CURRENT_RANK == 2
	void write(std::ofstream &file, std::string comment = "", unsigned int num_length = 8)
	{
		#pragma omp master
		if(is_ready())
		{
			file << comment << std::endl;
			const unsigned int space_length(num_length + 10);
			if(second_rank() <= 5)
			{
//
				file.std::ofstream::width(space_length + ARRAY_INDEX_LENGTH);
				file.std::ofstream::fill(' ');
				file << std::right << (second_rank() >= 1? "1" : "");
//
				file.std::ofstream::width(space_length);
				file.std::ofstream::fill(' ');
				file << std::right << (second_rank() >= 2? "2" : "");
//
				file.std::ofstream::width(space_length);
				file.std::ofstream::fill(' ');
				file << std::right << (second_rank() >= 3? "3" : "");
//
				file.std::ofstream::width(space_length);
				file.std::ofstream::fill(' ');
				file << std::right << (second_rank() >= 4? "4" : "");
//
				file.std::ofstream::width(space_length);
				file.std::ofstream::fill(' ');
				file << std::right << (second_rank() >= 5? "5" : "");
//
				file << std::endl;
//
				for(unsigned int i(1); i <= first_rank(); ++i)
				{
					switch(second_rank())
					{
						case 1:
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file.std::ofstream::fill(' ');
							file << i;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 1)];
//
							file << std::endl;
//
						}
						break;
						case 2:
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file.std::ofstream::fill(' ');
							file << i;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 1)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 2)];
//
							file << std::endl;
//
						}
						break;
						case 3:
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file.std::ofstream::fill(' ');
							file << i;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 1)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 2)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 3)];
//
							file << std::endl;
//
						}
						break;
						case 4:
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file.std::ofstream::fill(' ');
							file << i;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 1)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 2)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 3)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 4)];
//
							file << std::endl;
//
						}
						break;
						case 5:
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file.std::ofstream::fill(' ');
							file << i;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 1)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 2)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 3)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 4)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(i, 5)];
//
							file << std::endl;
//
						}
						break;
					}
				}
			}
			else // if(second_rank() > 5)
			{
				if(second_rank()%5 == 0)
				{
					unsigned int column_counter(0);
					for(unsigned int i(1); i <= second_rank()/5; ++i)
					{
//
						file.std::ofstream::width(space_length + ARRAY_INDEX_LENGTH);
						file.std::ofstream::fill(' ');
						file << i + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 1 + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 2 + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 3 + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 4 + column_counter;
//
						file << std::endl;
//
						for(unsigned int j(1); j <= first_rank(); ++j)
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file << j;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 1 + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 2 + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 3 + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 4 + column_counter)];
//
							file << std::endl;
//
						} // for(j)
						column_counter += 4;
					} // for(i)
				}
				else // if(second_rank()%5 != 0)
				{
					unsigned int column_number(0), column_counter(0);
					for(unsigned int i(1); i <= second_rank()/5; ++i)
					{
//
						file.std::ofstream::width(space_length + ARRAY_INDEX_LENGTH);
						file.std::ofstream::fill(' ');
						file << i + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 1 + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 2 + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 3 + column_counter;
//
						file.std::ofstream::width(space_length);
						file.std::ofstream::fill(' ');
						file << i + 4 + column_counter;
//
						file << std::endl;
//
						for(unsigned int j(1); j <= first_rank(); ++j)
						{
//
							file.std::ofstream::width(ARRAY_INDEX_LENGTH);
							file << j;
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 1 + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 2 + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 3 + column_counter)];
//
							file.std::ofstream::precision(num_length);
							file.std::ofstream::width(space_length);
							file << std::right << std::scientific << data[offset(j, i + 4 + column_counter)];
//
							file << std::endl;
//
						} // for(j)
						column_counter += 4;
						column_number = i + column_counter;
					} // for(i)
//
					file.std::ofstream::width(space_length + ARRAY_INDEX_LENGTH);
					file.std::ofstream::fill(' ');
					file << (second_rank()%5 >= 1? tools::convert<std::string>(column_number + 1) : "");
//
					file.std::ofstream::width(space_length);
					file.std::ofstream::fill(' ');
					file << (second_rank()%5 >= 2? tools::convert<std::string>(column_number + 2) : "");
//
					file.std::ofstream::width(space_length);
					file.std::ofstream::fill(' ');
					file << (second_rank()%5 >= 3? tools::convert<std::string>(column_number + 3) : "");
//
					file.std::ofstream::width(space_length);
					file.std::ofstream::fill(' ');
					file << (second_rank()%5 >= 4? tools::convert<std::string>(column_number + 4) : "");
//
					file.std::ofstream::width(space_length);
					file.std::ofstream::fill(' ');
					file << (second_rank()%5 >= 5? tools::convert<std::string>(column_number + 5) : "");
//
					file << std::endl;
//
					for(unsigned int m(1); m <= first_rank(); ++m)
					{
						switch(second_rank()%5)
						{
							case 1:
							{
//
								file.std::ofstream::width(ARRAY_INDEX_LENGTH);
								file.std::ofstream::fill(' ');
								file << m;
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								file << std::endl;
//
							}
							break;
							case 2:
							{
//
								file.std::ofstream::width(ARRAY_INDEX_LENGTH);
								file.std::ofstream::fill(' ');
								file << m;
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 2)];
//
								file << std::endl;
//
							}
							break;
							case 3:
							{
//
								file.std::ofstream::width(ARRAY_INDEX_LENGTH);
								file.std::ofstream::fill(' ');
								file << m;
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 2)];
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 3)];
//
								file << std::endl;
//
							}
							break;
							case 4:
							{
//
								file.std::ofstream::width(ARRAY_INDEX_LENGTH);
								file.std::ofstream::fill(' ');
								file << m;
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 2)];
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 3)];
//
								file.std::ofstream::precision(num_length);
								file.std::ofstream::width(space_length);
								file << std::right << std::scientific << data[offset(m, column_number + 4)];
//
								file << std::endl;
//
							}
							break;
						}
					} // for(m)
				} // else if(second_rank()%5 != 0)
			} // else if(second_rank() > 5)
		} // if(is_ready())
	};
#endif
//
//
//
/// @param [in] comment An optional comment (an empty string by default if not given).
//
/// @param [in] num_length The data precision (8 digits by default if not given).
//
/// @brief Write out the content in the @c std::cout, only if the current rank two array was previously
/// initialized either by construction or the array::create() member function. Otherwise nothing is done.
/// Optional arguments, namely a comment as string and the precision of the written data, can be  given in
/// order to customize its usage. An empty string as comment and a precision of 8 digits is used by default
/// if not specified. The operation is carried out by the master thread only.
//
/// @return None.
//
#if CURRENT_RANK == 2
	void write(std::string comment = "", unsigned int num_length = 8)
	{
		#pragma omp master
		if(is_ready())
		{
			std::cout << comment << std::endl;
			const unsigned int space_length(num_length + 10);
			if(second_rank() <= 5)
			{
//
				std::cout.std::ostream::width(space_length + ARRAY_INDEX_LENGTH);
				std::cout.std::ostream::fill(' ');
				std::cout << std::right << (second_rank() >= 1? "1" : "");
//
				std::cout.std::ostream::width(space_length);
				std::cout.std::ostream::fill(' ');
				std::cout << std::right << (second_rank() >= 2? "2" : "");
//
				std::cout.std::ostream::width(space_length);
				std::cout.std::ostream::fill(' ');
				std::cout << std::right << (second_rank() >= 3? "3" : "");
//
				std::cout.std::ostream::width(space_length);
				std::cout.std::ostream::fill(' ');
				std::cout << std::right << (second_rank() >= 4? "4" : "");
//
				std::cout.std::ostream::width(space_length);
				std::cout.std::ostream::fill(' ');
				std::cout << std::right << (second_rank() >= 5? "5" : "");
//
				std::cout << std::endl;
//
				for(unsigned int i(1); i <= first_rank(); ++i)
				{
					switch(second_rank())
					{
						case 1:
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout.std::ostream::fill(' ');
							std::cout << i;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 1)];
//
							std::cout << std::endl;
//
						}
						break;
						case 2:
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout.std::ostream::fill(' ');
							std::cout << i;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 1)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 2)];
//
							std::cout << std::endl;
//
						}
						break;
						case 3:
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout.std::ostream::fill(' ');
							std::cout << i;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 1)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 2)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 3)];
//
							std::cout << std::endl;
//
						}
						break;
						case 4:
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout.std::ostream::fill(' ');
							std::cout << i;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 1)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 2)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 3)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 4)];
//
							std::cout << std::endl;
//
						}
						break;
						case 5:
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout.std::ostream::fill(' ');
							std::cout << i;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 1)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 2)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 3)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 4)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(i, 5)];
//
							std::cout << std::endl;
//
						}
						break;
					}
				}
			}
			else // if(second_rank() > 5)
			{
				if(second_rank()%5 == 0)
				{
					unsigned int column_counter(0);
					for(unsigned int i(1); i <= second_rank()/5; ++i)
					{
//
						std::cout.std::ostream::width(space_length + ARRAY_INDEX_LENGTH);
						std::cout.std::ostream::fill(' ');
						std::cout << i + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 1 + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 2 + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 3 + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 4 + column_counter;
//
						std::cout << std::endl;
//
						for(unsigned int j(1); j <= first_rank(); ++j)
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout << j;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 1 + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 2 + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 3 + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 4 + column_counter)];
//
							std::cout << std::endl;
//
						} // for(j)
						column_counter += 4;
					} // for(i)
				}
				else // if(second_rank()%5 != 0)
				{
					unsigned int column_number(0), column_counter(0);
					for(unsigned int i(1); i <= second_rank()/5; ++i)
					{
//
						std::cout.std::ostream::width(space_length + ARRAY_INDEX_LENGTH);
						std::cout.std::ostream::fill(' ');
						std::cout << i + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 1 + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 2 + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 3 + column_counter;
//
						std::cout.std::ostream::width(space_length);
						std::cout.std::ostream::fill(' ');
						std::cout << i + 4 + column_counter;
//
						std::cout << std::endl;
//
						for(unsigned int j(1); j <= first_rank(); ++j)
						{
//
							std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
							std::cout << j;
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 1 + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 2 + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 3 + column_counter)];
//
							std::cout.std::ostream::precision(num_length);
							std::cout.std::ostream::width(space_length);
							std::cout << std::right << std::scientific << data[offset(j, i + 4 + column_counter)];
//
							std::cout << std::endl;
//
						} // for(j)
						column_counter += 4;
						column_number = i + column_counter;
					} // for(i)
//
					std::cout.std::ostream::width(space_length + ARRAY_INDEX_LENGTH);
					std::cout.std::ostream::fill(' ');
					std::cout << (second_rank()%5 >= 1? tools::convert<std::string>(column_number + 1) : "");
//
					std::cout.std::ostream::width(space_length);
					std::cout.std::ostream::fill(' ');
					std::cout << (second_rank()%5 >= 2? tools::convert<std::string>(column_number + 2) : "");
//
					std::cout.std::ostream::width(space_length);
					std::cout.std::ostream::fill(' ');
					std::cout << (second_rank()%5 >= 3? tools::convert<std::string>(column_number + 3) : "");
//
					std::cout.std::ostream::width(space_length);
					std::cout.std::ostream::fill(' ');
					std::cout << (second_rank()%5 >= 4? tools::convert<std::string>(column_number + 4) : "");
//
					std::cout.std::ostream::width(space_length);
					std::cout.std::ostream::fill(' ');
					std::cout << (second_rank()%5 >= 5? tools::convert<std::string>(column_number + 5) : "");
//
					std::cout << std::endl;
//
					for(unsigned int m(1); m <= first_rank(); ++m)
					{
						switch(second_rank()%5)
						{
							case 1:
							{
//
								std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
								std::cout.std::ostream::fill(' ');
								std::cout << m;
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								std::cout << std::endl;
//
							}
							break;
							case 2:
							{
//
								std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
								std::cout.std::ostream::fill(' ');
								std::cout << m;
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 2)];
//
								std::cout << std::endl;
//
							}
							break;
							case 3:
							{
//
								std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
								std::cout.std::ostream::fill(' ');
								std::cout << m;
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 2)];
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 3)];
//
								std::cout << std::endl;
//
							}
							break;
							case 4:
							{
//
								std::cout.std::ostream::width(ARRAY_INDEX_LENGTH);
								std::cout.std::ostream::fill(' ');
								std::cout << m;
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 1)];
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 2)];
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 3)];
//
								std::cout.std::ostream::precision(num_length);
								std::cout.std::ostream::width(space_length);
								std::cout << std::right << std::scientific << data[offset(m, column_number + 4)];
//
								std::cout << std::endl;
//
							}
							break;
						}
					} // for(m)
				} // else if(second_rank()%5 != 0)
			} // else if(second_rank() > 5)
		} // if(is_ready())
	};
#endif
