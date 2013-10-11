//
//
//
inline double mass(const unsigned int &element)
{
    if((element > 0) and (element <= total_elements))
    {
        periodic_table::database(element);
        return element_mass;
    }
    else
    {
        return 0.0;
    }
}
