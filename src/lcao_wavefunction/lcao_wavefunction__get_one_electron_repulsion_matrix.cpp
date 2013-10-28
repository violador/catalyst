//
//
//
inline array *get_one_electron_repulsion_matrix()
{
    switch(repulsion_matrix1_ready)
    {
        case false: return NULL; break;
        case  true: return &v_matrix1; break;
    }
};
