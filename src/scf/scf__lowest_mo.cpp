//
//
//
inline unsigned int lowest_mo() 
{
    switch(scf_iterations_ready)
    {
        case false: return 0; break;                             
        case  true: return f_eigenvalues.array::get_min_index(); break;
    }
};
