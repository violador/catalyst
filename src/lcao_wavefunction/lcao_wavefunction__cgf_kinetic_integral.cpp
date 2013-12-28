#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::cgf_kinetic_integral(array &type,                   // The system atomic types.
                                               array &x,                      // The atomic x-axis positions.
                                               array &y,                      // The atomic y-axis positions.
                                               array &z,                      // The atomic z-axis positions.
                                               const unsigned int &atom_a,    // The i-th atom.
                                               const unsigned int &atom_b,    // The j-th atom.
                                               const unsigned int &a_orbital, // The i-th atomic orbital.
                                               const unsigned int &b_orbital, // The j-th atomic orbital.
                                               const unsigned int &level)     // The basis set type. 
{
    double t_integral = 0.0;
    periodic_table a_set(level, type(atom_a));
    periodic_table b_set(level, type(atom_b));
    unsigned int m_primitive = tools::first_gf(level, a_orbital); 
    unsigned int  n_primitive = tools::first_gf(level, b_orbital);
//
    for(unsigned int i = 1; 
        i <= a_set.periodic_table::basis_size(); 
        ++i)
    {
        for(unsigned int j = 1; 
            j <= b_set.periodic_table::basis_size(); 
            ++j)
        {
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, 
                   f = 0.0, g = 0.0, h = 0.0, i = 0.0;
            #pragma omp parallel sections num_threads(9)
            {
                #pragma omp section
                {
                    a = a_set(BASIS_COEFFICIENT, m_primitive)
                      * b_set(BASIS_COEFFICIENT, n_primitive);
                }
                #pragma omp section
                 {
                    b = gf_norm(a_set(BASIS_EXPONENT, m_primitive),
                                    angular_component_x(a_orbital),
                                    angular_component_y(a_orbital),
                                    angular_component_z(a_orbital))
                      * gf_norm(b_set(BASIS_EXPONENT, n_primitive),
                                    angular_component_x(b_orbital),
                                    angular_component_y(b_orbital),
                                    angular_component_z(b_orbital));
                }
                #pragma omp section
                {
                    c = kinetic_integral(x,
                                         atom_a,
                                         atom_b,
                                         angular_component_x(a_orbital),
                                         angular_component_x(b_orbital),
                                         a_set(BASIS_EXPONENT, m_primitive),
                                         b_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    d = kinetic_integral(y,
                                         atom_a,
                                         atom_b,
                                         angular_component_y(a_orbital),
                                         angular_component_y(b_orbital),
                                         a_set(BASIS_EXPONENT, m_primitive),
                                         b_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    e = kinetic_integral(z,
                                         atom_a,
                                         atom_b,
                                         angular_component_z(a_orbital),
                                         angular_component_z(b_orbital),
                                         a_set(BASIS_EXPONENT, m_primitive),
                                         b_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    f = overlap_integral(x,
                                         atom_a,
                                         atom_b,
                                         angular_component_x(a_orbital),
                                         angular_component_x(b_orbital),
                                         a_set(BASIS_EXPONENT, m_primitive),
                                         b_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    g = overlap_integral(y,
                                         atom_a,
                                         atom_b,
                                         angular_component_y(a_orbital),
                                         angular_component_y(b_orbital),
                                         a_set(BASIS_EXPONENT, m_primitive),
                                         b_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    h = overlap_integral(z,
                                         atom_a,
                                         atom_b,
                                         angular_component_z(a_orbital),
                                         angular_component_z(b_orbital),
                                         a_set(BASIS_EXPONENT, m_primitive),
                                         b_set(BASIS_EXPONENT, n_primitive));
                }
                #pragma omp section
                {
                    i = gf_overlap_factor(a_set(BASIS_EXPONENT, m_primitive),
                                          b_set(BASIS_EXPONENT, n_primitive),
                                             tools::point_distance(x(atom_b),
                                                                   y(atom_b),
                                                                   z(atom_b),
                                                                   x(atom_a),
                                                                   y(atom_a),
                                                                   z(atom_a)));
                }
            }
            #pragma omp atomic
            t_integral += a*b*(c*g*f + f*d*h + f*g*e)*i;
            ++n_primitive;
        }
        ++m_primitive;
        n_primitive = tools::first_gf(level, b_orbital);
    }
//
    return t_integral;
}
