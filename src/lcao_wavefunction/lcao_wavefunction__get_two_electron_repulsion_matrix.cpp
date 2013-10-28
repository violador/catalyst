//
//
//
inline array *get_two_electron_repulsion_matrix()
{
    switch(repulsion_matrix2_ready)
    {
        case false: return NULL; break;
        case  true: return &v_matrix2; break;
    }
};
