// ../src/log_file_handler/log_file_handler__timestamp.cpp ================================== //
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
inline std::string timestamp() 
{
    #ifdef USE_OMP
//
    time_t current_time = time(0);
    struct tm *time_info;
    time_info = localtime(&current_time);
    char timestamp[12];
    strftime(timestamp, 12, ", %T]", time_info);
    std::string output(timestamp);
    return "[thread " + tools::convert<std::string>(omp_get_thread_num()) 
                      + output 
                      + " ";
//
    #elif USE_MPI
//
//  Empty so far.
//
    #else
//
    time_t current_time = time(0);
    struct tm *time_info;
    time_info = localtime(&current_time);
    char timestamp[11];
    strftime(timestamp, 11, "[%T]", time_info);
    std::string output(timestamp);
    return output + " ";
//
    #endif
};