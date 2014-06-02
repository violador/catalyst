// ../src/include/tools.hpp ----------------------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms
//  of the GNU General Public License as published by the Free Software Foundation, either
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib.
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
#ifndef __TOOLS_HPP
    #define __TOOLS_HPP
    #include "globals.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 06/2013
//
/// @brief Generic data and functions for general tasks.
//
/// @details: The aiming is to group under the scope of 'tools', all the
///           data members or data functions for general tasks and that
///           does not belong to any class or struct. All the members are
///           of public access by any client. The only requirement is that
///           its header file should be included where it is needed.
//
// References: http://www.codata.org/
//
//             R. T. Sanderson. Inorganic Chemistry, Reinhold, 1967.
//
//             CRC Handbook of Chemistry and Physics, 1989.
//
namespace tools
{
//
//  Declaring data members to unit conversion:
    static const double ang_to_au = 1.0/0.529177208;      // From angstron to atomic unit.
    static const double au_to_ang = 0.529177208;          // From atomic unit to angstron.
    static const double ev_to_au = 1.0/27.211396;         // From electron volt to atomic unit.
    static const double au_to_ev = 27.211396;             // From atomic unit to electron volt.
    static const double s_to_au = 1.0/2.418884326505e-17; // From second to atomic unit.
    static const double au_to_s = 2.418884326505e-17;     // From atomic unit to second.
//
//
    unsigned int first_gf(const unsigned int &given_level,
                          const unsigned int &given_orbital);
//
//
    const char* convert_enum(const unsigned int option);
    unsigned int convert_enum(const char* option);
//
//  Including the inline/template/public member functions:
    #include "tools__module.cpp"
    #include "tools__square_module.cpp"
    #include "tools__pattern_length.cpp"
    #include "tools__factorial.cpp"
    #include "tools__double_factorial.cpp"
    #include "tools__binomial_coeff.cpp"
    #include "tools__point_distance.cpp"
    #include "tools__gamma_function.cpp"
    #include "tools__incomplete_gamma_function.cpp"
    #include "tools__error_function.cpp"
    #include "tools__random_number.cpp"
    #include "tools__kronecker_delta.cpp"
    #include "tools__convert.cpp"
    #include "tools__lower_case.cpp"
    #include "tools__remove_blank_spaces.cpp"
    #include "tools__remove_char.cpp"
    #include "tools__remove.cpp"
    #include "tools__comment_line.cpp"
    #include "tools__is_equal.cpp"
    #include "tools__default_precision.cpp"
    #include "tools__default_scf_criteria.cpp"
    #include "tools__default_log_file.cpp"
    #include "tools__default_config_file.cpp"
    #include "tools__default_no_file.cpp"
    #include "tools__on_ctrl_key.cpp"
    #include "tools__off_ctrl_key.cpp"
    #include "tools__max_precision.cpp"
    #include "tools__GB.cpp"
    #include "tools__MB.cpp"
    #include "tools__kB.cpp"
    #include "tools__kilobyte_to_gigabyte.cpp"
    #include "tools__default_current_dir.cpp"
    #include "tools__bohr_radius.cpp"
    #include "tools__electron_mass.cpp"
    #include "tools__atomic_mass.cpp"
    #include "tools__speed_of_light.cpp"
    #include "tools__mol.cpp"
    #include "tools__electron_charge.cpp"
    #include "tools__angstrom_length.cpp"
    #include "tools__electron_volt.cpp"
    #include "tools__boltzmann_const.cpp"
    #include "tools__planck_const.cpp"
    #include "tools__proton_mass.cpp"
    #include "tools__neutron_mass.cpp"
	#include "tools__omp_chunk.cpp"
	#include "tools__is_null.cpp"
};
#endif
