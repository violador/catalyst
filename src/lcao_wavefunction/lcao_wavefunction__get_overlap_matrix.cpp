//
//
//
inline array *get_overlap_matrix()
{
    switch(overlap_matrix_ready)
    {
        case false: return NULL; break;
        case  true: return &s_matrix; break;
    }
};
