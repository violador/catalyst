//
//
//
/// @brief The default constructor used to declare with no defined shape
///        and no allocated memory. Before use the object constructed in
///        such a way, i.e. not previously initialized, the @c
///        array::create() member function should be invoked first to
///        allocate memory and to define the array dimensionality.
//
#if CURRENT_RANK == 1
	constexpr explicit array(): data(NULL),
	                            rank1(0)
	{
	};
#endif
//
//
//
/// @brief The default constructor used to declare with no defined shape
///        and no allocated memory. Before use the object constructed in
///        such a way, i.e. not previously initialized, the @c
///        array::create() member function should be invoked first to
///        allocate memory and to define the array dimensionality.
//
#if CURRENT_RANK == 2
	constexpr explicit array(): data(NULL),
	                            rank1(0),
	                            rank2(0)
	{
	};
#endif
//
//
//
/// @brief The default constructor used to declare with no defined shape
///        and no allocated memory. Before use the object constructed in
///        such a way, i.e. not previously initialized, the @c
///        array::create() member function should be invoked first to
///        allocate memory and to define the array dimensionality.
//
#if CURRENT_RANK == 3
	constexpr explicit array(): data(NULL),
	                            rank1(0),
	                            rank2(0),
	                            rank3(0)
	{
	};
#endif
//
//
//
/// @brief The default constructor used to declare with no defined shape
///        and no allocated memory. Before use the object constructed in
///        such a way, i.e. not previously initialized, the @c
///        array::create() member function should be invoked first to
///        allocate memory and to define the array dimensionality.
//
#if CURRENT_RANK == 4
	constexpr explicit array(): data(NULL),
	                            rank1(0),
	                            rank2(0),
	                            rank3(0),
	                            rank4(0)
	{
	};
#endif
//
//
//
/// @param [in] size1 Length for the first rank.
//
/// @brief The constructor used to declare a rank one array. The memory
///        is allocated and initialized to zero, by default. If for
///        some reason there is no memory available the array remains
///        uninitialized and any attempt to use it may imply segmentation
///        fault or any C++ out of range standard error. To check if the
///        object was well constructed the array::is_ready() can be used.
//
#if CURRENT_RANK == 1
	inline explicit array(unsigned int size1): data(NULL),
	                                           rank1(size1)
	{
		if(!init_data())
		{
			reset_data_members();
		}
	};
#endif
//
//
//
/// @param [in] size1 Length for the first rank.
//
/// @param [in] size2 Length for the second rank.
//
/// @brief The constructor used to declare a rank two array. The memory
///        is allocated and initialized to zero, by default. If for
///        some reason there is no memory available the array remains
///        uninitialized and any attempt to use it may imply segmentation
///        fault or any C++ out of range standard error. To check if the
///        object was well constructed the array::is_ready() can be used.
//
#if CURRENT_RANK == 2
	inline explicit array(unsigned int size1,
	                      unsigned int size2): data(NULL),
	                                           rank1(size1),
	                                           rank2(size2)
	{
		if(!init_data())
		{
			reset_data_members();
		}
	};
#endif
//
//
//
/// @param [in] size1 Length for the first rank.
//
/// @param [in] size2 Length for the second rank.
//
/// @param [in] size3 Length for the third rank.
//
/// @brief The constructor used to declare a rank three array. The memory
///        is allocated and initialized to zero, by default. If for
///        some reason there is no memory available the array remains
///        uninitialized and any attempt to use it may imply segmentation
///        fault or any C++ out of range standard error. To check if the
///        object was well constructed the array::is_ready() can be used.
//
#if CURRENT_RANK == 3
	inline explicit array(unsigned int size1,
	                      unsigned int size2,
	                      unsigned int size3): data(NULL),
	                                           rank1(size1),
	                                           rank2(size2),
	                                           rank3(size3)
	{
		if(!init_data())
		{
			reset_data_members();
		}
	};
#endif
//
//
//
/// @param [in] size1 Length for the first rank.
//
/// @param [in] size2 Length for the second rank.
//
/// @param [in] size3 Length for the third rank.
//
/// @param [in] size4 Length for the fourth rank.
//
/// @brief The constructor used to declare a rank four array. The memory
///        is allocated and initialized to zero, by default. If for
///        some reason there is no memory available the array remains
///        uninitialized and any attempt to use it may imply segmentation
///        fault or any C++ out of range standard error. To check if the
///        object was well constructed the array::is_ready() can be used.
//
#if CURRENT_RANK == 4
	inline explicit array(unsigned int size1,
	                      unsigned int size2,
	                      unsigned int size3,
	                      unsigned int size4): data(NULL),
	                                           rank1(size1),
	                                           rank2(size2),
	                                           rank3(size3),
	                                           rank4(size4)
	{
		if(!init_data())
		{
			reset_data_members();
		}
	};
#endif
//
//
//
/// @param [in] A previously declared 1D array object.
//
/// @brief The copy constructor...
//
#if CURRENT_RANK == 1
	array<data_type, 1>(const array_type &input): data(NULL),
	                                              rank1(input.rank1)
	{
		if(init_data())
		{
			#pragma omp master
			std::copy(input.data, input.data_end(), data);
		}
		else
		{
			reset_data_members();
		}
	};
#endif
//
//
//
#if CURRENT_RANK == 2
	array<data_type, 2>(const array_type &input): data(NULL),
	                                              rank1(input.rank1),
	                                              rank2(input.rank2)
	{
		if(init_data())
		{
			#pragma omp master
			std::copy(input.data, input.data_end(), data);
		}
		else
		{
			reset_data_members();
		}
	};
#endif
//
//
//
#if CURRENT_RANK == 3
	array<data_type, 3>(const array_type &input): data(NULL),
	                                              rank1(input.rank1),
	                                              rank2(input.rank2),
	                                              rank3(input.rank3)
	{
		if(init_data())
		{
			#pragma omp master
			std::copy(input.data, input.data_end(), data);
		}
		else
		{
			reset_data_members();
		}
	};
#endif
//
//
//
#if CURRENT_RANK == 4
	array<data_type, 4>(const array_type &input): data(NULL),
	                                              rank1(input.rank1),
	                                              rank2(input.rank2),
	                                              rank3(input.rank3),
	                                              rank4(input.rank4)
	{
		if(init_data())
		{
			#pragma omp master
			std::copy(input.data, input.data_end(), data);
		}
		else
		{
			reset_data_members();
		}
	};
#endif
//
//
//
/// @param [in] A previously declared 1D array object.
//
/// @brief The move constructor...
//
#if CURRENT_RANK == 1
	inline array<data_type, 1>(array_type &&input): data(input.data),
	                                                rank1(input.rank1)
	{
		input.reset_data_members();
	};
#endif
//
//
//
#if CURRENT_RANK == 2
	inline array<data_type, 2>(array_type &&input): data(input.data),
	                                                rank1(input.rank1),
	                                                rank2(input.rank2)
	{
		input.reset_data_members();
	};
#endif
//
//
//
#if CURRENT_RANK == 3
	inline array<data_type, 3>(array_type &&input): data(input.data),
	                                                rank1(input.rank1),
	                                                rank2(input.rank2),
	                                                rank3(input.rank3)
	{
		input.reset_data_members();
	};
#endif
//
//
//
#if CURRENT_RANK == 4
	inline array<data_type, 4>(array_type &&input): data(input.data),
	                                                rank1(input.rank1),
	                                                rank2(input.rank2),
	                                                rank3(input.rank3),
	                                                rank4(input.rank4)
	{
		input.reset_data_members();
	};
#endif
