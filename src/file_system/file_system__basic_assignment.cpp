#include "file_system.hpp"
//
//
//
void file_system::operator =(const file_system &given)
{
    #pragma omp parallel sections num_threads(9)
    {
        #pragma omp section
        {
            switch(this -> stream_ready)
            {
                case true: close(); break;
            }
        }
        #pragma omp section
        {
            this -> filename = given.filename;
        }
        #pragma omp section
        {
            this -> root_path = given.root_path;
        }
        #pragma omp section
        {
            this -> parent_path = given.parent_path;
        }
        #pragma omp section
        {
            this -> relative_path = given.relative_path;
        }
        #pragma omp section
        {
            this -> file_extension = given.file_extension;
        }
        #pragma omp section
        {
            this -> file_status = given.file_status;
        }
        #pragma omp section
        {
            this -> path_status = given.path_status;
        }
        #pragma omp section
        {
            this -> disk_space = given.disk_space;
        }
    }
}
