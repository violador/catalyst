//
//
//
inline std::string name(const unsigned int &element)
{
    if((element > 0) and (element <= total_elements))
    {
        periodic_table::database(element);
        return element_name;
    }
    else
    {
        return 0;
    }
}
