//
//
//
inline const unsigned int init_set_size()
{
    switch(current_level)
    {
        case basis::STO_1G: return 0; break;
        case basis::STO_2G: return 0; break;
        case basis::STO_3G: return check_sto3g_size(); break;
        case basis::STO_6G: return 0; break;
                   default: return 0; break;
    }
};
