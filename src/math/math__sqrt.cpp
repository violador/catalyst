// ../src/math/math__sqrt.cpp =============================================================== //
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
/// @brief Calls the GSL library to calculate the square root of the given @c a.
//
/// @return @f$ \sqrt{a} @f$
//
/// @cite gsl
//
inline double sqrt(const double &a)
{
//
/// @note Notice that negative values of @c a are accepted, in such case
///       this function returns the imaginary part of the calculated
///       complex number.
//
	switch(a > 0.0)
	{
		case false: return GSL_IMAG(gsl_complex_sqrt_real(a)); break;
		case  true: return GSL_REAL(gsl_complex_sqrt_real(a)); break;
	}
};
