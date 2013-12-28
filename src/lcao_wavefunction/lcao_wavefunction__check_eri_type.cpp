#include "lcao_wavefunction.hpp"
//
//
//
unsigned int lcao_wavefunction::check_eri_type(const unsigned int &i_orbital, // The i-th atomic orbital.
                                               const unsigned int &j_orbital, // The j-th atomic orbital.
                                               const unsigned int &p_orbital, // The p-th atomic orbital.
                                               const unsigned int &q_orbital) // The q-th atomic orbital.
{
    unsigned int integral_type[4];
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {   
            switch(i_orbital)
            {   
                case SUB_SHELL_1s:  integral_type[0] = 0; break; 
                case SUB_SHELL_2s:  integral_type[0] = 0; break; 
                case SUB_SHELL_2px: integral_type[0] = 1; break; 
                case SUB_SHELL_2py: integral_type[0] = 1; break; 
                case SUB_SHELL_2pz: integral_type[0] = 1; break; 
            }
        }
        #pragma omp section
        {
            switch(j_orbital)
            {   
                case SUB_SHELL_1s:  integral_type[1] = 0; break; 
                case SUB_SHELL_2s:  integral_type[1] = 0; break; 
                case SUB_SHELL_2px: integral_type[1] = 1; break; 
                case SUB_SHELL_2py: integral_type[1] = 1; break; 
                case SUB_SHELL_2pz: integral_type[1] = 1; break; 
            }
        }
        #pragma omp section
        {
            switch(p_orbital)
            {   
                case SUB_SHELL_1s:  integral_type[2] = 0; break; 
                case SUB_SHELL_2s:  integral_type[2] = 0; break; 
                case SUB_SHELL_2px: integral_type[2] = 1; break; 
                case SUB_SHELL_2py: integral_type[2] = 1; break; 
                case SUB_SHELL_2pz: integral_type[2] = 1; break; 
            }
        }
        #pragma omp section
        {
            switch(q_orbital)
            {   
                case SUB_SHELL_1s:  integral_type[3] = 0; break; 
                case SUB_SHELL_2s:  integral_type[3] = 0; break; 
                case SUB_SHELL_2px: integral_type[3] = 1; break; 
                case SUB_SHELL_2py: integral_type[3] = 1; break; 
                case SUB_SHELL_2pz: integral_type[3] = 1; break; 
            }
        }
    }
    switch(integral_type[0] + integral_type[1] + integral_type[2] + integral_type[3])
    {
        case 0: return INTEGRAL_ssss; break;
        case 1: return INTEGRAL_psss; break;
       default: return 0;     
    }
}
