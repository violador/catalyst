//
//
//
inline std::string symbol(const unsigned int &given_element)
{
    switch((given_element >= 1) and (given_element <= total_elements))
    {
        case false:
        {
            return "";
        }
        break;
        case true:
        {
            periodic_table::database(given_element);
            return element_symbol;
        }
        break;
    }
};
//
//
//
inline std::string symbol()
{
    switch(standard_database_ready)
    {
        case false: return ""; break;
        case  true: return element_symbol; break;
    }
};
