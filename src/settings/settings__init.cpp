#include "settings.hpp"
//
//
//
void settings::init()
{
    total_tasks = read_value<unsigned int>("tasksnumber=", 
                                           tools::pattern_length("tasksnumber="), 
                                           0);
    #pragma omp parallel sections num_threads(16)
    {
        #pragma omp section
        {
            output_mode_on = read_state("output=", 
                                        ON_KEY_CONTROL, 
                                        tools::pattern_length("output="), 
                                        tools::pattern_length(ON_KEY_CONTROL), 
                                        true);
        }
        #pragma omp section
        {
            vibration_mode_on = read_state("vibrationmode=", 
                                           ON_KEY_CONTROL, 
                                           tools::pattern_length("vibrationmode="), 
                                           tools::pattern_length(ON_KEY_CONTROL), 
                                           true);
        }
        #pragma omp section
        {
            rotation_mode_on = read_state("rotationmode=", 
                                          ON_KEY_CONTROL, 
                                          tools::pattern_length("rotationmode="), 
                                          tools::pattern_length(ON_KEY_CONTROL), 
                                          true);
        }
        #pragma omp section
        {
            translation_mode_on = read_state("translationmode=", 
                                             ON_KEY_CONTROL, 
                                             tools::pattern_length("translationmode="), 
                                             tools::pattern_length(ON_KEY_CONTROL), 
                                             true);
        }
        #pragma omp section
        {
            debug_mode_on = read_state("debugmode=", 
                                       ON_KEY_CONTROL, 
                                       tools::pattern_length("debugmode="), 
                                       tools::pattern_length(ON_KEY_CONTROL), 
                                       false);
        }
        #pragma omp section
        {
            highend_mode_on = read_state("high-endmode=", 
                                         ON_KEY_CONTROL, 
                                         tools::pattern_length("high-endmode="), 
                                         tools::pattern_length(ON_KEY_CONTROL), 
                                         true);
        }
        #pragma omp section
        {
            standby_mode_on = read_state("standbymode=", 
                                         ON_KEY_CONTROL, 
                                         tools::pattern_length("standbymode="), 
                                         tools::pattern_length(ON_KEY_CONTROL), 
                                         false);
        }
        #pragma omp section
        {
            temp_files_on = read_state("tempfiles=", 
                                       ON_KEY_CONTROL, 
                                       tools::pattern_length("tempfiles="), 
                                       tools::pattern_length(ON_KEY_CONTROL), 
                                       true);
        }
        #pragma omp section
        {
            logging_matrices = read_state("printmatrices=",
                                          ON_KEY_CONTROL,
                                          tools::pattern_length("printmatrices="),
                                          tools::pattern_length(ON_KEY_CONTROL),
                                          false);
        }
        #pragma omp section
        {
            log_filename = read_preference("logfilename=", 
                                           tools::pattern_length("logfilename="), 
                                           "catalyst.log");
        }
        #pragma omp section
        {
            read_inputs();
        }
        #pragma omp section
        {
            scratch_dir = read_preference("scratchdirectory=", 
                                          tools::pattern_length("scratchdirectory="), 
                                          DEFAULT_NOT_DEFINED);
        }
        #pragma omp section
        {
            work_dir = read_preference("workdirectory=", 
                                       tools::pattern_length("workdirectory="), 
                                       DEFAULT_NOT_DEFINED);
        }
        #pragma omp section
        {
            read_levels();
        }
        #pragma omp section 
        {
            precision = read_value<unsigned short int>("numericprecision=", 
                                                       tools::pattern_length("numericprecision="), 
                                                       DEFAULT_PRECISION);
            switch((precision < 1) and (precision > MAX_PRECISION))
            {
                case true: precision = DEFAULT_PRECISION; break;
            }
        }
        #pragma omp section 
        {
            scf_criteria = read_value<double>("scfconvergencecriteria=", 
                                              tools::pattern_length("scfconvergencecriteria="), 
                                              DEFAULT_SCF_CRITERIA);
        }
    }
}
