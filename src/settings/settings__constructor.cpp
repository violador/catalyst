#include "settings.hpp"
//
//
//
#ifndef USE_MPI
settings::settings()
{
    total_tasks = read_number_of("tasksnumber=", 
                                  pattern_length("tasksnumber="), 
                                  0);
    #pragma omp parallel sections num_threads(14)
    {
        #pragma omp section
        {
            output_mode_on = read_state("output=", 
                                        "on", 
                                        pattern_length("output="), 
                                        pattern_length("on"), 
                                        true);
        }
//
        #pragma omp section
        {
            vibration_mode_on = read_state("vibrationmode=", 
                                           "on", 
                                           pattern_length("vibrationmode="), 
                                           pattern_length("on"), 
                                           true);
        }
//
        #pragma omp section
        {
            rotation_mode_on = read_state("rotationmode=", 
                                          "on", 
                                          pattern_length("rotationmode="), 
                                          pattern_length("on"), 
                                          true);
        }
//
        #pragma omp section
        {
            translation_mode_on = read_state("translationmode=", 
                                             "on", 
                                             pattern_length("translationmode="), 
                                             pattern_length("on"), 
                                             true);
        }
//
        #pragma omp section
        {
            debug_mode_on = read_state("debugmode=", 
                                       "on", 
                                       pattern_length("debugmode="), 
                                       pattern_length("on"), 
                                       false);
        }
//
        #pragma omp section
        {
            highend_mode_on = read_state("high-endmode=", 
                                         "on", 
                                         pattern_length("high-endmode="), 
                                         pattern_length("on"), 
                                         true);
        }
//
        #pragma omp section
        {
            standby_mode_on = read_state("standbymode=", 
                                         "on", 
                                         pattern_length("standbymode="), 
                                         pattern_length("on"), 
                                         false);
        }
//
        #pragma omp section
        {
            log_filename = read_preference("logfilename=", 
                                           pattern_length("logfilename="), 
                                           "catalyst.log");
        }
//
        #pragma omp section
        {
            input_filename = read_preference("inputname=", 
                                             pattern_length("inputname="), 
                                             DEFAULT_NOT_DEFINED);
        }
//
        #pragma omp section
        {
            scratch_dir = read_preference("scratchdirectory=", 
                                          pattern_length("scratchdirectory="), 
                                          DEFAULT_NOT_DEFINED);
        }
//
        #pragma omp section
        {
            work_dir = read_preference("workdirectory=", 
                                       pattern_length("workdirectory="), 
                                       DEFAULT_NOT_DEFINED);
        }
//
        #pragma omp section
        {
            if(total_tasks > 0)
            {
                theory_level = new unsigned int[total_tasks];
            }
            else
            {
                theory_level = 0;
            }
        }
//
        #pragma omp section 
        {
            precision = read_number_of("numericprecision=", 
                                       pattern_length("numericprecision="), 
                                       DEFAULT_PRECISION);
            if((precision < 1) and (precision > DEFAULT_PRECISION))
            {
                precision = DEFAULT_PRECISION;
            }
        }
//
        #pragma omp section 
        {
            scf_criteria = read_value_of("scfconvergencecriteria=", 
                                         pattern_length("scfconvergencecriteria="), 
                                         DEFAULT_SCF_CRITERIA);
        }
//
    }
}
#endif
//
//
//
#ifdef USE_MPI
settings::settings(boost::mpi::communicator process)
{
    if(process.boost::mpi::communicator::size() >= 14)
    {
        if(process.boost::mpi::communicator::rank() == MASTER_PROCESS)
        {
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  1,  1, output_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  2,  2, vibration_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  3,  3, rotation_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  4,  4, translation_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  5,  5, debug_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  6,  6, highend_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  7,  7, standby_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  8,  8, log_filename);
            process.boost::mpi::communicator::recv(MASTER_PROCESS +  9,  9, input_filename);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 10, 10, scratch_dir);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 11, 11, work_dir);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 12, 12, total_tasks);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 13, 13, precision);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 14, 14, scf_criteria);
            if(total_tasks > 0)
            {
                theory_level.create_array(total_tasks);
            }
            theory_level.set(1, (double) 1);
            if((precision < 1) and (precision > 10))
            {
                precision = DEFAULT_PRECISION;
            }
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 1))
        {
            output_mode_on = read_state("output=", 
                                        "on", 
                                        pattern_length("output="), 
                                        pattern_length("on"), 
                                        true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 1, output_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 2))
        {
            vibration_mode_on = read_state("vibrationmode=", 
                                           "on", 
                                           pattern_length("vibrationmode="), 
                                           pattern_length("on"), 
                                           true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 2, vibration_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 3))
        {
            rotation_mode_on = read_state("rotationmode=", 
                                          "on", 
                                          pattern_length("rotationmode="), 
                                          pattern_length("on"), 
                                          true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 3, rotation_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 4))
        {
            translation_mode_on = read_state("translationmode=", 
                                             "on", 
                                             pattern_length("translationmode="), 
                                             pattern_length("on"), 
                                             true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 4, translation_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 5))
        {
            debug_mode_on = read_state("debugmode=", 
                                       "on", 
                                       pattern_length("debugmode="), 
                                       pattern_length("on"), 
                                       false);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 5, debug_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 6))
        {
            highend_mode_on = read_state("high-endmode=", 
                                         "on", 
                                         pattern_length("high-endmode="), 
                                         pattern_length("on"), 
                                         true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 6, highend_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 7))
        {
            standby_mode_on = read_state("standbymode=", 
                                         "on", 
                                         pattern_length("standbymode="), 
                                         pattern_length("on"),
                                         false);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 7, standby_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 8))
        {
            log_filename = read_preference("logfilename=", pattern_length("logfilename="), "catalyst.log");
            process.boost::mpi::communicator::send(MASTER_PROCESS, 8, log_filename);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 9))
        {
            input_filename = read_preference("inputname=", pattern_length("inputname="), DEFAULT_NOT_DEFINED);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 9, input_filename);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 10))
        {
            scratch_dir = read_preference("scratchdirectory=", pattern_length("scratchdirectory="), DEFAULT_NOT_DEFINED);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 10, scratch_dir);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 11))
        {
            work_dir = read_preference("workdirectory=", pattern_length("workdirectory="), DEFAULT_NOT_DEFINED);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 11, work_dir);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 12))
        {
            total_tasks  = read_number_of("tasksnumber=", pattern_length("tasksnumber="), 0);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 12, total_tasks);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 13))
        {
            precision = read_number_of("numericprecision=", pattern_length("numericprecision="), 8);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 13, precision);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 14))
        {
            scf_criteria = read_value_of("scfconvergencecriteria=", pattern_length("scfconvergencecriteria="), DEFAULT_SCF_CRITERIA);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 14, scf_criteria);
        }
    }
    else if(process.boost::mpi::communicator::size() == 8)
    {
        std::cout << "ESTOU NO ROTINA PRA 8 CPUS" << std::endl;
        if(process.boost::mpi::communicator::rank() == MASTER_PROCESS)
        {
            std::cout << "ENTREI NO MASTER" << std::endl;
            boost::mpi::request reqs[1];
            //reqs[0] = process.boost::mpi::communicator::isend(MASTER_PROCESS + 1, 20);
            reqs[0] = process.boost::mpi::communicator::irecv(MASTER_PROCESS + 1,  1, output_mode_on);
            std::cout << "OUTPUT MODE NO CPU 0 = " << output_mode_on << std::endl; 
            boost::mpi::wait_all(reqs, reqs);
            //std::cout << "PROCESS = " << process.boost::mpi::communicator::rank() << ", OUTPUT = " << output_mode_on << std::endl;
/*
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 1,  2, vibration_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 2,  3, rotation_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 2,  4, translation_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 3,  5, debug_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 3,  6, highend_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 4,  7, standby_mode_on);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 4,  8, log_filename);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 5,  9, input_filename);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 5, 10, scratch_dir);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 6, 11, work_dir);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 6, 12, total_tasks);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 7, 13, precision);
            process.boost::mpi::communicator::recv(MASTER_PROCESS + 7, 14, scf_criteria);
            if(total_tasks > 0)
            {
                theory_level.create_array(total_tasks);
            }
            theory_level.set(1, (double) 1);
            if((precision < 1) and (precision > 10))
            {
                precision = DEFAULT_PRECISION;
            }
*/
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 1))
        {
            //boost::mpi::request reqs[2];
            //reqs[0] = process.boost::mpi::communicator::irecv(MASTER_PROCESS, 20);
            output_mode_on = read_state("output=", 
                                        "on", 
                                        pattern_length("output="), 
                                        pattern_length("on"), 
                                        true);
            std::cout << "OUTPUT MODE NO CPU 1 = " << output_mode_on << std::endl; 
            /*reqs[1] =*/ process.boost::mpi::communicator::isend(MASTER_PROCESS, 1, output_mode_on);
            //boost::mpi::wait_all(reqs, reqs + 2);
/*
//
            vibration_mode_on = read_state("vibrationmode=", 
                                           "on", 
                                           pattern_length("vibrationmode="), 
                                           pattern_length("on"), 
                                           true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 2, vibration_mode_on);
*/
        }
/*
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 2))
        {
            rotation_mode_on = read_state("rotationmode=", 
                                          "on", 
                                          pattern_length("rotationmode="), 
                                          pattern_length("on"), 
                                          true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 3, rotation_mode_on);
//
            translation_mode_on = read_state("translationmode=", 
                                             "on", 
                                             pattern_length("translationmode="), 
                                             pattern_length("on"), 
                                             true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 4, translation_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 3))
        {
            debug_mode_on = read_state("debugmode=", 
                                       "on", 
                                       pattern_length("debugmode="), 
                                       pattern_length("on"), 
                                       false);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 5, debug_mode_on);
//
            highend_mode_on = read_state("high-endmode=", 
                                         "on", 
                                         pattern_length("high-endmode="), 
                                         pattern_length("on"), 
                                         true);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 6, highend_mode_on);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 4))
        {
            standby_mode_on = read_state("standbymode=", 
                                         "on", 
                                         pattern_length("standbymode="), 
                                         pattern_length("on"),
                                         false);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 7, standby_mode_on);
//
            log_filename = read_preference("logfilename=", pattern_length("logfilename="), "catalyst.log");
            process.boost::mpi::communicator::send(MASTER_PROCESS, 8, log_filename);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 5))
        {
            input_filename = read_preference("inputname=", pattern_length("inputname="), DEFAULT_NOT_DEFINED);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 9, input_filename);
//
            scratch_dir = read_preference("scratchdirectory=", pattern_length("scratchdirectory="), DEFAULT_NOT_DEFINED);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 10, scratch_dir);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 6))
        {
            work_dir = read_preference("workdirectory=", pattern_length("workdirectory="), DEFAULT_NOT_DEFINED);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 11, work_dir);
//
            total_tasks  = read_number_of("tasksnumber=", pattern_length("tasksnumber="), 0);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 12, total_tasks);
        }
        else if(process.boost::mpi::communicator::rank() == (MASTER_PROCESS + 7))
        {
            precision = read_number_of("numericprecision=", pattern_length("numericprecision="), 8);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 13, precision);
//
            scf_criteria = read_value_of("scfconvergencecriteria=", pattern_length("scfconvergencecriteria="), DEFAULT_SCF_CRITERIA);
            process.boost::mpi::communicator::send(MASTER_PROCESS, 14, scf_criteria);
        }
*/
    }
}
#endif
