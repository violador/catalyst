#include "molecular_system.hpp"
//
//
//
unsigned int molecular_system::get_total_atoms(const std::string input_filename)
{
//  (1) To open the input file.
//  (2) If the input file is open and ok: count the number of lines.
//  (3) To read an entire line from the input.
//  (4) To increment the counter.
//  (5) The total number of lines must be the total number of atoms.
    std::ifstream geometry_file(input_filename.c_str(), std::ios::in); // (1)
    if(geometry_file.is_open() && geometry_file.good())                // (2)
    {
        unsigned int line_counter = 0;
        std::string line;
        while (std::getline(geometry_file, line))                      // (3)
        {
            ++line_counter;                                            // (4)
        }  
        geometry_file.close();
        total_atoms_ready = true;
        return line_counter;                                           // (5)
    }
    else
    {
        std::cout << "ERROR: Was not possible to open the file!" << std::endl;
        return 0;
    }
}
