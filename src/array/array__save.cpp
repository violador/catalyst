// ../src/array/array__save.cpp ============================================================= //
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
inline void save()
{
    input.file_system::init(config -> scratch_dir(),
                                   build_filename());
    switch(input.file_system::exists())
    {
        case true: book_data(); break;
    }
};
//
//
//
inline void save(std::string &filename)
{
    input.file_system::init(config -> scratch_dir(),
                                          filename);
    switch(input.file_system::exists())
    {
        case true: book_data(); break;
    }
};