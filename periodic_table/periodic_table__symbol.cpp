//
//
//
inline std::string symbol(const unsigned int &element)
{
    if((element > 0) and (element <= total_elements))
    {
        periodic_table::database(element);
        return element_symbol;
    }
    else
    {
        return 0;
    }
}
