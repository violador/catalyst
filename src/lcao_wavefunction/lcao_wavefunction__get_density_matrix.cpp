//
//
//
void inline *get_density_matrix()
{
    switch(iterative_routine.algorithm::scf::iterations_ready())
    {
        case false: return NULL; break;
        case  true: return p_matrix; break;
    }

};
