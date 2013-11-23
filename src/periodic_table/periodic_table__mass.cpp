//
//
//
inline double mass(const unsigned int &element)
{
    switch((element >= 1) and (element <= total_elements))
    {
        case false:
        {
            return 0.0;
        }
        break;
        case true:
        {
            periodic_table::database(element);
            return element_mass;
        }
        break;
    }
};
//
//
//
inline double mass()
{
    switch(std_database_ready)
    {
        case false: return 0.0; break;
        case  true: return element_mass; break;
    }
};
