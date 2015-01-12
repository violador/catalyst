#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::os_scheme(array &position,                        // The atomic positions onto one axis.
                                    const unsigned int &i_atom,             // The i-th atom.
                                    const unsigned int &j_atom,             // The j-th atom.
                                    const unsigned int &p_atom,             //
                                    const unsigned int &i_orbital_position, // The i-th atomic orbital onto one axis.
                                    const unsigned int &j_orbital_position, // The j-th atomic orbital onto one axis.
                                    const unsigned int &p_orbital_position, //
                                    const unsigned int &i_orbital_p,        // The p orbital position at the i-th atom.
                                    const double &i_exponent,               // The i-th gf exponent.
                                    const double &j_exponent,               // The j-th gf exponent.
                                    const double &p_exponent)
{
//
//  The orbital s = (0, 0, 0) case:
    switch((i_orbital_position == 0) 
           and (j_orbital_position == 0) 
           and (p_orbital_position == 0))
    {
        case true:
        tools get;
        double a = 0.0, b = 0.0, c = 0.0;
        #pragma omp parallel sections num_threads(3) 
        {
            #pragma omp section
            {
                a = std::sqrt(M_PI/(i_exponent + j_exponent + p_exponent));
            }
            #pragma omp section
            {
                b = gf_overlap(i_exponent,
                               j_exponent,
                               get.module(position(i_atom),
                                          position(j_atom)));
            }
            #pragma omp section
            {
                c = gf_overlap_factor(i_exponent + j_exponent,
                                                   p_exponent,
                                                   get.module(position(i_atom),
                                                              position(j_atom)));
            }
        }
//
//      S. Obara and A. Saika;
//      The Journal of Chemical Physics;
//      Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//      equation (21):
        return a*b*c;
        break;
    }
//
//  The general case:
    tools get;
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0, g = 0.0;
    #pragma omp parallel sections num_threads(7)
    {
        #pragma omp section
        {
            a = gf_product(i_exponent,
                           j_exponent,
                           p_exponent,
                           position(i_atom),
                           position(j_atom),
                           position(p_atom)) - position(i_atom);

        }
        #pragma omp section
        {
            b = overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 p_atom,
                                 i_orbital_position,
                                 j_orbital_position,
                                 p_orbital_position,
                                 i_exponent,
                                 j_exponent,
                                 p_exponent);
        }
        #pragma omp section
        {
            c = 1.0/(2.0*(i_exponent + j_exponent + p_exponent));
        }
        #pragma omp section
        {
            d = i_orbital_position
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 p_atom,
                                 i_orbital_position,
                                 j_orbital_position,
                                 p_orbital_position,
                                 i_exponent,
                                 j_exponent,
                                 p_exponent);
        }
        #pragma omp section
        {
            e = j_orbital_position
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 p_atom,
                                 i_orbital_position - ,
                                 j_orbital_position,
                                 p_orbital_position,
                                 i_exponent,
                                 j_exponent,
                                 p_exponent);
        }
        #pragma omp section
        {
            f = j_orbital_position
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 p_atom,
                                 i_orbital_position,
                                 j_orbital_position,
                                 p_orbital_position,
                                 i_exponent,
                                 j_exponent,
                                 p_exponent);
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (20):
    return a*b + c*d + c*e + c*f;
}
