#include "sto3g.hpp"
//
//
//
void lcao_wavefunction::sto3g::two_electrons_repulsion()
{
//  (1) To allocate memory for the two electrons interaction (V) array.
//  (2) To run a loop over the centers i_atom, j_atom, p_atom and q_atom from the given molecular system.
//  (3) To run a loop over the primitives gf.
//  (4) To use gf_midpoint() to get the distance of i_atom and j_atom from the midpoint between them. 
//  (5) To use gf_midpoint() to get the distance of p_atom and q_atom from the midpoint between them.
//  (6) To calculate the integral <i_atom j_atom | p_atom q_atom>, v_integral.
    two_electron_terms.create_array(gsl_pow_4(number_of_atoms),
                                    gsl_pow_4(number_of_atoms),
                                    gsl_pow_4(number_of_atoms),
                                    gsl_pow_4(number_of_atoms)); // (1)
    two_electron_terms.set_name("Two electron Coulomb repulsion array");
    double v_integral  = 0.0; 
    double i_distance  = 0.0; 
    double j_distance  = 0.0;
    double p_distance  = 0.0;
    double q_distance  = 0.0;
    double ij_distance = 0.0;
    double pq_distance = 0.0;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double e = 0.0;
    double f = 0.0;
    double g = 0.0;
    unsigned int i_type = 0;
    unsigned int j_type = 0;
    unsigned int p_type = 0;
    unsigned int q_type = 0;
    //#pragma omp parallel for ordered schedule(dynamic)
    for(unsigned int i_atom = 1; i_atom <= number_of_atoms; i_atom++)
    {
        i_type = (type -> get(i_atom));
        for(unsigned int j_atom = 1; j_atom <= number_of_atoms; j_atom++)
        {
            j_type = (type -> get(j_atom));
            ij_distance = ((i_atom == j_atom)? 0.0 : interatomic_distance(i_atom, j_atom));
            for(unsigned int p_atom = 1; p_atom <= number_of_atoms; p_atom++)
            {
                p_type = (type -> get(p_atom));
                for(unsigned int q_atom = 1; q_atom <= number_of_atoms; q_atom++)                                          // (2)
                {
                    q_type = (type -> get(q_atom));
                    pq_distance = ((p_atom == q_atom)? 0.0 : interatomic_distance(p_atom, q_atom));
                    for(unsigned int m_primitive = 1; m_primitive <= (i_type == 1? 3:6); m_primitive++)
                    {
                        for(unsigned int n_primitive = 1; n_primitive <= (i_type == 1? 3:6); n_primitive++)
                        {
                            for(unsigned int k_primitive = 1; k_primitive <= (i_type == 1? 3:6); k_primitive++)
                            {
                                for(unsigned int l_primitive = 1; l_primitive <= (i_type == 1? 3:6); l_primitive++)                        // (3)
                                {
                                    gf_midpoint(i_distance,
                                                j_distance,
                                                exp(i_type, m_primitive),
                                                exp(j_type, n_primitive),
                                                ij_distance);                                                             // (4)
                                    gf_midpoint(p_distance,
                                                q_distance,
                                                exp(p_type, k_primitive),
                                                exp(q_type, l_primitive),
                                                pq_distance);                                                             // (5)
                                    a = coeff(i_type, m_primitive)*coeff(j_type, n_primitive)
                                      * coeff(p_type, k_primitive)*coeff(q_type, l_primitive);
                                    b =  exp(i_type, m_primitive) + exp(j_type, n_primitive);
                                    c =  exp(p_type, k_primitive) + exp(q_type, l_primitive);
                                    d = -exp(i_type, m_primitive)*exp(j_type, n_primitive)*gsl_pow_2(ij_distance)/b;
                                    e = -exp(p_type, k_primitive)*exp(q_type, l_primitive)*gsl_pow_2(pq_distance)/c;
                                    if((i_atom == j_atom) && (p_atom == q_atom) && (i_atom != q_atom))
                                    { 
                                        f = interatomic_distance(i_atom, q_atom);
                                    }
                                    else
                                    {
                                        f = i_distance - p_distance;
                                    }
                                    g =  b*c*gsl_pow_2(f)/(b + c);
//
//                                  A. Szabo and N. Ostlund; Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                                  Appendix A; pag. 416; equation (A.41):
                                    //#pragma omp atomic
                                    v_integral += a*(2.0*pow(M_PI, 2.5)/(b*c*sqrt(b + c)))*gsl_sf_exp(d + e)*error_function(g); // (6)
//
                                    a = b = c = d = e = f = i_distance = j_distance = p_distance = q_distance = 0.0;
                                } // for(l_primitive)
                            } // for(k_primitive)
                        } // for(n_primitive)
                    } // for(m_primitive)
                    two_electron_terms.set(i_atom, 
                                           j_atom, 
                                           p_atom, 
                                           q_atom, 
                                           two_electron_terms.get(i_atom, j_atom, p_atom, q_atom) + v_integral);
                    v_integral = 0.0;
                } // for(q_atom)
            } // for(p_atom)
        } // for(j_atom)
    } // for(i_atom)
}
