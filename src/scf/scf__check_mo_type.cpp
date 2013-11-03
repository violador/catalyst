//
//
//
inline std::string check_mo_type(const unsigned int &mo_number) 
{
    switch((mo_number >= 1) and (mo_number <= f_eigenvectors.array::size_of_row()))
    {
        case false:
        {
            return "";
        }
        break;
        case true:
        {
            switch(f_eigenvectors.array::check_if_column_is(IS_POSITIVE, mo_number)
                   or f_eigenvectors.array::check_if_column_is(IS_NEGATIVE, mo_number))
            {
               case false: return "antibonding"; break;
               case  true: return "bonding";     break;
            }
        }
        break;
    }
};
