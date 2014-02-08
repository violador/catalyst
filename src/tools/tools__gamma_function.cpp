// ../src/tools/tools__gamma_function.cpp =================================================== //
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
/// @param [in] a A real number, where @f$ 0.0 < a \leq 171.0 @f$.
//
/// @brief Calls the GSL library to calculate the value of the gamma function.
//
/// @return @f$ \Gamma(a) \equiv (a - 1)! @f$. If @f$ a @f$ is out of range,
///         the function returns zero.
//
/// @cite gsl
//
inline double gamma_function(const double &a)
{
	switch(a <= 0.0 or a > GSL_SF_GAMMA_XMAX)
	{
		case false: return gsl_sf_gamma(a); break;
		case  true: return 0.0; break;
	}
};
