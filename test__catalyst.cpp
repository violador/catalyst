#include "globals.hpp"
#include "settings.hpp"
#include "periodic_table.hpp"
#include "sto3g.hpp"
#include "molecular_system.hpp"
#include "tools.hpp"
#include "array.hpp"
#include "file_system.hpp"
#include "log_file_handler.hpp"
#include "global_log.hpp"
#include "timer.hpp"
//
//
//
int main(int argc, char* argv[])
{
/*
    settings a;
    timer my_clock(a);
    boost::timer::cpu_timer a;
    boost::timer::cpu_timer b;
    a.boost::timer::cpu_timer::start();
    my_clock.timer::start();
    for (long i = 0; i < 100000000; ++i)
    {
        std::sqrt(123.456L); // burn some time
        std::cout << "estou no loop!" << std::endl;
        //std::cout << boost::timer::format(a.boost::timer::cpu_timer::elapsed(), (short int) 10,"%w") << std::endl;
    }
    my_clock.timer::stop();
    std::cout << "wall = " << my_clock.timer::get(1) << std::endl;
    std::cout << "sys  = " << my_clock.timer::get(2) << std::endl;
    std::cout << "user = " << my_clock.timer::get(3) << std::endl;
    std::cout << "cpu  = " << my_clock.timer::get(4) << std::endl;
*/
/*
    a.boost::timer::cpu_timer::stop();
    std::cout << "time a = " << boost::timer::format(a.boost::timer::cpu_timer::elapsed(), (short int) 10,"%w") << std::endl;
//
    b.boost::timer::cpu_timer::start();
    b.boost::timer::cpu_timer::stop();
    std::cout << "time b = " << boost::timer::format(b.boost::timer::cpu_timer::elapsed(), (short int) 10,"%w") << std::endl;
*/
//
/*
    tools a;
    std::map<int, double> my_map;
    std::map<int, double>::iterator i = my_map.begin();
    my_map.insert(i, std::pair<int, double>(1, a.generate_double_type(1)));
    my_map.insert(i, std::pair<int, double>(2, a.generate_double_type(2)));
    std::cout << my_map[1] << std::endl;
    std::cout << my_map[2] << std::endl;
    my_map.insert(i, std::pair<int, double>(3, a.generate_double_type(3)));
    std::cout << my_map[3] << std::endl;
    std::cout << my_map[4] << std::endl;
    std::cout << my_map[0] << std::endl;
*/
    return 0;
}
