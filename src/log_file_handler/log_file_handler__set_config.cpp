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
void inline set_config(settings &runtime_setup)
{
	config = &runtime_setup;
};
