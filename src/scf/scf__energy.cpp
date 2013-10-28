//
//
//
inline double energy() 
{
    return scf_energy[iteration];
};
//
//
//
inline double energy(const unsigned int &given_iteration)
{
    switch((given_iteration >= 1) and (given_iteration <= iteration))
    {
        case false: return 0.0; break;
        case  true: return scf_energy[given_iteration]; break;
    }
}; 
