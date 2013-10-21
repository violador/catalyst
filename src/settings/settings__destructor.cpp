#include "settings.hpp"
//
//
//
settings::~settings()
{
    delete[] input_filename;
    delete[] theory_level;
}
