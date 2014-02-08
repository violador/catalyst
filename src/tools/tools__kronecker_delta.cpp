// ../src/tools/tools__kronecker_delta.cpp ================================================== //
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
/// @param [in] a A templated number.
//
/// @param [in] b A templated number.
//
/// @brief Calculates the Kronecker's delta between the given @c a and @c b.
//
/// @return One if @c a and @c b are equal and zero otherwise.
//
template<typename data_type>
inline data_type kronecker_delta(const data_type &a,
                                 const data_type &b)
{
//
/// @warning The type of @c a and @c b must be the same. Otherwise it's
///          behavior is unknown. Also, by its templated nature, this
///          function accepts @c char and @c std::string types. But it
///          is meaningless too, thus make sure to use only numerical
///          datas as input arguments.
//
	switch(a == b)
	{
		case false: return (data_type) 0.0; break;
		case  true: return (data_type) 1.0; break;
	}
};
