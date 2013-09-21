/*
 *
 * Usage:
 *
 * mpiCC -o mpi_test mpi_test.cpp
 * export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
 * mpirun -np 2 ./mpi-test
 *
 *
 */
#include <iostream>
#include <mpi.h>
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 0)
    {
        int value = 17;
        int result = MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        if (result == MPI_SUCCESS)
        std::cout << "Rank 0: Ok." << std::endl;
    }
    else if(rank == 1) 
    {
        int value;
        int result = MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (result == MPI_SUCCESS && value == 17)
        std::cout << "Rank 1: Ok.\n\nThe Open MPI is installed and working well." << std::endl;
    }
    MPI_Finalize();
    return 0;
}
