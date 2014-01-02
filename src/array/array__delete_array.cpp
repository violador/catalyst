#include "array.hpp"
//
//
//
void array::delete_array()
{
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            switch(is_1d_array)
            {
                case true:
                delete_1d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_2d_array)
            {
                case true:
                delete_2d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_3d_array)
            {
                case true:
                delete_3d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_4d_array)
            {
                case true:
                delete_4d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            reset_properties();
        }
    }
}
