// ../src/tools/tools__square_module.cpp ==================================================== //
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
/// @param [in] a A templated number
//
/// @param [in] b A templated number
//
/// @brief Calculates the square of the absolute value of the difference
///        between the given @f$ a @f$ and @f$ b @f$.
//
/// @return @f$ |a - b|^{2} @f$
//
template<typename data_type>
inline data_type square_module(const data_type &a,
							   const data_type &b)
{
	return gsl_pow_2(tools::module(a - b));
};
