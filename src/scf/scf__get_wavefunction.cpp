//
//
//
inline array *get_wavefunction()
{
    switch(scf_iterations_ready)
    {
        case false: return NULL;            break;
        case  true: return &f_eigenvectors; break;
    }
};
