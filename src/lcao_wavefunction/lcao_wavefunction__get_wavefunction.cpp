//
//
//
void inline *get_wavefunction()
{
    switch(iterative_routine.algorithm::scf::iterations_ready())
    {
        case false: return NULL; break;
        case  true: return wavefunction; break;
    }

};
