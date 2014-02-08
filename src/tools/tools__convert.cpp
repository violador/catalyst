// ../src/tools/tools__convert.cpp ========================================================== //
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
/// @param [in] input A templated data (either @c char type or number).
//
/// @brief Converts and returns the given @c input in the requested
///        type.
//
/// @return The @c input converted, if it was possible.
//
/// @cite boost_lexical_cast
//
template <typename data_type0, typename data_type1>
inline data_type0 convert(const data_type1 &input)
{
//
/// @note Notice the desired return type should be specified in the
///       function call by the @c "class::function<output>(input)"
///       layout. Also that some conversions such as string to
///       number are meaningless and it may force a compiler error.
//
/// @warning When handling @c char type, this function accepts a
///          pure @c char data and not a string (or array) of @c char,
///          i.e. @c char*.
//
	return boost::lexical_cast<data_type0>(input);
};
//
//
//
/// @param [in] input A @c std::string data.
//
/// @brief Converts and returns the given @c input in the requested
///        type.
//
/// @return The @c input converted, if it was possible.
//
/// @cite boost_lexical_cast
//
template <typename data_type0>
inline data_type0 convert(const std::string &input)
{
//
/// @note Notice the desired return type should be specified in the
///       function call by the @c "class::function<output>(input)"
///       layout.
//
	return boost::lexical_cast<data_type0>(input);
};
