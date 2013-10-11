#include "scf.hpp"
//
//
//
std::string algorithm::scf::check_mo_type(const unsigned int &mo_num) 
{
    if((mo_num > 0) && (mo_num <= f_eigenvectors.size_of_row()))
    {
        if(f_eigenvectors.check_if_column_is(IS_POSITIVE, mo_num))
        {
            return "bonding";
        }
        else if(f_eigenvectors.check_if_column_is(IS_NEGATIVE, mo_num))
        {
            return "bonding";
        }
        else 
        {
            return "antibonding";
        }
    }
    else
    {
        return "";
    }
}
