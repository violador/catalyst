//
//
//
inline void init_data()
{
    element_symbol = "";
    element_name = "";
    element_config = "";
    element_core_electrons = 0;
    element_valence_electrons = 0;
    total_orbitals = 0;
    element_mass = 0.0;
    covalent_radius = 0.0;
    total_functions = 0;
    std_database_ready = false;
    basis_database_ready = false;
//
    exponent = new double[1];
    coefficient = new double[1];
//
    exponent[0] = 0.0;
    coefficient[0] = 0.0;
}; 
