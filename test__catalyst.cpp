#include "globals.hpp"
#include "settings.hpp"
#include "periodic_table.hpp"
#include "sto3g.hpp"
#include "molecular_system.hpp"
#include "tools.hpp"
#include "array.hpp"
#include "file_system.hpp"
#include "log_file_handler.hpp"
//
//
//
int main(int argc, char* argv[])
{
    settings config;
    //log_file_handler file(config);
    //molecular_system pyr("data/pyr.xyz", config);
/*
    file.output << "testando do main" << std::endl;
    file.output.width(50);
    file.output.fill(' ');
    file.output << "Positions";
*/
    array A(2, 2);
    array B(2, 2);
    array C(2, 2);
    //array D(2, 2);
    A.array::set(1, 1, 7.0); 
    A.array::set(1, 2, 3.0); 
    A.array::set(2, 1, 1.0); 
    A.array::set(2, 2, 0.0);
    B.array::set(1, 1, 2.0); 
    B.array::set(1, 2, 1.0); 
    B.array::set(2, 1, 4.0); 
    B.array::set(2, 2, 0.0);
    //double b = 2.0;
    //C = A*B;
    A *= B;
    std::cout << "A11 = " << A.array::get(1, 1) << std::endl; 
    std::cout << "A12 = " << A.array::get(1, 2) << std::endl; 
    std::cout << "A21 = " << A.array::get(2, 1) << std::endl; 
    std::cout << "A22 = " << A.array::get(2, 2) << std::endl; 
    std::cout << "A is transposed = " << A.array::check_if(IS_TRANSPOSED) << std::endl;
    std::cout << " " << std::endl;
    std::cout << "B11 = " << B.array::get(1, 1) << std::endl; 
    std::cout << "B12 = " << B.array::get(1, 2) << std::endl; 
    std::cout << "B21 = " << B.array::get(2, 1) << std::endl; 
    std::cout << "B22 = " << B.array::get(2, 2) << std::endl; 
    std::cout << "B is transposed = " << B.array::check_if(IS_TRANSPOSED) << std::endl;
    std::cout << " " << std::endl;
    std::cout << "C11 = " << C.array::get(1, 1) << std::endl; 
    std::cout << "C12 = " << C.array::get(1, 2) << std::endl; 
    std::cout << "C21 = " << C.array::get(2, 1) << std::endl; 
    std::cout << "C22 = " << C.array::get(2, 2) << std::endl; 
    std::cout << "C is transposed = " << C.array::check_if(IS_TRANSPOSED) << std::endl;
    std::cout << "A11 = " << A.array::get(1, 1) << std::endl; 
    std::cout << "A12 = " << A.array::get(1, 2) << std::endl; 
    std::cout << "A21 = " << A.array::get(2, 1) << std::endl; 
    std::cout << "A22 = " << A.array::get(2, 2) << std::endl; 
    std::cout << "A is transposed = " << A.array::check_if(IS_TRANSPOSED) << std::endl;
    std::cout << " " << std::endl;
/*
    C = A*B;
    D = C*A;
    std::cout << "A11 = " << A.array::get(1, 1) << std::endl; 
    std::cout << "A12 = " << A.array::get(1, 2) << std::endl; 
    std::cout << "A21 = " << A.array::get(2, 1) << std::endl; 
    std::cout << "A22 = " << A.array::get(2, 2) << std::endl; 
    std::cout << "B11 = " << B.array::get(1, 1) << std::endl; 
    std::cout << "B12 = " << B.array::get(1, 2) << std::endl; 
    std::cout << "B21 = " << B.array::get(2, 1) << std::endl; 
    std::cout << "B22 = " << B.array::get(2, 2) << std::endl; 
    std::cout << "C11 = " << C.array::get(1, 1) << std::endl; 
    std::cout << "C12 = " << C.array::get(1, 2) << std::endl; 
    std::cout << "C21 = " << C.array::get(2, 1) << std::endl; 
    std::cout << "C22 = " << C.array::get(2, 2) << std::endl; 
    std::cout << "D11 = " << D.array::get(1, 1) << std::endl; 
    std::cout << "D12 = " << D.array::get(1, 2) << std::endl; 
    std::cout << "D21 = " << D.array::get(2, 1) << std::endl; 
    std::cout << "D22 = " << D.array::get(2, 2) << std::endl; 
    C = A*B;
    D = B*A;
    std::cout << "DEPOIS" << std::endl;
    std::cout << "A11 = " << A.array::get(1, 1) << std::endl; 
    std::cout << "A12 = " << A.array::get(1, 2) << std::endl; 
    std::cout << "A21 = " << A.array::get(2, 1) << std::endl; 
    std::cout << "A22 = " << A.array::get(2, 2) << std::endl; 
    std::cout << "B11 = " << B.array::get(1, 1) << std::endl; 
    std::cout << "B12 = " << B.array::get(1, 2) << std::endl; 
    std::cout << "B21 = " << B.array::get(2, 1) << std::endl; 
    std::cout << "B22 = " << B.array::get(2, 2) << std::endl; 
    std::cout << "C11 = " << C.array::get(1, 1) << std::endl; 
    std::cout << "C12 = " << C.array::get(1, 2) << std::endl; 
    std::cout << "C21 = " << C.array::get(2, 1) << std::endl; 
    std::cout << "C22 = " << C.array::get(2, 2) << std::endl; 
    std::cout << "D11 = " << D.array::get(1, 1) << std::endl; 
    std::cout << "D12 = " << D.array::get(1, 2) << std::endl; 
    std::cout << "D21 = " << D.array::get(2, 1) << std::endl; 
    std::cout << "D22 = " << D.array::get(2, 2) << std::endl; 
*/
    return 0;
}
