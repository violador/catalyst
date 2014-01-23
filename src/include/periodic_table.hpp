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
    #include "tools.hpp"
//
//
//
class periodic_table
{
    private:
//
//  Declaring the data members:
    unsigned int current_element;
    unsigned int current_core_electrons;
    unsigned int current_valence_electrons;
    unsigned int current_orbitals;
    std::string current_symbol;
    std::string current_name;
    std::string current_electronic_config;
    double current_mass;
    double current_covalent_radius;
    static const unsigned int table_length = 103;
//
//  Declaring the private member functions:
    void update_data();
//
    public:
//
//  Class identifier:
    static const int id = 31100;
//
//  Declaring the class constructor:
    periodic_table();
    periodic_table(const std::string &element);
    periodic_table(const periodic_table &given);
    periodic_table(const unsigned int &given_element);
//
//  Including the inline/template/public member functions:
    #include "periodic_table__electrons.cpp"
    #include "periodic_table__mass.cpp"
    #include "periodic_table__name.cpp"
    #include "periodic_table__symbol.cpp"
    #include "periodic_table__type.cpp"
    #include "periodic_table__delete_current_data.cpp"
    #include "periodic_table__init.cpp"
    #include "periodic_table__sub_shells.cpp"
    #include "periodic_table__electronic_config.cpp"
    #include "periodic_table__increment.cpp"
    #include "periodic_table__decrement.cpp"
    #include "periodic_table__atomic_number.cpp"
    #include "periodic_table__destructor.cpp"
//
};
#endif
