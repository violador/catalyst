//
//
//
inline unsigned int orbitals_number(const unsigned int &given_element)
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
            database(given_element);
            return total_orbitals;
        }
        break;
    }
};
//
//
//
inline unsigned int orbitals_number()
{
    switch(std_database_ready)
    {
        case false: return 0; break;
        case  true: return total_orbitals; break;
    }
};
