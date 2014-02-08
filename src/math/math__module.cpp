// ../src/math/math__module.cpp ============================================================= //
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
/// @brief Calculates the absolute value of the given @f$ a @f$.
//
/// @return @f$ |a| @f$
//
template<typename data_type>
inline data_type module(const data_type &a)
{
//
/// @warning By its templated nature, this function accepts @c char and
///          @c std::string types. But since it is meaningless make sure
///          to use only numerical datas as input arguments. Otherwise
///          its behavior may be unknown.
//
	switch(a >= 0.0)
	{
		case false: return -a; break;
		case  true: return  a; break;
	}
};
//
//
//
/// @param [in] a A templated number
//
/// @param [in] b A templated number
//
/// @brief Calculates the absolute value of the difference between the
///        given @f$ a @f$ and @f$ b @f$.
//
/// @return @f$ |a - b| @f$
//
template<typename data_type>
inline data_type module(const data_type &a,
						const data_type &b)
{
//
/// @warning By its templated nature, this function accepts @c char and
///          @c std::string types. But since it is meaningless make sure
///          to use only numerical datas as input arguments. Otherwise
///          its behavior may be unknown.
//
	return module(a - b);
};
