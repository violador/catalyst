#include "array.hpp"
//
//
//
/// @brief A help function to print the current 2D array in the log file.
//
/// @return None.
//
void array::write_2d_array()
{
	#pragma omp critical
	if(config -> output_mode() && is_2d() && not_deleted())
	{
		log_file << "\n- ";
		log_file << get_name();
		log_file << ":";
		log_file -> set_new_line();
		if(rank2 <= 5)
		{
			log_file -> set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
			log_file -> set_right();
			log_file << (rank2 >= 1? "1" : "");
//
			log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
			log_file -> set_right();
			log_file << (rank2 >= 2? "2" : "");
//
			log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
			log_file -> set_right();
			log_file << (rank2 >= 3? "3" : "");
//
			log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
			log_file -> set_right();
			log_file << (rank2 >= 4? "4" : "");
//
			log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
			log_file -> set_right();
			log_file << (rank2 >= 5? "5" : "");
//
			log_file -> set_new_line();
			for(unsigned int i = 1; i <= rank1; ++i)
			{
				switch(rank2)
				{
					case 1:
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file -> set_right();
						log_file << i;
//
						log_file -> set_scientific_notation();
						log_file << get(i, 1);
//
						log_file -> set_new_line();
					}
					break;
					case 2:
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file -> set_right();
						log_file << i;
//
						log_file -> set_scientific_notation();
						log_file << get(i, 1);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 2);
//
						log_file -> set_new_line();
					}
					break;
					case 3:
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file -> set_right();
						log_file << i;
//
						log_file -> set_scientific_notation();
						log_file << get(i, 1);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 2);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 3);
//
						log_file -> set_new_line();
					}
					break;
					case 4:
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file -> set_right();
						log_file << i;
//
						log_file -> set_scientific_notation();
						log_file << get(i, 1);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 2);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 3);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 4);
//
						log_file -> set_new_line();
					}
					break;
					case 5:
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file -> set_right();
						log_file << i;
//
						log_file -> set_scientific_notation();
						log_file << get(i, 1);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 2);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 3);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 4);
//
						log_file -> set_scientific_notation();
						log_file << get(i, 5);
//
						log_file -> set_new_line();
					}
					break;
				}
			} // for(i)
		}
		else // if(rank2 > 5)
		{
			if(rank2%5 == 0)
			{
				unsigned int column_counter = 0;
				for(unsigned int i = 1; i <= rank2/5; ++i)
				{
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
					log_file -> set_right();
					log_file << i + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 1 + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 2 + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 3 + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 4 + column_counter;
//
					log_file -> set_new_line();
					for(unsigned int j = 1; j <= rank1; ++j)
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file << j;
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 1 + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 2 + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 3 + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 4 + column_counter);
//
						log_file -> set_new_line();
					} // for(j)
					column_counter += 4;
				} // for (i)
			}
			else // if(rank2%5 != 0)
			{
				unsigned int column_number = 0, column_counter = 0;
				for(unsigned int i = 1; i <= rank2/5; ++i)
				{
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
					log_file -> set_right();
					log_file << i + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 1 + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 2 + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 3 + column_counter;
//
					log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
					log_file -> set_right();
					log_file << i + 4 + column_counter;
//
					log_file -> set_new_line();
					for(unsigned int j = 1; j <= rank1; ++j)
					{
						log_file -> set_width(ARRAY_INDEX_LENGTH);
						log_file << j;
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 1 + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 2 + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 3 + column_counter);
//
						log_file -> set_scientific_notation();
						log_file << get(j, i + 4 + column_counter);
//
						log_file -> set_new_line();
					} // for(j)
					column_counter += 4;
					column_number = i + column_counter;
				} // for(i)
//
				log_file -> set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
				log_file -> set_right();
				log_file << (rank2%5 >= 1? tools::convert<std::string>(column_number + 1) : "");
//
				log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
				log_file -> set_right();
				log_file << (rank2%5 >= 2? tools::convert<std::string>(column_number + 2) : "");
//
				log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
				log_file -> set_right();
				log_file << (rank2%5 >= 3? tools::convert<std::string>(column_number + 3) : "");
//
				log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
				log_file -> set_right();
				log_file << (rank2%5 >= 4? tools::convert<std::string>(column_number + 4) : "");
//
				log_file -> set_width(MAX_PRECISION + SPACE_LENGTH);
				log_file -> set_right();
				log_file << (rank2%5 >= 5? tools::convert<std::string>(column_number + 5) : "");
//
				log_file -> set_new_line();
				unsigned int m = 0;
				for(m = 1; m <= rank1; ++m)
				{
					switch(size_of_column()%5)
					{
						case 1:
						{
							log_file -> set_width(ARRAY_INDEX_LENGTH);
							log_file -> set_right();
							log_file << m;
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 1);
//
							log_file -> set_new_line();
						}
						break;
						case 2:
						{
							log_file -> set_width(ARRAY_INDEX_LENGTH);
							log_file -> set_right();
							log_file << m;
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 1);
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 2);
//
							log_file -> set_new_line();
						}
						break;
						case 3:
						{
							log_file -> set_width(ARRAY_INDEX_LENGTH);
							log_file -> set_right();
							log_file << m;
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 1);
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 2);
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 3);
//
							log_file -> set_new_line();
						}
						break;
						case 4:
						{
							log_file -> set_width(ARRAY_INDEX_LENGTH);
							log_file -> set_right();
							log_file << m;
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 1);
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 2);
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 3);
//
							log_file -> set_scientific_notation();
							log_file << get(m, column_number + 4);
//
							log_file -> set_new_line();
						}
						break;
					}
				} // for(i)
			} // else if(rank2%5 != 0)
		} // else if(rank2 > 5)
		log_file -> set_new_line();
	}
}
