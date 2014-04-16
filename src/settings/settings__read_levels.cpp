#include "settings.hpp"
//
//
//
/// @brief This help function dynamically allocates the @c level_list data
///        member (an array of @c total_tasks size) and initializes its content.
//
/// @return None.
//
void settings::read_levels()
{
//
/// @note This member function is designed only to help the class constructor and has
///       no other application so far.
//
/// @warning This function should be invoked only after that @c total_task was properly
///          initialized. The default value of @c total_task should be 1, in such case,
///          this function creates the default @c input_list[1] and initializes the
///          single input.
//
	switch(total_tasks > 1)
	{
		case false:
		{
			level_list = new unsigned int[1];
			level_list[0] = 2;
		}
		break;
		case true:
		{
			unsigned int i = 0;
			level_list = new unsigned int[total_tasks];
			#pragma omp parallel for private(i) ordered schedule(dynamic)
			for(i = 1; i <= total_tasks; ++i)
			{
				std::string option = "level"
								   + tools::convert<std::string>(i)
								   + "=";
				//level_list[i - 1] = scan_config_file(option, 2);
			}
		}
		break;
	}
}
