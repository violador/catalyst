#include "timer.hpp"
//
//
//
timer::timer()
{
    stopped = true;
    counter = 0;
    name = "";
};
//
//
//
timer::timer(settings &runtime_setup, std::string given_name)
{
    init(runtime_setup, given_name);
}
