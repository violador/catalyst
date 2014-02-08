// ../src/file_system/file_system__size.cpp ================================================= //
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
/// @brief Returns the file size in bytes if the file exists.
//
/// @return A non-negative real number. Or returns zero if the
///         file do not exist.
//
/// @cite boost_filesystem
//
inline double size()
{
	switch(exists())
	{
		case false: return 0.0; break;
		case  true: return boost::filesystem::file_size(file); break;
	}
};
