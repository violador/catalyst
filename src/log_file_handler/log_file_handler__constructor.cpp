// ../src/log_file_handler/log_file_handler__constructor.cpp ================================ //
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
#include "log_file_handler.hpp"
//
//
//
log_file_handler::log_file_handler(): log_file_ready(false),
                                      config(&global_settings::config)
{
    manager.file_system::init(config -> work_dir(), config -> log_file());
    switch(config -> output_mode())
    {
        case true:
        switch(manager.file_system::exists())
        {
            case false: open_and_init(); break;
            case  true: open(); break;
        }
        break;
    }
}
//
//
//
log_file_handler::log_file_handler(settings &runtime_setup): log_file_ready(false),
                                                             config(&runtime_setup)
{
    manager.file_system::init(config -> work_dir(), config -> log_file());
    switch(config -> output_mode())
    {
        case true:
        switch(manager.file_system::exists())
        {
            case false: open_and_init(); break;
            case  true: open(); break;
        }
        break;
    }
}
//
//
//
log_file_handler::log_file_handler(log_file_handler &given): manager(given.manager),
                                                             log_file_ready(given.log_file_ready),
                                                             config(&global_settings::config)
{
    switch(given.log_file_ready)
    {
        case true:
        this -> manager.file_system::open_txt_output(this -> log_file);
        break;
    }
}