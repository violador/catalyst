// ../src/include/settings.hpp ---------------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 05/2013
//
// Description: The settings class defines the type of variables used to handle
//              the current configuration given by the user. This should be the 
//              most important type and these variables should be given as arg-
//              ument in the constructor calls of several other classes. In the
//              declaration of a variable of settings type, the user's config 
//              file should be readed several times to store all the settings.
//              Thus, it is recomended to avoid to declare several objects of
//              this type. Usually just one, and to pass its reference or a po-
//              inter.
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __SETTINGS_HPP
    #define __SETTINGS_HPP
    #include "globals.hpp"
    #include "tools.hpp"
//
//
//
class settings
{
    private:
//
//  Declaring the data members:
    bool output_mode_on;              // To store the output state (on/off).
    bool vibration_mode_on;           // To store the molecular vibration state (on/off).
    bool rotation_mode_on;            // To store the molecular rotation state (on/off).
    bool translation_mode_on;         // To store the molecular translation state (on/off).
    bool debug_mode_on;               // To store the debug mode state (on/off).
    bool highend_mode_on;             // To store the high-end mode state (on/off).
    bool standby_mode_on;             // To store the stand-by mode state (on/off).
    unsigned int total_tasks;         // To store the total number of tasks.
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
    unsigned int *theory_level;
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
//  Including the inline/template/private member functions:
    #include "settings__pattern_length.cpp"
//
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
//  Including the inline/template/public member functions: 
    #include "settings__numeric_precision.cpp"
    #include "settings__scf_convergence_criteria.cpp"
    #include "settings__wavefunction_type.cpp"
    #include "settings__my_size.cpp"
    #include "settings__state_of.cpp"
    #include "settings__number_of.cpp"
    #include "settings__dir_path_of.cpp"
    #include "settings__filename_of.cpp"
    #include "settings__control_key_of.cpp"
    #include "settings__check_current_username.cpp"
    #include "settings__check_current_hostname.cpp"
    #include "settings__check_current_time.cpp"
    #include "settings__check_current_cpus.cpp"
    #include "settings__check_current_memory.cpp"
//
//  Defining some alias for the dir_path_of() member function options:
    #define SCRATCH 1
    #define WORK    2
//
//  Defining some alias for the filename_of() member function options:
    #define LOG_FILE   1
    #define INPUT_FILE 2
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
//  Defining some alias for the number_of() member function options:
    #define TASKS 1
    #define CPUS  2
};
#endif