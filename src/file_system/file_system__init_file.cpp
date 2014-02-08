// ../src/file_system/file_system__init_file.cpp ============================================ //
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
/// @param [in] given_pathname A string pattern with the desired path.
//
/// @param [in] given_filename A string pattern with the desired file.
//
/// @brief A help function used to initialize the current file.
//
/// @return A @c boost::filesystem::path pointer.
//
/// @cite boost_filesystem
//
inline boost::filesystem::path* init_file(const std::string &given_filename,
										  const std::string &given_pathname)
{
//
/// @note Notice that if the @c given_pathname is an empty string, the function
///       uses the default directory defined in the tools::default_current_dir().
//
	switch(given_pathname.std::string::empty())
	{
		case false:
		{
			boost::filesystem::path init(given_pathname + given_filename);
			file = init;
			return &file;
		}
		break;
		case true:
		{
			boost::filesystem::path init(tools::default_current_dir() + given_filename);
			file = init;
			return &file;
		}
		break;
	}
	return NULL;
};
//
//
//
/// @brief A help function used to initialize the file with the default path,
///        defined in the tools::default_current_dir(), as the current path.
//
/// @return A @c boost::filesystem::path pointer.
//
/// @cite boost_filesystem
//
inline boost::filesystem::path* init_file(const std::string &given_filename)
{
	boost::filesystem::path init(tools::default_current_dir() + given_filename);
	file = init;
	return &file;
};
//
//
//
/// @brief A help function used to initialize no file in the default path,
///        defined in the tools::default_current_dir(), as the current path.
//
/// @return A @c boost::filesystem::path pointer.
//
/// @cite boost_filesystem
//
inline boost::filesystem::path* init_file()
{
	boost::filesystem::path init(tools::default_current_dir());
	file = init;
	return &file;
};
