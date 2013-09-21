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
    f_matrix.create_array(s_matrix.size_of_row(), s_matrix.size_of_column());         // (1)
//
//  First guess of a Fock matrix:
    h_matrix.copy_to(f_matrix);
    if(config -> state_of(DEBUG_MODE))
    {
        //f_matrix.set_name("Initial Fock matrix");
        //config -> log("algorithm::scf::roothaan_equation_solver() debug mode: Follows the starting Fock matrix\n");
        //config -> log(f_matrix);
    }
//
//
    f_eigenvectors.create_array(s_matrix.size_of_row(), s_matrix.size_of_column());   // (2)
    f_eigenvalues.create_array(s_matrix.size_of_row());                               // (3)
    p_matrix.create_array(s_matrix.size_of_row(), s_matrix.size_of_column());         // (4)
    scf_energy.create_array(1000);
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
    while(check_convergence() not_eq true)                                                // (12)
    {
        ++iteration;
        scf_energy.set(iteration, get_energy(p_matrix, h_matrix, f_matrix));
        s_matrix.orthonormalize(f_matrix);
        f_matrix.save_eigens_to(f_eigenvalues, f_eigenvectors);
        s_matrix.restore_original_basis_of(f_eigenvectors);
        build_density_matrix(f_eigenvectors, p_matrix);
        update_fock_matrix(f_matrix, h_matrix, p_matrix, two_electrons_interaction);
    }
    if(scf_converged)
    {
        f_matrix.set_name("Converged Fock matrix");
        f_eigenvectors.set_name("Converged wavefunction matrix");
        p_matrix.set_name("Converged density matrix");
    }
    else
    {
        f_matrix.set_name("Unconverged Fock matrix");
        f_eigenvectors.set_name("Unconverged wavefunction matrix");
        p_matrix.set_name("Unconverged density matrix");
    }
    if(config -> state_of(DEBUG_MODE))
    {
        //config -> log("algorithm::scf::roothaan_equation_solver() debug mode: Follows the final Fock matrix\n");
        //config -> log(f_matrix);
    }
    //config -> log(f_eigenvectors);
    //config -> log(p_matrix);
}
