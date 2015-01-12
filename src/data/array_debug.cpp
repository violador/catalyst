#include "globals.hpp"
#include "settings.hpp"
#include "periodic_table.hpp"
#include "molecular_system.hpp"
#include "tools.hpp"
#include "array.hpp"
#include "file_system.hpp"
#include "log_file_handler.hpp"
#include "global_log.hpp"
#include "timer.hpp"
#include "lcao_wavefunction.hpp"
#include "global_settings.hpp"
#include "basis_set.hpp"
//
//
//
int main()
{
/*
    unsigned int atoms = 3;
    array type(atoms), x(atoms), y(atoms), z(atoms), s(7, 7), t(7, 7); 
    x(1, 0.0);
    x(2, 0.0);
    x(3, 0.0);
    y(1,  1.43233673);
    y(2, -1.43233673);
    y(3,  0.0);
    z(1, -0.96104039);
    z(2, -0.96104039);
    z(3,  0.24026010);
    type((unsigned int) 1, (double) 1.0);
    type((unsigned int) 2, (double) 1.0);
    type((unsigned int) 3, (double) 8.0);
    lcao_wavefunction teste;
    teste.lcao_wavefunction::build_overlap_matrix(s,
                                                  type,
                                                  x,
                                                  y,
                                                  z,
                                                  1);
    teste.lcao_wavefunction::build_kinetic_matrix(t,
                                                  type,
                                                  x,
                                                  y,
                                                  z,
                                                  1);
    std::cout << "Overlap matrix wall time = " << teste.lcao_wavefunction::overlap_timing.timer::get(WALL_TIME) << std::endl;
    std::cout << "Kinetic matrix wall time = " << teste.lcao_wavefunction::kinetic_timing.timer::get(WALL_TIME) << std::endl;
    for(unsigned int i_atom = 1; i_atom <= 7; i_atom++)
    {
        for(unsigned int j_atom = 1; j_atom <= 7; j_atom++)
        {
            std::cout << "S(" << i_atom << ", " << j_atom << ") = " << s(i_atom, j_atom) << std::endl;
        }
    }
    std::cout << " " << std::endl;
    for(unsigned int i_atom = 1; i_atom <= 7; i_atom++)
    {
        for(unsigned int j_atom = 1; j_atom <= 7; j_atom++)
        {
            std::cout << "T(" << i_atom << ", " << j_atom << ") = " << t(i_atom, j_atom) << std::endl;
        }
    }
*/
    global_log::file << "ola";
    std::cout << tools::convert_enum("STO-3G") << std::endl;
    std::cout << tools::convert_enum(basis::STO_3G) << std::endl;
    //file_system a("text1.txt", "/home/violador/catalyst/src/data/");
    file_system a("", "");
    //file_system a("catalyst__compiler.sh");
    std::cout << "file exists = " << (a.exists()? "yes" : "no") << std::endl;
    std::cout << "root = " << a.root_dir() << std::endl;
    std::cout << "parent = " << a.parent_dir() << std::endl;
    std::cout << "relative = " << a.relative_dir() << std::endl;
    std::cout << "full name = " << a.full_name() << std::endl;
    std::cout << "name = " << a.name() << std::endl;
    std::cout << "extension = " << a.extension() << std::endl;
    std::cout << "is dir? = " << (a.is_dir()? "yes" : "no") << std::endl;
    std::cout << "is file? = " << (a.is_file()? "yes" : "no") << std::endl;
    std::cout << "valid dir? = " << (a.valid_dir()? "yes" : "no") << std::endl;
    std::cout << "disk space = " << a.check_disk_space() << " GB" << std::endl;
    std::cout << "disk capacity = " << a.check_disk_capacity() << " GB" << std::endl;
//
/*
    std::cout << std::endl;
    std::cout << "renaming to text2.txt" << std::endl;
    a.rename_file("text2.txt");
    std::cout << std::endl;
//
    std::cout << "file exists = " << (a.exists()? "yes" : "no") << std::endl;
    std::cout << "root = " << a.root_dir() << std::endl;
    std::cout << "parent = " << a.parent_dir() << std::endl;
    std::cout << "relative = " << a.relative_dir() << std::endl;
    std::cout << "full name = " << a.full_name() << std::endl;
    std::cout << "name = " << a.name() << std::endl;
    std::cout << "extension = " << a.extension() << std::endl;
    std::cout << "no file = " << (a.there_is_no_file()? "yes" : "no") << std::endl;
    std::cout << "is dir? = " << (a.is_dir()? "yes" : "no") << std::endl;
    std::cout << "is file? = " << (a.is_file()? "yes" : "no") << std::endl;
    std::cout << "valid dir? = " << (a.valid_dir()? "yes" : "no") << std::endl;
    std::cout << "disk space = " << a.check_disk_space() << " GB" << std::endl;
    std::cout << "disk capacity = " << a.check_disk_capacity() << " GB" << std::endl;
*/
//
/*
    std::cout << std::endl;
    std::cout << "remove text2.txt" << std::endl;
    a.remove_file();
    std::cout << std::endl;
*/
//
    //std::cout << "file size = " << a.size()*BYTE_TO_KILOBYTE << " kB" << std::endl;
/*
    bool a = true, b = false;
    double c = 2.22, d = 2.22;
    switch(a and (not b))
    {
        case false: std::cout << "e falso!" << std::endl; break;
        case  true: std::cout << "e verdadeiro!" << std::endl; break;
    }
*/
/*
    periodic_table a(1, 53);
    for(unsigned int i = 1; i <= a.periodic_table::basis_size(); i++)
    {
            std::cout << "exponent " << i << "= " << a(BASIS_EXPONENT, i) << std::endl;
    }
    for(unsigned int i = 1; i <= a.periodic_table::basis_size(); i++)
    {
            std::cout << "coefficient " << i << "= " << a(BASIS_COEFFICIENT, i) << std::endl;
    }
*/
/*
    array S(2, 2);
    S.set(1, 1, 1.0);
    S.set(1, 2, 0.4508);
    S.set(2, 1, 0.4508);
    S.set(2, 2, 1.0);
    S.array::build_orthonormalizer_form();
    std::cout << S.get(1, 1) << std::endl;  
    std::cout << S.get(1, 2) << std::endl;  
    std::cout << S.get(2, 1) << std::endl;  
    std::cout << S.get(2, 2) << std::endl;  
    array F(2, 2);
    F.set(1, 1, -2.6527);
    F.set(1, 2, -1.3472);
    F.set(2, 1, -1.3472);
    F.set(2, 2, -1.7318);
    S.array::orthonormalize(F);
    std::cout << std::endl;
    std::cout << F.get(1, 1) << std::endl;  
    std::cout << F.get(1, 2) << std::endl;  
    std::cout << F.get(2, 1) << std::endl;  
    std::cout << F.get(2, 2) << std::endl;  
    array C(2, 2);
    C.set(1, 1,  0.9104);
    C.set(1, 2,  0.4136);
    C.set(2, 1,  0.4136);
    C.set(2, 2, -0.9104);
    S.restore_original_basis_of(C);
    std::cout << std::endl;
    std::cout << C.get(1, 1) << std::endl;  
    std::cout << C.get(1, 2) << std::endl;  
    std::cout << C.get(2, 1) << std::endl;  
    std::cout << C.get(2, 2) << std::endl;  
*/
/*
    unsigned int size = 2;
//
    array A(size, size);
    array B(size, size);
    array C(size, size);
    array D(size, size);
    array E(size, size);
    array F(size, size);
    array G(size, size);
    array W(size);
    int const1 = 2;
    int const2 = 3;
//
    A.set(1, 1, 7.0);
    A.set(1, 2, 3.0);
    A.set(2, 1, 1.0);
    A.set(2, 2, 0.0);
//
    B.set(1, 1, 2.0);
    B.set(1, 2, 1.0);
    B.set(2, 1, 4.0);
    B.set(2, 2, 0.0);
//
    C = A*B;
    D = A + B;
    E = A - B;
    F = A + const1;
    G = A - const2;
//
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "C("  << i << ", "  << j << ") = " << C.get(i, j) << std::endl;
       }
    }
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "D("  << i << ", "  << j << ") = " << D.get(i, j) << std::endl;
       }
    }
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "E("  << i << ", "  << j << ") = " << E.get(i, j) << std::endl;
       }
    }
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "F("  << i << ", "  << j << ") = " << F.get(i, j) << std::endl;
       }
    }
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "G("  << i << ", "  << j << ") = " << G.get(i, j) << std::endl;
       }
    }
//
    A *= B;
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "A = A*B("  << i << ", "  << j << ") = " << A.get(i, j) << std::endl;
       }
    }
//
    A += const1;
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "A = A + const1("  << i << ", "  << j << ") = " << A.get(i, j) << std::endl;
       }
    }
//
    A -= const1;
    for(unsigned int i = 1; i <= size; i++)
    {
       for(unsigned int j = 1; j <= size; j++)
       {
        std::cout << "A = A - const1("  << i << ", "  << j << ") = " << A.get(i, j) << std::endl;
       }
    }
*/
    return 0;
}
