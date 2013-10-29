//
//
//
inline double electronic_energy()
{
    switch(lcao_psi.lcao_wavefunction::scf_ready())
    {
        case false:
        {
            get_wavefunction();
            return lcao_psi.lcao_wavefunction::energy();
        }
        break;
        case true:
        {
            return lcao_psi.lcao_wavefunction::energy();
        }
        break;
    }
};
