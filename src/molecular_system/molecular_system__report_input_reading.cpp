#include "molecular_system.hpp"
//
//
//
void molecular_system::report_input_reading() 
{
//
    global_log::file.write_debug_msg("molecular_system::report_input_reading()");
//
    switch(config -> state_of(option::output_mode))                                                                   
    {
        case true:
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
//
//      To print the title bar:
//
        global_log::file.write_title_bar(system_name, 
                                         FIRST_COLUMN_LENGTH
                                         + SECOND_COLUMN_LENGTH
                                         + SPACE_LENGTH
                                         + 7*(MAX_PRECISION + SPACE_LENGTH));
//
//      To print "Positions":
//
        global_log::file.set_width(58);
        global_log::file.set_right();
        global_log::file << "Positions";
//
//      To print "Velocities":
//
        global_log::file.set_width(46);
        global_log::file.set_right();
        global_log::file << "Velocities\n";
//
//      To print a section bar:
//
        global_log::file.set_width(FIRST_COLUMN_LENGTH + SECOND_COLUMN_LENGTH 
                                   + SPACE_LENGTH 
                                   + 6*(MAX_PRECISION + SPACE_LENGTH));
        global_log::file.set_right();
        global_log::file << "-----------------------------------------------------------------------------------------\n";
//
//      To print "Num." in the number column:
//
        global_log::file.set_width(FIRST_COLUMN_LENGTH);
        global_log::file.set_right();
        global_log::file << "Num.";
//
//      To print "Type" in the type column:
//
        global_log::file.set_width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "Type";
//
//      To print "x" in the x-axis positions column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "x";
//
//      To print "y" in the y-axis positions column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "y";
//
//      To print "z" in the z-axis positions column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "z";
//
//      To print "x" in the x-axis velocities column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "x";
//
//      To print "y" in the y-axis velocities column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "y";
//
//      To print "z" in the z-axis velocities column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "z";
//
//      To print "Mass" in the mass column:
//
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "Mass\n";
//
//      To print a section bar:
//
        global_log::file.fill_line_with(FIRST_COLUMN_LENGTH 
                                        + SECOND_COLUMN_LENGTH 
                                        + SPACE_LENGTH 
                                        + 7*(MAX_PRECISION + SPACE_LENGTH),
                                        "-");
        global_log::file.set_new_line();
//
//      To print "0" in the number column:
//
        global_log::file.set_width(FIRST_COLUMN_LENGTH);
        global_log::file.set_right();
        global_log::file << "0";
//
//      To print "COM" in the type column: 
//
        global_log::file.set_width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
        global_log::file.set_right();
        global_log::file << "COM";
//
//      To print the COM x-axis in the x-axis positions column:
//
        global_log::file.set_scientific_notation();
        global_log::file << x();
//
//      To print the COM y-axis in the y-axis positions column:
//
        global_log::file.set_scientific_notation();
        global_log::file << y();
//
//      To print the COM z-axis in the z-axis positions column:
//
        global_log::file.set_scientific_notation();
        global_log::file << z();
//
//      To print the COM x-axis in the x-axis velocities column:
//
        global_log::file.set_scientific_notation();
        global_log::file << "0.0";
//
//      To print the COM y-axis in the y-axis velocities column:
//
        global_log::file.set_scientific_notation();
        global_log::file << "0.0";
//
//      To print the COM z-axis in the z-axis velocities column:
//
        global_log::file.set_scientific_notation();
        global_log::file << "0.0";
//
//      To print the system total mass in the mass column:
//
        global_log::file.set_fixed();
        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
        global_log::file << mass();
//
        global_log::file.set_new_line();
        periodic_table get;
        for(unsigned int i_atom = 1; i_atom <= total_atoms; ++i_atom)
        {
            get.periodic_table::init(type(i_atom));
//
//          To print the number of an atom in the number column:
//
            global_log::file.set_width(FIRST_COLUMN_LENGTH);
            global_log::file.set_right();
            global_log::file << i_atom;
//
//          To print the symbol of an atom in the type column:
//
            global_log::file.set_width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
            global_log::file.set_right();
            global_log::file << get.periodic_table::symbol();
//
//          To print the x-axis value of an atom in the x-axis positions column:
//
            global_log::file.set_scientific_notation();
            global_log::file << x(POSITION, i_atom);
//
//          To print the y-axis value of an atom in the y-axis positions column:
//
            global_log::file.set_scientific_notation();
            global_log::file << y(POSITION, i_atom);
//
//          To print the z-axis value of an atom in the z-axis positions column:
//
            global_log::file.set_scientific_notation();
            global_log::file << z(POSITION, i_atom);
//
//          To print the x-axis value of an atom in the x-axis velocities column:
//
            global_log::file.set_scientific_notation();
            global_log::file << x(VELOCITY, i_atom);
//
//          To print the y-axis value of an atom in the y-axis velocities column:
//
            global_log::file.set_scientific_notation();
            global_log::file << y(VELOCITY, i_atom);
//
//          To print the z-axis value of an atom in the z-axis velocities column:
//
            global_log::file.set_scientific_notation();
            global_log::file << z(VELOCITY, i_atom);
//
//          To print the mass of an atom in the mass column:
//
            global_log::file.set_fixed();
            global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
            global_log::file << mass(i_atom);
//
            global_log::file.set_new_line();
        } // for(i_atom)
        global_log::file << "\n- Input file               = ";
        global_log::file << name();
        global_log::file << "\n- Total atoms              = ";
        global_log::file << number_of_atoms();
        global_log::file << "\n- Charge                   = ";
        global_log::file << charge;
        global_log::file << "\n- Nuclear repulsion energy = ";
        global_log::file << nuclear_repulsion_energy();
        global_log::file << " a.u.";
        global_log::file << "\n- Vibration mode           = ";
        global_log::file << config -> control_key_of(config -> state_of(option::vibration_mode));
        global_log::file << "\n- Rotation mode            = ";
        global_log::file << config -> control_key_of(config -> state_of(option::rotational_mode));
        global_log::file << "\n- Translation mode         = ";
        global_log::file << config -> control_key_of(config -> state_of(option::translation_mode));
        global_log::file << "\n";
        global_log::file.set_new_line();
        #undef FIRST_COLUMN_LENGTH
        #undef SECOND_COLUMN_LENGTH
        break;
    } 
}
