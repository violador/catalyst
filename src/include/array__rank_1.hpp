//
//
//
template<typename data_type>
class array<data_type, 1>
{
	public:
//
// ==========================
// The array<data_type, 1> ID
// ==========================
//
	static const unsigned int id = 2431;
//
// =============================================
// Declaring and defining the class constructors
// =============================================
//
//
//
/// @brief The default constructor used to declare 1D arrays objects
///        with no defined shape and no allocated memory. Before use
///        any object constructed in such way, i.e. not previously
///        initialized, the @c array::create() member function should
///        be invoked first to allocate memory and define the array
///        shape.
//
	explicit inline array(): rank1(0),
	                         data(NULL)
	{
	};
//
//
//
/// @param [in] size The rank length.
//
/// @brief The constructor used to declare 1D arrays objects with @c
///        size length. The memory is allocated by default and the
///        elements are initialized to zero. To check if the current
///        array was well constructed, the array::is_ready() member
///        function can be used. To free the used memory, the
///        array::clear() member should be invoked and the result is
///        an array object as constructed by the default constructor.
///        Any attempt to reuse it will need to reallocate the memory
///        first by means of the array::create() function.
//
	explicit array(const unsigned int &size): data(new (std::nothrow) data_type[size]()),
	                                          rank1(size)
	{
		switch(data == NULL)
		{
			case true: rank1 = 0;
		}
	};
//
//
//
/// @param [in] A previously declared 1D array object.
//
/// @brief The copy constructor...
//
	explicit array(const array<data_type, 1> &input): rank1(0),
	                                                  data(NULL)
	{
		switch(input.data != NULL)
		{
			case true:
			data = new (std::nothrow) data_type[input.rank1]();
			switch(this -> data != NULL)
			{
				case true:
				std::copy(input.data, input.data_end(), this -> data);
				rank1 = input.rank1;
			}
		}
	};
//
// ===========================================
// Declaring and defining the class destructor
// ===========================================
//
	~array()
	{
		switch(data != NULL)
		{
			case true: delete[] data;
		}
	};
//
// =============================
// Declaring the class operators
// =============================
//
/*
	void  operator +=(const array &a);
	void  operator -=(const array &a);
	void  operator *=(const array &a);
*/
//
//
//
/// @param [in] i The array element.
//
/// @brief Returns the current value in the @f$ A_{i} @f$ element.
///        This function does not checks the array bounds. If the
///        given element is out of range, it throws the standard
///        C/C++ out of range error (and/or segmentation fault).
//
/// @return A numerical data of the same type of the current array.
//
	inline data_type &operator ()(const unsigned int &i) const
	{
		return data[offset(i)];
	};
//
//
//
/// @param [in] i The array element.
//
/// @param [in] input The element new value.
//
/// @brief Sets the given @c input in the @f$ A_{i} @f$ element.
///        This function does not checks the array bounds. If the
///        given element is out of range, it throws the standard
///        C/C++ out of range error (and/or segmentation fault).
//
/// @return None.
//
	inline void operator ()(const unsigned int &i,
                            const data_type &input)
	{
		data[offset(i)] = input;
	};
//
//
//
/// @param [in] input A previously declared 1D array object.
//
/// @brief The operator @c = is used to copy the elements from the
///        given @c input array to the current one. If the current
///        size is not either equal or grater than the @c input
///        one, the object is going to be resized on-the-fly. Thus,
///        for performance reasons, is always recommended to use an
///        operator between objects of the same size. If any of the
///        arrays are not previously initialized by the constructor
///        or the array::create() member function, nothing is done.
//
/// @return None.
//
	inline void operator =(const array<data_type, 1> &input)
	{
		switch(this -> data != NULL && input.data != NULL)
		{
			case true:
			copy_1d_arrays(this, input);
			return;
		}
	};
//
//
//
/// @param [in] input A real number.
//
/// @brief The operator @c + applied between an 1D array object (at
///        left) and a number of the same data type (at right), adds
///        the given number to all the elements of the array. Such
///        operation takes place only if the current array was
///        previously initialized either by the constructor or the
///        array::create() member function.
//
/// @return An 1D array object (by value).
//
	inline array operator +(const data_type &input)
	{
		array<data_type, 1> output = *this;
		switch(data != NULL)
		{
			case true: add_1d_arrays(output, input);
		}
		return output;
	};
//
//
//
/// @param [in] input A real number.
//
/// @brief The operator @c - applied between an 1D array object (at
///        left) and a number of the same data type (at right), subs
///        the given number to all the elements of the array. Such
///        operation takes place only if the current array was
///        previously initialized either by the constructor or the
///        array::create() member function.
//
/// @return An 1D array object (by value).
//
	inline array operator -(const data_type &input)
	{
		array<data_type, 1> output = *this;
		switch(data != NULL)
		{
			case true: add_1d_arrays(output, -input);
		}
		return output;
	};
//
//
//
/// @param [in] input A real number.
//
/// @brief The operator @c * applied between an 1D array object (at
///        left) and a number of the same data type (at right), scales
///        the current array by the given factor. Such operation takes
///        place only if the current array was previously initialized
///        either by the constructor or the array::create() member
///        function.
//
/// @return An 1D array object (by value).
//
	inline array operator *(const data_type &input)
	{
		array<data_type, 1> output = *this;
		switch(data != NULL)
		{
			case true: mul_1d_arrays(output, input);
		}
		return output;
	};
//
//
//
/// @param [in] input A real number.
//
/// @brief The operator @c / applied between an 1D array object (at
///        left) and a number of the same data type (at right), divides
///        the current array by the given factor. Such operation takes
///        place only if the current array was previously initialized
///        either by the constructor or the array::create() member
///        function.
//
/// @return An 1D array object (by value).
//
	inline array operator /(const data_type &input)
	{
		array<data_type, 1> output = *this;
		switch(data != NULL)
		{
			case true: mul_1d_arrays(output, 1.0/input);
		}
		return output;
	};
//
//
//
/// @param [in] input A previously declared 1D array object.
//
/// @brief The operator @c + applied between two 1D array objects adds
///        them in a new 1D array. Such operation takes place only if
///        both objects were previously initialized either by the
///        constructor or the array::create() member function. In the
///        cases that the first ranks length doesn't fits each other,
///        nothing is done.
//
/// @return An 1D array object (by value).
//
	inline array operator +(const array<data_type, 1> &input)
	{
		array<data_type, 1> output = *this;
		switch(output.data != NULL && input.data != NULL)
		{
			case true: add_1d_arrays(output, input);
		}
		return output;
	};
//
//
//
/// @param [in] input A real number.
//
/// @brief The operator @c - applied between two 1D array objects subs
///        them in a new 1D array. Such operation takes place only if
///        both objects were previously initialized either by the
///        constructor or the array::create() member function. In the
///        cases that the first ranks length doesn't fits each other,
///        nothing is done.
//
/// @return An 1D array object (by value).
//
	inline array operator -(const array<data_type, 1> &input)
	{
		array<data_type, 1> output = *this;
		switch(output.data != NULL && input.data != NULL)
		{
			case true: add_1d_arrays(output, input, -1.0);
		}
		return output;
	};
//
//
//
/// @param [in] input A real number.
//
/// @brief The operator @c * applied between two 1D array objects returns the
///        scalar product between them. Such operation takes place only if both
///        objects were previously initialized either by the constructor or the
///        array::create() member function. In the cases that the first ranks
///        length doesn't fits each other, it returns zero.
//
/// @return @f$ (A_{1} \cdot B_{1}) + (A_{2} \cdot B_{2}) + \ldots +
///         (A_{n} \cdot B_{n}) @f$, where @f$ n := @f$ array::first_rank().
//
	inline data_type operator *(const array<data_type, 1> &input)
	{
		switch(this -> data != NULL && input.data != NULL)
		{
			case false: return 0.0;
			case  true: return mul_1d_arrays(this, input);
		}
	};
//
//
//
// =====================================================
// Including the inline/template/public member functions
// =====================================================
//
	#include "array__norm.cpp"
//
// ==============================================================
// Declaring and defining the specialized/public member functions
// ==============================================================
//
//
/// @param [in] size The first rank length.
//
/// @brief This member function is designed to those cases when
///        the array object was declared without the bounds and
///        do not have any memory allocated. Thus, before to be
///        used, array::create() will allocate memory and setup
///        all the elements to zero. In the cases of an already
///        allocated array object, any attempt to resize it
///        should be done through the array::resize() instead.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
	inline int create(unsigned int &size)
	{
		switch(data == NULL)
		{
			case false: return EXIT_FAILURE;
			case  true: return init_data(size);
		}
	};
//
//
//
/// @param [in] size The first rank length.
//
/// @brief This member function will resize the current object if
///        it was previously properly initialized either by the
///        constructor or by the array::create() member function.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
	inline int resize(const unsigned int &new_size)
	{
		switch(data != NULL && rank1 != new_size)
		{
			case false:
			{
				return EXIT_FAILURE;
			}
			case true:
			{
				delete_data();
				return init_data(new_size);
			}
		}
	};
//
//
//
/// @brief Returns the current dimensionality.
//
/// @return A nonnegative integer number.
//
	inline short unsigned int rank() const
	{
		return 1;
	};
//
//
//
/// @brief Returns the length of the first rank.
//
/// @return A nonnegative integer number.
//
	inline unsigned int first_rank() const
	{
		return rank1;
	};
//
//
//
/// @brief Returns the length of the second rank.
//
/// @return A nonnegative integer number.
//
	inline unsigned int second_rank() const
	{
		return 0;
	};
//
//
//
/// @brief Returns the length of the third rank.
//
/// @return A nonnegative integer number.
//
	inline unsigned int third_rank() const
	{
		return 0;
	};
//
//
//
/// @brief Returns the length of the fourth rank.
//
/// @return A nonnegative integer number.
//
	inline unsigned int fourth_rank() const
	{
		return 0;
	};
//
//
//
/// @brief Returns the length of the fourth rank.
//
/// @return A nonnegative integer number.
//
	inline bool is_ready() const
	{
		return (data != NULL);
	};
//
//
//
/// @param [in] i The array element.
//
/// @param [in] input The element new value.
//
/// @brief Sets the given @c input in the @f$ A_{i} @f$ element,
///        checking if it is inside the array length. To avoid
///        the bounds check-in, the operator @c () can be uesd
///        instead.
//
/// @return None.
//
	inline void set(const unsigned int &i,
	                const data_type &input)
	{
		switch(offset(i) < rank1)
		{
			case true:
			data[offset(i)] = input;
			return;
		}
	};
//
//
//
/// @param [in] i The array element.
//
/// @brief Returns the @f$ A_{i} @f$ element, checking if it is
///        inside the array length. To avoid the bounds check-in,
///        the operator @c '()' can be used instead.
//
/// @return A numerical data of the same type of the current array.
//
	inline data_type get(const unsigned int &i)
	{
		switch(offset(i) < rank1)
		{
			case false: return 0.0;
			case  true: return data[offset(i)];
		}
	};
//
//
//
/// @param [in] input A new value for all the elements.
//
/// @brief Sets the given @c input in all the elements, if the array
///        was previously initialized either by the constructor or
///        the array::create() member function. Otherwise nothing is
///        really done.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
	inline int set_all(const data_type &input)
	{
		switch(data != NULL)
		{
			case false:
			{
				return EXIT_FAILURE;
			}
			case true:
			{
				std::fill(data, data_end(), input);
				return EXIT_SUCCESS;
			}
		}
	};
//
//
//
/// @brief Sets zero in all the elements, if the array was previously
///        initialized either by the constructor or the array::create()
///        member function. Otherwise nothing is really done.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
	inline int set_zero()
	{
		switch(data != NULL)
		{
			case false:
			{
				return EXIT_FAILURE;
			}
			case true:
			{
				std::fill(data, data_end(), data_type(0.0));
				return EXIT_SUCCESS;
			}
		}
	};
//
//
//
/// @brief If the current array was previously initialized,
///        either by the constructor or the array::create()
///        member function, array::clear() will delete the
///        current data, deallocating the memory used. After
///        this, to use the object again, array::create()
///        should be invoked first, to reallocate the memory.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
/// @note Please notice, this member function does not replace
///       the class destructor that is going to be called by
///       default in the right moment. The main usage of this
///       function is to free memory when desired.
//
	inline int clear()
	{
		switch(data != NULL)
		{
			case false: return EXIT_FAILURE;
			case  true: return delete_data();
		}
	};
//
//
//
	inline int move_to(array<data_type, 1> &output)
	{
		return move_1d_arrays(output, this);
	}
/*
//
//
//
/// @param [in] input A previously declared 1D array object.
//
/// @brief This member function makes the current array to see
///        the content of the given @c input one as its own. In
///        such case the current array works as (it is indeed)
///        a pointer to the given one. This solution is a
///        replacement to explicit calls of the operator @c =
///        which implies the bottleneck of copy the entire array
///        and to have twice data at memory. It works only for
///        objects that were not previously initialized either by
///        the constructor or the array::create() member function;
///        and for @c input that was previously initialized. For
///        well initialized objects, the member @c array::clear()
///        should be invoked first to delete themselves.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
/// @note Please notice, after calls of this member function, the
///       current array objects has the full control over the @c
///       input one, and all the member functions called from now
///       on are going to work directly on @c input. Also any
///       external changes in @c input changes the state of the
///       current object. If the @c input is deleted this array
///       is just an usual not initialized array that can be used
///       invoking the @c array::create() member function.
//
	inline int view(array<data_type, 1> &input)
	{
		switch(this -> data == NULL && input.data != NULL)
		{
			case false:
			{
				return EXIT_FAILURE;
			}
			case true:
			{
				this -> data = input.data;
				this -> rank1 = input.rank1;
				return EXIT_SUCCESS;
			}
		}
	};
*/
//
//
//
/// @brief If the current array was previously initialized, either
///        by the constructor or the array::create() member function,
///        array::build_randomly() replaces the data by random numbers
///        generated in the range between zero and five times the rank
///        size.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
	inline int build_randomly()
	{
		switch(data != NULL)
		{
			case false: return EXIT_FAILURE;
			case  true: return random_1d_array();
		}
	};
//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::min()
///        returns the smaller element. Or returns zero, otherwise.
//
/// @return A numerical data of the same type of the current array.
//
	inline data_type min() const
	{
		switch(data != NULL)
		{
			case false: return data_type(0.0);
			case  true: return *std::min_element(data, data_end());
		}
	};
//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::max()
///        returns the higher element. Or returns zero, otherwise.
//
/// @return A numerical data of the same type of the current array.
//
	inline data_type max() const
	{
		switch(data != NULL)
		{
			case false: return data_type(0.0);
			case  true: return *std::max_element(data, data_end());
		}
	};
//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::sort()
///        sorts the current values in some order.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
	inline int sort()
	{
		switch(data != NULL)
		{
			case false:
			{
				return EXIT_FAILURE;
			}
			case true:
			{
				std::sort(data, data_end());
				return EXIT_SUCCESS;
			}
		}
	};
//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::sum()
///        returns the summation of all the elements. Or returns zero,
///        otherwise.
//
/// @return A numerical data of the same type of the current array.
//
	inline data_type sum()
	{
		switch(data != NULL)
		{
			case false: return 0.0;
			case  true: return std::accumulate(data, data_end(), data_type(0.0));
		}
	};
//
//
	inline void write()
	{
		//write_1d_array();
		return;
	};
//
//
	std::string save(const std::string &dir, const std::string &comment = "")
	{
		std::fstream txt_file, bin_file;
		std::string filename = dir + build_filename();
		std::string txt_filename = filename + TXT_FILE_EXTENSION;
		std::string bin_filename = filename + BIN_FILE_EXTENSION;
		txt_file.std::fstream::open(txt_filename.std::string::c_str(), std::fstream::out);
		bin_file.std::fstream::open(bin_filename.std::string::c_str(), std::fstream::out | std::ios::binary);
		switch(txt_file.std::fstream::is_open() && txt_file.std::fstream::good()
		       && bin_file.std::fstream::is_open() && bin_file.std::fstream::good())
		{
			case true:
			#pragma omp sections nowait
			{
				#pragma omp section
				{
					bin_file.std::fstream::write((char*) &data + rank1, sizeof(data_type));
					bin_file.std::fstream::close();
				}
				#pragma omp section
				{
					txt_file << typeid(data_type).name() // 1) The data type
					         << std::endl
					         << bin_filename             // 2) The bin filename
					         << std::endl
					         << data_length()            // 3) The real internal length
					         << std::endl
					         << rank()                   // 4) The rank
					         << std::endl
					         << comment;                 // 5) A optional comment
/*
					txt_file << "\ndata    = " << bin_filename
					         << "\nsize    = " << data_length()
					         << "\nrank    = " << rank()
					         << "\ntype    = " << typeid(data_type).name()
					         << "\ncomment = " << comment;
*/
					txt_file.std::fstream::close();
				}
			}
			return txt_filename;
		}
		txt_file.std::fstream::close();
		bin_file.std::fstream::close();
		return "";
	};
//
//
	inline int load(const std::string &txt_filename)
	{
		switch(data == NULL)
		{
			case true:
			txt_file.std::fstream::open(txt_filename.std::string::c_str(), std::fstream::in);
			switch(txt_file.std::fstream::is_open() && txt_file.std::fstream::good())
			{
				case true:
				//
				std::string type_name;
				txt_file >> type_name;
				switch(typeid(data_type).name() != type_name)
				{
					case true: return EXIT_FAILURE;
				}
				std::string bin_filename;
				txt_file >> bin_filename;
			}
		}
		return EXIT_FAILURE;
	};
//
//
//
/// @brief Checks if all the elements of the current array are zero.
//
/// @return @c true if all the elements are zero or if the current
///         array was not previously initialized by the constructor
///         or the array::create() member funtion. @c false
///         otherwise.
//
	inline bool is_null() const
	{
		auto check = [](int iter)
		{
			return (iter == 0.0);
		};
		switch(data != NULL)
		{
			case false: return true;
			case  true: return std::all_of(data, data_end(), check);
		}
	};
//
//
//
/// @brief Checks if all the elements of the current array are positive,
///        including zero as an unsigned number, i.e. nonegative.
//
/// @return @c true if all the elements are positive, @c false otherwise,
///         or if the current array was not previously initialized by the
///         constructor or the array::create() member funtion.
//
	inline bool is_positive() const
	{
		auto check = [](int iter)
		{
			return (iter >= 0.0);
		};
		switch(data != NULL)
		{
			case false: return false;
			case  true: return std::all_of(data, data_end(), check);
		}
	};
//
//
//
/// @brief Checks if all the elements of the current array are negative.
//
/// @return @c true if all the elements are negative, @c false otherwise,
///         or if the current array was not previously initialized by the
///         constructor or the array::create() member funtion.
//
	inline bool is_negative() const
	{
		auto check = [](int iter)
		{
			return (iter < 0.0);
		};
		switch(data != NULL)
		{
			case false: return false;
			case  true: return std::all_of(data, data_end(), check);
		}
	};
//
//
//
/// @brief Checks if at least one element of the current array is a @c nan,
///        i.e. not-a-number, like @c '0/0' or @c 'std::sqrt(-1)'.
//
/// @return @c true if it has one or more @c nan, @c false otherwise.
//
	inline bool has_nan() const
	{
		auto check = [](int iter)
		{
			return std::isnan(iter);
		};
		switch(data != NULL)
		{
			case false: return false;
			case  true: return std::any_of(data, data_end(), check);
		}
	};
//
//
//
	private:
//
// ==================================
// Declaring the private data members
// ==================================
//
	data_type *data;
	unsigned int rank1;
//
// ======================================================
// Including the inline/template/private member functions
// ======================================================
//
	#include "array__init_1d_array.cpp"
	#include "array__delete_1d_array.cpp"
	#include "array__build_filename.cpp"
	#include "array__add_1d_arrays.cpp"
	#include "array__mul_1d_arrays.cpp"
	#include "array__copy_1d_arrays.cpp"
	#include "array__random_1d_array.cpp"
	#include "array__resize_1d_array.cpp"
	#include "array__move_1d_arrays.cpp"
//
// ===============================================================
// Declaring and defining the specialized/private member functions
// ===============================================================
//
//
//
/// @brief A help function used to calculate the real position of
///        a given element, since even the higher rank arrays are
///        common C vectors. Please notice that the arguments are
///        given by value and not by reference, in such way we can
///        safely change it.
//
/// @return @f$ := i - 1 @f$
//
	inline unsigned int offset(unsigned int i) const
	{
		return (--i);
	};
//
//
//
/// @brief A help function used to check the pointer pointing the
//         end of the array. The pointer for the begin is the @c
//         data or @c data[0] itself.
//
/// @return A pointer of the same type of the current array.
//
	inline data_type *data_end() const
	{
		return data + rank1;
	};
//
//
//
/// @brief A help function used to check the internal real length
///        of the given array.
//
/// @return A nonnegative integer.
//
	inline unsigned int data_length() const
	{
		return rank1;
	};
//
//
//
/// @param [in] size The first rank length.
//
/// @brief A help function to allocate memory for a rank one array.
//
/// @return @c EXIT_SUCCESS if the allocation was successful, and
///         @c EXIT_FAILURE otherwise.
//
	inline int init_data(const unsigned int &size)
	{
		data = new (std::nothrow) data_type[size]();
		switch(data != NULL)
		{
			case false:
			{
				return EXIT_FAILURE;
			}
			case true:
			{
				rank1 = size;
				return EXIT_SUCCESS;
			}
		}
	};
//
//
//
/// @brief A help function to deallocate the current memory and to set
///        zero the rank's lengths.
//
/// @return @c EXIT_SUCCESS.
//
	inline int delete_data()
	{
		delete[] data;
		data = NULL;
		rank1 = 0;
		return EXIT_SUCCESS;
	};
};
