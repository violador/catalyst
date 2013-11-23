#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::cgf_overlap_integral(array &type,                   // The system atomic types.
                                               array &x,                      // The atomic x-axis positions.
                                               array &y,                      // The atomic y-axis positions.
                                               array &z,                      // The atomic z-axis positions.
                                               const unsigned int &i_atom,    // The i-th atom.
                                               const unsigned int &j_atom,    // The j-th atom.
                                               const unsigned int &i_orbital, // The i-th atomic orbital.
                                               const unsigned int &j_orbital, // The j-th atomic orbital.
                                               const unsigned int &level)     // The basis set type. 
{
//
    switch(i_orbital)
    {
        case SUB_SHELL_2px:
        {
            switch(j_orbital)
            {
                case SUB_SHELL_2py: return 0.0; break;
                case SUB_SHELL_2pz: return 0.0; break;
            }
        }
        break;
        case SUB_SHELL_2py:
        {
            switch(j_orbital)
            {
                case SUB_SHELL_2px: return 0.0; break;
                case SUB_SHELL_2pz: return 0.0; break;
            }
        }
        break;
        case SUB_SHELL_2pz:
        {
            switch(j_orbital)
            {
                case SUB_SHELL_2px: return 0.0; break;
                case SUB_SHELL_2py: return 0.0; break;
            }
        }
        break;
    }
    double s_integral = 0.0;
    periodic_table i_basis_set(level, type(i_atom));
    periodic_table j_basis_set(level, type(j_atom));
    unsigned int m_primitive = first_gf(level, i_orbital);
    unsigned int n_primitive = first_gf(level, j_orbital);
    for(unsigned int i = 1; 
        i <= i_basis_set.periodic_table::basis_size(); 
        ++i)
    {
        for(unsigned int j = 1; 
            j <= j_basis_set.periodic_table::basis_size(); 
            ++j)
        {
            tools get;
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0;
            #pragma omp parallel sections num_threads(6)
            {
                #pragma omp section
                {
                    a = gf_overlap_factor(i_basis_set(BASIS_EXPONENT, m_primitive),
                                          j_basis_set(BASIS_EXPONENT, n_primitive),
                                                      get.point_distance(x(i_atom),
                                                                         y(i_atom),
                                                                         z(i_atom),
                                                                         x(j_atom),
                                                                         y(j_atom),
                                                                         z(j_atom))); 
                }
                #pragma omp section
                {
                    b = i_basis_set(BASIS_COEFFICIENT, m_primitive)
                      * j_basis_set(BASIS_COEFFICIENT, n_primitive);
                }
                #pragma omp section
                 {
                    c = gf_norm(i_basis_set(BASIS_EXPONENT, m_primitive),
                                          angular_component_x(i_orbital),
                                          angular_component_y(i_orbital),
                                          angular_component_z(i_orbital))
                      * gf_norm(j_basis_set(BASIS_EXPONENT, n_primitive),
                                          angular_component_x(j_orbital),
                                          angular_component_y(j_orbital),
                                          angular_component_z(j_orbital));
                }
                #pragma omp section
                {
                    d = overlap_integral(x,
                                         i_atom,
                                         j_atom,
                                         angular_component_x(i_orbital),
                                         angular_component_x(j_orbital),
                                         i_basis_set(BASIS_EXPONENT, m_primitive),
                                         j_basis_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    e = overlap_integral(y,
                                         i_atom,
                                         j_atom,
                                         angular_component_y(i_orbital),
                                         angular_component_y(j_orbital),
                                         i_basis_set(BASIS_EXPONENT, m_primitive),
                                         j_basis_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    f = overlap_integral(z,
                                         i_atom,
                                         j_atom,
                                         angular_component_z(i_orbital),
                                         angular_component_z(j_orbital),
                                         i_basis_set(BASIS_EXPONENT, m_primitive),
                                         j_basis_set(BASIS_EXPONENT, n_primitive));
                }
            }
            #pragma omp atomic
            s_integral += a*b*c*d*e*f;
            ++n_primitive;
        }
        ++m_primitive;
        n_primitive = first_gf(level, j_orbital);
    }
//
    return s_integral;
}
