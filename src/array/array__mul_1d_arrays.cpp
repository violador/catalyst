//
//
//
/// @param [out] output A previously declared 1D array object.
//
/// @param [in] input A number of the same type of the current array.
//
/// @brief A private member function to scale the current array by the
///        @c input factor through the CBLAS library.
//
/// @return None.
//
inline void mul_1d_arrays(array<data_type, 1> &output, const data_type &input)
{
	cblas_dscal(output.rank1, input, output.data, 1);
	return;
};
//
//
//
/// @param [in] input1 A previously declared 1D array object.
//
/// @param [in] input2 A previously declared 1D array object.
//
/// @brief A private member function that calculates the scalar product
///        between the two given @c input1 and @c input2 arrays if the
///        first ranks lenght fits each other.
//
/// @return @f$ (A_{1} \cdot B_{1}) + (A_{2} \cdot B_{2}) + \ldots +
///         (A_{n} \cdot B_{n}) @f$, where @f$ n := @f$
///         @c array::first_rank().
//
inline data_type mul_1d_arrays(const array<data_type, 1> &input1,
                               const array<data_type, 1> &input2)
{
	switch(input1.rank1 == input2.rank1)
	{
		case false:
		{
			return 0.0;
		}
		case true:
		{
			return std::inner_product(input1.data,
			                          input1.data + input1.rank1,
			                          input2,
			                          (data_type) 0.0);
		}
	}
};
