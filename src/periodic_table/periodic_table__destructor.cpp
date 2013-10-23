#include "periodic_table.hpp"
//
//
//
periodic_table::~periodic_table()
{
    switch(basis_database_ready)
    {
        case true:
        delete[] exponent;
        delete[] coefficient;
        break;
    }
}
