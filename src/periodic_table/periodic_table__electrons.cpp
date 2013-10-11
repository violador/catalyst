//
//
//
inline unsigned int core_electrons(const unsigned int &element)
{
    if((element > 0) and (element <= total_elements))
    {
        periodic_table::database(element);
        return element_core_electrons;
    }
    else
    {
        return 0;
    }
}
//
//
//
inline unsigned int valence_electrons(const unsigned int &element)
{
    if((element > 0) and (element <= total_elements))
    {       
        periodic_table::database(element);
        return element_valence_electrons;
    }
    else
    {
        return 0;
    }
}
