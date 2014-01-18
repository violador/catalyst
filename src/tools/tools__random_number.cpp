// ../src/tools/tools__point_distance.cpp --------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
//
//
//
/// @author Humberto Jr. 
//
/// @date 07/2013
//
/// @return A random number by means of the given @c seed 
///         number and the @c GSL random number generator.
//
/// @cite
//
template<typename data_type>
data_type random_number(const unsigned long int seed, 
                        const unsigned int option)
{
//
//  (1) To allocate memory for the GSL random number generator.
//  (2) To define the given GSL random number generator.
//  (3) To seed the generator.
//  (4) To get the random number.
//  (5) To free the memory used by the generator.
    gsl_rng *generator; // (1)
    switch(option)      // (2)
    { 
        case     option::taus2: generator = gsl_rng_alloc(gsl_rng_taus2);     break;
        case   option::mt19937: generator = gsl_rng_alloc(gsl_rng_mt19937);   break;
        case   option::ranlxs0: generator = gsl_rng_alloc(gsl_rng_ranlxs0);   break;
        case   option::ranlxs2: generator = gsl_rng_alloc(gsl_rng_ranlxs2);   break;
        case   option::ranlxd2: generator = gsl_rng_alloc(gsl_rng_ranlxd2);   break;
        case option::ranlux389: generator = gsl_rng_alloc(gsl_rng_ranlux389); break;
        case     option::gfsr4: generator = gsl_rng_alloc(gsl_rng_gfsr4);     break;
                       default: generator = gsl_rng_alloc(gsl_rng_taus2);     break;
    }
    gsl_rng_set(generator, seed);                     // (3)
    data_type random_number = gsl_rng_get(generator); // (4)
    gsl_rng_free(generator);                          // (5)
    return random_number;
};
//
//
/// @author Humberto Jr. 
//
/// @date 07/2013
//
/// @return A random number by means of a given @c seed number.
///         The default @c GSL generator used is the @c taus2.
//
/// @cite
//
template<typename data_type>
inline data_type random_number(const unsigned long int seed)
{
//
//  (6) If not given the generator, to use by default the GSL taus2.
    gsl_rng *generator = gsl_rng_alloc(gsl_rng_taus2); // (6)
    gsl_rng_set(generator, seed);
    data_type random_number = gsl_rng_get(generator);
    gsl_rng_free(generator);
    return random_number;
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 07/2013
//
/// @return A random number. The default @c ctime member, @c time(), 
///         is used as seed; and the @c GSL @c taus2 is used as the 
///         generator.
//
/// @cite
//
template<typename data_type>
inline data_type random_number()
{
//
//  (7) If not given either the generator or the seed, to use by 
//      default the GSL taus2 and the ctime function time().
    gsl_rng *generator = gsl_rng_alloc(gsl_rng_taus2);
    gsl_rng_set(generator, (unsigned long int) time(NULL)); // (7)
    data_type random_number = gsl_rng_uniform(generator);
    gsl_rng_free(generator);
    return random_number;
};
