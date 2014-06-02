// ../src/include/molecular_system.hpp -------------------------------------------------- //
//
// File author: Humberto Jr.
//
// Date: 06/2013
//
// Description: The molecular system class defines the type of variables that aims to
//              handle everything concerning the molecular systems like molecules and
//              solids. Given an input file, the class will read the molecular geome-
//              try and provide the member functions to controls its motion, ab-init-
//              io tasks and properties.
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __MOLECULAR_SYSTEM_HPP
    #define __MOLECULAR_SYSTEM_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "global_settings.hpp"
    #include "periodic_table.hpp"
    #include "lcao_wavefunction.hpp"
    #include "tools.hpp"
    #include "global_log.hpp"
    #include "timer.hpp"
//
//
//
class molecular_system
{
    private:
//
//  Declaring the data members:
    settings *config;             // A pointer-object to link with any object of settings type.
    unsigned int task_number;     // The number of the current task.
    unsigned int total_electrons; // The total number of electrons.
    unsigned int total_atoms;     // The total number of atoms.
    array atom_type;              // The type of each atom (Z) as a non negative integral type.
    array<double, 1> position_x;             // The atom position in the x axis.
    array<double, 1> position_y;             // The atom position in the y axis.
    array<double, 1> position_z;             // The atom position in the z axis.
    array<double, 1> velocity_x;             // The atom velocity in the x axis.
    array<double, 1> velocity_y;             // The atom velocity in the y axis.
    array<double, 1> velocity_z;             // The atom velocity in the z axis.
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
    lcao_wavefunction lcao_psi;   // The LCAO wavefunction.
    file_system input;            // The input file manager;
    timer constructor_time;       // The timer to measure the construction time.
//
//  get_total_atoms(): To count the number of lines in a given input file,
//                     i.e. the number of atoms.
    unsigned int get_total_atoms(const std::string &input_filename);
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
    void get_wavefunction();
//
    public:
//
//  Class identifier:
    static const int id = 5127;
//
//  Declaring the class constructor:
    molecular_system(const std::string &input_filename);
//
//  Declaring the class constructor:
    molecular_system(const unsigned int &given_task);
//
//  interatomic_distance(): To return the distance between two given atoms.
    double interatomic_distance(const unsigned int &first_atom, const unsigned int &second_atom);
//
//  Including the inline/template/public member functions:
    #include "molecular_system__number_of_atoms.cpp"
    #include "molecular_system__x.cpp"
    #include "molecular_system__y.cpp"
    #include "molecular_system__z.cpp"
    #include "molecular_system__mass.cpp"
    #include "molecular_system__atomic_number.cpp"
    #include "molecular_system__type.cpp"
    #include "molecular_system__nuclear_repulsion_energy.cpp"
    #include "molecular_system__electronic_energy.cpp"
    #include "molecular_system__name.cpp"
    #include "molecular_system__set_task_number.cpp"
    #include "molecular_system__set_name.cpp"
    #include "molecular_system__set_system_com.cpp"
    #include "molecular_system__density.cpp"
//
//  Defining some alias for the x(), y() and z() members options:
    #define POSITION 1
    #define VELOCITY 2
//
};
#endif
