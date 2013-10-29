//
//
//
inline double energy()
{
    switch(iterative_routine.algorithm::scf::iterations_ready())
    {
        case false: return 0.0; break;
        case  true: return iterative_routine.algorithm::scf::energy(); break;
    }
};
