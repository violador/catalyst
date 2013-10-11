// ../src/periodic_table/periodic_table__sto3g_coefficient_database.cpp ----------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: The setter of default STO-3G coefficient values for each 
//              element shell, from elements H to I (1 - 35).
//
// References: EMSL Basis Set Exchange Library.
//
// ------------------------------------------------------------------------------------- //
#include "periodic_table.hpp"
//
//
//
void periodic_table::sto3g_coefficient_database(const unsigned int &element)
{
    coefficient = new double[sto3g_total_functions(element) + 1];
    switch(element)
    {
        case 1:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
        }
        break;
        case 2:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
        }
        break;
        case 3:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 4:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 5:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 6:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 7:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 8:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 9:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 10:
        {
            coefficient[1] =  0.15432897;
            coefficient[2] =  0.53532814;
            coefficient[3] =  0.44463454;
            coefficient[4] = -0.09996723;
            coefficient[5] =  0.39951283;
            coefficient[6] =  0.70011547;
            coefficient[7] =  0.15591627;
            coefficient[8] =  0.60768372;
            coefficient[9] =  0.39195739;
        }
        break;
        case 11:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 12:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 13:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 14:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 15:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 16:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 17:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 18:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.01058760429;
            coefficient[13] =  0.59516700530;
            coefficient[14] =  0.46200101200;
        }
        break;
        case 19:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.0105876043;
            coefficient[13] =  0.5951670053;
            coefficient[14] =  0.4620010120;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
        }
        break;
        case 20:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.219620369;
            coefficient[10] =  0.225595433;
            coefficient[11] =  0.900398426;
            coefficient[12] =  0.0105876043;
            coefficient[13] =  0.5951670053;
            coefficient[14] =  0.4620010120;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
        }
        break;
        case 21:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 22:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 23:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 24:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 25:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 26:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 27:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 28:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 29:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 30:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 31:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 32:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 33:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 34:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 35:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 36:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] =  0.219767950;
            coefficient[20] =  0.655547362;
            coefficient[21] =  0.286573259;
        }
        break;
        case 37:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
        }
        break;
        case 38:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.308844121;
            coefficient[15] =  0.019606411;
            coefficient[16] =  1.131034442;
            coefficient[17] =  0.1215468600;
            coefficient[18] =  0.5715227604;
            coefficient[19] =  0.5498949471;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
        }
        break;
        case 39:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 40:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 41:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 42:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 43:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 44:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 45:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 46:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 47:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 48:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515111;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.155787450;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 49:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.115578745;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 50:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.115578745;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 51:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.115578745;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 52:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.115578745;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
        case 53:
        {
            coefficient[1] =  0.1543289673;
            coefficient[2] =  0.5353281423;
            coefficient[3] =  0.4446345422;
            coefficient[4] = -0.099967229;
            coefficient[5] =  0.399512826;
            coefficient[6] =  0.700115468;
            coefficient[7] =  0.1559162750;
            coefficient[8] =  0.6076837186;
            coefficient[9] =  0.3919573931;
            coefficient[9] = -0.227763502;
            coefficient[10] =  0.217543604;
            coefficient[11] =  0.916676961;
            coefficient[12] =  0.0049515112;
            coefficient[13] =  0.5777664691;
            coefficient[14] =  0.4846460366;
            coefficient[14] = -0.330610062;
            coefficient[15] =  0.057610953;
            coefficient[16] =  1.115578745;
            coefficient[17] =  0.1283927634;
            coefficient[18] =  0.5852047641;
            coefficient[19] =  0.5439442040;
            coefficient[19] = -0.384264260;
            coefficient[20] = -0.197256743;
            coefficient[21] =  1.375495512;
            coefficient[22] =  0.3481691526;
            coefficient[23] =  0.6290323690;
            coefficient[24] =  0.6662832743;
            coefficient[24] =  0.219767950;
            coefficient[25] =  0.655547362;
            coefficient[26] =  0.286573259;
            coefficient[27] =  0.125066213;
            coefficient[28] =  0.668678557;
            coefficient[29] =  0.305246824;
        }
        break;
    }
}
