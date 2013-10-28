//
//
//
inline array *get_core_hamiltonian_matrix()
{
    switch(hamiltonian_matrix_ready)
    {
        case false: return NULL; break;
        case  true: return &h_matrix; break;
    }
};
