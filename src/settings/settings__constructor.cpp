#include "settings.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 05/2013
//
/// @return None.
//
/// @cite
//
settings::settings()
//
// Initialization list:
: config_file(tools::default_config_file())
, total_tasks(scan_config_file("tasksnumber=", 1))
, output_mode_on(scan_config_file("output=", true))
, vibration_mode_on(scan_config_file("vibrationmode=", true))
, rotation_mode_on(scan_config_file("rotationmode=", true))
, translation_mode_on(scan_config_file("translationmode=", true))
, debug_mode_on(scan_config_file("debugmode=", false))
, highend_mode_on(scan_config_file("high-endmode=", false))
, standby_mode_on(scan_config_file("standbymode=", false))
, temp_files_on(scan_config_file("tempfiles=", true))
, logging_matrices(scan_config_file("printmatrices=", true))
, precision(scan_config_file("numericprecision=", tools::default_precision()))
, log_filename(scan_config_file("logfilename=", tools::default_log_file()))
, scf_criteria(scan_config_file("scfconvergencecriteria=", tools::default_scf_criteria()))
//
{
	scratch_dir_manager.file_system::init(scan_config_file("scratchdirectory=", (std::string) ""), "");
	work_dir_manager.file_system::init(scan_config_file("workdirectory=", (std::string) ""), "");
	#pragma omp parallel sections num_threads(2)
	{
		#pragma omp section
		{
			read_inputs();
		}
		#pragma omp section
		{
			read_levels();
		}
	}
}
//
//
//
/// @author Humberto Jr.
//
/// @date 05/2013
//
/// @return None.
//
/// @cite
//
settings::settings(const std::string &filename)
//
// Initialization list:
: config_file(filename)
, total_tasks(scan_config_file("tasksnumber=", 1))
, output_mode_on(scan_config_file("output=", true))
, vibration_mode_on(scan_config_file("vibrationmode=", true))
, rotation_mode_on(scan_config_file("rotationmode=", true))
, translation_mode_on(scan_config_file("translationmode=", true))
, debug_mode_on(scan_config_file("debugmode=", false))
, highend_mode_on(scan_config_file("high-endmode=", false))
, standby_mode_on(scan_config_file("standbymode=", false))
, temp_files_on(scan_config_file("tempfiles=", true))
, logging_matrices(scan_config_file("printmatrices=", true))
, precision(scan_config_file("numericprecision=", tools::default_precision()))
, log_filename(scan_config_file("logfilename=", tools::default_log_file()))
, scf_criteria(scan_config_file("scfconvergencecriteria=", tools::default_scf_criteria()))
//
{
	scratch_dir_manager.file_system::init(scan_config_file("scratchdirectory=", (std::string) ""), "");
	work_dir_manager.file_system::init(scan_config_file("workdirectory=", (std::string) ""), "");
	#pragma omp parallel sections num_threads(2)
	{
		#pragma omp section
		{
			read_inputs();
		}
		#pragma omp section
		{
			read_levels();
		}
	}
}
