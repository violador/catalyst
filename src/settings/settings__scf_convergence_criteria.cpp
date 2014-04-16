//
//
//
/// @brief Returns the current convergence criteria for the SCF energy.
///        Its default value is given by tools::default_scf_criteria().
//
/// @return A non-negative real number.
//
inline double &scf_convergence_criteria()
{
	return scf_criteria;
};
