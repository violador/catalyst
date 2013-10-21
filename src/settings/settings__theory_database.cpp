#include "settings.hpp"
//
//
//
std::string settings::theory_database(const unsigned int &option)
{
    switch(option)
    {
        case 1: return "STO-3G"; break;
        case 2: return "STO-2G"; break;
        case 3: return "STO-1G"; break;
       default: return "";
    }
};
//
//
//
unsigned int settings::theory_database(const std::string &option)
{
    unsigned int i = 0, theory_number = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 1; i <= 3; i++)
    {
        switch(option.compare(theory_database(i)))
        {
            case false: theory_number = i; break;
            case  true: break;
        }
    }
    return theory_number;
};
