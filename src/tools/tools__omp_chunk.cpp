//
//
//
/// @param [in] tasks The number of tasks.
//
/// @brief Divides the given number of tasks by the number of current OMP
///        threads in order to obtain the number of chunks per thread. It
///        will always be a nonnegative integer value. This function can
///        be found as argument in OMP clauses to setup the chunk size of
///        OMP dynamic schedule.
//
/// @return A nonnegative integer.
//
template <typename data_type>
inline unsigned int omp_chunk(const data_type &tasks)
{
	return convert<unsigned int>(tasks/omp_get_num_threads());
};
