//
//
//
/// @param [out] output A previously declared 1D array object.
//
/// @param [in] input A number of the same type of the current array.
//
/// @brief A private member function to add the given constant @c input to all
///        the elements.
//
/// @return None.
//
inline void add_1d_arrays(array<data_type, 1> &output, const data_type &input)
{
	auto add = [&input](data_type &iter)
	{
		iter += input;
	};
	std::for_each(output.data, output.data + output.rank1, add);
	return;
};
//
//
//
/// @param [out] output A previously declared 1D array object.
//
/// @param [in] input A previously declared 1D array object.
//
/// @param [in] scale_factor A numeric data (optional).
//
/// @brief A private member function to add the given @c input array to
///        the given @c output one if the first ranks fits each other.
///        The summmation is done through the CBLAS library.
//
/// @return None.
//
inline void add_1d_arrays(array<data_type, 1> &output,
                          const array<data_type, 1> &input,
						  const data_type scale_factor = 1.0)
{
	switch(output.rank1 == input.rank1)
	{
		case true:
		cblas_daxpy(input.rank1,
		            scale_factor,
		            input.data,
		            1,
		            output.data,
		            1);
		return;
	}
};
