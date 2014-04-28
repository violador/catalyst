//
//
//
inline void copy_1d_arrays(const array &B)
{
	resize(B.rank1);
	gsl_vector_memcpy(&this -> gsl_1d_view.vector, &B.gsl_1d_view.vector);
};
