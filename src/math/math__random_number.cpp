//
//
//
/// @param [in] seed A non-negative number.
//
/// @param [in] option An enum @c option for the GSL generator
///                    algorithms.
//
/// @brief Calculates a random number by means of the given @c
///        seed number and the chosen GSL random number generator.
//
/// @return A random number in the type requested.
//
template<typename data_type>
data_type random_number(const unsigned long int seed,
                        const unsigned int option)
{
//
/// @note Notice that the type of the random number should be specified
///       in the function call by the @c "class::function<output>(input)"
///       layout.
//
	gsl_rng *g;
	switch(option)
	{
		case     option::taus2: g = gsl_rng_alloc(gsl_rng_taus2);     break;
		case   option::mt19937: g = gsl_rng_alloc(gsl_rng_mt19937);   break;
		case   option::ranlxs0: g = gsl_rng_alloc(gsl_rng_ranlxs0);   break;
		case   option::ranlxs2: g = gsl_rng_alloc(gsl_rng_ranlxs2);   break;
		case   option::ranlxd2: g = gsl_rng_alloc(gsl_rng_ranlxd2);   break;
		case option::ranlux389: g = gsl_rng_alloc(gsl_rng_ranlux389); break;
		case     option::gfsr4: g = gsl_rng_alloc(gsl_rng_gfsr4);     break;
					   default: g = gsl_rng_alloc(gsl_rng_taus2);     break;
	}
	gsl_rng_set(g, seed);
	data_type number = gsl_rng_get(g);
	gsl_rng_free(g);
	return number;
};
//
//
//
/// @param [in] seed A non-negative number.
//
/// @brief Calculates a random number by means of a given @c
///        seed number, where the default GSL generator used
///        is the @c taus2.
//
/// @return A random number in the type requested.
//
template<typename data_type>
inline data_type random_number(const unsigned long int seed)
{
//
/// @note Notice that the type of the random number should be specified
///       in the function call by the @c "class::function<output>(input)"
///       layout.
//
	gsl_rng *g = gsl_rng_alloc(gsl_rng_taus2);
	gsl_rng_set(g, seed);
	data_type number = gsl_rng_get(g);
	gsl_rng_free(g);
	return number;
};
//
//
//
/// @brief Calculates a random number using the @c ctime member @c
///        time() as seed; and the GSL @c taus2 as g.
//
/// @return A random number of the type requested.
//
template<typename data_type>
inline data_type random_number()
{
//
/// @note Notice that the type of the random number should be specified
///       in the function call by the @c "class::function<output>(input)"
///       layout.
//
	gsl_rng *g = gsl_rng_alloc(gsl_rng_taus2);
	gsl_rng_set(g, (unsigned long int) time(NULL));
	data_type number = gsl_rng_uniform(g);
	gsl_rng_free(g);
	return number;
};
