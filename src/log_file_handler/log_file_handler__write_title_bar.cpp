// ../src/log_file_handler/log_file_handler__write_title_bar.cpp ============================ //
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
inline void write_title_bar(std::string title, 
                            unsigned int size)
{
    switch(log_file_ready)
    {
        case true:
        std::string stamp = timestamp();
        if(size > stamp.std::string::length() + title.std::string::length() + 1) 
        {
            log_file << "\n";
            size -= stamp.std::string::length() + title.std::string::length() + 1; 
            log_file << stamp << title << " ";
            log_file.std::fstream::width(size);
            log_file.std::fstream::fill(TITLE_BAR_SYMBOL);
            log_file << "\n";
            log_file << std::endl;
        }
        else
        {
            log_file << "\n";
            log_file << stamp << title;
            log_file << "\n";
            log_file << std::endl;
        }
        break;
    }
};