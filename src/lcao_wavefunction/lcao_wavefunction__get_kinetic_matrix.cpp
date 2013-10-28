//
//
//
inline array *get_kinetic_matrix()
{
    switch(kinetic_matrix_ready)
    {
        case false: return NULL; break;
        case  true: return &t_matrix; break;
    }
};
