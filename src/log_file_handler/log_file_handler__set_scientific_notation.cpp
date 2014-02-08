// ../src/log_file_handler/log_file_handler__set_scientific_notation.cpp ==================== //
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
inline void set_scientific_notation(const unsigned int &width)
{
    switch(log_file_ready)
    {
        case true:
        log_file << std::scientific;
        log_file.std::fstream::width(width);
        log_file.std::fstream::precision(config -> numeric_precision());
        log_file << std::right;
        break;
    }
};
//
//
//
inline void set_scientific_notation()
{
    switch(log_file_ready)
    {
        case true:
        log_file << std::scientific;
        log_file.std::fstream::width(MAX_PRECISION + SPACE_LENGTH);
        log_file.std::fstream::precision(config -> numeric_precision());
        log_file << std::right;
        break;
    }
};