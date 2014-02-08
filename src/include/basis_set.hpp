// ../src/include/basis_set.hpp -------------------------------------------------------- //
//
// File author: Humberto Jr.
//
// Date: 10/2013
//
// Description:
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __BASIS_SET_HPP
    #define __BASIS_SET_HPP
    #include "globals.hpp"
    #include "tools.hpp"
//
//
//
class basis_set
{
    private:
//
//  Declaring the private data members:
    unsigned int current_element;
    unsigned int current_level;
    unsigned int current_set_size;
    unsigned int iter;
    static const unsigned int sto3g_limit = 53;
    double *coeff;
    double *expon;
//
//  Declaring the private member functions:
    void init_sto3g_coeff();
    void init_sto3g_expon();
    const unsigned int check_sto3g_size();
//
//  Including the inline/template/private member functions:
    #include "basis_set__init_set_size.cpp"
//
    public:
//
//  Class identifier:
    static const int id = 28723;
//
//  Declaring the class constructor:
    basis_set(const unsigned int &element,
              const unsigned int &level);
//
//  Including the inline/template/public member functions:
    #include "basis_set__function_expon.cpp"
    #include "basis_set__function_coeff.cpp"
    #include "basis_set__size.cpp"
    #include "basis_set__destructor.cpp"
    #include "basis_set__ready.cpp"
    #include "basis_set__increment.cpp"
    #include "basis_set__decrement.cpp"
    #include "basis_set__first.cpp"
    #include "basis_set__last.cpp"
    #include "basis_set__iterator.cpp"
    #include "basis_set__set_iterator.cpp"
	#include "basis_set__function_call.cpp"
//
};
#endif
