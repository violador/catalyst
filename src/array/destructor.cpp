//
//
//
inline ~array()
{
	#pragma omp master
	delete[] data;
};
