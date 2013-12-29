//
//
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
template<typename data_type>
inline data_type random_number()
{
//
//  (7) If not given either the generator or the seed, 
//      to use by default the GSL taus2 and the ctime 
//      function time().
    gsl_rng *generator = gsl_rng_alloc(gsl_rng_taus2);
    gsl_rng_set(generator, (unsigned long int) time(NULL)); // (7)
    data_type random_number = gsl_rng_uniform(generator);
    gsl_rng_free(generator);
    return random_number;
};
