#include "scf.hpp"
//
//
//
void algorithm::scf::roothaan_equation_solver(array &h_matrix, array &s_matrix, array &v_matrix)
{
//  (1) To allocate memory for the Fock (F) matrix, f_matrix.
//  (2) To allocate memory for eigenvectors of f_matrix, f_eigenvectors (a matrix with the sizes of s_matrix).
//  (3) To allocate memory for eigenvalues of f_matrix, f_eigenvalues (a vector with the size of a s_matrix row).
//  (4) To allocate memory for a density (P) matrix, p_matrix (a matrix with the sizes of s_matrix).
    #pragma omp parallel sections num_threads(6)
    {
        #pragma omp section
        {
            global_log::file.write_debug_msg("algorithm::scf::roothaan_equation_solver()");
        }
        #pragma omp section
        {
            f_matrix.array::create_array(s_matrix.array::size_of_row(), s_matrix.array::size_of_column());       // (1)
            f_matrix.array::set_name("Initial Fock matrix");
//
//          First guess of a Fock matrix:
            f_matrix = h_matrix;
//
            switch(config -> debug_mode())
            {
                 case false: break;
                 case  true: f_matrix.array::write(); break;
            }
        }
        #pragma omp section
        {
            s_matrix.array::build_orthonormalizer_form();
        }
        #pragma omp section
        {
            f_eigenvectors.array::create_array(s_matrix.array::size_of_row(), s_matrix.array::size_of_column()); // (2)
            f_eigenvectors.array::set_name("Fock matrix eigenvectors");
        }
        #pragma omp section
        {
            f_eigenvalues.array::create_array(s_matrix.array::size_of_row());                                    // (3)
            f_eigenvalues.array::set_name("Fock matrix eigenvalues");
        }
        #pragma omp section
        {
            p_matrix.array::create_array(s_matrix.array::size_of_row(), s_matrix.array::size_of_column());       // (4)
            p_matrix.array::set_name("Density matrix");
        }
    }
    iterations_time.timer::start();
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
    scf_energy.insert(std::pair<unsigned int, double>(iteration, get_energy(p_matrix, h_matrix, f_matrix)));   // (5)
    s_matrix.array::orthonormalize(f_matrix);                                                                  // (6)
    f_matrix.array::eigen(f_eigenvalues, f_eigenvectors);                                             // (7)
    s_matrix.array::restore_original_basis_of(f_eigenvectors);                                                 // (8)
    build_density_matrix(f_eigenvectors, p_matrix);                                                            // (9)
    update_fock_matrix(f_matrix, h_matrix, p_matrix, v_matrix);                                                // (10)
//
//  SCF iteration 2:
    scf_energy.insert(std::pair<unsigned int, double>(++iteration, get_energy(p_matrix, h_matrix, f_matrix))); // (11)
    s_matrix.array::orthonormalize(f_matrix);
    f_matrix.array::eigen(f_eigenvalues, f_eigenvectors);
    s_matrix.array::restore_original_basis_of(f_eigenvectors);
    build_density_matrix(f_eigenvectors, p_matrix);
    update_fock_matrix(f_matrix, h_matrix, p_matrix, v_matrix);
//
//  SCF ith-iterations until reach the energy convergence criteria:
    while(check_convergence() not_eq true)                                                                     // (12)
    {
        ++iteration;
        scf_energy.insert(std::pair<unsigned int, double>(iteration, get_energy(p_matrix, h_matrix, f_matrix)));
//
        std::cout << "iter = " << iteration << ", energy = " << scf_energy[iteration] << std::endl;
//
        s_matrix.array::orthonormalize(f_matrix);
        f_matrix.array::eigen(f_eigenvalues, f_eigenvectors);
        s_matrix.array::restore_original_basis_of(f_eigenvectors);
        build_density_matrix(f_eigenvectors, p_matrix);
        update_fock_matrix(f_matrix, h_matrix, p_matrix, v_matrix);
    }
    iterations_time.timer::stop();
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
            switch(scf_converged)
            {
                case false:
                {
                    f_matrix.array::set_name("Unconverged Fock matrix");
                    f_eigenvectors.array::set_name("Unconverged wavefunction matrix");
                    p_matrix.array::set_name("Unconverged density matrix");
                }
                break;
                case true:
                {
                    f_matrix.array::set_name("Converged Fock matrix");
                    f_eigenvectors.array::set_name("Converged wavefunction matrix");
                    p_matrix.array::set_name("Converged density matrix");
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(config -> debug_mode())
            {
                case false: break;
                case  true: f_matrix.array::write(); break;
            }
        }
    }
}
