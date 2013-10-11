//
//
//
inline unsigned int type(const std::string &given_symbol)
{
    for(unsigned int i = 1; i <= total_elements; i++)
    {
        if(symbol(i) == given_symbol)
        {
            return i;
        }
    }
    return 0;
}
