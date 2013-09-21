#include "scf.hpp"
//
//
//
void algorithm::scf::report_scf_iterations() 
{
    if(config -> state_of(OUTPUT_MODE))                                                                   
    {
        if(/*config -> logfile_initialized()*/true)
        {
            LOGFILE_IS_READY:
            std::string log_filename = config -> filename_of(LOG_FILE);
            std::ofstream log_file(log_filename.c_str(), std::ios::out | std::ios::app); 
            if(log_file.is_open() && log_file.good())                                    
            {
                #define FIRST_COLUMN_LENGTH  5
                #define SECOND_COLUMN_LENGTH 10
                #define THIRD_COLUMN_LENGTH  10
                #define FIRST_TITLE_LENGTH         28
                unsigned int title_bar_length = FIRST_COLUMN_LENGTH 
                                              + SECOND_COLUMN_LENGTH
                                              + THIRD_COLUMN_LENGTH
                                              + SPACE_LENGTH
                                              + 7 // +7 characters space to add "(a.u.)".
                                              - FIRST_TITLE_LENGTH;
//
                log_file << "\n== SCF algorithm iterations "; 
                log_file.width(title_bar_length);
                log_file.fill('=');
                log_file << "\n" << std::endl;
//
                log_file.width(FIRST_COLUMN_LENGTH);
                log_file.fill(' ');
                log_file << "Iter.";
//
                log_file.width(SECOND_COLUMN_LENGTH + SPACE_LENGTH + 7); // +7 characters space to add "(a.u.)".
                log_file.fill(' ');
                log_file << "Energy (a.u.)";
//
                log_file.width(THIRD_COLUMN_LENGTH + SPACE_LENGTH);
                log_file.fill(' ');
                log_file << "Correction" << std::endl;
//
//              log_file.width(SPACE_LENGTH);
//              log_file.fill(' ');           // Use this template to add any new column, and make sure to
//              log_file << "" std::endl;     // remove the the std::endl in the last block.
//
                log_file.width(FIRST_COLUMN_LENGTH + SECOND_COLUMN_LENGTH + THIRD_COLUMN_LENGTH + 2*SPACE_LENGTH + 7);
                log_file.fill('-');
                log_file << "\n";
//
                tools get;
                for(unsigned int i = 1; i <= iteration; i++)
                {
//
                    log_file.width(FIRST_COLUMN_LENGTH);
                    log_file.fill(' ');
                    log_file << std::right << i;
//
                    log_file.width(SECOND_COLUMN_LENGTH + SPACE_LENGTH + 7); // +7 characters space to add "(a.u.)".
                    log_file.precision(config -> numeric_precision());
                    log_file << std::right << scf_energy.get(i);
//
                    log_file.width(THIRD_COLUMN_LENGTH + SPACE_LENGTH);
                    log_file.precision(config -> numeric_precision());
                    log_file << std::right << get.module(scf_energy.get(i), scf_energy.get(i - 1)) << std::endl;
//
//                  log_file.width(SPACE_LENGTH);
//                  log_file.precision();
//                  log_file << std::right << "" << std::endl;  // Use this template to add any new column, and make sure to
//                                                              // remove the std::endl in the last block.
                } // for(i)
//
                log_file << "\n- Iterations convergence           = " << (scf_converged? "reached" : "not reached")
                         << (scf_converged? "\n- Final converged SCF energy       = " : "\n- Final unconverged SCF energy     = ") 
                         << energy() << " a.u."
                         << "\n- Lowest molecular orbital number  = " << lowest_mo()
                         << "\n- Highest molecular orbital number = " << highest_mo() << std::endl; 
//
                #define FOURTH_COLUMN_LENGTH  6
                #define FIFTH_COLUMN_LENGTH  10
                #define SIXTH_COLUMN_LENGTH  10
                #define SECOND_TITLE_LENGTH  22
                title_bar_length = FOURTH_COLUMN_LENGTH
                                 + FIFTH_COLUMN_LENGTH
                                 + SIXTH_COLUMN_LENGTH
                                 + SPACE_LENGTH
                                 + 7 // +7 characters space to add "(a.u.)".
                                 - SECOND_TITLE_LENGTH;
//
                log_file << "\n== Molecular orbitals ";
                log_file.width(title_bar_length);
                log_file.fill('=');
                log_file << "\n" << std::endl;
//
                log_file.width(FOURTH_COLUMN_LENGTH);
                log_file.fill(' ');
                log_file << std::right << "Num.";
//
                log_file.width(FIFTH_COLUMN_LENGTH + SPACE_LENGTH + 7); // +7 characters space to add "(a.u.)".
                log_file.fill(' ');
                log_file << "Energy (a.u.)";
//
                log_file.width(SIXTH_COLUMN_LENGTH + SPACE_LENGTH);
                log_file.fill(' ');
                log_file << "Type" << std::endl;
//
                log_file.width(FOURTH_COLUMN_LENGTH + FIFTH_COLUMN_LENGTH + SIXTH_COLUMN_LENGTH + 2*SPACE_LENGTH + 7);
                log_file.fill('-');
                log_file << "\n";
//
                for(unsigned int i = 1; i <= f_eigenvalues.size_of_row(); i++)
                {
//
                    log_file.width(FOURTH_COLUMN_LENGTH);
                    log_file.fill(' ');
                    log_file << std::right << i;
//
                    log_file.width(FIFTH_COLUMN_LENGTH + SPACE_LENGTH + 7); // +7 characters space to add "(a.u.)".
                    log_file.precision(config -> numeric_precision());
                    log_file << std::right << f_eigenvalues.get(i);
//
                    log_file.width(SIXTH_COLUMN_LENGTH + SPACE_LENGTH);
                    log_file.precision(config -> numeric_precision());
                    log_file << std::right << check_mo_type(i) << std::endl;
//
                }
//
                log_file.close();
            }
            else // if(!log_file.is_open() || !log_file.good())
            {
            }
        }
        else // if(!config -> logfile_initialized())
        {
            //config -> init_log();
            goto LOGFILE_IS_READY;
        }
    } // !output_mode_on
}
