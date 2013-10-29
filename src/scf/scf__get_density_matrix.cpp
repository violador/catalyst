//
//
//
inline array *get_density_matrix() 
{
    switch(scf_iterations_ready)
    {
        case false: return NULL;      break;
        case  true: return &p_matrix; break;
    }
};
