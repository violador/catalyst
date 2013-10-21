//
//
//
inline double x()
{
    switch(system_com_ready)
    {
        case true: 
        {
            return system_com_x;
        }
        break;
        case false:
        {
            get_system_com();
            return system_com_x;
        }
        break;
    }
};
//
//
//
inline double x(const unsigned int &option, const unsigned int &atom)
{
    switch(option)
    {
    case 1:
    {
        if(atom_positions_ready and (atom > 0) and (atom <= total_atoms))
        {
            return position_x(atom);
        }
        else
        {
            return 0.0;
        }
    }
    break;
    case 2:
    {
        if(atom_velocities_ready and (atom > 0) and (atom <= total_atoms))
        {
            return velocity_x(atom);
        }
        else
        {
            return 0.0;  
        }
    }
    break;
    default: return 0.0;
    } 
};
