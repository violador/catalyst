//
//
//
inline unsigned int angular_component_x(const unsigned int &given_orbital)
{
    switch(given_orbital)
    {
        case  SUB_SHELL_1s: return 0; break;
        case  SUB_SHELL_2s: return 0; break;
        case SUB_SHELL_2px: return 1; break;
        case SUB_SHELL_2py: return 0; break;
        case SUB_SHELL_2pz: return 0; break;
                   default: return 0; 
    }
};
//
//
//
inline unsigned int angular_component_y(const unsigned int &given_orbital)
{
    switch(given_orbital)
    {
        case  SUB_SHELL_1s: return 0; break;
        case  SUB_SHELL_2s: return 0; break;
        case SUB_SHELL_2px: return 0; break;
        case SUB_SHELL_2py: return 1; break;
        case SUB_SHELL_2pz: return 0; break;
                   default: return 0; 
    }
};
//
//
//
inline unsigned int angular_component_z(const unsigned int &given_orbital)
{
    switch(given_orbital)
    {
        case  SUB_SHELL_1s: return 0; break;
        case  SUB_SHELL_2s: return 0; break;
        case SUB_SHELL_2px: return 0; break;
        case SUB_SHELL_2py: return 0; break;
        case SUB_SHELL_2pz: return 1; break;
                   default: return 0; 
    }
};
