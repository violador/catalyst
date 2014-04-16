#include "timer.hpp"
//
//
//
timer::timer(): stopped(true),
				timer_length(10),
				counter(0),
				name(""),
				config(&global_settings::config)
{
// Empty constructor.
}
//
//
//
timer::timer(std::string &given_name): stopped(true),
									   timer_length(10),
									   counter(0),
									   name(given_name),
									   config(&global_settings::config)
{
// Empty constructor.
}
