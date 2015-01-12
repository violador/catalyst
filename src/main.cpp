//#include "math.hpp"
#include "array.hpp"
//#include "globals.hpp"
//#include "lcao_wavefunction.hpp"
//#include "scf.hpp"
//#include "timer.hpp"
//#include <boost/timer/timer.hpp>
#include <omp.h>
#include <cstdlib>
#include <iostream>
//
//
//
inline void print_array(const array<double, 1> &C, const std::string name)
{
	std::cout << std::endl;
	for(unsigned int i = 1; i <= C.array::first_rank(); ++i)
	{
		std::cout << name << "(" << i << ") = " << C(i) << std::endl;
	}
	std::cout << "Rank = " << C.array::rank() << std::endl;
	std::cout << "Rank 1 = " << C.array::first_rank() << std::endl;
	std::cout << "Status = " << (C.array::is_ready()? "created" : "not created") << std::endl;
	std::cout << "Is null = " << (C.array::is_null()? "yes" : "no") << std::endl;
	std::cout << "Is positive = " << (C.array::is_positive()? "yes" : "no") << std::endl;
	std::cout << "Is negative = " << (C.array::is_negative()? "yes" : "no") << std::endl;
	std::cout << "Min = " << C.array::min() << std::endl;
	std::cout << "Max = " << C.array::max() << std::endl;
};

template <typename data_type0>
inline data_type0 func_test()
{
	return data_type0(2.334);
};
//
//
//
inline void print_array(const array<double, 2> &C, const std::string name)
{
	std::cout << std::endl;
	for(unsigned int i = 1; i <= C.array::first_rank(); ++i)
	{
		for(unsigned int j = 1; j <= C.array::second_rank(); ++j)
		{
			std::cout << name << "(" << i << ", " << j << ") = " << C(i, j) << std::endl;
		}
	}
	std::cout << "Rank = " << C.array::rank() << std::endl;
	std::cout << "Rank 1 = " << C.array::first_rank() << std::endl;
	std::cout << "Rank 2 = " << C.array::second_rank() << std::endl;
	std::cout << "Status = " << (C.array::is_ready()? "created" : "not created") << std::endl;
	std::cout << "Is null = " << (C.array::is_null()? "yes" : "no") << std::endl;
	std::cout << "Is positive = " << (C.array::is_positive()? "yes" : "no") << std::endl;
	std::cout << "Is negative = " << (C.array::is_negative()? "yes" : "no") << std::endl;
	std::cout << "Min = " << C.array::min() << std::endl;
	std::cout << "Max = " << C.array::max() << std::endl;
};
//
//
//
int main()
{
/*
	size =      0, construction wall time = 0.000000657001 s
	size =     50, construction wall time = 0.0001215   s
	size =    100, construction wall time = 0.000122804 s
	size =    200, construction wall time = 0.000120979 s
	size =    400, construction wall time = 0.000126246 s
	size =    800, construction wall time = 0.000152721 s
	size =   1000, construction wall time = 0.000131989 s
	size =   5000, construction wall time = 0.000164553 s
//
//
//
int main()
{
	size =      0, construction wall time = 0.000000657001 s
	size =     50, construction wall time = 0.0001215   s
	size =    100, construction wall time = 0.000122804 s
	size =    200, construction wall time = 0.000120979 s
	size =    400, construction wall time = 0.000126246 s
	size =    800, construction wall time = 0.000152721 s
	size =   1000, construction wall time = 0.000131989 s
	size =   5000, construction wall time = 0.000164553 s
	size =  10000, construction wall time = 0.000211936 s
	size =  20000, construction wall time = 0.000308194 s
	size = 100000, construction wall time = 0.00103987  s
*/
	unsigned int row = 20;
	double start_time = 0.0, end_time = 0.0;
	start_time = omp_get_wtime();
	array<double, 1> A(row);
	array<double, 1> B(row);
	array<double, 1> C(row);
	array<double, 1> D(10);
	array<double, 1> E(10);
	array<double, 1> F(1000001);
	array<double, 1> G(1000001);
	array<double, 1> H(50);
	array<double, 1> I(50);
	array<double, 1> Z;
	array<double, 1> T;
	array<double, 1> W1(10);
	array<double, 1> W2(10);
	array<double, 2> a;
	array<double, 2> b;
	array<double, 2> c;
	array<double, 2> d;
	a.create(6, 6);
	b.create(2, 3);
	c.create(3, 2);
	d.create(2, 2);
	W1 = 2.5;
	W2 = 0.5;
	H = 2.5;
	I = T + Z;
	A.array::build_randomly();
	F.array::build_randomly();
	//end_time = omp_get_wtime();
	print_array(A, "A");
	double test[100];
	unsigned int i = 100;
	start_time = omp_get_wtime();
	std::cout << sizeof(test)/sizeof(double);
	end_time = omp_get_wtime();
	std::cout << "\nwall time for a/b = " << end_time - start_time << " s" << std::endl;
	start_time = omp_get_wtime();
	std::cout << i;
	end_time = omp_get_wtime();
	std::cout << "\nwall time for i = " << end_time - start_time << " s" << std::endl;
	unsigned int element = 1;
	A(element) = 34.0;
	std::cout << "\nnovo elemento A(1) = " << A(element) << std::endl;
	B = A;
	print_array(B, "B");
	B = 180.1;
	print_array(B, "B");
	A << B;
	///*array<double, 1>*/ C += B;
	print_array(B, "B");
	print_array(A, "A");
	//D = 25.5;
	//F = 25.5;
	start_time = omp_get_wtime();
	//#pragma omp parallel
	//{
	//	#pragma omp master
		//E = D + 0.5;
	//}
	end_time = omp_get_wtime();
	//print_array(E, "E");
	//std::cout << "wall time for 100000 = " << end_time - start_time << " s" << std::endl;
	print_array(D, "D");
	print_array(E, "E");
	print_array(H, "H");
	print_array(Z, "Z");
	print_array(I, "I");
	print_array(T, "T");
	////W2.clear();
	T = W1 + W2;
	print_array(T, "T");
	I.create(30);
	a.create(17, 10);
	print_array(I, "I");
	print_array(a, "a");
	a.build_randomly();
	print_array(a, "a");
	std::cout << "a(2, 3) = " << a(2, 3)  << std::endl;
	a.transpose();
	print_array(a, "a");
	a.build_identity_form();
	print_array(a, "a");
	a.set_diagonal(2.5);
	print_array(a, "a");
	a.set_zero();
	a.set_anti_diagonal(3.5);
	print_array(a, "a");
	start_time = omp_get_wtime();
	{
		G << F;
	}
	end_time = omp_get_wtime();
	//print_array(G, "G");
	std::cout << "G = F no inline = " << end_time - start_time << " s" << std::endl;
	std::cout << "T(9) = " << T.get(9) << std::endl;
	a.build_randomly();
	std::ofstream file("teste.txt");
	a.write(file, "hahahah!", 8);
	a.clear();
	start_time = omp_get_wtime();
	{
		switch(a.is_ready())
		{
			case true: std::cout << "from switch: is ready!" << std::endl; break;
			case false: std::cout << "from switch: is not ready!" << std::endl; break;
		}
	}
	end_time = omp_get_wtime();
	std::cout << "switch time = " << end_time - start_time << std::endl;
	start_time = omp_get_wtime();
	{
		if(a.is_ready())
		{
			std::cout << "from if: is ready!" << std::endl;
		}
		else
		{
			std::cout << "from if: is not ready!" << std::endl;
		}
	}
	end_time = omp_get_wtime();
	std::cout << "if time = " << end_time - start_time << std::endl;
	b(1, 1) = 1.0;
	b(1, 2) = 2.0;
	b(1, 3) = 3.0;
	b(2, 1) = 4.0;
	b(2, 2) = 5.0;
	b(2, 3) = 6.0;
	c(1, 1) = 7.0;
	c(1, 2) = 8.0;
	c(2, 1) = 9.0;
	c(2, 2) = 10.0;
	c(3, 1) = 11.0;
	c(3, 2) = 12.0;
	print_array(b, "b");
	print_array(c, "c");
	print_array(d, "d");
	d = b*c;
	print_array(d, "d");
	b *= c;
	print_array(b, "b");
	b.write();
	b.debug_check();
	//std::cout << "return type test = " << c.func_t<double>() << std::endl;
	//std::cout << "return type test = " << c.func_t<int>() << std::endl;
	//std::cout << "return type test = " << c.func_t<float>() << std::endl;
	/*
	double matrix_a[2*3] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	double matrix_b[3*2] = {7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
	double matrix_c[2*2] = {0.0, 0.0, 0.0, 0.0};
	cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans,
                2, // A and C
                2, // B and C
                3, // A and B
                1.0,
                matrix_a,
                3,
                matrix_b,
                2,
                1.0,
                matrix_c,
                2);
	std::cout << matrix_c[0] << std::endl;
	std::cout << matrix_c[1] << std::endl;
	std::cout << matrix_c[2] << std::endl;
	std::cout << matrix_c[3] << std::endl;
	*/
	//a.get(1);
	/*
	double* vet1 = NULL;
	vet1 = new double[0]();
	std::cout << "ve1 is NULL = " << (vet1 == NULL? "yes" : "no") << std::endl;
	vet1[9] = 1.5;
	vet1[10] = 2.5;
	vet1[11] = 3.5;
	std::cout << "ve1 = " << vet1[9] << std::endl;
	std::cout << "ve1 = " << vet1[10] << std::endl;
	std::cout << "ve1 = " << vet1[11] << std::endl;
	*/
	/*
	#pragma omp parallel
	{
	start_time = omp_get_wtime();
	G = F + 0.5;
	end_time = omp_get_wtime();
	}
	print_array(G, "G");
	*/
	//C = (A )
	//std::cout << "wall time = " << end_time - start_time << " s" << std::endl;
	//A.array::set_all(0.5);
	//print_array(A, "A");
	//array<double, 1> B(row);
	/*
	//print_array(A, row);
	std::cout << "[Summ 2.0!!]" << std::endl;
	B = A - 2.0;
	print_array(B, row);
	std::cout << "[Using set all!!]" << std::endl;
	A.array::set_all(2.8574);
	//B = A;
	//std::cout << "[B!!]" << std::endl;
	//print_array(B, row);
	std::cout << "[A!!]" << std::endl;
	for(unsigned int i = 1; i <= row; ++i)
	{
		std::cout << "A(" << i << ") = " << A(i) << std::endl;
	}
	A(1, 1.5432);
	A(3, 9.5432);
	std::cout << "[Changing the variables!!]" << std::endl;
	for(unsigned int i = 1; i <= row; ++i)
	{
		std::cout << "A(" << i << ") = " << A(i) << std::endl;
	}
	std::cout << "[Sort!!]" << std::endl;
	A.array::sort();
	for(unsigned int i = 1; i <= row; ++i)
	{
		std::cout << "A(" << i << ") = " << A(i) << std::endl;
	}
	std::cout << "Summ = " << A.array::summation() << std::endl;
	std::cout << "Norm = " << A.array::norm() << std::endl;
	std::cout << "[Reseting!!]" << std::endl;
	A.array::reset();
	std::cout << "[Recreating!!]" << std::endl;
	A.array::create(row);
	for(unsigned int i = 1; i <= row; ++i)
	{
		std::cout << "A(" << i << ") = " << A(i) << std::endl;
	}
	*/
	return 0;
}
