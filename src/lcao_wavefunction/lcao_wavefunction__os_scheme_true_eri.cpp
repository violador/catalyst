#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::os_scheme_true_eri(array &position,                    // The atomic positions onto one axis.
                                             const unsigned int &p_type_orbital, // The p-type component over the i-th atom.
                                             const unsigned int &i_atom,         // The i-th atom.
                                             const unsigned int &j_atom,         // The j-th atom.
                                             const unsigned int &p_atom,         // The p-th atom.
                                             const unsigned int &q_atom,         // The q-th atom.
                                             const unsigned int &i_orbital,      // The orbital component over the i-th atom.
                                             const unsigned int &j_orbital,      // The orbital component over the j-th atom.
                                             const unsigned int &p_orbital,      // The orbital component over the p-th atom.
                                             const unsigned int &q_orbital,      // The orbital component over the q-th atom.
                                             const double &i_exponent,           // The i-th gf exponent.
                                             const double &j_exponent,           // The j-th gf exponent.
                                             const double &p_exponent,           // The p-th gf exponent.
                                             const double &q_exponent)           // The q-th gf exponent.
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, 
           f = 0.0, g = 0.0, h = 0.0, i = 0.0, j = 0.0;
    #pragma omp parallel sections num_threads(10)
    {
        #pragma omp section
        {
            a = gf_product(i_exponent,
                           j_exponent,
                           position(i_atom),
                           position(j_atom)) - position(i_atom);
        }
        #pragma omp section
        {
            b = os_scheme_aux_eri(position,
                                  order,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital,
                                  j_orbital,
                                  p_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
        }
        #pragma omp section
        {
            c = gf_overlap_product(i_exponent,
                                   j_exponent,
                                   p_exponent,
                                   q_exponent,
                                   position(i_atom),
                                   position(j_atom),
                                   position(p_atom),
                                   position(q_atom)) - gf_product(i_exponent,
                                                                  j_exponent,
                                                                  position(i_atom),
                                                                  position(j_atom));
        }
        #pragma omp section
        {
            d = os_scheme_aux_eri(position,
                                  order + 1,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital,
                                  j_orbital,
                                  p_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
        }
        #pragma omp section
        {
            e = os_scheme_aux_eri(position,
                                  order,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital - p_type_orbital,
                                  j_orbital,
                                  p_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
        }
        #pragma omp section
        {
            f = os_scheme_aux_eri(position,
                                  order + 1,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital - p_type_orbital,
                                  j_orbital,
                                  p_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
            f *= (i_exponent + j_exponent)*(p_exponent + q_exponent);
            f /= i_exponent + j_exponent + p_exponent + q_exponent;
            f /= i_exponent + j_exponent;
        }
        #pragma omp section
        {
            g = os_scheme_aux_eri(position,
                                  order,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital,
                                  j_orbital - p_type_orbital,
                                  p_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
        }
        #pragma omp section
        {
            h = os_scheme_aux_eri(position,
                                  order + 1,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital,
                                  j_orbital - p_type_orbital,
                                  p_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
            h *= (i_exponent + j_exponent)*(p_exponent + q_exponent);
            h /= i_exponent + j_exponent + p_exponent + q_exponent;
            h /= i_exponent + j_exponent;
        }
        #pragma omp section
        {
            i = os_scheme_aux_eri(position,
                                  order + 1,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital,
                                  j_orbital,
                                  p_orbital - p_type_orbital,
                                  q_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
            i *= p_orbital/2.0*(i_exponent + j_exponent + p_exponent + q_exponent);
        }
        #pragma omp section
        {
            j = os_scheme_aux_eri(position,
                                  order + 1,
                                  p_type_orbital,
                                  i_atom,
                                  j_atom,
                                  p_atom,
                                  q_atom,
                                  i_orbital,
                                  j_orbital,
                                  p_orbital,
                                  q_orbital - p_type_orbital,
                                  i_exponent,
                                  j_exponent,
                                  p_exponent,
                                  q_exponent);
            j *= q_orbital/2.0*(i_exponent + j_exponent + p_exponent + q_exponent);
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (39):
    return a*b + c*d 
               + (e - f)*i_orbital/2.0*(i_orbital + j_orbital)
               + (g - h)*j_orbital/2.0*(i_orbital + j_orbital)
               + i
               + j;
}
