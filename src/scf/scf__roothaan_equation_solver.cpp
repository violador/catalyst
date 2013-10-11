#include "scf.hpp"
//
//
//
void algorithm::scf::roothaan_equation_solver(array &h_matrix, array &s_matrix, array &two_electrons_interaction)
{
//  (1) To allocate memory for the Fock (F) matrix, f_matrix.
//  (2) To allocate memory for eigenvectors of f_matrix, f_eigenvectors (a matrix with the sizes of s_matrix).
//  (3) To allocate memory for eigenvalues of f_matrix, f_eigenvalues (a vector with the size of a s_matrix row).
//  (4) To allocate memory for a density (P) matrix, p_matrix (a matrix with the sizes of s_matrix).
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            f_matrix.array::create_array(s_matrix.size_of_row(), s_matrix.size_of_column()); // (1)
            f_matrix.array::set_name("Initial Fock matrix");
            f_matrix.array::set_config(*config);
//
//          First guess of a Fock matrix:
            f_matrix = h_matrix;
//
            if(config -> state_of(DEBUG_MODE))
            {
                 global_log::file.write_debug_msg("algorithm::scf::roothaan_equation_solver()");
                 global_log::file.write_debug_msg("algorithm::scf::roothaan_equation_solver():");
                 f_matrix.array::write();
            }
        }
        #pragma omp section
        {
            f_eigenvectors.array::create_array(s_matrix.size_of_row(), s_matrix.size_of_column()); // (2)
            f_matrix.array::set_name("Fock matrix eigenvectors");
            f_matrix.array::set_config(*config);
        }
        #pragma omp section
        {
            f_eigenvalues.array::create_array(s_matrix.size_of_row());                             // (3)
            f_matrix.array::set_name("Fock matrix eigenvalues");
            f_matrix.array::set_config(*config);
        }
        #pragma omp section
        {
            p_matrix.array::create_array(s_matrix.size_of_row(), s_matrix.size_of_column());       // (4)
            f_matrix.array::set_name("Density matrix");
            f_matrix.array::set_config(*config);
        }
        #pragma omp section
        {
            scf_energy.create_array(1000);
        }
    } // pragma omp parallel sections num_threads(5)
//
//  SCF iteration 1:
//  (5)  To check the energy of the current Fock matrix.
//  (6)  To use the overlap matrix, s_matrix, to orthonormalize the current Fock matrix.
//  (7)  To calculate the eigenvectors (orbitals) and eigenvalues (energies) of the Fock matrix. 
//  (8)  To restore the eigenvectors in the original non-orthonormal basis.
//  (9)  To use the new eigenvectors to (re)build up the density matrix.
//  (10) To use the new density matrix to (re)build the Fock matrix.
//  (11) Go to step (5).
//  (12) To repeat the process until reach the given energy convergence criteria.
    scf_energy.set(1, get_energy(p_matrix, h_matrix, f_matrix));                      // (5)
    s_matrix.orthonormalize(f_matrix);                                                // (6)
    f_matrix.save_eigens_to(f_eigenvalues, f_eigenvectors);                           // (7)
    s_matrix.restore_original_basis_of(f_eigenvectors);                               // (8)
    build_density_matrix(f_eigenvectors, p_matrix);                                   // (9)
    update_fock_matrix(f_matrix, h_matrix, p_matrix, two_electrons_interaction);      // (10)
//
//  SCF iteration 2:
    scf_energy.set(2, get_energy(p_matrix, h_matrix, f_matrix));                      // (11)
    s_matrix.orthonormalize(f_matrix);
    f_matrix.save_eigens_to(f_eigenvalues, f_eigenvectors);
    s_matrix.restore_original_basis_of(f_eigenvectors);
    build_density_matrix(f_eigenvectors, p_matrix);
    update_fock_matrix(f_matrix, h_matrix, p_matrix, two_electrons_interaction);
//
//  SCF ith-iterations until reach the energy convergence criteria:
    iteration = 2;
    while(check_convergence() not_eq true)                                            // (12)
    {
        ++iteration;
        scf_energy.set(iteration, get_energy(p_matrix, h_matrix, f_matrix));
        s_matrix.orthonormalize(f_matrix);
        f_matrix.save_eigens_to(f_eigenvalues, f_eigenvectors);
        s_matrix.restore_original_basis_of(f_eigenvectors);
        build_density_matrix(f_eigenvectors, p_matrix);
        update_fock_matrix(f_matrix, h_matrix, p_matrix, two_electrons_interaction);
    }
//
    #pragma omp parallel sections num_threads(6)
    {
        #pragma omp section
        {
            f_matrix.array::save();
        }
        #pragma omp section
        {
            p_matrix.array::save();
        }
        #pragma omp section
        {
            f_eigenvectors.array::save();
        }
        #pragma omp section
        {
            f_eigenvalues.array::save();
        }
        #pragma omp section
        {
            if(scf_converged)
            {
                f_matrix.array::set_name("Converged Fock matrix");
                f_eigenvectors.array::set_name("Converged wavefunction matrix");
                p_matrix.array::set_name("Converged density matrix");
            }
        }
        #pragma omp section
        {
            if(not scf_converged)
            {
                f_matrix.array::set_name("Unconverged Fock matrix");
                f_eigenvectors.array::set_name("Unconverged wavefunction matrix");
                p_matrix.array::set_name("Unconverged density matrix");
            }
        }
    }
    if(config -> state_of(DEBUG_MODE))
    {
        global_log::file.write("algorithm::scf::roothaan_equation_solver():");
        f_matrix.array::write();
    }
    //config -> log(f_eigenvectors);
    //config -> log(p_matrix);
}
