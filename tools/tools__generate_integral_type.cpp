#include "tools.hpp"
//
//
//
unsigned long int tools::generate_integral_type(const unsigned long int seed, const unsigned int option)
{
    switch(option)
    { 
    case 1:  
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_taus2);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    } 
    break; // Tausworthe's generator (level 2).
    case 2:
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_mt19937);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    } 
    break; // Makoto Matsumoto and Takuji Nishimura's generator.
    case 3: 
    { 
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_ranlxs0);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    } 
    break; // Luscher's generator (level 0).
    case 4: 
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_ranlxs2);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    } 
    break; // Luscher's generator (level 2).
    case 5: 
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_ranlxd2);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    }
    break; // Luscher's generator (level 2) + double precision.
    case 6: 
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_ranlux389);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    }
    break; // Luscher + lagged-fibonacci-with-skipping algorithm.
    case 7:
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_gfsr4);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    }
    break; // lagged-fibonacci-like generator.
    default:
    {
        gsl_rng *random_number_generator = gsl_rng_alloc(gsl_rng_taus2);
        gsl_rng_set(random_number_generator, seed);
        unsigned long int random_number = gsl_rng_get(random_number_generator);
        gsl_rng_free(random_number_generator);
        return random_number;
    }
    break; // Default generator: Tausworthe's generator (level 2).
    }
}
