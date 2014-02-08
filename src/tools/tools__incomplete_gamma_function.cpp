// ../src/tools/tools__incomplete_gamma_function.cpp ======================================== //
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
/// @param [in] b A real number, where @f$ b \geq 0.0 @f$
//
/// @brief Calls the GSL library to calculate the incomplete
///        gamma function.
//
/// @return @f[ \int_{b}^{\infty} t^{a - 1} \exp(-t)dt @f]
///         If @f$ b @f$ is out of range, the function
///         returns zero.
//
/// @cite gsl
//
inline double incomplete_gamma_function(const double &a,
                                        const double &b)
{
	switch(b >= 0.0)
	{
		case false: return 0.0; break;
		case  true: return gsl_sf_gamma_inc(a, b); break;
	}
};
