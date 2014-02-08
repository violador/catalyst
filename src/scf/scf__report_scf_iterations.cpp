// ../src/scf/scf__report_scf_iterations.cpp ================================================ //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
#include "scf.hpp"
//
//
//
void algorithm::scf::report_scf_iterations() 
{
    switch(config -> output_mode())                                                                   
    {
        case true:
        #ifdef FIRST_COLUMN_LENGTH
            #undef FIRST_COLUMN_LENGTH
            #define FIRST_COLUMN_LENGTH 5
        #else
            #define FIRST_COLUMN_LENGTH 5
        #endif
        #ifdef SECOND_COLUMN_LENGTH
            #undef SECOND_COLUMN_LENGTH
            #define SECOND_COLUMN_LENGTH 10
        #else
            #define SECOND_COLUMN_LENGTH 10
        #endif
        #ifdef THIRD_COLUMN_LENGTH
            #undef THIRD_COLUMN_LENGTH
            #define THIRD_COLUMN_LENGTH 10
        #else
            #define THIRD_COLUMN_LENGTH 10
        #endif
        global_log::file.write_title_bar("SCF algorithm iterations",
                                         FIRST_COLUMN_LENGTH 
                                         + SECOND_COLUMN_LENGTH
                                         + THIRD_COLUMN_LENGTH
                                         + SPACE_LENGTH
                                         + 7);
//
//      To print "Iter.":
//
        global_log::file.set_width(FIRST_COLUMN_LENGTH);
        global_log::file.set_right();
        global_log::file << "Iter.";
//
//      To print "Energy (a.u.)":
//
        global_log::file.set_width(SECOND_COLUMN_LENGTH + SPACE_LENGTH + 7);
        global_log::file.set_right();
        global_log::file << "Energy (a.u.)";
//
//      To print "Correction":
//
        global_log::file.set_width(THIRD_COLUMN_LENGTH + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "Correction";
//
        global_log::file.set_new_line();
        global_log::file.fill_line_with(FIRST_COLUMN_LENGTH 
                                        + SECOND_COLUMN_LENGTH 
                                        + THIRD_COLUMN_LENGTH 
                                        + 2*SPACE_LENGTH 
                                        + 7, 
                                        "-");
        global_log::file.set_new_line();
        for(unsigned int i = 1; i <= iteration; ++i)
        {
//
//          To print the iteration number in the iteration column:
//
            global_log::file.set_width(FIRST_COLUMN_LENGTH);
            global_log::file.set_right();
            global_log::file << i;
//
//          To print the iteration energy in the energy column:
//
            global_log::file.set_scientific_notation(SECOND_COLUMN_LENGTH + SPACE_LENGTH + 7);
            global_log::file << scf_energy[i];
//
//          To print the iteration correction in the correction column:
//
            global_log::file.set_scientific_notation();
            global_log::file << tools::module(scf_energy[i], scf_energy[i - 1]);
//
            global_log::file.set_new_line();
        }
        global_log::file << "\n- Iterations convergence           = ";
        global_log::file << (scf_converged? "reached" : "not reached");
        global_log::file << (scf_converged? "\n- Final converged SCF energy       = " : "\n- Final unconverged SCF energy     = ");
        global_log::file << energy();
        global_log::file << " a.u.";
        global_log::file << "\n- Lowest molecular orbital number  = ";
        global_log::file << lowest_mo();
        global_log::file << "\n- Highest molecular orbital number = ";
        global_log::file << highest_mo();
        global_log::file << "\n- Iteration wall time              = "; 
        global_log::file << iterations_time.timer::get(WALL_TIME, 1);
        global_log::file.set_new_line();
        #ifdef FOURTH_COLUMN_LENGTH
            #undef FOURTH_COLUMN_LENGTH
            #define FOURTH_COLUMN_LENGTH 6
        #else
            #define FOURTH_COLUMN_LENGTH 6
        #endif
        #ifdef FIFTH_COLUMN_LENGTH
            #undef FIFTH_COLUMN_LENGTH
            #define FIFTH_COLUMN_LENGTH 10
        #else
            #define FIFTH_COLUMN_LENGTH 10
        #endif
        #ifdef SIXTH_COLUMN_LENGTH
            #undef SIXTH_COLUMN_LENGTH
            #define SIXTH_COLUMN_LENGTH 10
        #else
           #define SIXTH_COLUMN_LENGTH 10
        #endif
        global_log::file.write_title_bar("Molecular orbitals",
                                         FOURTH_COLUMN_LENGTH
                                         + FIFTH_COLUMN_LENGTH
                                         + SIXTH_COLUMN_LENGTH
                                         + SPACE_LENGTH
                                         + 7);
//
//      To print "Num.":      
//
        global_log::file.set_width(FOURTH_COLUMN_LENGTH);
        global_log::file.set_right();
        global_log::file << "Num.";
//
//      To print "Energy (a.u.)":
//
        global_log::file.set_width(FIFTH_COLUMN_LENGTH + SPACE_LENGTH + 7);
        global_log::file.set_right();
        global_log::file << "Energy (a.u.)";
//
//      To print "Type":
//
        global_log::file.set_width(SIXTH_COLUMN_LENGTH + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "Type";
//
        global_log::file.set_new_line();
        global_log::file.fill_line_with(FOURTH_COLUMN_LENGTH 
                                        + FIFTH_COLUMN_LENGTH 
                                        + SIXTH_COLUMN_LENGTH 
                                        + 2*SPACE_LENGTH 
                                        + 7,
                                        "-");
        global_log::file.set_new_line();
        for(unsigned int i = 1; i <= f_eigenvalues.array::size_of_row(); ++i)
        {
//
//          To print the orbital number in the number column:
//
            global_log::file.set_width(FOURTH_COLUMN_LENGTH);
            global_log::file.set_right();
            global_log::file << i;
//
//          To print the orbital energy in the energy column:
//
            global_log::file.set_scientific_notation(FIFTH_COLUMN_LENGTH + SPACE_LENGTH + 7);
            global_log::file << f_eigenvalues(i);
//
//          To print the orbital type in the type column:
//
            global_log::file.set_width(SIXTH_COLUMN_LENGTH + SPACE_LENGTH);
            global_log::file << check_mo_type(i);
//
            global_log::file.set_new_line();
        }
        break;
    }
}