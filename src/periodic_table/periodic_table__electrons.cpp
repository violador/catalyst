//
//
//
inline unsigned int core_electrons(const unsigned int &given_element)
{
    switch((given_element >= 1) and (given_element <= total_elements))
    {
        case false:
        {
            return 0;
        }
        break;
        case true:
        {
            periodic_table::database(given_element);
            return element_core_electrons;
        }
        break;
    }
};
//
//
//
inline unsigned int valence_electrons(const unsigned int &given_element)
{
    switch((given_element >= 1) and (given_element <= total_elements))
    {
        case false:
        {
            return 0;
        }
        break;
        case true:
        {
            periodic_table::database(given_element);
            return element_valence_electrons;
        }
        break;
    }
};
//
//
//
inline unsigned int core_electrons()
{
    switch(std_database_ready)
    {
        case false: return 0; break;
        case  true: return element_core_electrons; break;
    }
};
//
//
//
inline unsigned int valence_electrons()
{
    switch(std_database_ready)
    {
        case false: return 0; break;
        case  true: return element_valence_electrons; break;
    }
};
