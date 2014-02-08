// ../src/math/math__double_factorial.cpp =================================================== //
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
/// @param [in] a An integer number, where @f$ 0 < a \leq 297 @f$
//
/// @brief Calls the GSL library to compute the double factorial of
///        the given @c a.
//
/// @return @f$ a!! @f$. If @f$ a @f$ is out of range, the function
///         returns one.
//
/// @cite gsl
//
inline double double_factorial(const int &a)
{
	switch(a <= 0 or a > GSL_SF_DOUBLEFACT_NMAX)
	{
		case false: return gsl_sf_doublefact(a); break;
		case  true: return 1.0; break;
	}
};
