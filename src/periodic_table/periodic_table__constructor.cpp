#include "periodic_table.hpp"
//
//
//
periodic_table::periodic_table(): current_element(0),
                                  current_core_electrons(0),
                                  current_valence_electrons(0),
                                  current_orbitals(0),
                                  current_symbol(""),
                                  current_name(""),
                                  current_electronic_config(""),
                                  current_mass(0.0),
                                  current_covalent_radius(0.0)
{
//  Empty constructor.
}
//
//
//
periodic_table::periodic_table(const unsigned int &element): current_element(element),
                                                             current_core_electrons(0),
                                                             current_valence_electrons(0),
                                                             current_orbitals(0),
                                                             current_symbol(""),
                                                             current_name(""),
                                                             current_electronic_config(""),
                                                             current_mass(0.0),
                                                             current_covalent_radius(0.0)
{
    update_data();
}
//
//
//
periodic_table::periodic_table(const std::string &element): current_element(0),
                                                            current_core_electrons(0),
                                                            current_valence_electrons(0),
                                                            current_orbitals(0),
                                                            current_symbol(""),
                                                            current_name(""),
                                                            current_electronic_config(""),
                                                            current_mass(0.0),
                                                            current_covalent_radius(0.0)
{
    do
    {
        ++current_element;
        update_data();
    }
    while(element.std::string::compare(current_symbol) not_eq 0);
}
//
//
//
periodic_table::periodic_table(const periodic_table &given): current_element(given.current_element),
                                                             current_core_electrons(given.current_core_electrons),
                                                             current_valence_electrons(given.current_valence_electrons),
                                                             current_orbitals(given.current_orbitals),
                                                             current_symbol(given.current_symbol),
                                                             current_name(given.current_name),
                                                             current_electronic_config(given.current_electronic_config),
                                                             current_mass(given.current_mass),
                                                             current_covalent_radius(given.current_covalent_radius)
{
}
