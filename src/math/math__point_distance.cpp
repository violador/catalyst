// ../src/tools/tools__point_distance.cpp =================================================== //
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
/// @param [in] a A templated number: the x-axis value of the first point
//
/// @param [in] b A templated number: the x-axis value of the second point
//
/// @brief Calculates the distance between two points onto only one axis.
//
/// @return @f$ |a - b| @f$
//
template<typename data_type>
inline data_type point_distance(const data_type &a,
								const data_type &b)
{
	return module(a, b);
};
//
//
//
/// @param [in] a A templated number: the x-axis value of the first point
//
/// @param [in] b A templated number: the y-axis value of the first point
//
/// @param [in] c A templated number: the x-axis value of the second point
//
/// @param [in] d A templated number: the y-axis value of the second point
//
/// @brief Calculates the distance between two points by means of their set
///        of coordinates onto two axis.
//
/// @return @f$ \sqrt[2]{(c - a)^{2} + (d - b)^{2}} @f$
//
template<typename data_type>
inline data_type point_distance(const data_type &a,
								const data_type &b,
								const data_type &c,
								const data_type &d)
{
	return std::sqrt(gsl_pow_2(c - a) + gsl_pow_2(d - b));
};
//
//
//
/// @param [in] a A templated number: the x-axis value of the first point
//
/// @param [in] b A templated number: the y-axis value of the first point
//
/// @param [in] c A templated number: the z-axis value of the first point
//
/// @param [in] d A templated number: the x-axis value of the second point
//
/// @param [in] e A templated number: the y-axis value of the second point
//
/// @param [in] f A templated number: the z-axis value of the second point
//
/// @brief Calculates the distance between two points by means of their set
///        of coordinates onto three axis.
//
/// @return @f$ \sqrt[2]{(d - a)^{2} + (e - b)^{2} + (f - c)^{2}} @f$
//
template<typename data_type>
inline data_type point_distance(const data_type &a,
								const data_type &b,
								const data_type &c,
								const data_type &d,
								const data_type &e,
								const data_type &f)
{
	return std::sqrt(gsl_pow_2(d - a) + gsl_pow_2(e - b) + gsl_pow_2(f - c));
};
