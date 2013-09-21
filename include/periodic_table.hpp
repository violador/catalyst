#ifndef __PERIODIC_TABLE_HPP
#define __PERIODIC_TABLE_HPP
#include "globals.hpp"
//
//
//
class periodic_table
{
private:
//
//  Declaring the data members to store the chemical element properties:
    std::string element_symbol;                     // The element symbol.
    std::string element_name;                       // The element name.
    std::string element_config;                     // The electron configuration for the given element.
    unsigned int element_core_electrons;            // The number of core electrons for the given element.
    unsigned int element_valence_electrons;         // The number of valence electrons for the given element.
    static const unsigned int total_elements = 103; // The total number of elements used until now.
    double element_mass;                            // The atomic mass for the given element.
    double covalent_radius;                         // The atomic radii (covalent) for the given element.
//
//  database(): Overloaded member function to set the data member values of a given element,
//              as unsigned int.
    void database(const unsigned int &element);
//
//  database(): Overloaded member function to set the data member values of a given element,
//              as std::string.
    void database(const std::string &symbol);
//
//
public:
//
// Declaring and defining the inline class constructor:
    periodic_table()
    {
        element_symbol = "";
        element_name = "";
        element_config = "";
        element_core_electrons = 0;
        element_valence_electrons = 0;
        element_mass = 0.0;
        covalent_radius = 0.0;
    };
//
//  type(): To get the integer element type of a given string element symbol.
    unsigned int type(const std::string symbol);
//
//  core_electrons(): To get the number of core electrons of a given element.
    unsigned int core_electrons(const unsigned int &element);
//
//  valence_electrons(): To get the number of valence electrons of a given element. 
    unsigned int valence_electrons(const unsigned int &element);
//
//  mass(): To get the mass of a given element.
    double mass(const unsigned int element);
//
//  symbol(): To get the symbol of a given element. 
    std::string symbol(const unsigned int &element);
//
//  name(): To get the name of a given element. 
    std::string name(const unsigned int &element);
//
//
};
#endif
