//
//
//
inline unsigned int first_gf(const unsigned int &given_level, 
                             const unsigned int &given_orbital)
{
    switch(given_level)
    {
        case STO3G: 
        {
            switch(given_orbital)
            {
                case  SUB_SHELL_1s: return 1; break;
                case  SUB_SHELL_2s: return 4; break;
                case SUB_SHELL_2px: return 7; break;
                case SUB_SHELL_2py: return 7; break;
                case SUB_SHELL_2pz: return 7; break;
                           default: return 0; break;
            }
        }
        break;
        default: return 0;
    }
};
