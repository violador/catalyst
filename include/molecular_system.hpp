#ifndef __MOLECULAR_SYSTEM_HPP
    #define __MOLECULAR_SYSTEM_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "periodic_table.hpp"
    #include "sto3g.hpp"
    #include "scf.hpp"
    #include "tools.hpp"
    #include "log_file_handler.hpp"
//
//
//
class molecular_system
{
private:
//
//  Declaring the data members:
    settings *config;             // A pointer-object to link with any object of settings type.
    log_file_handler *log_file;   // A pointer-object to link with any object of log_file_handler type. 
    unsigned int task_number;     // The number of the current task.
    unsigned int total_electrons; // The total number of electrons.
    unsigned int total_atoms;     // The total number of atoms.
    array atom_type;              // The type of each atom (Z) as a non negative integral type.
    array position_x;             // The atom position in the x axis.
    array position_y;             // The atom position in the y axis.
    array position_z;             // The atom position in the z axis.
    array velocity_x;             // The atom velocity in the x axis.
    array velocity_y;             // The atom velocity in the y axis.
    array velocity_z;             // The atom velocity in the z axis.
    double total_mass;            // The molecular system mass.
    double charge;                // The molecular system charge.
    double nuclear_repulsion;     // The nuclei-nuclei repulsion energy.
    double system_com_x;          // The system's center of mass position in the x axis.
    double system_com_y;          // The system's center of mass position in the y axis.
    double system_com_z;          // The system's center of mass position in the z axis.
    std::string system_name;      // The molecular system name.
    bool ab_initio_ready;         // The ab-initio calculation state. True if it is already done, false otherwise.
    bool system_com_ready;        // The center of mass (COM) calculation state. True if it is already done, false otherwise.
    bool atom_types_ready;        // The atom types reading state. True if it is already done, false otherwise.
    bool atom_positions_ready;    // The atom positions reading state. True if it is already done, false otherwise.
    bool atom_velocities_ready;   // The atom velocities reading state. True if it is already done, false otherwise.
    bool total_atoms_ready;       // The total number of atoms calculation state. True if it is already done, false otherwise.
    bool nuclear_repulsion_ready; // The nuclear repulsion calculation state. True if it is already done, false otherwise.
    algorithm::scf *wavefunction; // A pointer-object to link with any object of algorithm::scf type.
//
//  get_total_atoms(): To count the number of lines in a given input file,
//                     i.e. the number of atoms.
    unsigned int get_total_atoms(std::string input_filename); 
//
//  read_geometry(): To read the molecular system's geometry from a given ifstream file.
    void read_input_file(const std::string &input_filename); 
//
//  get_system_com(): To calculate the system center of mass.
    void get_system_com();
//
//  get_nuclear_repulsion(): To calculate the nuclear repulsion energy.
    void get_nuclear_repulsion();
//
//  report_input_reading(): To report the inputfile reading in the logfile.
    void report_input_reading();
//
//  get_wavefunction(): To start the calculation of all ab-initio datas. Caution: The usage of this member function
//                      may be the most expensive part of the entire runtime. 
    void get_wavefunction(unsigned int theory_level);
public:
//
//  Class identifier:
    static const int id = 5127;
//
//  Declaring the class constructor:
    molecular_system(const std::string &input_filename);
//
//  Declaring the class constructor:
    molecular_system(const std::string &input_filename, settings &runtime_setup);
//
//  number_of_atoms(): To return the total number of atoms.
    #include "molecular_system__number_of_atoms.cpp"
//
//  x(): To return the COM position in the x-axis when used without arguments.
//       When given an option (velocity or position) and an atom number it will return
//       the x-axis value of the current atom.
    #include "molecular_system__x.cpp"
//
//  y(): To return the COM position in the y-axis when used without arguments.
//       When given an option (velocity or position) and an atom number it will return
//       the y-axis value of the current atom.
    #include "molecular_system__y.cpp"
//
//  z(): To return the COM position in the z-axis when used without arguments.
//       When given an option (velocity or position) and an atom number it will return
//       the z-axis value of the current atom.
    #include "molecular_system__z.cpp"
//
//  Defining some alias for the x(), y() and z() members options:
    #define POSITION 1
    #define VELOCITY 2
//
//  mass(): To return the mass of a atom if its number as an unsigned integral type 
//          argument is given. Otherwise it will return the system total mass.
    #include "molecular_system__mass.cpp"
//
//  interatomic_distance(): To return the distance between two given atoms.
    double interatomic_distance(const unsigned int &first_atom, const unsigned int &second_atom);
//
//  atomic_number(): To return the atomic number (Z) of the given atom.
    #include "molecular_system__atomic_number.cpp"
//
//  type(): To return the type of a given atom (Z) as an unsigned integral type.
    #include "molecular_system__type.cpp"
//
//  density(): To return the value of the density matrix for two given atoms.
    double density(const unsigned int &first_atom, const unsigned int &second_atom);
//
//  nuclear_repulsion_energy(): To return the nuclear repulsion energy.
    #include "molecular_system__nuclear_repulsion_energy.cpp"
//
//  electronic_energy(): To return the converged energy from any SCF routine.
    #include "molecular_system__electronic_energy.cpp"
//
//  name(): To return the current system's name if any.
    #include "molecular_system__name.cpp"
//
//  set_task_number(): To set the task number of the current molecular system.
    #include "molecular_system__set_task_number.cpp" 
//
//  set_name(): To set the name of the current molecular system. The default name given by the
//              constructor is the system input filename.
    #include "molecular_system__set_name.cpp"
//
//  set_system_com(): To set a new COM for a given double type x-axis, y-axis and z-axis point. 
//                    Caution: The usage of this member function imply to update the position of
//                    each atom with respect to the new COM.
    #include "molecular_system__set_system_com.cpp"
};
#endif
