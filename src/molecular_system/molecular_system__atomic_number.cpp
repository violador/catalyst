//
//
//
inline double atomic_number(const unsigned int &atom)
{
    if(atom_types_ready and (atom > 0) and (atom <= total_atoms))
    {
        return ((double) atom_type.array::get(atom));
    }
    else
    {
        return 0.0;
    }
};
