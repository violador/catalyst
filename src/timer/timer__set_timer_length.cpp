//
//
//
/// @param [in] given_timer_length A short integer number
//
/// @brief Changes the current timer length, if the internal @c
///        chronometer is stopped.
//
/// @return None.
//
inline void set_timer_length(const short int &given_timer_length)
{
	switch(stopped)
	{
		timer_length = given_timer_length;
	}
};
