// ../src/periodic_table/periodic_table__sto3g_coefficient_database.cpp ----------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: The setter of default STO-3G coefficient values for each 
//              element shell, from elements H to I (1 - 53).
//
// References: EMSL Basis Set Exchange Library.
//
// ------------------------------------------------------------------------------------- //
#include "periodic_table.hpp"
//
//
//
void periodic_table::sto3g_coefficient_database(const unsigned int &given_element)
{
    switch((given_element >= 1) and (given_element <= STO3G_RANGE))
    {
        case false: return; break;
        case  true: coefficient = new double[sto3g_set_size(given_element) + 1]; break;
    }
    switch(given_element)
    {
        case 1:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
        }
        break;
        case 2:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
        }
        break;
        case 3:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 4:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 5:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 6:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 7:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 8:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 9:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 10:
        {
            coefficient[1] = 0.15432897;
            coefficient[2] = 0.53532814;
            coefficient[3] = 0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] = 0.39951283;
            coefficient[6] = 0.70011547;
            coefficient[7] = 0.15591627;
            coefficient[8] = 0.60768372;
            coefficient[9] = 0.39195739;
        }
        break;
        case 11:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 12:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 13:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 14:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 15:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 16:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 17:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 18:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.09996722919;
            coefficient[5] = 0.39951282610;
            coefficient[6] = 0.70011546890;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.01058760429;
            coefficient[14] = 0.59516700530;
            coefficient[15] = 0.46200101200;
        }
        break;
        case 19:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.0105876043;
            coefficient[14] = 0.5951670053;
            coefficient[15] = 0.4620010120;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
        }
        break;
        case 20:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2196203690;
            coefficient[11] = 0.2255954336;
            coefficient[12] = 0.9003984260;
            coefficient[13] = 0.0105876043;
            coefficient[14] = 0.5951670053;
            coefficient[15] = 0.4620010120;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
        }
        break;
        case 21:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 22:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 23:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 24:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 25:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 26:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 27:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 28:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 29:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 30:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 31:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 32:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 33:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 34:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 35:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 36:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = 0.2197679508;
            coefficient[23] = 0.6555473627;
            coefficient[24] = 0.2865732590;
        }
        break;
        case 37:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
        }
        break;
        case 38:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3088441215;
            coefficient[17] = 0.0196064117;
            coefficient[18] = 1.1310344420;
            coefficient[19] = -0.1215468600;
            coefficient[20] = 0.5715227604;
            coefficient[21] = 0.5498949471;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
        }
        break;
        case 39:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 40:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 41:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 42:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 43:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 44:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 45:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 46:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 47:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 48:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515111;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109533;
            coefficient[18] = 1.1557874500;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 49:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109534;
            coefficient[18] = 1.1155787450;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 50:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109534;
            coefficient[18] = 1.1155787450;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 51:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109534;
            coefficient[18] = 1.1155787450;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 52:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109534;
            coefficient[18] = 1.1155787450;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
        case 53:
        {
            coefficient[1] = 0.1543289673;
            coefficient[2] = 0.5353281423;
            coefficient[3] = 0.4446345422;
            coefficient[4] = -0.0999672292;
            coefficient[5] = 0.3995128261;
            coefficient[6] = 0.7001154689;
            coefficient[7] = 0.1559162750;
            coefficient[8] = 0.6076837186;
            coefficient[9] = 0.3919573931;
            coefficient[10] = -0.2277635023;
            coefficient[11] = 0.2175436044;
            coefficient[12] = 0.9166769611;
            coefficient[13] = 0.0049515112;
            coefficient[14] = 0.5777664691;
            coefficient[15] = 0.4846460366;
            coefficient[16] = -0.3306100626;
            coefficient[17] = 0.0576109534;
            coefficient[18] = 1.1155787450;
            coefficient[19] = -0.1283927634;
            coefficient[20] = 0.5852047641;
            coefficient[21] = 0.5439442040;
            coefficient[22] = -0.3842642607;
            coefficient[23] = -0.1972567438;
            coefficient[24] = 1.3754955120;
            coefficient[25] = -0.3481691526;
            coefficient[26] = 0.6290323690;
            coefficient[27] = 0.6662832743;
            coefficient[28] = 0.2197679508;
            coefficient[29] = 0.6555473627;
            coefficient[30] = 0.2865732590;
            coefficient[31] = 0.1250662138;
            coefficient[32] = 0.6686785577;
            coefficient[33] = 0.3052468245;
        }
        break;
    }
}
