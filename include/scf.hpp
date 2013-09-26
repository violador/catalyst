#ifndef __SCF_HPP
    #define __SCF_HPP
    #include "settings.hpp"
    #include "tools.hpp"
    #include "array.hpp"
    #include "log_file_handler.hpp"
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
        settings *config;       // An empty object to the settings class.
        log_file_handler *log_file;
        bool scf_converged;     // To store the convergence state (converged/true or not converged/false).  
        unsigned int iteration; // To store the number of iterations.
        array scf_energy;       // To store the SCF energy for each iteration.
        array p_matrix;         // To store the density matrix.
        array f_matrix;         // To store the Fock matrix.
        array f_eigenvalues;    // To store the Fock eigenvalues.
        array f_eigenvectors;   // To store the Fock eigenvectors.
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
        void update_fock_matrix(array &f_matrix, array &h_matrix, array &p_matrix, array &two_electrons_interaction);
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
//
    public:
//
//
        static const int id = 13836;
//
//      Declaring the overloaded class constructor:
        scf();
//
//      Declaring the overloaded class constructor:
        scf(settings &runtime_setup);
//
//      Declaring the overloaded class constructor:
        scf(array &core_hamiltonian, array &overlap, array &two_electrons_interaction, settings &runtime_setup);
//
//      init_scf(): To start the iterative procedure if the class was invoked by the empty constructor.
        void init_scf(array &core_hamiltonian, array &overlap, array &two_electrons_interaction, settings &runtime_setup);
//
//      number_of_iterations(): To get the number of iterations used.
        unsigned int number_of_iterations();
//
//      converged(): To get the convergence state.
        bool converged();
//
//      energy(): To get the converged energy.
        double energy();
//
//      energy(): To get the energy of a given iterative step.
        double energy(const unsigned int &scf_iteration);
//
//      density_matrix(): To get the ith and jth element of the converged density matrix.
        double density_matrix(const unsigned int &i, const unsigned int &j);   
//
//      fock_matrix(): To get the ith and jth element of the converged Fock matrix.
        double fock_matrix(const unsigned int &i, const unsigned int &j);
//
//      orbital_energy(): To get the energy of a given orbital.
        double mo_energy(const unsigned int &mo_number);
//
//      save_density_to(): To write the density matrix in a given file.
        void save_density_to(const std::string &filename);
//
//      check_mo_type(): To check if all the signs coefficients of a given molecular orbital are positive
//                       (bonding type), negative (bonding type) or positive/negative (antibonding type).
        std::string check_mo_type(const unsigned int &mo_number); 
//
//      set_config(): To initialize the settings inside the class if it was not did by
//                    the class constructors.
        void set_config(settings &runtime_setup)
        {
            config = &runtime_setup;
        };
//
//
        unsigned int lowest_mo();
//
//
        unsigned int highest_mo();
    };
}
#endif
