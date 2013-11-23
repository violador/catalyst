//
//
//
inline std::string name(const unsigned int &given_element)
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
            return element_name;
        }
        break;
    }
};
//
//
//
inline std::string name()
{
    switch(std_database_ready)
    {
        case false: return ""; break;
        case  true: return element_name; break;
    }
};
