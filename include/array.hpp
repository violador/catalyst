#ifndef __ARRAY_HPP
    #define __ARRAY_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "tools.hpp"
    #include "file_system.hpp"
    #include "global_log.hpp"
//
//
//
struct array
{
    protected:
//
//  Declaring the data members: 
    settings *config;               // A pointer-object to link with any object of settings type.
    unsigned int sizeof_row;        // The size of row. 
    unsigned int sizeof_column;     // The size of column.
    unsigned int sizeof_1st_layer;  // The size of first layer.
    unsigned int sizeof_2nd_layer;  // The size of second layer.
    unsigned int sizeof_3rd_layer;  // The size of third layer.
    unsigned int array_id;          // To tag the current array.
    bool is_1d_array;               // True, if it is a 1D array, false otherwise.
    bool is_2d_array;               // True, if it is a 2D array, false otherwise.
    bool is_3d_array;               // True, if it is a 3D array, false otherwise.
    bool is_4d_array;               // True, if it is a 4D array, false otherwise.
    bool is_const_array;            // True, if it is a constant array, false otherwise.
    bool is_square_array;           // True, if it is a square array, false otherwise.
    bool is_transposed;             // True, if it is a transposed array, false otherwise.
    bool created_array;             // True, if it was created already by constructors or create_array(), false otherwise.
    bool deleted_array;             // True, if it was deleted already by delete_array(), false otherwise.
    bool lowend_mode_on;            // True, if the high-end mode is off, false otherwise.
    bool setup_ready;               // True, if the *config pointer is already liked. False otherwise.
    gsl_vector *user_1d_array;      // The current user's 1D array.
    gsl_matrix *user_2d_array;      // The current user's 2D array.
    double   ***user_3d_array;      // The current user's 3D array.
    double  ****user_4d_array;      // The current user's 4D array.
    std::string array_name;         // The array name, if any.
    std::string array_filename;     // 
    file_system array_file_manager; //
    file_system log_file_manager;   // A pointer-object to link with any object of file_system type.
    FILE* array_file;
//
//  Including the inline/template/private member functions: 
    #include "array__init_properties.cpp"
    #include "array__init_3d_array.cpp"
    #include "array__init_4d_array.cpp"
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
    array(const unsigned int &local_layer_size, const unsigned int &local_row_size, const unsigned int &local_column_size);
//
//  Declaring the class constructor:
    array(const unsigned int &local_1st_layer_size, 
          const unsigned int &local_2nd_layer_size, 
          const unsigned int &local_row_size, 
          const unsigned int &local_column_size);
//
//  Declaring the class copy constructor:
    array(const array &given_array);
//
//  Declaring the class operators:
    void  operator=(const array &b);
    array operator+(const double &b);
    array operator+(const array &b);
    array operator-(const double &b);
    array operator-(const array &b);
    array operator*(const double &b);
    array operator*(const array &b);
    void  operator+=(const array &a);
    void  operator-=(const array &a);
    void  operator*=(const array &a);
//
//  create_array(): To allocate memory for the requested size.
    void create_array(const unsigned int local_1st_layer_size = 0,
                      const unsigned int local_2nd_layer_size = 0,
                      const unsigned int local_row_size = 0,
                      const unsigned int local_column_size = 0);
//
//  delete_array(): Frees the allocated memory of the current array.
    void delete_array();
//
//  Including the inline/template/public member functions: 
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
    #include "array__unset_lowend_mode.cpp"
    #include "array__set_config.cpp"
    #include "array__set_transpose.cpp"
    #include "array__unset_transpose.cpp"
    #include "array__norm.cpp"
//
//  size_of_row(), size_of_column(), size_of_1st_layer() and size_of_2nd_layer(): 
//  A set of inlined member functions to return the respective size of each dimension.
//
//  set_constant(): To set up the current array as constant (change the behavior of some functions).
//
//  unset_constant(): To set up the current array as non constant (change the behavior of some functions).
//
//  check_array_id(): To check the identifier number of the current array.
//
//  check_if(): To check properties in the current array.
    bool check_if(const unsigned int &option);
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
//
    bool check_if_column_is(const unsigned int &option, const unsigned int &j);
//
// 
    #define POSITIVE 1
    #define NEGATIVE 2
//
//  set(): A set of overloaded inlined member functions to set the given value in the given position.
//
//  set_all(): To fill up the array with the given value.
//
//  get(): A set of overloaded inlined member functions to return the current value of the given position.
//
//  set_name(): An inlined member function to set the name of the current array.
//
//  get_name(): To return the name of the current array.
//
//
    unsigned int get_min_index()
    {
        return gsl_vector_min_index(user_1d_array) + 1;
    };
//
//
    unsigned int get_max_index()
    { 
        return gsl_vector_max_index(user_1d_array) + 1;
    };
//
//  save_transpose_to(): To save the transpose of the current array in the given one (2D
//                       array only).
    void save_transpose_to(array &given_array);
//
//  save_jacobi_svd_to(): To calculate (2D array only) the singular value decompositions (SVD) using the
//                        Jacobi's method and to store the transformation matrix, U, and the eigenvalues in 
//                        the given arrays. The current matrix will be replaced by its transformation.
    void save_jacobi_svd_to(array &u_matrix, array &eigenvalues);
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
//  build_identity_form(): To replace the content of the current array by its identity form (2D array only).
//
//  save(): To save the current array in a binary file.
    void save();
//
//  open(): To read the current array from a binary file.
    void open();
//
//
    double read_array_file(const unsigned int &i_given, const unsigned int &j_given)
    {
        return 0.0;
/*

        if(is_1d_array && created_array && (!deleted_array))
        {
        }
        else if(is_2d_array && created_array && (!deleted_array))
        {
//
            array_file_manager.file_system::open_txt_input(array_file);
            if(array_file_manager.file_system::is_open())
            {
                std::cout << "ARQUIVO ABERTO" << std::endl;
                double value = 0.0;
*/
/*
                unsigned int local_sizeof_row = 0;
                unsigned int local_sizeof_column = 0;
                array_file >> local_sizeof_row;
                array_file >> local_sizeof_column;
//
                std::cout << "LINHA = " << local_sizeof_row << std::endl;
                std::cout << "COLUNA = " << local_sizeof_column << std::endl;
//
*/
/*
                for(unsigned int i = 1; i <= local_sizeof_row; i++)
                {
                    for(unsigned int j = 1; j <= local_sizeof_column; j++)
                    {
                        array_file >> value;
                        if((i == i_given) && (j == j_given))
                        {
                            return value;
                        }
                    }
                }
            }
            array_file_manager.file_system::close(array_file);
//
        }
        else if(is_3d_array && created_array && (!deleted_array))
        {
        }
        else if(is_4d_array && created_array && (!deleted_array))
        {
        }
        else
        {
            return 0.0;
        }
*/
    };
//
//
    void set_lowend_mode(/*std::string scratch_dir*/)
    {
/*
        tools convert;
        data_book data;
        //array_filename = "array." + convert.to_string_from(array_id);
        array_f = gsl_ntuple_create("caca_teste", &data, sizeof(sizeof_row));
        for(unsigned int i = 0; i < sizeof_row; i++)
        {
            data.a = user_1d_array -> data[i*user_1d_array -> stride];
            gsl_ntuple_bookdata(array_f);
        }
*/
/*
        array_file_manager.file_system::init(array_filename, scratch_dir);
        array_file_manager.file_system::open_txt_output(array_file);
        if(array_file_manager.file_system::is_open())
        {
            save_to();
            lowend_mode_on = true;
            array_file_manager.file_system::close(array_file);
            //array_file_manager.file_system::open_txt_input(array_file);
        }
        else
        {
        }
*/
    };
//
    void report();
};
#endif
