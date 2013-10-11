//
//
//
inline std::string control_key_of(const bool &state)
{
    if(state == true)
    {
        return ON_KEY_CONTROL;
    }
    else
    {
        return OFF_KEY_CONTROL;
    }
}

