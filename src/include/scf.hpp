// ../src/include/scf.hpp --------------------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 08/2013
//
// Description: The SCF class defines the type of variables that handle the self-
//              consistent field algorithm for a given Core-Hamiltonian, overlap 
//              and two electrons interaction matrix of array type or in a file.
//
// References: 
//
// ------------------------------------------------------------------------------------- //
#ifndef __SCF_HPP
    #define __SCF_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "global_settings.hpp"
    #include "array.hpp"
    #include "tools.hpp"
    #include "global_log.hpp"
    #include "timer.hpp"
//
//
//
namespace algorithm
{
    class scf
    {
        private:
//
//      Declaring the data members:
        settings *config;                          // An empty object to the settings class.
        bool scf_converged;                        // To store the convergence state (converged/true or not converged/false).  
        bool scf_iterations_ready;                 // To store the current iterations state (running/true or not running/false).
        unsigned int iteration;                    // To store the number of iterations.
        std::map<unsigned int, double> scf_energy; // To store the SCF energy for each iteration.
        array p_matrix;                            // To store the density matrix.
        array f_matrix;                            // To store the Fock matrix.
        array f_eigenvalues;                       // To store the Fock eigenvalues.
        array f_eigenvectors;                      // To store the Fock eigenvectors.
        timer iterations_time;                     // 
//
//      roothaan_equation_solver(): Given a Core-Hamiltonian matrix, an overlap matrix and a
//                                  multidimensional array with all two electron interaction
//                                  terms; this function iterates until reach the self cons-
//                                  istence. And stores the resulting Fock matrix, density 
//                                  matrix, Fock eigenvectors (the orbitals) and the Fock e-
//                                  igenvalues (the energies) in the data members.
        void roothaan_equation_solver(array &core_hamiltonian,
                                      array &overlap,
                                      array &two_electrons_interaction);
//
//      build_density_matrix(): To build up a density matrix from a set of given Fock matrix 
//                              eigenvectors (also a matrix).
        void build_density_matrix(array &f_eigenvectors, array &p_matrix);
//
//      update_fock_matrix(): Given a Core-Hamiltonian matrix, a density matrix, a multidime-
//                            nsional array with all two electrons interaction terms; this f-
//                            unction update the Fock matrix.
        void update_fock_matrix(array &f_matrix, 
                                array &h_matrix, 
                                array &p_matrix, 
                                array &v_matrix2);
//
//      get_energy(): To calculate the energy using the density matrix, the Core-Hamiltonian
//                    matrix and the Fock matrix.
        double get_energy(array &p_matrix, array &h_matrix, array &f_matrix);
//
//      check_convergence(): To check if the iterative procedure reach the self consistence.
        bool check_convergence();
//
//      report_scf_iterations(): To report the SCF iterative procedure in the logfile.
        void report_scf_iterations();
//
        public:
//
//      Class identifier:
        static const int id = 13836;
//
//      Declaring the overloaded class constructor:
        scf();
//
//      Declaring the overloaded class constructor:
        scf(array &h_matrix, array &s_matrix, array &v_matrix);
//
//      Including the inline/template/public member functions:
        #include "scf__start_iterations.cpp"
        #include "scf__get_density_matrix.cpp"
        #include "scf__number_of_iterations.cpp"
        #include "scf__get_fock_matrix.cpp"
        #include "scf__energy.cpp"
        #include "scf__converged.cpp"
        #include "scf__get_wavefunction.cpp"
        #include "scf__highest_mo.cpp"
        #include "scf__lowest_mo.cpp"
        #include "scf__set_config.cpp"
        #include "scf__iterations_ready.cpp"
        #include "scf__check_mo_type.cpp"
//
    };
}
#endif
