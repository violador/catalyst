//
//
//
inline double x()
{
    if(system_com_ready)
    {
        return system_com_x;
    }
    else
    {
        get_system_com();
        return system_com_x;
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
            return position_x.array::get(atom);
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
            return velocity_x.array::get(atom);
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
