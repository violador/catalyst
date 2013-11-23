// ../src/periodic_table/periodic_table__sto3g_set_size.cpp ----------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: The setter of default STO-3G number of primitive functions per set 
//              for a given element. From elements H to I. 
//
// References: EMSL Basis Set Exchange Library.
//
// ------------------------------------------------------------------------------------- //
#include "periodic_table.hpp"
//
//
//
unsigned int periodic_table::sto3g_set_size(const unsigned int &element)
{
    switch(element)
    {
        case 1:
        {
            return 3;
        }
        break;
        case 2:
        {
            return 3;
        }
        break;
        case 3:
        {
            return 9;
        }
        break;
        case 4:
        {
            return 9;
        }
        break;
        case 5:
        {
            return 9;
        }
        break;
        case 6:
        {
            return 9;
        }
        break;
        case 7:
        {
            return 9;
        }
        break;
        case 8:
        {
            return 9;
        }
        break;
        case 9:
        {
            return 9;
        }
        break;
        case 10:
        {
            return 9;
        }
        break;
        case 11:
        {
            return 15;
        }
        break;
        case 12:
        {
            return 15;
        }
        break;
        case 13:
        {
            return 15;
        }
        break;
        case 14:
        {
            return 15;
        }
        break;
        case 15:
        {
            return 15;
        }
        break;
        case 16:
        {
            return 15;
        }
        break;
        case 17:
        {
            return 15;
        }
        break;
        case 18:
        {
            return 15;
        }
        break;
        case 19:
        {
            return 21;
        }
        break;
        case 20:
        {
            return 21;
        }
        break;
        case 21:
        {
            return 24;
        }
        break;
        case 22:
        {
            return 24;
        }
        break;
        case 23:
        {
            return 24;
        }
        break;
        case 24:
        {
            return 24;
        }
        break;
        case 25:
        {
            return 24;
        }
        break;
        case 26:
        {
            return 24;
        }
        break;
        case 27:
        {
            return 24;
        }
        break;
        case 28:
        {
            return 24;
        }
        break;
        case 29:
        {
            return 24;
        }
        break;
        case 30:
        {
            return 24;
        }
        break;
        case 31:
        {
            return 24;
        }
        break;
        case 32:
        {
            return 24;
        }
        break;
        case 33:
        {
            return 24;
        }
        break;
        case 34:
        {
            return 24;
        }
        break;
        case 35:
        {
            return 24;
        }
        break;
        case 36:
        {
            return 24;
        }
        break;
        case 37:
        {
            return 30;
        }
        break;
        case 38:
        {
            return 30;
        }
        break;
        case 39:
        {
            return 33;
        }
        break;
        case 40:
        {
            return 33;
        }
        break;
        case 41:
        {
            return 33;
        }
        break;
        case 42:
        {
            return 33;
        }
        break;
        case 43:
        {
            return 33;
        }
        break;
        case 44:
        {
            return 33;
        }
        break;
        case 45:
        {
            return 33;
        }
        break;
        case 46:
        {
            return 33;
        }
        break;
        case 47:
        {
            return 33;
        }
        break;
        case 48:
        {
            return 33;
        }
        break;
        case 49:
        {
            return 33;
        }
        break;
        case 50:
        {
            return 33;
        }
        break;
        case 51:
        {
            return 33;
        }
        break;
        case 52:
        {
            return 33;
        }
        break;
        case 53:
        {
            return 33;
        }
        break;
        default: 
        {
            return 0;
        }
    }
}
