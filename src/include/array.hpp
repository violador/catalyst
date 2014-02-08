// ../src/include/array.hpp ------------------------------------------------------------- //
//
// File author: Humberto Jr.
//
// Date: 07/2013
//
// Description: The array class defines the type of variables used to easily handle
//              1D, 2D, 3D and 4D arrays. The 1D and 2D types has most of its oper-
//              ations handled by the GSL library. This operations includes linear
//              algebra tasks by an user given CBLAS interface. If not given, the
//              installed GSL lib provides its own CBLAS. Some of the member funct-
//              ions are designed to some sort of arrays only. Its usage also may
//              or may not change internal properties of an array and it will chan-
//              ge the behavior of the following members. These properties can be
//              turned on or off by the respective setter. For instance the members
//              array::set_constant() and array::unset_constant() allows or not the
//              given array to be rewritten. The arithmetic operators "+", "-", "*"
//              and "/" are overloaded to recognize operations between number types
//              or arrays types (1D and 2D only). In the array types operations so-
//              me common properties like dimension sizes will be checked first.
//
/// @cite gsl
//
// ------------------------------------------------------------------------------------- //
#ifndef __ARRAY_HPP
    #define __ARRAY_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "global_settings.hpp"
    #include "tools.hpp"
    #include "global_log.hpp"
    #include "file_system.hpp"
//
//
//
struct array
{
    protected:
//
//  Declaring the data members:
    unsigned int sizeof_row;       // The size of row.
    unsigned int sizeof_column;    // The size of column.
    unsigned int sizeof_1st_layer; // The size of first layer.
    unsigned int sizeof_2nd_layer; // The size of second layer.
    unsigned int array_id;         // To tag the current array.
    bool is_1d_array;              // True, if it is a 1D array, false otherwise.
    bool is_2d_array;              // True, if it is a 2D array, false otherwise.
    bool is_3d_array;              // True, if it is a 3D array, false otherwise.
    bool is_4d_array;              // True, if it is a 4D array, false otherwise.
    bool is_const_array;           // True, if it is a constant array, false otherwise.
    bool is_square_array;          // True, if it is a square array, false otherwise.
    bool is_transposed;            // True, if it is a transposed array, false otherwise.
    bool deleted_array;            // True, if it was deleted already by delete_array(), false otherwise.
    double    *user_1d_array;      // The current user's 1D array.
    double    *user_2d_array;      // The current user's 2D array.
    double  ***user_3d_array;      // The current user's 3D array.
    double ****user_4d_array;      // The current user's 4D array.
    gsl_vector_view gsl_1d_view;   //
    gsl_matrix_view gsl_2d_view;   //
    std::string array_name;        // The array name, if any.
    file_system input;
    settings *config;              // A pointer-object to link with any object of settings type.
//
//  book_data(): To start the temp file (as binary) and to store the current array if set_lowend_mode()
//               was invoked.
    void book_data();
//
//
    bool is_positive();
//
//
    bool is_negative();
//
//
    bool is_null();
//
//
    void reset_properties();
//
//
    void reset_properties(const unsigned int &row_size);
//
//
    void reset_properties(const unsigned int &row_size,
                          const unsigned int &column_size);
//
//
    void reset_properties(const unsigned int &row_size,
                          const unsigned int &column_size,
                          const unsigned int &layer_size);
//
//
    void reset_properties(const unsigned int &row_size,
                          const unsigned int &column_size,
                          const unsigned int &layer1_size,
                          const unsigned int &layer2_size);
//
//  Including the inline/template/private member functions:
    #include "array__init_1d_array.cpp"
    #include "array__init_2d_array.cpp"
    #include "array__init_3d_array.cpp"
    #include "array__init_4d_array.cpp"
    #include "array__delete_1d_array.cpp"
    #include "array__delete_2d_array.cpp"
    #include "array__delete_3d_array.cpp"
    #include "array__delete_4d_array.cpp"
    #include "array__build_filename.cpp"
    #include "array__add_1d_array.cpp"
    #include "array__add_2d_array.cpp"
    #include "array__add_3d_array.cpp"
    #include "array__add_4d_array.cpp"
//
    public:
//
//  Struct identifier:
    static const int id = 2431;
//
//  Declaring the class constructor:
    array();
//
//  Declaring the class constructor:
    array(const unsigned int &local_row_size);
//
//  Declaring the class constructor:
    array(const unsigned int &local_row_size, const unsigned int &local_column_size);
//
//  Declaring the class constructor:
    array(const unsigned int &local_layer_size,
          const unsigned int &local_row_size,
          const unsigned int &local_column_size);
//
//  Declaring the class constructor:
    array(const unsigned int &local_1st_layer_size,
          const unsigned int &local_2nd_layer_size,
          const unsigned int &local_row_size,
          const unsigned int &local_column_size);
//
//  Declaring the class destructor:
    ~array();
//
//  Declaring the class copy constructor:
    array(const array &given_array);
//
//  Declaring the class operators:
    void  operator  =(const array &b);
    array operator  +(const double &b);
    array operator  +(const array &b);
    array operator  -(const double &b);
    array operator  -(const array &b);
    array operator  *(const double &b);
    array operator  *(const array &b);
    void  operator +=(const array &a);
    void  operator -=(const array &a);
    void  operator *=(const array &a);
//
//  delete_array(): Frees the allocated memory of the current array.
    void delete_array();
//
//  Defining some alias for the check_if() member function options:
    #define IS_POSITIVE   1
    #define IS_NEGATIVE   2
    #define IS_NULL       3
    #define IS_CONSTANT   4
    #define IS_SQUARE     5
    #define IS_CREATED    6
    #define IS_DELETED    7
    #define IS_TRANSPOSED 8
//
//  check_if_column(): To check properties (option) of a given column from a 2D array.
    bool check_if_column_is(const unsigned int &option, const unsigned int &j);
//
//
    unsigned int get_min_index()
    {
        return 0;//gsl_vector_min_index(user_1d_array) + 1;
    };
//
//
    unsigned int get_max_index()
    {
        return 0;//gsl_vector_max_index(user_1d_array) + 1;
    };
//
//  save_eigens_to(): To calculate the eigenvalues and eigenvectors of the current matrix and to
//                    store in the given arrays. The current matrix keeps unchanged (2D array only).
    void save_eigens_to(array &eigenvalues, array &eigenvectors);
//
//  orthonormalize(): To use the current array to build a transformation array and to orthonormalize
//                    the given one using the canonical orthonormalization. The current array will
//                    be replaced by its canonical orthonormalization form and its internal state
//                    is_const_array is set as true. In the already canonical form the same array can
//                    be reused to orthonormalize other given arrays.
    void orthonormalize(array &given_array);
//
//  restore_original_basis_of(): If the current array is a transformation and the given array is a
//                               transformed one, this routine transforms back the given array into
//                               its original basis and keeps the transformation unchanged. The
//                               current internal state is_const_array must be true.
    void restore_original_basis_of(array &given_array);
//
//  write(): To report the current array (2D only) in the global log file.
    void write();
//
//
    void build_orthonormalizer_form();
//
//  Including the inline/template/public member functions:
    #include "array__create_array.cpp"
    #include "array__size_of.cpp"
    #include "array__set_constant.cpp"
    #include "array__unset_constant.cpp"
    #include "array__check_array_id.cpp"
    #include "array__set.cpp"
    #include "array__set_all.cpp"
    #include "array__get.cpp"
    #include "array__set_name.cpp"
    #include "array__get_name.cpp"
    #include "array__build_identity_form.cpp"
    #include "array__set_config.cpp"
    #include "array__set_transpose.cpp"
    #include "array__norm.cpp"
    #include "array__my_size.cpp"
    #include "array__save.cpp"
    #include "array__open.cpp"
    #include "array__save_transpose_to.cpp"
    #include "array__save_jacobi_svd_to.cpp"
    #include "array__function_call.cpp"
    #include "array__set_diagonal.cpp"
    #include "array__resize_array.cpp"
    #include "array__check_if.cpp"
//
};
#endif
