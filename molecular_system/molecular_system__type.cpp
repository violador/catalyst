//
//
//
inline unsigned int type(const unsigned int &atom)
{
    return (atom_types_ready and (atom > 0) and (atom <= total_atoms)? atom_type.array::get(atom) : 0);
};
