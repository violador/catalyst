//
//
//
inline array *get_fock_matrix() 
{
    switch(scf_converged)
    {
        case false: return NULL;      break;
        case  true: return &f_matrix; break;
    }
};
