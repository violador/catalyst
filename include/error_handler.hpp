// ../src/include/error_handler.hpp ---------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: THIS CLASS ARE NOT FINISHED AND DO NOT SHOULD BE USED YET! 
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __ERROR_HANDLER_HPP
    #define __ERROR_HANDLER_HPP
    #include "globals.hpp"
    #include "global_log.hpp"
//
//
//
class error_handler
{
    private:
//
    bool check_gsl;
    bool check_boost;
    unsigned int class_id;
    unsigned int process_id;
// 
    public:
//
    error_handler(unsigned int option, unsigned int given_class_id = 0, unsigned int given_process_id = 0)
    {
        #pragma omp parallel sections num_threads(3)
        {
            #pragma omp section
            {
                given_class_id not_eq 0? class_id = given_class_id : class_id = 0;
            }
            #pragma omp section
            {
                given_process_id not_eq 0? process_id = given_process_id : process_id = 0;
            }
            #pragma omp section
            {
                switch(option)
                {
                    case 1:
                    {
                        check_gsl = true;
                        check_boost = false;
                    }
                    break;
                }
            }
        }
    };
//
//
//
    void evaluate_behavior(const int &error);
//
//
    void operator =(const int &error);
};
#endif
