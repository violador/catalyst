#include "molecular_system.hpp"
//
//
//
void molecular_system::report_input_reading() 
{
    if(config -> state_of(OUTPUT_MODE))                                                                   
    {
        #ifdef FIRST_COLUMN_LENGTH
            #undef FIRST_COLUMN_LENGTH
            #define FIRST_COLUMN_LENGTH 4
        #else
            #define FIRST_COLUMN_LENGTH 4
        #endif
        #ifdef SECOND_COLUMN_LENGTH
            #undef SECOND_COLUMN_LENGTH
            #define SECOND_COLUMN_LENGTH 4
        #else
            #define SECOND_COLUMN_LENGTH 4
        #endif
        unsigned int title_bar_length = FIRST_COLUMN_LENGTH 
                                      + SECOND_COLUMN_LENGTH
                                      + SPACE_LENGTH
                                      + 7*(MAX_PRECISION + SPACE_LENGTH)
                                      - system_name.length() 
                                      + 4;
//
//      To print the title bar:
//
        log_file -> output << "\n== " << system_name << " "; 
        log_file -> output.width(title_bar_length);
        log_file -> output.fill('=');
        log_file -> output << "\n" << std::endl;
//
//      To print "Positions":
//
        log_file -> output.width(58);
        log_file -> output.fill(' ');
        log_file -> output << "Positions";
//
//      To print "Velocities":
//
        log_file -> output.width(46);
        log_file -> output.fill(' ');
        log_file -> output << "Velocities\n";
//
//      To print a section bar:
//
        log_file -> output.width(FIRST_COLUMN_LENGTH + 
                                 SECOND_COLUMN_LENGTH + 
                                 SPACE_LENGTH + 
                                 6*(MAX_PRECISION + SPACE_LENGTH));
        log_file -> output.fill(' ');
        log_file -> output << "-----------------------------------------------------------------------------------------\n";
//
//      To print "Num." in the number column:
//
        log_file -> output.width(FIRST_COLUMN_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << "Num.";
//
//      To print "Type" in the type column:
//
        log_file -> output.width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << "Type";
//
//      To print "x" in the x-axis positions column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "x";
//
//      To print "y" in the y-axis positions column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "y";
//
//      To print "z" in the z-axis positions column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "z";
//
//      To print "x" in the x-axis velocities column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "x";
//
//      To print "y" in the y-axis velocities column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "y";
//
//      To print "z" in the z-axis velocities column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "z";
//
//      To print "Mass" in the mass column:
//
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "Mass\n";
//
//      To print a section bar:
//
        log_file -> output.width(FIRST_COLUMN_LENGTH + 
                                 SECOND_COLUMN_LENGTH + 
                                 SPACE_LENGTH + 
                                 7*(MAX_PRECISION + SPACE_LENGTH));
        log_file -> output.fill('-');
        log_file -> output << "\n";
//
//      To print "0" in the number column:
//
        log_file -> output.fill(' ');
        log_file -> output.width(FIRST_COLUMN_LENGTH);
        log_file -> output << std::right << "0";
//
//      To print "COM" in the type column: 
//
        log_file -> output.width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
        log_file -> output.fill(' ');
        log_file -> output << std::right << "COM";
//
//      To print the COM x-axis in the x-axis positions column:
//
        log_file -> output << std::scientific;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << x();
//
//      To print the COM y-axis in the y-axis positions column:
//
        log_file -> output << std::scientific;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << y();
//
//      To print the COM z-axis in the z-axis positions column:
//
        log_file -> output << std::scientific;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << z();
//
//      To print the COM x-axis in the x-axis velocities column:
//
        log_file -> output << std::scientific;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << "0.0";
//
//      To print the COM y-axis in the y-axis velocities column:
//
        log_file -> output << std::scientific;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << "0.0";
//
//      To print the COM z-axis in the z-axis velocities column:
//
        log_file -> output << std::scientific;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << "0.0";
//
//      To print the system total mass in the mass column:
//
        log_file -> output << std::fixed;
        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
        log_file -> output.precision(config -> numeric_precision());
        log_file -> output << std::right << mass() << std::endl;
//
        periodic_table get;
        for(unsigned int i_atom = 1; i_atom <= total_atoms; i_atom++)
        {
//
//          To print the number of an atom in the number column:
//
            log_file -> output.fill(' ');
            log_file -> output.width(FIRST_COLUMN_LENGTH);
            log_file -> output << std::right << i_atom;
//
//          To print the symbol of an atom in the type column:
//
            log_file -> output.width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
            log_file -> output.fill(' ');
            log_file -> output << std::right << get.periodic_table::symbol(type(i_atom));
//
//          To print the x-axis value of an atom in the x-axis positions column:
//
            log_file -> output << std::scientific;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << x(POSITION, i_atom);
//
//          To print the y-axis value of an atom in the y-axis positions column:
//
            log_file -> output << std::scientific;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << y(POSITION, i_atom);
//
//          To print the z-axis value of an atom in the z-axis positions column:
//
            log_file -> output << std::scientific;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << z(POSITION, i_atom);
//
//          To print the x-axis value of an atom in the x-axis velocities column:
//
            log_file -> output << std::scientific;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << x(VELOCITY, i_atom);
//
//          To print the y-axis value of an atom in the y-axis velocities column:
//
            log_file -> output << std::scientific;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << y(VELOCITY, i_atom);
//
//          To print the z-axis value of an atom in the z-axis velocities column:
//
            log_file -> output << std::scientific;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << z(VELOCITY, i_atom);
//
//          To print the mass of an atom in the mass column:
//
            log_file -> output << std::fixed;
            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
            log_file -> output.precision(config -> numeric_precision());
            log_file -> output << std::right << mass(i_atom) << std::endl;
//
        } // for(i_atom)
        log_file -> output << "\n- Input file               = " << name()
                           << "\n- Total atoms              = " << number_of_atoms()
                           << "\n- Charge                   = " << charge
                           << "\n- Nuclear repulsion energy = " << nuclear_repulsion_energy() << " a.u."
                           << std::endl;
        #undef FIRST_COLUMN_LENGTH
        #undef SECOND_COLUMN_LENGTH
    } // if(not config -> state_of(OUTPUT_MODE)) 
}
