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
    #include "global_log.hpp"
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
    unsigned int total_functions;                   // The basis's number of primitive functions for the current element.
    unsigned int current_level;                     // The current level of theory used to init the basis database.
    double *exponent;                               // The basis's exponent set.
    double *coefficient;                            // The basis's coefficient set.
    double slater_exponent;
    static const unsigned int total_elements = 103; // The total number of elements used until now.
    double element_mass;                            // The atomic mass for the given element.
    double covalent_radius;                         // The atomic radii (covalent) for the given element.
    bool standard_database_ready;                   // The usage state of the current database.
    bool basis_database_ready;                      // The usage state of the current database.
//
//  database(): Overloaded member function to set the data member values for a given element,
//              as unsigned int.
    void database(const unsigned int &element);
//
//  database(): Overloaded member function to set the data member values for a given element,
//              as std::string.
    void database(const std::string &symbol);
//
//  sto3g_exponent_database(): To set all the primitive exponents for a given element.
    void sto3g_exponent_database(const unsigned int &element);
//
//  sto3g_coefficient_database(): To set all the primitive coefficients for a given element.
    void sto3g_coefficient_database(const unsigned int &element);
//
//  sto3g_total_functions(): To return the total number of primitives for a given element.
    unsigned int sto3g_set_size(const unsigned int &element);
//
    public:
//
//  Class identifier:
    static const int id = 31100;
//
//  Declaring the class constructor:
    periodic_table();
//
//  Declaring the class constructor:
    periodic_table(const unsigned int &given_element);
//
//  Declaring the class constructor:
    periodic_table(const unsigned int &given_theory_level, const unsigned int &given_element);
//
//  Declaring the class destructor:
    ~periodic_table();
//
//
    #define BASIS_EXPONENT    1
    #define BASIS_COEFFICIENT 2
//
//  Including the inline/template/public member functions:
    #include "periodic_table__electrons.cpp"
    #include "periodic_table__mass.cpp"
    #include "periodic_table__name.cpp"
    #include "periodic_table__symbol.cpp"
    #include "periodic_table__type.cpp"
    #include "periodic_table__basis_exponent.cpp"
    #include "periodic_table__basis_coefficient.cpp"
    #include "periodic_table__basis_size.cpp"
    #include "periodic_table__function_call.cpp"
    #include "periodic_table__init_data.cpp"
    #include "periodic_table__norm.cpp"
//
};
#endif
