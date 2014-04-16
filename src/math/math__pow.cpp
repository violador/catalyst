// ../src/math/math__pow.cpp ================================================================ //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
//
//
//
/// @param [in] a A real number
//
/// @brief Calls the GSL library to calculate the square of @c a.
//
/// @return @f$ a^{2} @f$
//
/// @cite gsl
//
inline double pow(const double &a)
{
	return gsl_pow_2(a);
};
//
//
//
/// @param [in] a A real number
//
/// @param [in] b An integer number
//
/// @brief Calls the GSL library to calculate @c a raised to @c b.
//
/// @return @f$ a^{b} @f$
//
/// @cite gsl
//
inline double pow(const double &a,
				  const int &b)
{
/*
	switch(b)
	{
		 case 2: return gsl_pow_2(a); break;
		 case 3: return gsl_pow_3(a); break;
		 case 4: return gsl_pow_4(a); break;
		 case 5: return gsl_pow_5(a); break;
		 case 6: return gsl_pow_6(a); break;
		 case 7: return gsl_pow_7(a); break;
		 case 8: return gsl_pow_8(a); break;
		 case 9: return gsl_pow_9(a); break;
		default: return gsl_pow_int(a, b); break;
	}
*/
	return gsl_pow_int(a, b);
};
//
//
//
/// @param [in] a A real number
//
/// @param [in] b A real number
//
/// @brief Calls the GSL library to calculate @c a raised to @c b.
//
/// @return @f$ a^{b} @f$
//
/// @cite gsl
//
inline double pow(const double &a,
				  const double &b)
{
	gsl_complex z;
	GSL_SET_COMPLEX(&z, a, 0.0);
	return GSL_REAL(gsl_complex_pow_real(z, b));
};
