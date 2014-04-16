// ../src/include/lcao_wavefunction.hpp ------------------------------------------------ //
//
// File author: Humberto Jr.
//
// Date: 10/2013
//
// Description:
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __LCAO_WAVEFUNCTION_HPP
    #define __LCAO_WAVEFUNCTION_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "global_settings.hpp"
    #include "array.hpp"
    #include "scf.hpp"
    #include "basis_set.hpp"
    #include "global_log.hpp"
    #include "periodic_table.hpp"
    #include "timer.hpp"
//
//
//
class lcao_wavefunction
{
    private:
//
//  Declaring the data members:
    settings *config;                 //
    array s_matrix;                   //
    array t_matrix;                   //
    array v_matrix1;                  //
    array v_matrix2;                  //
    array h_matrix;                   //
    array *f_matrix;                  //
    array *p_matrix;                  //
    array *wavefunction;              //
    unsigned int current_level;       //
    bool overlap_matrix_ready;        //
    bool kinetic_matrix_ready;        //
    bool repulsion_matrix1_ready;     //
    bool repulsion_matrix2_ready;     //
    bool hamiltonian_matrix_ready;    //
    algorithm::scf iterative_routine; //
//
//  check_matrix_size(): To check the sizes of the given matrices used to store
//                       the data and to resize it when needed.
    void check_matrix_size(array &given_matrix, const unsigned int &dimension_size);
//
//  build_overlap_matrix(): To calculate the overlaping integral, S, and to build the overlap
//                          matrix.
    void build_matrices(array &type,
                        array &x,
                        array &y,
                        array &z,
                        const unsigned int given_level = 1);
//
//  cgf_overlap_integral():
    double cgf_overlap_integral(array &type,
                                array &x,
                                array &y,
                                array &z,
                                const unsigned int &atom_a,
                                const unsigned int &atom_b,
                                const unsigned int &a_orbital,
                                const unsigned int &b_orbital,
                                const unsigned int &level);
//
//  cgf_kinetic_integral():
    double cgf_kinetic_integral(array &type,
                                array &x,
                                array &y,
                                array &z,
                                const unsigned int &atom_a,
                                const unsigned int &atom_b,
                                const unsigned int &a_orbital,
                                const unsigned int &b_orbital,
                                const unsigned int &level);
//
//
    double overlap_integral(array &r,
                            const unsigned int &atom_a,
                            const unsigned int &atom_b,
                            const unsigned int &a_orbital_r,
                            const unsigned int &b_orbital_r,
                            const double &alpha,
                            const double &beta);
//
//
    double overlap_integral(array &r,
                            const unsigned int &atom_a,
                            const unsigned int &atom_b,
                            const unsigned int &atom_c,
                            const unsigned int &a_orbital_r,
                            const unsigned int &b_orbital_r,
                            const unsigned int &c_orbital_r,
                            const double &alpha,
                            const double &beta,
                            const double &gamma);
//
//
    double kinetic_integral(array &r,
                            const unsigned int &atom_a,
                            const unsigned int &atom_b,
                            const unsigned int &a_orbital_r,
                            const unsigned int &b_orbital_r,
                            const double &alpha,
                            const double &beta);
//
//
    double overlap_integral(array &type,
                            array &x,
                            array &y,
                            array &z,
                            const unsigned int &atom_a,
                            const unsigned int &atom_b,
                            const unsigned int &level);
//
//  get_kinetic_integral():
    double kinetic_integral(array &type,
                            array &x,
                            array &y,
                            array &z,
                            const unsigned int &atom_a,
                            const unsigned int &atom_b,
                            const unsigned int &level);
//
//
    double os_scheme_overlap_integral(array &r,
                                      const unsigned int &atom_a,
                                      const unsigned int &atom_b,
                                      const unsigned int &atom_c,
                                      const unsigned int &a_orbital,
                                      const unsigned int &b_orbital,
                                      const unsigned int &c_orbital,
                                      const double &alpha,
                                      const double &beta,
                                      const double &gamma);
//
//
    double os_scheme_aux_eri(array &r,
                             const unsigned int &order,
                             const unsigned int &atom_a,
                             const unsigned int &atom_b,
                             const unsigned int &atom_c,
                             const unsigned int &atom_d,
                             const unsigned int &a_orbital,
                             const unsigned int &b_orbital,
                             const unsigned int &c_orbital,
                             const unsigned int &d_orbital,
                             const double &alpha,
                             const double &beta,
                             const double &gamma,
                             const double &delta);
//
//
    double os_scheme_ssss_eri(array &r,
                              const unsigned int &atom_a,
                              const unsigned int &atom_b,
                              const unsigned int &atom_c,
                              const unsigned int &atom_d,
                              const double &alpha,
                              const double &beta,
                              const double &gamma,
                              const double &delta);
//
//
    double os_scheme_psss_eri(array &r,
                              const unsigned int &atom_a,
                              const unsigned int &atom_b,
                              const unsigned int &atom_c,
                              const unsigned int &atom_d,
                              const double &alpha,
                              const double &beta,
                              const double &gamma,
                              const double &delta);
//
//
    double os_scheme_psps_eri(array &r,
                              const unsigned int &atom_a,
                              const unsigned int &atom_b,
                              const unsigned int &atom_c,
                              const unsigned int &atom_d,
                              const double &alpha,
                              const double &beta,
                              const double &gamma,
                              const double &delta);
//
//
    double os_scheme_ppss_eri(array &r,
                              const unsigned int &atom_a,
                              const unsigned int &atom_b,
                              const unsigned int &atom_c,
                              const unsigned int &atom_d,
                              const double &alpha,
                              const double &beta,
                              const double &gamma,
                              const double &delta);
//
//
    double os_scheme_ppps_eri(array &r,
                              const unsigned int &atom_a,
                              const unsigned int &atom_b,
                              const unsigned int &atom_c,
                              const unsigned int &atom_d,
                              const double &alpha,
                              const double &beta,
                              const double &gamma,
                              const double &delta);
//
//
    double os_scheme_pppp_eri(array &r,
                              const unsigned int &atom_a,
                              const unsigned int &atom_b,
                              const unsigned int &atom_c,
                              const unsigned int &atom_d,
                              const double &alpha,
                              const double &beta,
                              const double &gamma,
                              const double &delta);
//
//
    double gf_norm(const double &alpha,
                   const unsigned int &x,
                   const unsigned int &y,
                   const unsigned int &z);
//
//
    unsigned int check_eri_type(const unsigned int &a_orbital,
                                const unsigned int &b_orbital,
                                const unsigned int &c_orbital,
                                const unsigned int &d_orbital);
//
//  Including the inline/template/private member functions:
    #include "lcao_wavefunction__gf_product_const.cpp"
    #include "lcao_wavefunction__gf_midpoint.cpp"
    #include "lcao_wavefunction__gf_overlap_integral.cpp"
    #include "lcao_wavefunction__gf_product.cpp"
    #include "lcao_wavefunction__gf_overlap_factor.cpp"
    #include "lcao_wavefunction__gf_overlap_product.cpp"
    #include "lcao_wavefunction__error_function.cpp"
    #include "lcao_wavefunction__interatomic_distance.cpp"
    #include "lcao_wavefunction__init_matrices.cpp"
    #include "lcao_wavefunction__first_gf.cpp"
    #include "lcao_wavefunction__count_orbitals.cpp"
    #include "lcao_wavefunction__angular_component_.cpp"
//
//  Buffer for calculations of the overlap equation:
/*
	namespace overlap
	{
		double a;
		double b;
		double c;
		double d;
		double e;
		double f;
		double g;
		double h;
		double m;
		double integral;
		inline void set_zero()
		{
			a = b = c = d = e = f = g = h = m = integral = 0.0;
		};
		inline void two_center_integral()
		{
//
//			Minhhuy Hô and Julio Manuel Hernández-Pérez;
//			The Mathematica Journal;
//			Evaluation of gaussian molecular integrals I - overlap integral;
//			equation (6):
            #pragma omp atomic
			integral += a*b*c*d*e*f/g;
		};
		inline void three_center_integral()
		{
//
//			S. Obara and A. Saika;
//			The Journal of Chemical Physics;
//			Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//			equation (17):
            #pragma omp atomic
			integral += a*b*c*d*e*f*g*h/m;
		};
	};
	*/
//
    public:
//
//  Class identifier:
    static const int id = 30988;
//
//  Declaring the class constructor:
    lcao_wavefunction();
//
//  Declaring the class constructor:
    lcao_wavefunction(array &type,
                      array &x,
                      array &y,
                      array &z,
                      const unsigned int given_level = DEFAULT_TASK_NUMBER);
//
//  build_hamiltonian_matrix(): To calculate the Core-Hamiltonian, H, matrix.
    void build_hamiltonian_matrix(array &h_matrix,
                                  array &type,
                                  array &x,
                                  array &y,
                                  array &z,
                                  const unsigned int given_level = 1);

//
//  build_overlap_matrix(): To calculate the overlaping integral, S, and to build the overlap
//                          matrix.
    void build_overlap_matrix(array &s_matrix,
                              array &type,
                              array &x,
                              array &y,
                              array &z,
                              const unsigned int given_level = 1);
//
//  build_kinetic_matrix(): To calculate the kinetic integral, T, and to build the kinetic
//                          matrix.
    void build_kinetic_matrix(array &t_matrix,
                              array &type,
                              array &x,
                              array &y,
                              array &z,
                              unsigned int level = 1);
//
//  build_repulsion_matrix_1(): To calculate the one electron repulsion integral, V,
//                              and to build the repulsion matrix.
    void build_repulsion_matrix_1(array &v_matrix1,
                                  array &type,
                                  array &x,
                                  array &y,
                                  array &z,
                                  unsigned int level = 1);
//
//  build_repulsion_matrix_2(): To calculate the two electron repulsion integral, V,
//                              and to build the repulsion matrix (four dimensions).
    void build_repulsion_matrix_2(array &v_matrix2,
                                  array &type,
                                  array &x,
                                  array &y,
                                  array &z,
                                  unsigned int level = 1);
//
//
    double boys_function(const double &given_order,
                         const double &given_value);
//
    timer overlap_timing;
    timer kinetic_timing;
//
//  Including the inline/template/public member functions:
    #include "lcao_wavefunction__get_overlap_matrix.cpp"
    #include "lcao_wavefunction__get_kinetic_matrix.cpp"
    #include "lcao_wavefunction__get_core_hamiltonian_matrix.cpp"
    #include "lcao_wavefunction__get_one_electron_repulsion_matrix.cpp"
    #include "lcao_wavefunction__get_two_electron_repulsion_matrix.cpp"
    #include "lcao_wavefunction__get_density_matrix.cpp"
    #include "lcao_wavefunction__get_fock_matrix.cpp"
    #include "lcao_wavefunction__get_wavefunction.cpp"
    #include "lcao_wavefunction__start_scf_iterations.cpp"
    #include "lcao_wavefunction__scf_ready.cpp"
    #include "lcao_wavefunction__energy.cpp"
//
};
#endif
