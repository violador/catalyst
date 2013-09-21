// ../src/include/settings.hpp ------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 05/2013
//
// Description: To declare all the data members and member functions 
//              of the class "settings", designed to read all the m-
//              ain information used to control all the other routi-
//              nes (runtime and compilation time). Also to write o-
//              ut any required data in the log file.
//
// References:
//
// ---------------------------------------------------------------------------- //
#ifndef __SETTINGS_HPP
    #define __SETTINGS_HPP
    #include "globals.hpp"
//
//
//
class settings
{
private:
//
//  Declaring the data members:
    bool logfile_ready;               // To store the logfile state. True if it exist already, false otherwise.
    bool output_mode_on;              // To store the output state (on/off).
    bool vibration_mode_on;           // To store the molecular vibration state (on/off).
    bool rotation_mode_on;            // To store the molecular rotation state (on/off).
    bool translation_mode_on;         // To store the molecular translation state (on/off).
    bool debug_mode_on;               // To store the debug mode state (on/off).
    bool highend_mode_on;             // To store the high-end mode state (on/off).
    bool standby_mode_on;             // To store the stand-by mode state (on/off).
    unsigned int total_tasks;         // To store the total number of tasks.
    unsigned int total_molecular_sys; // To store the total number of molecular systems.
    unsigned int total_atoms;         // To store the total number of atoms.
    unsigned short int precision;     // To store the number precision in the log file.
    std::string log_filename;         // To store the log filename. 
    std::string input_filename;       // To store the input filename.
    std::string scratch_dir;          // To store the scratch directory path.   
    std::string work_dir;             // To store the work directory path.
    std::string in_energy_unit;       // To store the input energy unit.
    std::string in_length_unit;       // To store the input length unit.
    std::string in_time_unit;         // To store the input time unit.
    std::string out_energy_unit;      // To store the output energy unit.
    std::string out_length_unit;      // To store the output length unit.
    std::string out_time_unit;        // To store the output time unit.
    double scf_criteria;              // To store the energy convergence criteria for any SCF routine.
    unsigned int theory_level[2];
//
//  read_preference(): To get the user's preference in a given option pattern like "option = preference". 
    std::string read_preference(const std::string option, const int option_length, const std::string default_preference);
//
//  read_state(): To check if the given control key is on/true or off/false. 
    bool read_state(const std::string option,
                    const std::string state,
                    const int option_length,
                    const int state_length,
                    bool default_state);
//
//  read_number_of(): To get a non negative integral number of something in a given option from the user's config file.
    unsigned int read_number_of(const std::string option, const int option_length, const unsigned int default_number);
//
//  read_value_of(): To get a double number in a given option from the user's config file.
    double read_value_of(const std::string option, const int option_length, const unsigned int default_value);    
//
//  pattern_length(): To help in some tasks. It will return the number of characters of a given string.
    #include "settings__pattern_length.cpp"
public:
//
//  Class identifier:
    static const int id = 29254;
//
//  Declaring the class constructor:
    settings();
//
//  Declaring the class constructor:
    #ifdef USE_MPI
    settings(boost::mpi::communicator process);
    #endif
//
//  dir_path_of(): To get the path of a given (option) directory.
    std::string dir_path_of(const unsigned int option);
//
//  Defining some alias for the dir_path_of() member function options:
    #define SCRATCH 1
    #define WORK    2
//
//  filename_of(): To get the filename_of a given (option) file.
    std::string filename_of(const unsigned int option);
//
//  Defining some alias for the filename_of() member function options:
    #define LOG_FILE   1
    #define INPUT_FILE 2
//
//  control_key_of(): To get the current control key (on/off) for a given state (true/false).
    std::string control_key_of(const bool &state);
//
//  state_of(): To get the state (true/false) of a given option.
    bool state_of(const unsigned int option);
//
//  Defining some alias for the state_of() member function options:
    #define OUTPUT_MODE      1
    #define VIBRATION_MODE   2
    #define ROTATIONAL_MODE  3
    #define TRANSLATION_MODE 4
    #define DEBUG_MODE       5
    #define HIGHEND_MODE     6
    #define STANDBY_MODE     7
//
//  number_of(): To get the number of something in a given option.
    unsigned int number_of(unsigned int option);
//
//  Defining some alias for the number_of() member function options:
    #define TASKS         1
    #define MOLECULAR_SYS 2
    #define ATOMS         3
    #define CPUS          4
//
//  check_memory(): To check the current memory available or the total memory.
    double check_current_memory(const int option);
//
//  check_username(): To return the current username.
    std::string check_current_username();
//
//  check_hostname(): To return the current hostname.
    std::string check_current_hostname();
//
//  check_time(): To return the current date/time.
    char* check_current_time();
//
//  check_current_cpus(): To check the total number of CPUs available.
    unsigned int check_current_cpus();
//
//  numeric_precision(): To get the user's preference value for the numeric precision.
    #include "settings__numeric_precision.cpp"
//
//  scf_convergence_criteria(): To get the energy convergence criteria for any SCF iterative calculation.
    #include "settings__scf_convergence_criteria.cpp"
//
//
    #include "settings__wavefunction_type.cpp"
};
#endif
