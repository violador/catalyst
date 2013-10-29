//
//
//
void inline *get_fock_matrix()
{
    switch(iterative_routine.algorithm::scf::iterations_ready())
    {
        case false: return NULL; break;
        case  true: return f_matrix; break;
    }

};
