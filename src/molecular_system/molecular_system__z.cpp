//
//
//
inline double z()
{
    if(system_com_ready)
    {
        return system_com_z;
    }
    else
    {
        get_system_com();
        return system_com_z;
    }
};
//
//
//
inline double z(const unsigned int &option, const unsigned int &atom)
{
    switch(option)
    {
    case 1:
    {
        if(atom_positions_ready and (atom > 0) and (atom <= total_atoms))
        {
            return position_z(atom);
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
            return velocity_z(atom);
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
