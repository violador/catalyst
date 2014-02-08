// ../src/file_system/file_system__close.cpp ================================================ //
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
inline void close(std::fstream &file)
{
    file.std::fstream::close();
    stream_ready = false;
};
//
//
//
inline void close()
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            switch(input_file.std::fstream::is_open())
            {
                case true:
                input_file.std::fstream::close();
                stream_ready = false;
                break;
            }
        }
        #pragma omp section
        {
            switch(output_file.std::fstream::is_open())
            {
                case true:
                output_file.std::fstream::close();
                stream_ready = false;
                break;
            }
        }
    }
};