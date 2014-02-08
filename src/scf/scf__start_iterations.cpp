// ../src/scf/scf__start_iterations.cpp ===================================================== //
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
inline void start_iterations(array &h_matrix, array &s_matrix, array &v_matrix)
{
    global_log::file.write_debug_msg("algorithm::scf::start_iterations(): Invoking roothaan_equation_solver()");
    scf_iterations_ready = false;
    roothaan_equation_solver(h_matrix, s_matrix, v_matrix);
    scf_iterations_ready = true;
};