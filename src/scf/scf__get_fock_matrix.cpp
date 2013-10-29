//
//
//
inline array *get_fock_matrix() 
{
    switch(scf_iterations_ready)
    {
        case false: return NULL;      break;
        case  true: return &f_matrix; break;
    }
};
