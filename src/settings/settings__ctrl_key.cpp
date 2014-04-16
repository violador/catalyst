//
//
//
/// @param [in] state The current @c bool state of some given key.
//
/// @brief Returns the 'on' or 'off' key, according with the given @c state.
//
/// @return A string pattern.
//
inline std::string ctrl_key(const bool &state)
{
	switch(state)
	{
		case false: return tools::off_ctrl_key(); break;
		case  true: return  tools::on_ctrl_key(); break;
	}
};
