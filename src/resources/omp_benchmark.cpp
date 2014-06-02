// ====================================================================================
//
// HOW TO:
//
// On a terminal just type:
//
// g++ -o omp_benchmark.out omp_benchmark.cpp -fopenmp
//
// You have now an executable called 'omp_benchmark.out' and may be invoked with
//
// ./omp_benchmark.out
//
// But before, there are a couple of options available:  'loop=', 'threads=', 'run='
// and 'no_omp'. Where, the loop one set the size of an internal loop to burn (wall)
// time machine; the thread should setup the number of  OpenMP threads used to para-
// llelize that internal loop, the higher the value the smaller the output walltime.
// The 'run=' option setup the number of tests to perform and 'no_omp' is optional,
// used to switch off the OpenMP and to have a real single-core runtime. Example:
//
// ./omp_benchmark.out loop=10000 threads=2 run=10
//
// If none of those options are given the program just finish itself, if a couple of
// them are given the remaing ones uses default values.
//
// ====================================================================================
//
// WARNING: The code starts from here on, please you don't need to keep reading!
//
#include <omp.h>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <iostream>
//
//
// read_arguments(): This small help function just read the arguments given as command
//                   line in the program execution and stores its content. The options
//                   available as arguments are as follows: 'loop=' to setup the numb-
//                   er of loop iterations to burn time machine;  'threads='  to setup
//                   the number of threads; 'run=' to setup the number of times to run
//                   the burn time machine routine and 'no_omp' to switch off the Open
//                   MP library (on by default). If some options are not given, defau-
//                   lt values are used, if none are given the runtime just finish it-
//                   self.
void read_arguments(int &argc,
                    char** argv,
                    unsigned int &loop_size,
                    unsigned int &threads,
                    unsigned int &runtime,
                    bool &use_omp)
{
	std::cout << std::endl;
	for(int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if(!arg.std::string::compare(0, 5, "loop="))
		{
			arg.std::string::erase(0, 5);
			loop_size = (unsigned int) atoi(arg.std::string::c_str());
			std::cout << "Given loop size   = " << loop_size << std::endl;
		}
		else if(!arg.std::string::compare(0, 8, "threads="))
		{
			arg.std::string::erase(0, 8);
			threads = (unsigned int) atoi(arg.std::string::c_str());
			std::cout << "Threads requested = " << threads << std::endl;
		}
		else if(!arg.std::string::compare(0, 4, "run="))
		{
			arg.std::string::erase(0, 4);
			runtime = (unsigned int) atoi(arg.std::string::c_str());
			std::cout << "Run               = " << runtime << " times" << std::endl;
		}
		else if(!arg.std::string::compare(0, 6, "no_omp"))
		{
			use_omp = false;
		}
		else
		{
			std::cout << arg << " is not a valid argument!" << std::endl;
		}
	}
	std::cout << "OpenMP            = " << (use_omp? "on" : "off") << std::endl;
};
//
//
//
// check_elapsed_time(): This is the burn time machine routine and runs a double for loop
//                       over 'loop_size' values doing an useless  sqrt of a long number.
//                       The loops are parallelized with OpenMP (if  'use_omp'  is true).
//                       The function returns its wall time to the main body of the code.
double check_elapsed_time(const unsigned int &loop_size,
                          const unsigned int &threads,
                          const bool &use_omp)
{
	double start_time = omp_get_wtime();
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < loop_size; ++i)
	{
		for(unsigned int j = 0; j < loop_size; ++j)
		{
			std::sqrt(123.456L); // Burn time!
		}
	}
	double end_time = omp_get_wtime();
	std::cout << std::setprecision(10);
	#pragma omp critical
	std::cout << "Elapsed time = " << end_time - start_time << " s" << std::endl;
	return end_time - start_time;
};
//
//
//
int main(int argc, char** argv)
{
	switch(argc > 1)
	{
		case true:
		bool use_omp = true;            // Default usage of OMP: on.
		double elapsed_time = 0.0;
		unsigned int loop_size = 10000, // Default size of the loop: 10000 iterations.
		             threads = 2,       // Default number of threads used: 2.
		             runtime = 5,       // Default number of tests: 5 times.
		             counter = 0;
		read_arguments(argc, argv, loop_size, threads, runtime, use_omp);
		#pragma omp parallel num_threads(threads) if(use_omp)
		{
			#pragma omp master
			std::cout << "Threads created   = " << omp_get_num_threads() << "/" << threads << std::endl;
			#pragma omp master
			while(counter < runtime)
			{
				elapsed_time += check_elapsed_time(loop_size, threads, use_omp);
				++counter;
			}
		}
		std::cout << "Average elapsed time = " << elapsed_time/runtime << " s" << std::endl;
		std::cout << std::endl;
		return EXIT_SUCCESS;
		break;
	}
	std::cout << std::endl;
	std::cout << "Do not forget the arguments:" << std::endl;
	std::cout << "loop=" << " [integer number, default = 10000]" << std::endl;
	std::cout << "threads=" << " [integer number, default = 2]" << std::endl;
	std::cout << "no_omp" << " (optional)" << std::endl;
	std::cout << "run=" << " [integer number, default = 5]" << std::endl;
	std::cout << std::endl;
	return EXIT_FAILURE;
}
