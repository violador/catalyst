//
//
//
inline double nuclear_repulsion_energy()
{
    if(nuclear_repulsion_ready)
    {
        return nuclear_repulsion;
    }
    else
    {
        get_nuclear_repulsion();
        return nuclear_repulsion;
    }
};
