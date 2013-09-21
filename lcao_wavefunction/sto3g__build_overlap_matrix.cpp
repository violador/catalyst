#include "sto3g.hpp"
//
//
//
void lcao_wavefunction::sto3g::build_overlap_matrix()
{
//  (1) To calculate the overlap integral between the ith-atom and the jth-atom, 
//  s_integral, over the set of primitive gf.
    s_matrix.create_array(number_of_atoms, number_of_atoms);
    s_matrix.set_name("Overlap matrix");
    s_matrix.set_all(1.0);
    double s_integral = 0.0;
    double ij_distance  = 0.0;
    double a = 0.0;
    double b = 0.0;
    unsigned int i_atom = 0;
    unsigned int i_type = 0;
    #pragma omp parallel for private(i_atom, i_type, ij_distance, a, b) reduction(+:s_integral) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= number_of_atoms; i_atom++)  
    {  
        i_type = (type -> get(i_atom));
        unsigned int j_atom = 0;
        unsigned int j_type = 0;
        #pragma omp parallel for private(j_atom, j_type, ij_distance, a, b) reduction(+:s_integral) ordered schedule(dynamic)
        for(j_atom = i_atom; j_atom <= number_of_atoms; j_atom++)
        {
            j_type = (type -> get(j_atom));
            if(i_atom != j_atom)
            {
                ij_distance = interatomic_distance(i_atom, j_atom);
                unsigned int m_primitive = 0;
                #pragma omp parallel for private(m_primitive, a, b) reduction(+:s_integral) ordered schedule(dynamic)
                for(m_primitive = 1; m_primitive <= (i_type == 1? 3:6); m_primitive++)
                {
                    unsigned int n_primitive = 0;
                    #pragma omp parallel for private(n_primitive, a, b) reduction(+:s_integral) ordered schedule(dynamic)
                    for(n_primitive = 1; n_primitive <= (i_type == 1? 3:6); n_primitive++)
                    {
                        #pragma omp parallel sections num_threads(2)
                        {
                            #pragma omp section
                            {
                                a = coeff(i_type, m_primitive)*coeff(j_type, n_primitive);
                            }
                            #pragma omp section
                            {
                                b = gf_overlaping(exp(i_type, m_primitive), exp(j_type, n_primitive), ij_distance);
                            }
                        }
//
//                      A. Szabo and N. Ostlund; Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                      Appendix A; pag. 412; equation (A.9):
                        #pragma omp atomic
                        s_integral += a*b;
//
                        a = b = 0.0; 
                    } // for(n_primitive)
                } // for(m_primitive)
                s_matrix.set(i_atom, j_atom, s_integral);
                s_matrix.set(j_atom, i_atom, s_integral);
                s_integral = ij_distance = a = b = 0.0;
                i_type = j_type = 0;
            }
        } // for(j_atom) 
    } // for(i_atom)
} 
