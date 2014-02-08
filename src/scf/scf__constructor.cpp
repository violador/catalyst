// ../src/scf/scf__constructor.cpp ========================================================== //
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
#include "scf.hpp"
//
//
//
algorithm::scf::scf() 
{
    config = &global_settings::config;
    scf_converged = false;
    scf_iterations_ready = false;
    iteration = 1;
}
//
//
//
algorithm::scf::scf(array &h_matrix, array &s_matrix, array &v_matrix)
{
    global_log::file.write_debug_msg("algorithm::scf::scf(): Invoking algorithm::scf::init()");
    config = &global_settings::config;
    scf_converged = false;
    scf_iterations_ready = false;
    iteration = 1;
    start_iterations(h_matrix, s_matrix, v_matrix);
}