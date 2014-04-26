#include "settings.hpp"
//
//
//
/// @brief A help function that dynamically allocates the @c input data member
///        (an array of @c total_tasks size) and initializes its content.
//
/// @return None.
//
void settings::read_inputs()
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
			input_list = new std::string[1];
			input_list[0] = scan_config_file("input1=", (std::string) "");
		}
		break;
		case true:
		{
			input_list = new std::string[total_tasks];
			#pragma omp for schedule(dynamic) nowait
			for(unsigned int i = 1; i <= total_tasks; ++i)
			{
				std::string option = "input"
								   + tools::convert<std::string>(i)
								   + "=";
				input_list[i - 1] = scan_config_file(option, (std::string) "");
			}
		}
		break;
	}
}
