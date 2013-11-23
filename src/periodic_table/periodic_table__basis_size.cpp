//
//
//
inline unsigned int basis_size()
{
    switch(current_level)
    {
        case STO3G: return 3; break;
        case STO2G: return 2; break;
        case STO1G: return 1; break;
           default: return 0; break;
    }
};
