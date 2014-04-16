// ../src/math/math__random_number.cpp ====================================================== //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
//
//
//
/// @param [in] seed A non-negative number
//
/// @param [in] option An enum @c option for the GSL generator
///                    algorithms
//
/// @brief Calculates a random number by means of the given @c
///        seed number and the chosen GSL random number generator.
//
/// @return A random number in the type requested.
//
/// @cite gsl
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
	gsl_rng *generator;
	switch(option)
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
	gsl_rng_set(generator, seed);
	data_type random_number = gsl_rng_get(generator);
	gsl_rng_free(generator);
	return random_number;
};
//
//
//
/// @param [in] seed A non-negative number
//
/// @brief Calculates a random number by means of a given @c
///        seed number, where the default GSL generator used
///        is the @c taus2.
//
/// @return A random number in the type requested.
//
/// @cite gsl
//
template<typename data_type>
inline data_type random_number(const unsigned long int seed)
{
//
/// @note Notice that the type of the random number should be specified
///       in the function call by the @c "class::function<output>(input)"
///       layout.
//
	gsl_rng *generator = gsl_rng_alloc(gsl_rng_taus2);
	gsl_rng_set(generator, seed);
	data_type random_number = gsl_rng_get(generator);
	gsl_rng_free(generator);
	return random_number;
};
//
//
//
/// @brief Calculates a random number using the @c ctime member @c
///        time() as seed; and the GSL @c taus2 as generator.
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
