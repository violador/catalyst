#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
int main(int argc, char* argv[])
{
    boost::mpi::environment env(argc, argv);
    boost::mpi::communicator world;
    std::cout << "I am process " << world.rank() << " of " << world.size() << "." << std::endl;
    return 0;
}
