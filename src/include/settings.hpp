// ../src/include/settings.hpp ---------------------------------------------------------- //
//
/// @author Humberto Jr. 
//
/// @date 05/2013
//
/// @brief Designed to handle the runtime configuration. 
//
/// @details Its main function is to define objects that are able to read the user's 
///          preferences from a standard configuration file and to control any other 
///          routines. It is also possible to declare objects based onto different 
///          configuration files and therefore with different contents. Such approach 
///          can be used to create several sets of configuration for several tasks if 
///          needed. There is no need to mind about how to read any kind of streaming 
///          file. The settings constructor is going to read the given file by default,
///          to collect all the data needed and to keep it. Therefore, the client can 
///          use the settings member functions to retrieve any information. An 
///          important task of the settings class is to prevent careless  changes in 
///          the configuration set, since there is no straightforward way to reset its 
///          content after the construction (there is no setter member functions).
//
//  References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __SETTINGS_HPP
    #define __SETTINGS_HPP
    #include "globals.hpp"
    #include "file_system.hpp"
    #include "tools.hpp"
//
//
//
class settings
{
    private:
//
/// The current configuration 
/// filename.
    std::string config_file;
//
/// The total number of tasks 
/// (the default value is 1).
    unsigned int total_tasks;
//
/// The output mode state 
/// (on/off, default value is on).
    bool output_mode_on;
//
/// The molecular vibration state 
/// (on/off, default value is on).
    bool vibration_mode_on;
//
/// The molecular rotation state 
/// (on/off, default value is on).
    bool rotation_mode_on;
//
/// The molecular translation state 
/// (on/off, default value is on).
    bool translation_mode_on;
//
/// The debug mode state 
/// (on/off, default value is off).
    bool debug_mode_on;
//
/// The high-end mode state 
/// (on/off, default value is on).
    bool highend_mode_on;
//
/// The stand-by mode state 
/// (on/off, default value is on).
    bool standby_mode_on;
//
/// The usage of temp files 
/// (on/off, default value is on).
    bool temp_files_on;
//
/// The state (on/off) of printing 
/// matrices at the log file.
    bool logging_matrices;
//
/// The numeric precision used to 
/// print numbers in the log file.
    unsigned short int precision;
//
/// The current log filename.
    std::string log_filename;
//
/// The respective input filename 
/// for each task (an array of @c 
/// total_tasks size).
    std::string *input_list;
//
/// The energy convergence criteria 
/// for any SCF routine.
    double scf_criteria;
//
/// The respective level of theory 
/// for each task.
    unsigned int *level_list;
//
/// The @c file_system type manager 
/// of inputs.
    file_system input_manager;
//
/// The @c file_system type manager 
/// of the scratch directory.
    file_system scratch_dir_manager;
//
/// The @c file_system type manager 
/// of the current work directory.
    file_system work_dir_manager;
//
//
    int scan_config_file(const std::string &option,
                         const int &default_key);
    double scan_config_file(const std::string &option,
                            const double &default_key);
    std::string scan_config_file(const std::string &option,
                                 const std::string &default_key);
    bool scan_config_file(const std::string &option,
                          const bool &default_key);
//
//
    void read_inputs();
    void read_levels();
//
//  Including the inline/template/private 
//  member functions: 
    #include "settings__remove_option.cpp"
//
    public:
//
/// The class identifier:
    static const int id = 29254;
//
//  Declaring the class constructor:
    settings();
    settings(const std::string &filename);
//
//  Declaring the class destructor:
    ~settings();
//
//
    std::string theory_database(const unsigned int &option);
//
//
    unsigned int theory_database(const std::string &option);
//
//
    void operator =(settings &given_config);
//
//
    double check_total_memory();
    double check_free_memory();
//
//  Including the inline/template/public 
//  member functions: 
    #include "settings__numeric_precision.cpp"
    #include "settings__scf_convergence_criteria.cpp"
    #include "settings__task_level.cpp"
    #include "settings__my_size.cpp"
    #include "settings__check_current_username.cpp"
    #include "settings__check_current_hostname.cpp"
    #include "settings__check_current_time.cpp"
    #include "settings__check_current_cpus.cpp"
    #include "settings__scratch_dir.cpp"
    #include "settings__work_dir.cpp"
    #include "settings__check_current_disk_space.cpp"
    #include "settings__tasks.cpp"
    #include "settings__output_mode.cpp"
    #include "settings__vibration_mode.cpp"
    #include "settings__rotation_mode.cpp"
    #include "settings__translation_mode.cpp"
    #include "settings__input_filename.cpp"
    #include "settings__ctrl_key.cpp"
    #include "settings__log_file.cpp"
    #include "settings__debug_mode.cpp"
//
};
#endif
