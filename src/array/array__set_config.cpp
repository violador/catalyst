//
//
//
/// @param [in] runtime_setup A @c settings object
///                           previously declared.
//
/// @brief Sets a new configuration object instead
///        of the global one.
//
/// @return None.
//
inline void set_config(settings &runtime_setup)
{
	switch(not_deleted())
	{
		case true: config = &runtime_setup;
	}
};
