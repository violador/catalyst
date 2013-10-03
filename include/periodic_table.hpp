// ../src/include/periodic_table.hpp ---------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 06/2013
//
// Description: The periodic table class defines the type of variables that provides
//              several infos for a given chemical element. Since it can be used in
//              calculations, the implementations are in terms of inline members for
//              performance reasons.
//
// References: CRC Handbook of Chemistry and Physics, 1989.
//             R. T. Sanderson, Inorganic Chemistry, Reinhold, 1967.
//
// ------------------------------------------------------------------------------------- //
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
//  Declaring the data members:
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
    public:
//
//  Declaring the class constructor:
    periodic_table();
//
//  Including the inline/template/public member functions:
    #include "periodic_table__electrons.cpp"
    #include "periodic_table__mass.cpp"
    #include "periodic_table__name.cpp"
    #include "periodic_table__symbol.cpp"
    #include "periodic_table__type.cpp"
};
#endif
