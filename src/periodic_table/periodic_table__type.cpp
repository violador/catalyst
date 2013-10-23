//
//
//
inline unsigned int type(const std::string &given_symbol)
{
    unsigned int i = 0, type_found = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 1; i <= total_elements; i++)
    {
        switch(given_symbol.compare(symbol(i)))
        {
            case false: type_found = i; break;
            case  true: break;
        }
    }
    return type_found;
}
