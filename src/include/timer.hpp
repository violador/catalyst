// ../src/include/timer.hpp ------------------------------------------------------------- //
//
// File author: Humberto Jr.
//
// Date: 10/2013
//
// Description: The timer class defines the type of variables used to calculate elapsed
//              time between the calls of the timer::start() and timer::stop() member
//              functions. It will store the times for every timer::start()/timer::stop
//              calls without lost the last values. Each time measurement can be check-
//              ed independently with the timer::get() member function. The sort of ti-
//              mes stored are: wall time, user time, system time and CPU usage in %.
//              Where wall time = user time + system time. All in seconds.
//
//
// References: http://www.boost.org/doc/libs/1_54_0/libs/timer/doc/cpu_timers.html
//
// ------------------------------------------------------------------------------------- //
#ifndef __TIMER_HPP
    #define __TIMER_HPP
    #include "settings.hpp"
    #include "global_settings.hpp"
//
//
//
class timer
{
    private:
//
    boost::timer::cpu_timer chronometer;             // The boost::timer::cpu_timer type variable to get the elapsed time.
    bool stopped;                                    // The chronometer state. True if it is stopped, false otherwise.
	short int timer_length;
    unsigned int counter;                            // The measurements counter.
    std::map<unsigned int, std::string> wall_time;   // The container to store the wall time for a given counter value.
    std::map<unsigned int, std::string> system_time; // The container to store the system time for a given counter value.
    std::map<unsigned int, std::string> user_time;   // The container to store the user time for a given counter value.
    std::map<unsigned int, std::string> cpu_usage;   // The container to store the CPU usage (%) for a given counter value.
    std::string name;
    settings *config;                                // A pointer-object to link with any object of settings type.
//
	#include "timer__elapsed_wall_time.cpp"
	#include "timer__elapsed_user_time.cpp"
	#include "timer__elapsed_system_time.cpp"
	#include "timer__elapsed_cpu_usage.cpp"
//
    public:
//
//  Class identifier:
    static const int id = 25939;
//
//  Declaring the class constructor:
    timer();
//
//  Declaring the class constructor:
    timer(std::string &given_name);
//
//  get(): To return the measured time.
    std::string get(unsigned int option, unsigned int measurement_number = 0);
//
//
    void stop();
//
//  Defining some alias for the get() member function options:
    #define WALL_TIME   1
    #define SYSTEM_TIME 2
    #define USER_TIME   3
    #define CPU_USAGE   4
    #define TIMER_NAME  5
//
//  Including the inline/template/public member functions:
    #include "timer__start.cpp"
    #include "timer__set_name.cpp"
    #include "timer__basic_assignment.cpp"
	#include "timer__set_timer_length.cpp"
};
#endif
