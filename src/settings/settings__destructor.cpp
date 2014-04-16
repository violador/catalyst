#include "settings.hpp"
//
//
//
/// @brief The default destructor.
//
settings::~settings()
{
	delete[] input_list;
	delete[] level_list;
}
