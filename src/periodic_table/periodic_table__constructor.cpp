#include "periodic_table.hpp"
//
//
//
/// @brief The standard constructor that initializes the object with the internal
///        data of the first element, the hydrogen.
//
periodic_table::periodic_table(): current_element(1),
								  current_core_electrons(0),
								  current_valence_electrons(1),
								  current_orbitals(1),
								  current_symbol("H"),
								  current_name("hydrogen"),
								  current_electronic_config("1s^1"),
								  current_mass(1.007940),
								  current_covalent_radius(0.32)
{
// Empty constructor.
}
//
//
//
/// @param [in] element The number of the desired chemical element.
//
/// @brief The standard constructor that initializes the object with the internal
///        data of the input @c element number.
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
/// @param [in] element The symbol of the desired chemical element.
//
/// @brief The standard constructor that initializes the object with the internal
///        data of the input @c element symbol.
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
/// @param [in] input An object of @c periodic_table type, declared previously.
//
/// @brief The copy constructor that initializes the object with the internal
///        data of a previously constructed object of @c periodic_table type.
//
periodic_table::periodic_table(const periodic_table &input): current_element(input.current_element),
															 current_core_electrons(input.current_core_electrons),
															 current_valence_electrons(input.current_valence_electrons),
															 current_orbitals(input.current_orbitals),
															 current_symbol(input.current_symbol),
															 current_name(input.current_name),
															 current_electronic_config(input.current_electronic_config),
															 current_mass(input.current_mass),
															 current_covalent_radius(input.current_covalent_radius)
{
//  Empty constructor.
}
