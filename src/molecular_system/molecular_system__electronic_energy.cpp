//
//
//
inline double electronic_energy()
{
    if(ab_initio_ready)
    {
        return wavefunction -> energy();
    }
    else
    {
        get_wavefunction();
        return wavefunction -> energy();
    }
};
