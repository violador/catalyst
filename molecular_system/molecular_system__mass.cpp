//
//
//
inline double mass(const unsigned int &atom)
{
    if(atom_positions_ready and (atom > 0) and (atom <= total_atoms))
    {
        periodic_table get;
        return get.periodic_table::mass(atom_type.array::get(atom));
    }
    else
    {
        return 0.0;
    }
};
//
//
//
inline double mass()
{
    return (atom_positions_ready? total_mass : 0.0);
};
