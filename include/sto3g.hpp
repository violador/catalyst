#ifndef __STO3G_HPP
    #define __STO3G_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "tools.hpp"
    #include "array.hpp"
    #include "scf.hpp"
    #include "global_log.hpp"
//
//
//
class molecular_settings;
//
//
//
namespace lcao_wavefunction
{
    class sto3g
    {
    private:
//
//      Declaring the data members:
        settings *config;
        log_file_handler *log_file;
        array *x;                     // A pointer-object to link with any array of atomic x axis positions.
        array *y;                     // A pointer-object to link with any array of atomic y axis positions.
        array *z;                     // A pointer-object to link with any array of atomic z axis positions.
        array *type;                  // A pointer-object to link with any array of atomic types.
        array s_matrix;               // The overlap matrix.
        array t_matrix;               // The kinetic matrix.
        array v_matrix;               // The one electron Coulomb repulsion matrix.
        array h_matrix;               // The core-Hamiltonian matrix.
        array two_electron_terms;     // To store the two electrons Coulomb repulsion terms.
        unsigned int number_of_atoms; // The total number of atoms.
        unsigned int task_number;     // The task number.
//
//      gf_midpoint(): To calculate the distance between the gf in the ith-atom and the gf in the jth-atom
//                     for the gf in the ij midpoint.
        void gf_midpoint(double &i_distance,
                         double &j_distance,
                         const double &i_exp,
                         const double &j_exp,
                         const double &ij_distance);
//
//      gf_product_const(): To calculate the constant in the two gf product.
        double gf_product_const(const double &i_exp, const double &j_exp, const double &ij_distance);
//
//      error_function(): To calculate the error function.
        double error_function(const double &value);
//
//      interatomic_distance(): To calculate the interatomic distance between two given atoms.
        double interatomic_distance(const unsigned int &first_atom, const unsigned int &second_atom);
//
//
    public:
//
//
        static const int id = 30988;
//
//
        algorithm::scf ab_initio_calculation;
//
//      Declaring the class constructor:
        sto3g(unsigned int &total_atoms,
              array  &position_x, 
              array  &position_y, 
              array  &position_z, 
              array  &atom_types, 
              settings &check_setup,
              const unsigned int &given_task = DEFAULT_TASK_NUMBER);
//
//      gf_overlaping(): To calculate the overlaping of two given gf.
        double gf_overlaping(const double &i_exp, const double &j_exp, const double &ij_distance);
//
//      build_overlap_matrix(): To calculate the overlaping integral, s, between two given atoms over the
//                              primitives gf.
        void build_overlap_matrix();
//
//      build_kinetic_matrix():
        void build_kinetic_matrix();
//
//      build_repulsion_matrix():
        void build_repulsion_matrix();
//
//      two_electrons_repulsion():
        void two_electrons_repulsion();
//
//      coeff(): To get the linear combination coefficient of a given primitive gf in a given atom.
        double coeff(const unsigned int &atom_type, const unsigned int &primitive_function);
//
//      exp(): To get the exponent of a given primitive gf in a given atom.
        double exp(const unsigned int &atom_type, const unsigned int &primitive_function);
//
//      density_matrix(): To return the density value of two given index.
        double density_matrix(const unsigned int &i, const unsigned int &j);  
//
//
        friend class molecular_settings;
    };
}
#endif
