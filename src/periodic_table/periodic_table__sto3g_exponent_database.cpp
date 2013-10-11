// ../src/periodic_table/periodic_table__sto3g_exponent_database.cpp ------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: The setter of default STO-3G exponent values for each 
//              element shell, from elements H to I (1 - 35).
//
// References: EMSL Basis Set Exchange Library.
//
// ------------------------------------------------------------------------------------- //
#include "periodic_table.hpp"
//
//
//
void periodic_table::sto3g_exponent_database(const unsigned int &element)
{
    exponent = new double[sto3g_total_functions(element) + 1];
    switch(element)
    {
        case 1:
        {
            exponent[1] = 3.42525091;
            exponent[2] = 0.62391373;
            exponent[3] = 0.16885540;
        }
        break;
        case 2:
        {
            exponent[1] = 6.36242139;
            exponent[2] = 1.15892300;
            exponent[3] = 0.31364979;
        }
        break;
        case 3:
        {
            exponent[1] = 16.1195750;
            exponent[2] = 2.9362007;
            exponent[3] = 0.7946505;
            exponent[4] = 0.6362897;
            exponent[5] = 0.1478601;
            exponent[6] = 0.0480887;
            exponent[7] = 0.6362897;
            exponent[8] = 0.1478601;
            exponent[9] = 0.0480887;
        }
        break;
        case 4:
        {
            exponent[1] = 30.1678710;
            exponent[2] = 5.4951153;
            exponent[3] = 1.4871927;
            exponent[4] = 1.3148331;
            exponent[5] = 0.3055389;
            exponent[6] = 0.0993707;
            exponent[7] = 1.3148331;
            exponent[8] = 0.3055389;
            exponent[9] = 0.0993707;
        }
        break;
        case 5:
        {
            exponent[1] = 48.7911130;
            exponent[2] = 8.8873622;
            exponent[3] = 2.4052670;
            exponent[4] = 2.2369561;
            exponent[5] = 0.5198205;
            exponent[6] = 0.1690618;
            exponent[7] = 2.2369561;
            exponent[8] = 0.5198205;
            exponent[9] = 0.1690618;
        }
        break;
        case 6:
        {
            exponent[1] = 71.6168370;
            exponent[2] = 13.0450960;
            exponent[3] = 3.5305122;
            exponent[4] = 2.9412494;
            exponent[5] = 0.6834831;
            exponent[6] = 0.2222899;
            exponent[7] = 2.9412494;
            exponent[8] = 0.6834831;
            exponent[9] = 0.2222899;
        }
        break;
        case 7:
        {
            exponent[1] = 99.1061690;
            exponent[2] = 18.0523120;
            exponent[3] = 4.8856602;
            exponent[4] = 3.7804559;
            exponent[5] = 0.8784966;
            exponent[6] = 0.2857144;
            exponent[7] = 3.7804559;
            exponent[8] = 0.8784966;
            exponent[9] = 0.2857144;
        }
        break;
        case 8:
        {
            exponent[1] = 130.7093200;
            exponent[2] = 23.8088610;
            exponent[3] = 6.4436083;
            exponent[4] = 5.0331513;
            exponent[5] = 1.1695961;
            exponent[6] = 0.3803890;
            exponent[7] = 5.0331513;
            exponent[8] = 1.1695961;
            exponent[9] = 0.3803890;
        }
        break;
        case 9:
        {
            exponent[1] = 166.6791300;
            exponent[2] = 30.3608120;
            exponent[3] = 8.2168207;
            exponent[4] = 6.4648032;
            exponent[5] = 1.5022812;
            exponent[6] = 0.4885885;
            exponent[7] = 6.4648032;
            exponent[8] = 1.5022812;
            exponent[9] = 0.4885885;
        }
        break;
        case 10:
        {
            exponent[1] = 207.0156100;
            exponent[2] = 37.7081510;
            exponent[3] = 10.2052970;
            exponent[4] = 8.2463151;
            exponent[5] = 1.9162662;
            exponent[6] = 0.6232293;
            exponent[7] = 8.2463151;
            exponent[8] = 1.9162662;
            exponent[9] = 0.6232293;
        }
        break;
        case 11:
        {
            exponent[1] = 250.7724300;
            exponent[2] = 45.6785110;
            exponent[3] = 12.3623880;
            exponent[4] = 12.0401930;
            exponent[5] = 2.7978819;
            exponent[6] = 0.9099580;
            exponent[7] = 12.0401930;
            exponent[8] = 2.7978819;
            exponent[9] = 0.9099580;
            exponent[10] = 1.4787406;
            exponent[11] = 0.4125649;
            exponent[12] = 0.1614751;
            exponent[13] = 1.4787406;
            exponent[14] = 0.4125649;
            exponent[15] = 0.1614751;
        }
        break;
        case 12:
        {
            exponent[1] = 299.2374000;
            exponent[2] = 54.5064700;
            exponent[3] = 14.7515800;
            exponent[4] = 15.1218200;
            exponent[5] = 3.5139870;
            exponent[6] = 1.1428570;
            exponent[7] = 15.1218200;
            exponent[8] = 3.5139870;
            exponent[9] = 1.1428570;
            exponent[10] = 1.3954480;
            exponent[11] = 0.3893260;
            exponent[12] = 0.1523800;
            exponent[13] = 1.3954480;
            exponent[14] = 0.3893260;
            exponent[15] = 0.1523800;
        }
        break;
        case 13:
        {
            exponent[1] = 351.4214767;
            exponent[2] = 64.01186067;
            exponent[3] = 17.32410761;
            exponent[4] = 18.89939621;
            exponent[5] = 4.391813233;
            exponent[6] = 1.428353970;
            exponent[7] = 18.89939621;
            exponent[8] = 4.391813233;
            exponent[9] = 1.428353970;
            exponent[10] = 1.3954482930;
            exponent[11] = 0.3893265318;
            exponent[12] = 0.1523797659;
            exponent[13] = 1.3954482930;
            exponent[14] = 0.3893265318;
            exponent[15] = 0.1523797659;
        }
        break;
        case 14:
        {
            exponent[1] = 407.7975514;
            exponent[2] = 74.28083305;
            exponent[3] = 20.10329229;
            exponent[4] = 23.19365606;
            exponent[5] = 5.389706871;
            exponent[6] = 1.752899952;
            exponent[7] = 23.19365606;
            exponent[8] = 5.389706871;
            exponent[9] = 1.752899952;
            exponent[10] = 1.4787406220;
            exponent[11] = 0.4125648801;
            exponent[12] = 0.1614750979;
            exponent[13] = 1.4787406220;
            exponent[14] = 0.4125648801;
            exponent[15] = 0.1614750979;
        }
        break;
        case 15:
        {
            exponent[1] = 468.3656378;
            exponent[2] = 85.31338559;
            exponent[3] = 23.08913156;
            exponent[4] = 28.03263958;
            exponent[5] = 6.514182577;
            exponent[6] = 2.118614352;
            exponent[7] = 28.03263958;
            exponent[8] = 6.514182577;
            exponent[9] = 2.118614352;
            exponent[10] = 1.7431032310;
            exponent[11] = 0.4863213771;
            exponent[12] = 0.1903428909;
            exponent[13] = 1.7431032310;
            exponent[14] = 0.4863213771;
            exponent[15] = 0.1903428909;
        }
        break;
        case 16:
        {
            exponent[1] = 533.1257359;
            exponent[2] = 97.10951830;
            exponent[3] = 26.28162542;
            exponent[4] = 33.32975173;
            exponent[5] = 7.745117521;
            exponent[6] = 2.518952599;
            exponent[7] = 33.32975173;
            exponent[8] = 7.745117521;
            exponent[9] = 2.518952599;
            exponent[10] = 2.0291942740;
            exponent[11] = 0.5661400518;
            exponent[12] = 0.2215833792;
            exponent[13] = 2.0291942740;
            exponent[14] = 0.5661400518;
            exponent[15] = 0.2215833792;
        }
        break;
        case 17:
        {
            exponent[1] = 601.3456136;
            exponent[2] = 109.5358542;
            exponent[3] = 29.64467686;
            exponent[4] = 38.96041889;
            exponent[5] = 9.053563477;
            exponent[6] = 2.944499834;
            exponent[7] = 38.96041889;
            exponent[8] = 9.053563477;
            exponent[9] = 2.944499834;
            exponent[10] = 2.1293864950;
            exponent[11] = 0.5940934274;
            exponent[12] = 0.2325241410;
            exponent[13] = 2.1293864950;
            exponent[14] = 0.5940934274;
            exponent[15] = 0.2325241410;
        }
        break;
        case 18:
        {
            exponent[1] = 674.4465184;
            exponent[2] = 122.8512753;
            exponent[3] = 33.24834945;
            exponent[4] = 45.16424392;
            exponent[5] = 10.49519900;
            exponent[6] = 3.413364448;
            exponent[7] = 45.16424392;
            exponent[8] = 10.49519900;
            exponent[9] = 3.413364448;
            exponent[10] = 2.6213665180;
            exponent[11] = 0.7313546050;
            exponent[12] = 0.2862472356;
            exponent[13] = 2.6213665180;
            exponent[14] = 0.7313546050;
            exponent[15] = 0.2862472356;
        }
        break;
        case 19:
        {
            exponent[1] = 771.5103681;
            exponent[2] = 140.5315766;
            exponent[3] = 38.03332899;
            exponent[4] = 52.40203979;
            exponent[5] = 12.17710710;
            exponent[6] = 3.960373165;
            exponent[7] = 52.40203979;
            exponent[8] = 12.17710710;
            exponent[9] = 3.960373165;
            exponent[10] = 3.651583985;
            exponent[11] = 1.018782663;
            exponent[12] = 0.3987446295;
            exponent[13] = 3.651583985;
            exponent[14] = 1.018782663;
            exponent[15] = 0.3987446295;
            exponent[16] = 0.5039822505;
            exponent[17] = 0.1860011465;
            exponent[18] = 0.08214006743;
            exponent[19] = 0.5039822505;
            exponent[20] = 0.1860011465;
            exponent[21] = 0.08214006743;
        }
        break;
        case 20:
        {
            exponent[1] = 854.0324951;
            exponent[2] = 155.5630851;
            exponent[3] = 42.10144179;
            exponent[4] = 59.56029944;
            exponent[5] = 13.84053270;
            exponent[6] = 4.501370797;
            exponent[7] = 59.56029944;
            exponent[8] = 13.84053270;
            exponent[9] = 4.501370797;
            exponent[10] = 4.374706256;
            exponent[11] = 1.220531941;
            exponent[12] = 0.477707930;
            exponent[13] = 4.374706256;
            exponent[14] = 1.220531941;
            exponent[15] = 0.477707930;
            exponent[16] = 0.4558489757;
            exponent[17] = 0.1682369410;
            exponent[18] = 0.0742952070;
            exponent[19] = 0.4558489757;
            exponent[20] = 0.1682369410;
            exponent[21] = 0.0742952070;
        }
        break;
        case 21:
        {
            exponent[1] = 941.6624250;
            exponent[2] = 171.5249862;
            exponent[3] = 46.42135516;
            exponent[4] = 67.17668771;
            exponent[5] = 15.61041754;
            exponent[6] = 5.076992278;
            exponent[7] = 67.17668771;
            exponent[8] = 15.61041754;
            exponent[9] = 5.076992278;
            exponent[10] = 4.698159231;
            exponent[11] = 1.433088313;
            exponent[12] = 0.552930024;
            exponent[13] = 4.698159231;
            exponent[14] = 1.433088313;
            exponent[15] = 0.552930024;
            exponent[16] = 0.6309328384;
            exponent[17] = 0.2328538976;
            exponent[18] = 0.1028307363;
            exponent[19] = 0.6309328384;
            exponent[20] = 0.2328538976;
            exponent[21] = 0.1028307363;
            exponent[22] = 0.5517000679;
            exponent[23] = 0.1682861055;
            exponent[24] = 0.0649300112;
        }
        break;
        case 22:
        {
            exponent[1] = 1033.5712450;
            exponent[2] = 188.2662926;
            exponent[3] = 50.95220601;
            exponent[4] = 75.25120460;
            exponent[5] = 17.48676162;
            exponent[6] = 5.687237606;
            exponent[7] = 75.25120460;
            exponent[8] = 17.48676162;
            exponent[9] = 5.687237606;
            exponent[10] = 5.395535474;
            exponent[11] = 1.645810296;
            exponent[12] = 0.635004777;
            exponent[13] = 5.395535474;
            exponent[14] = 1.645810296;
            exponent[15] = 0.635004777;
            exponent[16] = 0.7122640246;
            exponent[17] = 0.2628702203;
            exponent[18] = 0.1160862609;
            exponent[19] = 0.7122640246;
            exponent[20] = 0.2628702203;
            exponent[21] = 0.1160862609;
            exponent[22] = 1.645981194;
            exponent[23] = 0.502076728;
            exponent[24] = 0.193716810;
        }
        break;
        case 23:
        {
            exponent[1] = 1130.7625170;
            exponent[2] = 205.9698041;
            exponent[3] = 55.74346711;
            exponent[4] = 83.78385011;
            exponent[5] = 19.46956493;
            exponent[6] = 6.332106784;
            exponent[7] = 83.78385011;
            exponent[8] = 19.46956493;
            exponent[9] = 6.332106784;
            exponent[10] = 6.141151276;
            exponent[11] = 1.873246881;
            exponent[12] = 0.7227568825;
            exponent[13] = 6.141151276;
            exponent[14] = 1.873246881;
            exponent[15] = 0.7227568825;
            exponent[16] = 0.7122640246;
            exponent[17] = 0.2628702203;
            exponent[18] = 0.1160862609;
            exponent[19] = 0.7122640246;
            exponent[20] = 0.2628702203;
            exponent[21] = 0.1160862609;
            exponent[22] = 2.964817927;
            exponent[23] = 0.9043639676;
            exponent[24] = 0.3489317337;
        }
        break;
        case 24:
        {
            exponent[1] = 1232.3204500;
            exponent[2] = 224.4687082;
            exponent[3] = 60.74999251;
            exponent[4] = 92.77462423;
            exponent[5] = 21.55882749;
            exponent[6] = 7.011599810;
            exponent[7] = 92.77462423;
            exponent[8] = 21.55882749;
            exponent[9] = 7.011599810;
            exponent[10] = 6.899488096;
            exponent[11] = 2.104563782;
            exponent[12] = 0.8120061343;
            exponent[13] = 6.899488096;
            exponent[14] = 2.104563782;
            exponent[15] = 0.8120061343;
            exponent[16] = 0.7547780537;
            exponent[17] = 0.2785605708;
            exponent[18] = 0.1230152851;
            exponent[19] = 0.7547780537;
            exponent[20] = 0.2785605708;
            exponent[21] = 0.1230152851;
            exponent[22] = 4.241479241;
            exponent[23] = 1.293786360;
            exponent[24] = 0.4991829993;
        }
        break;
        case 25:
        {
            exponent[1] = 1337.1532660;
            exponent[2] = 243.5641365;
            exponent[3] = 65.91796062;
            exponent[4] = 102.0220021;
            exponent[5] = 23.70771923;
            exponent[6] = 7.710486098;
            exponent[7] = 102.0220021;
            exponent[8] = 23.70771923;
            exponent[9] = 7.710486098;
            exponent[10] = 7.701960922;
            exponent[11] = 2.349343572;
            exponent[12] = 0.906449787;
            exponent[13] = 7.701960922;
            exponent[14] = 2.349343572;
            exponent[15] = 0.906449787;
            exponent[16] = 0.670982286;
            exponent[17] = 0.247634663;
            exponent[18] = 0.109358078;
            exponent[19] = 0.670982286;
            exponent[20] = 0.247634663;
            exponent[21] = 0.109358078;
            exponent[22] = 5.426950461;
            exponent[23] = 1.655392868;
            exponent[24] = 0.638702032;
        }
        break;
        case 26:
        {
            exponent[1] = 1447.4004110;
            exponent[2] = 263.6457916;
            exponent[3] = 71.35284019;
            exponent[4] = 111.9194891;
            exponent[5] = 26.00768236;
            exponent[6] = 8.458505490;
            exponent[7] = 111.9194891;
            exponent[8] = 26.00768236;
            exponent[9] = 8.458505490;
            exponent[10] = 8.548569754;
            exponent[11] = 2.607586250;
            exponent[12] = 1.006087840;
            exponent[13] = 8.548569754;
            exponent[14] = 2.607586250;
            exponent[15] = 1.006087840;
            exponent[16] = 0.5921156814;
            exponent[17] = 0.2185279254;
            exponent[18] = 0.0965042359;
            exponent[19] = 0.5921156814;
            exponent[20] = 0.2185279254;
            exponent[21] = 0.0965042359;
            exponent[22] = 6.411803475;
            exponent[23] = 1.955804428;
            exponent[24] = 0.754610151;
        }
        break;
        case 27:
        {
            exponent[1] = 1557.2987040;
            exponent[2] = 283.6639029;
            exponent[3] = 76.77052234;
            exponent[4] = 121.8344741;
            exponent[5] = 28.31171164;
            exponent[6] = 9.207847321;
            exponent[7] = 121.8344741;
            exponent[8] = 28.31171164;
            exponent[9] = 9.207847321;
            exponent[10] = 9.480851678;
            exponent[11] = 2.891961952;
            exponent[12] = 1.115808827;
            exponent[13] = 9.480851678;
            exponent[14] = 2.891961952;
            exponent[15] = 1.115808827;
            exponent[16] = 0.5921156814;
            exponent[17] = 0.2185279254;
            exponent[18] = 0.0965042359;
            exponent[19] = 0.5921156814;
            exponent[20] = 0.2185279254;
            exponent[21] = 0.0965042359;
            exponent[22] = 7.664527389;
            exponent[23] = 2.337925151;
            exponent[24] = 0.902044205;
        }
        break;
        case 28:
        {
            exponent[1] = 1679.7710280;
            exponent[2] = 305.9723896;
            exponent[3] = 82.80806943;
            exponent[4] = 132.8588899;
            exponent[5] = 30.87354878;
            exponent[6] = 10.04103627;
            exponent[7] = 132.8588899;
            exponent[8] = 30.87354878;
            exponent[9] = 10.04103627;
            exponent[10] = 10.33074335;
            exponent[11] = 3.151206003;
            exponent[12] = 1.215833241;
            exponent[13] = 10.33074335;
            exponent[14] = 3.151206003;
            exponent[15] = 1.215833241;
            exponent[16] = 0.6309328384;
            exponent[17] = 0.2328538976;
            exponent[18] = 0.1028307363;
            exponent[19] = 0.6309328384;
            exponent[20] = 0.2328538976;
            exponent[21] = 0.1028307363;
            exponent[22] = 8.627722755;
            exponent[23] = 2.631730438;
            exponent[24] = 1.015403419;
        }
        break;
        case 29:
        {
            exponent[1] = 1801.8067300;
            exponent[2] = 328.2013450;
            exponent[3] = 88.82409228;
            exponent[4] = 144.1212184;
            exponent[5] = 33.49067173;
            exponent[6] = 10.89220588;
            exponent[7] = 144.1212184;
            exponent[8] = 33.49067173;
            exponent[9] = 10.89220588;
            exponent[10] = 11.30775402;
            exponent[11] = 3.449225397;
            exponent[12] = 1.330818388;
            exponent[13] = 11.30775402;
            exponent[14] = 3.449225397;
            exponent[15] = 1.330818388;
            exponent[16] = 0.6309328384;
            exponent[17] = 0.2328538976;
            exponent[18] = 0.1028307363;
            exponent[19] = 0.6309328384;
            exponent[20] = 0.2328538976;
            exponent[21] = 0.1028307363;
            exponent[22] = 9.647911930;
            exponent[23] = 2.942920654;
            exponent[24] = 1.135470278;
        }
        break;
        case 30:
        {
            exponent[1] = 1929.4323010;
            exponent[2] = 351.4485021;
            exponent[3] = 95.11568021;
            exponent[4] = 155.8416755;
            exponent[5] = 36.21425391;
            exponent[6] = 11.77799934;
            exponent[7] = 155.8416755;
            exponent[8] = 36.21425391;
            exponent[9] = 11.77799934;
            exponent[10] = 12.28152744;
            exponent[11] = 3.746257327;
            exponent[12] = 1.445422541;
            exponent[13] = 12.28152744;
            exponent[14] = 3.746257327;
            exponent[15] = 1.445422541;
            exponent[16] = 0.8897138854;
            exponent[17] = 0.3283603790;
            exponent[18] = 0.1450074055;
            exponent[19] = 0.8897138854;
            exponent[20] = 0.3283603790;
            exponent[21] = 0.1450074055;
            exponent[22] = 10.94737077;
            exponent[23] = 3.339297018;
            exponent[24] = 1.288404602;
        }
        break;
        case 31:
        {
            exponent[1] = 2061.4245320;
            exponent[2] = 375.4910517;
            exponent[3] = 101.6225324;
            exponent[4] = 167.7618680;
            exponent[5] = 38.98425028;
            exponent[6] = 12.67888813;
            exponent[7] = 167.7618680;
            exponent[8] = 38.98425028;
            exponent[9] = 12.67888813;
            exponent[10] = 12.61505520;
            exponent[11] = 3.847993927;
            exponent[12] = 1.484675684;
            exponent[13] = 12.61505520;
            exponent[14] = 3.847993927;
            exponent[15] = 1.484675684;
            exponent[16] = 0.7985243736;
            exponent[17] = 0.2947057141;
            exponent[18] = 0.1301451506;
            exponent[19] = 0.7985243736;
            exponent[20] = 0.2947057141;
            exponent[21] = 0.1301451506;
            exponent[22] = 12.61505520;
            exponent[23] = 3.847993927;
            exponent[24] = 1.484675684;
        }
        break;
        case 32:
        {
            exponent[1] = 2196.3842290;
            exponent[2] = 400.0741292;
            exponent[3] = 108.2756726;
            exponent[4] = 180.3890380;
            exponent[5] = 41.91853304;
            exponent[6] = 13.63320795;
            exponent[7] = 180.3890380;
            exponent[8] = 41.91853304;
            exponent[9] = 13.63320795;
            exponent[10] = 14.19665619;
            exponent[11] = 4.330432640;
            exponent[12] = 1.670815538;
            exponent[13] = 14.19665619;
            exponent[14] = 4.330432640;
            exponent[15] = 1.670815538;
            exponent[16] = 0.9858325600;
            exponent[17] = 0.3638342150;
            exponent[18] = 0.1606730254;
            exponent[19] = 0.9858325600;
            exponent[20] = 0.3638342150;
            exponent[21] = 0.1606730254;
            exponent[22] = 14.19665619;
            exponent[23] = 4.330432640;
            exponent[24] = 1.670815538;
        }
        break;
        case 33:
        {
            exponent[1] = 2337.0656730;
            exponent[2] = 425.6994298;
            exponent[3] = 115.2108790;
            exponent[4] = 193.1970535;
            exponent[5] = 44.89484040;
            exponent[6] = 14.60119548;
            exponent[7] = 193.1970535;
            exponent[8] = 44.89484040;
            exponent[9] = 14.60119548;
            exponent[10] = 15.87163584;
            exponent[11] = 4.841354819;
            exponent[12] = 1.867945198;
            exponent[13] = 15.87163584;
            exponent[14] = 4.841354819;
            exponent[15] = 1.867945198;
            exponent[16] = 1.1076814640;
            exponent[17] = 0.4088041239;
            exponent[18] = 0.1805322114;
            exponent[19] = 1.1076814640;
            exponent[20] = 0.4088041239;
            exponent[21] = 0.1805322114;
            exponent[22] = 15.87163584;
            exponent[23] = 4.841354819;
            exponent[24] = 1.867945198;
        }
        break;
        case 34:
        {
            exponent[1] = 2480.6268140;
            exponent[2] = 451.8492708;
            exponent[3] = 122.2880464;
            exponent[4] = 206.1578780;
            exponent[5] = 47.90665727;
            exponent[6] = 15.58073180;
            exponent[7] = 206.1578780;
            exponent[8] = 47.90665727;
            exponent[9] = 15.58073180;
            exponent[10] = 17.63999414;
            exponent[11] = 5.380760465;
            exponent[12] = 2.076064666;
            exponent[13] = 17.63999414;
            exponent[14] = 5.380760465;
            exponent[15] = 2.076064666;
            exponent[16] = 1.2146442970;
            exponent[17] = 0.4482801363;
            exponent[18] = 0.1979652346;
            exponent[19] = 1.2146442970;
            exponent[20] = 0.4482801363;
            exponent[21] = 0.1979652346;
            exponent[22] = 17.63999414;
            exponent[23] = 5.380760465;
            exponent[24] = 2.076064666;
        }
        break;
        case 35:
        {
            exponent[1] = 2629.9974710;
            exponent[2] = 479.0573224;
            exponent[3] = 129.6516070;
            exponent[4] = 219.8350255;
            exponent[5] = 51.08493222;
            exponent[6] = 16.61440546;
            exponent[7] = 219.8350255;
            exponent[8] = 51.08493222;
            exponent[9] = 16.61440546;
            exponent[10] = 19.50173109;
            exponent[11] = 5.948649577;
            exponent[12] = 2.295173940;
            exponent[13] = 19.50173109;
            exponent[14] = 5.948649577;
            exponent[15] = 2.295173940;
            exponent[16] = 1.3960374880;
            exponent[17] = 0.5152256318;
            exponent[18] = 0.2275290713;
            exponent[19] = 1.3960374880;
            exponent[20] = 0.5152256318;
            exponent[21] = 0.2275290713;
            exponent[22] = 19.50173109;
            exponent[23] = 5.948649577;
            exponent[24] = 2.295173940;
        }
        break;
        case 36:
        {
            exponent[1] = 2782.1600550;
            exponent[2] = 506.7739270;
            exponent[3] = 137.1528019;
            exponent[4] = 233.9514118;
            exponent[5] = 54.36527681;
            exponent[6] = 17.68127533;
            exponent[7] = 233.9514118;
            exponent[8] = 54.36527681;
            exponent[9] = 17.68127533;
            exponent[10] = 21.45684671;
            exponent[11] = 6.545022156;
            exponent[12] = 2.525273021;
            exponent[13] = 21.45684671;
            exponent[14] = 6.545022156;
            exponent[15] = 2.525273021;
            exponent[16] = 1.5900493360;
            exponent[17] = 0.5868282053;
            exponent[18] = 0.2591495227;
            exponent[19] = 1.5900493360;
            exponent[20] = 0.5868282053;
            exponent[21] = 0.2591495227;
            exponent[22] = 21.45684671;
            exponent[23] = 6.545022156;
            exponent[24] = 2.525273021;
        }
        break;
        case 37:
        {
            exponent[1] = 2938.6015290;
            exponent[2] = 535.2699370;
            exponent[3] = 144.8649340;
            exponent[4] = 248.5070370;
            exponent[5] = 57.7476910;
            exponent[6] = 18.7813410;
            exponent[7] = 248.5070370;
            exponent[8] = 57.7476910;
            exponent[9] = 18.7813410;
            exponent[10] = 23.50534097;
            exponent[11] = 7.169878201;
            exponent[12] = 2.766361909;
            exponent[13] = 23.50534097;
            exponent[14] = 7.169878201;
            exponent[15] = 2.766361909;
            exponent[16] = 2.247796820;
            exponent[17] = 0.829578393;
            exponent[18] = 0.366350565;
            exponent[19] = 2.247796820;
            exponent[20] = 0.829578393;
            exponent[21] = 0.366350565;
            exponent[22] = 0.4869939919;
            exponent[23] = 0.2622161565;
            exponent[24] = 0.1158254875;
            exponent[25] = 0.4869939919;
            exponent[26] = 0.2622161565;
            exponent[27] = 0.1158254875;
            exponent[28] = 23.50534097;
            exponent[29] = 7.169878201;
            exponent[30] = 2.766361909;
        }
        break;
        case 38:
        {
            exponent[1] = 3100.9839510;
            exponent[2] = 564.8480978;
            exponent[3] = 152.8699389;
            exponent[4] = 263.5019007;
            exponent[5] = 61.23217493;
            exponent[6] = 19.91460372;
            exponent[7] = 263.5019007;
            exponent[8] = 61.23217493;
            exponent[9] = 19.91460372;
            exponent[10] = 25.57886692;
            exponent[11] = 7.802369707;
            exponent[12] = 3.010396794;
            exponent[13] = 25.57886692;
            exponent[14] = 7.802369707;
            exponent[15] = 3.010396794;
            exponent[16] = 2.461032403;
            exponent[17] = 0.908275734;
            exponent[18] = 0.401104140;
            exponent[19] = 2.461032403;
            exponent[20] = 0.908275734;
            exponent[21] = 0.401104140;
            exponent[22] = 0.4370804803;
            exponent[23] = 0.2353408164;
            exponent[24] = 0.1039541771;
            exponent[25] = 0.4370804803;
            exponent[26] = 0.2353408164;
            exponent[27] = 0.1039541771;
            exponent[28] = 25.57886692;
            exponent[29] = 7.802369707;
            exponent[30] = 3.010396794;
        }
        break;
        case 39:
        {
            exponent[1] = 3266.0268690;
            exponent[2] = 594.9108710;
            exponent[3] = 161.0060990;
            exponent[4] = 277.9377240;
            exponent[5] = 64.5867500;
            exponent[6] = 21.0056160;
            exponent[7] = 277.9377240;
            exponent[8] = 64.5867500;
            exponent[9] = 21.0056160;
            exponent[10] = 30.6713260;
            exponent[11] = 8.5572220;
            exponent[12] = 3.3492390;
            exponent[13] = 30.6713260;
            exponent[14] = 8.5572220;
            exponent[15] = 3.3492390;
            exponent[16] = 2.6676880;
            exponent[17] = 0.9845440;
            exponent[18] = 0.4347850;
            exponent[19] = 2.6676880;
            exponent[20] = 0.9845440;
            exponent[21] = 0.4347850;
            exponent[22] = 0.2074240;
            exponent[23] = 0.1116850;
            exponent[24] = 0.0493330;
            exponent[25] = 0.2074240;
            exponent[26] = 0.1116850;
            exponent[27] = 0.0493330;
            exponent[28] = 5.6600430;
            exponent[29] = 1.7747150;
            exponent[30] = 0.6912950;
            exponent[31] = 2.1282120;
            exponent[32] = 0.9625940;
            exponent[33] = 0.4728610;
        }
        break;
        case 40:
        {
            exponent[1] = 3435.3486770;
            exponent[2] = 625.7530498;
            exponent[3] = 169.3531958;
            exponent[4] = 293.7830292;
            exponent[5] = 68.26885797;
            exponent[6] = 22.20315144;
            exponent[7] = 293.7830292;
            exponent[8] = 68.26885797;
            exponent[9] = 22.20315144;
            exponent[10] = 30.73293103;
            exponent[11] = 9.374523538;
            exponent[12] = 3.616982618;
            exponent[13] = 30.73293103;
            exponent[14] = 9.374523538;
            exponent[15] = 3.616982618;
            exponent[16] = 2.827607815;
            exponent[17] = 1.101055827;
            exponent[18] = 0.4846874856;
            exponent[19] = 2.827607815;
            exponent[20] = 1.101055827;
            exponent[21] = 0.4846874856;
            exponent[22] = 0.8878301887;
            exponent[23] = 0.3457164736;
            exponent[24] = 0.1521852428;
            exponent[25] = 0.8878301887;
            exponent[26] = 0.3457164736;
            exponent[27] = 0.1521852428;
            exponent[28] = 30.73293103;
            exponent[29] = 9.374523538;
            exponent[30] = 3.616982618;
            exponent[31] = 0.4869939919;
            exponent[32] = 0.2622161565;
            exponent[33] = 0.1158254875;
        }
        break;
        case 41:
        {
            exponent[1] = 3610.7428640;
            exponent[2] = 657.7013201;
            exponent[3] = 177.9996445;
            exponent[4] = 310.0675728;
            exponent[5] = 72.05303569;
            exponent[6] = 23.43388348;
            exponent[7] = 310.0675728;
            exponent[8] = 72.05303569;
            exponent[9] = 23.43388348;
            exponent[10] = 33.01997858;
            exponent[11] = 10.07214594;
            exponent[12] = 3.886147028;
            exponent[13] = 33.01997858;
            exponent[14] = 10.07214594;
            exponent[15] = 3.886147028;
            exponent[16] = 3.144798430;
            exponent[17] = 1.224568208;
            exponent[18] = 0.5390579399;
            exponent[19] = 3.144798430;
            exponent[20] = 1.224568208;
            exponent[21] = 0.5390579399;
            exponent[22] = 0.4869939919;
            exponent[23] = 0.2622161565;
            exponent[24] = 0.1158254875;
            exponent[25] = 0.4869939919;
            exponent[26] = 0.2622161565;
            exponent[27] = 0.1158254875;
            exponent[28] = 33.01997858;
            exponent[29] = 10.07214594;
            exponent[30] = 3.886147028;
            exponent[31] = 1.344878866;
            exponent[32] = 0.5236888594;
            exponent[33] = 0.2305291251;
        }
        break;
        case 42:
        {
            exponent[1] = 3788.6661150;
            exponent[2] = 690.1102623;
            exponent[3] = 186.7707691;
            exponent[4] = 326.4309567;
            exponent[5] = 75.85553420;
            exponent[6] = 24.67057401;
            exponent[7] = 326.4309567;
            exponent[8] = 75.85553420;
            exponent[9] = 24.67057401;
            exponent[10] = 35.46948129;
            exponent[11] = 10.81932234;
            exponent[12] = 4.174430912;
            exponent[13] = 35.46948129;
            exponent[14] = 10.81932234;
            exponent[15] = 4.174430912;
            exponent[16] = 3.496895188;
            exponent[17] = 1.361672861;
            exponent[18] = 0.5994117456;
            exponent[19] = 3.496895188;
            exponent[20] = 1.361672861;
            exponent[21] = 0.5994117456;
            exponent[22] = 0.5129625081;
            exponent[23] = 0.2761985970;
            exponent[24] = 0.1220017773;
            exponent[25] = 0.5129625081;
            exponent[26] = 0.2761985970;
            exponent[27] = 0.1220017773;
            exponent[28] = 35.46948129;
            exponent[29] = 10.81932234;
            exponent[30] = 4.174430912;
            exponent[31] = 1.702112315;
            exponent[32] = 0.6627937127;
            exponent[33] = 0.2917634240;
        }
        break;
        case 43:
        {
            exponent[1] = 3970.8682570;
            exponent[2] = 723.2986098;
            exponent[3] = 195.7528311;
            exponent[4] = 343.5846323;
            exponent[5] = 79.84167952;
            exponent[6] = 25.96699219;
            exponent[7] = 343.5846323;
            exponent[8] = 79.84167952;
            exponent[9] = 25.96699219;
            exponent[10] = 38.08991983;
            exponent[11] = 11.61863962;
            exponent[12] = 4.482832367;
            exponent[13] = 38.08991983;
            exponent[14] = 11.61863962;
            exponent[15] = 4.482832367;
            exponent[16] = 3.829752708;
            exponent[17] = 1.491285854;
            exponent[18] = 0.6564677040;
            exponent[19] = 3.829752708;
            exponent[20] = 1.491285854;
            exponent[21] = 0.6564677040;
            exponent[22] = 0.4616999826;
            exponent[23] = 0.2485968963;
            exponent[24] = 0.1098096207;
            exponent[25] = 0.4616999826;
            exponent[26] = 0.2485968963;
            exponent[27] = 0.1098096207;
            exponent[28] = 38.08991983;
            exponent[29] = 11.61863962;
            exponent[30] = 4.482832367;
            exponent[31] = 2.101373228;
            exponent[32] = 0.8182638428;
            exponent[33] = 0.3602017580;
        }
        break;
        case 44:
        {
            exponent[1] = 4159.2742100;
            exponent[2] = 757.6169894;
            exponent[3] = 205.0407239;
            exponent[4] = 360.7986561;
            exponent[5] = 83.84184843;
            exponent[6] = 27.26797127;
            exponent[7] = 360.7986561;
            exponent[8] = 83.84184843;
            exponent[9] = 27.26797127;
            exponent[10] = 40.71751678;
            exponent[11] = 12.42014044;
            exponent[12] = 4.792076302;
            exponent[13] = 40.71751678;
            exponent[14] = 12.42014044;
            exponent[15] = 4.792076302;
            exponent[16] = 4.197516371;
            exponent[17] = 1.634491118;
            exponent[18] = 0.7195070139;
            exponent[19] = 4.197516371;
            exponent[20] = 1.634491118;
            exponent[21] = 0.7195070139;
            exponent[22] = 0.4131354848;
            exponent[23] = 0.2224479167;
            exponent[24] = 0.0982591566;
            exponent[25] = 0.4131354848;
            exponent[26] = 0.2224479167;
            exponent[27] = 0.0982591566;
            exponent[28] = 40.71751678;
            exponent[29] = 12.42014044;
            exponent[30] = 4.792076302;
            exponent[31] = 2.390895761;
            exponent[32] = 0.9310024167;
            exponent[33] = 0.4098295558;
        }
        break;
        case 45:
        {
            exponent[1] = 4350.0777940;
            exponent[2] = 792.3721005;
            exponent[3] = 214.4468133;
            exponent[4] = 378.4334264;
            exponent[5] = 87.93978981;
            exponent[6] = 28.60074899;
            exponent[7] = 378.4334264;
            exponent[8] = 87.93978981;
            exponent[9] = 28.60074899;
            exponent[10] = 43.52179455;
            exponent[11] = 13.27553454;
            exponent[12] = 5.122113939;
            exponent[13] = 43.52179455;
            exponent[14] = 13.27553454;
            exponent[15] = 5.122113939;
            exponent[16] = 4.540857408;
            exponent[17] = 1.768186338;
            exponent[18] = 0.7783599789;
            exponent[19] = 4.540857408;
            exponent[20] = 1.768186338;
            exponent[21] = 0.7783599789;
            exponent[22] = 0.4131354848;
            exponent[23] = 0.2224479167;
            exponent[24] = 0.0982591566;
            exponent[25] = 0.4131354848;
            exponent[26] = 0.2224479167;
            exponent[27] = 0.0982591566;
            exponent[28] = 43.52179455;
            exponent[29] = 13.27553454;
            exponent[30] = 5.122113939;
            exponent[31] = 2.779066094;
            exponent[32] = 1.082153932;
            exponent[33] = 0.4763668250;
        }
        break;
        case 46:
        {
            exponent[1] = 4545.1602690;
            exponent[2] = 827.9066168;
            exponent[3] = 224.0638402;
            exponent[4] = 396.4889433;
            exponent[5] = 92.13550365;
            exponent[6] = 29.96532535;
            exponent[7] = 396.4889433;
            exponent[8] = 92.13550365;
            exponent[9] = 29.96532535;
            exponent[10] = 46.41945097;
            exponent[11] = 14.15941211;
            exponent[12] = 5.463141383;
            exponent[13] = 46.41945097;
            exponent[14] = 14.15941211;
            exponent[15] = 5.463141383;
            exponent[16] = 4.919104589;
            exponent[17] = 1.915473830;
            exponent[18] = 0.8431962954;
            exponent[19] = 4.919104589;
            exponent[20] = 1.915473830;
            exponent[21] = 0.8431962954;
            exponent[22] = 0.4370804803;
            exponent[23] = 0.2353408164;
            exponent[24] = 0.1039541771;
            exponent[25] = 0.4370804803;
            exponent[26] = 0.2353408164;
            exponent[27] = 0.1039541771;
            exponent[28] = 46.41945097;
            exponent[29] = 14.15941211;
            exponent[30] = 5.463141383;
            exponent[31] = 3.025977448;
            exponent[32] = 1.178299934;
            exponent[33] = 0.5186905316;
        }
        break;
        case 47:
        {
            exponent[1] = 4744.5216340;
            exponent[2] = 864.2205383;
            exponent[3] = 233.8918045;
            exponent[4] = 414.9652069;
            exponent[5] = 96.42898995;
            exponent[6] = 31.36170035;
            exponent[7] = 414.9652069;
            exponent[8] = 96.42898995;
            exponent[9] = 31.36170035;
            exponent[10] = 49.41048605;
            exponent[11] = 15.07177314;
            exponent[12] = 5.815158634;
            exponent[13] = 49.41048605;
            exponent[14] = 15.07177314;
            exponent[15] = 5.815158634;
            exponent[16] = 5.290230450;
            exponent[17] = 2.059988316;
            exponent[18] = 0.9068119281;
            exponent[19] = 5.290230450;
            exponent[20] = 2.059988316;
            exponent[21] = 0.9068119281;
            exponent[22] = 0.4370804803;
            exponent[23] = 0.2353408164;
            exponent[24] = 0.1039541771;
            exponent[25] = 0.4370804803;
            exponent[26] = 0.2353408164;
            exponent[27] = 0.1039541771;
            exponent[28] = 49.41048605;
            exponent[29] = 15.07177314;
            exponent[30] = 5.815158634;
            exponent[31] = 3.283395668;
            exponent[32] = 1.278537254;
            exponent[33] = 0.5628152469;
        }
        break;
        case 48:
        {
            exponent[1] = 4950.2619050;
            exponent[2] = 901.6963856;
            exponent[3] = 244.0342313;
            exponent[4] = 433.4469385;
            exponent[5] = 100.7237469;
            exponent[6] = 32.75848861;
            exponent[7] = 433.4469385;
            exponent[8] = 100.7237469;
            exponent[9] = 32.75848861;
            exponent[10] = 52.59279235;
            exponent[11] = 16.04247800;
            exponent[12] = 6.189686744;
            exponent[13] = 52.59279235;
            exponent[14] = 16.04247800;
            exponent[15] = 6.189686744;
            exponent[16] = 5.674851796;
            exponent[17] = 2.209757875;
            exponent[18] = 0.9727408566;
            exponent[19] = 5.674851796;
            exponent[20] = 2.209757875;
            exponent[21] = 0.9727408566;
            exponent[22] = 0.5949150981;
            exponent[23] = 0.3203250000;
            exponent[24] = 0.1414931855;
            exponent[25] = 0.5949150981;
            exponent[26] = 0.3203250000;
            exponent[27] = 0.1414931855;
            exponent[28] = 52.59279235;
            exponent[29] = 16.04247800;
            exponent[30] = 6.189686744;
            exponent[31] = 3.642963976;
            exponent[32] = 1.418551290;
            exponent[33] = 0.6244497700;
        }
        break;
        case 49:
        {
            exponent[1] = 5158.2247140;
            exponent[2] = 939.5770707;
            exponent[3] = 254.2862231;
            exponent[4] = 452.3313223;
            exponent[5] = 105.1120716;
            exponent[6] = 34.18570799;
            exponent[7] = 452.3313223;
            exponent[8] = 105.1120716;
            exponent[9] = 34.18570799;
            exponent[10] = 55.97539769;
            exponent[11] = 17.07428044;
            exponent[12] = 6.587788204;
            exponent[13] = 55.97539769;
            exponent[14] = 17.07428044;
            exponent[15] = 6.587788204;
            exponent[16] = 5.048549180;
            exponent[17] = 1.965878882;
            exponent[18] = 0.8653847237;
            exponent[19] = 5.048549180;
            exponent[20] = 1.965878882;
            exponent[21] = 0.8653847237;
            exponent[22] = 0.5669230612;
            exponent[23] = 0.3052530187;
            exponent[24] = 0.1348356264;
            exponent[25] = 0.5669230612;
            exponent[26] = 0.3052530187;
            exponent[27] = 0.1348356264;
            exponent[28] = 55.97539769;
            exponent[29] = 17.07428044;
            exponent[30] = 6.587788204;
            exponent[31] = 5.048549180;
            exponent[32] = 1.965878882;
            exponent[33] = 0.8653847237;
        }
        break;
        case 50:
        {
            exponent[1] = 5370.4664130;
            exponent[2] = 978.2371611;
            exponent[3] = 264.7491522;
            exponent[4] = 472.0515322;
            exponent[5] = 109.6946243;
            exponent[6] = 35.67609636;
            exponent[7] = 472.0515322;
            exponent[8] = 109.6946243;
            exponent[9] = 35.67609636;
            exponent[10] = 59.15141188;
            exponent[11] = 18.04306600;
            exponent[12] = 6.961575790;
            exponent[13] = 59.15141188;
            exponent[14] = 18.04306600;
            exponent[15] = 6.961575790;
            exponent[16] = 5.583138529;
            exponent[17] = 2.174045204;
            exponent[18] = 0.9570200509;
            exponent[19] = 5.583138529;
            exponent[20] = 2.174045204;
            exponent[21] = 0.9570200509;
            exponent[22] = 0.6235816420;
            exponent[23] = 0.3357601616;
            exponent[24] = 0.1483111678;
            exponent[25] = 0.6235816420;
            exponent[26] = 0.3357601616;
            exponent[27] = 0.1483111678;
            exponent[28] = 59.15141188;
            exponent[29] = 18.04306600;
            exponent[30] = 6.961575790;
            exponent[31] = 5.583138529;
            exponent[32] = 2.174045204;
            exponent[33] = 0.9570200509;
        }
        break;
        case 51:
        {
            exponent[1] = 5586.9870020;
            exponent[2] = 1017.6766570;
            exponent[3] = 275.4230189;
            exponent[4] = 492.1924888;
            exponent[5] = 114.3749494;
            exponent[6] = 37.19828336;
            exponent[7] = 492.1924888;
            exponent[8] = 114.3749494;
            exponent[9] = 37.19828336;
            exponent[10] = 62.52179775;
            exponent[11] = 19.07114112;
            exponent[12] = 7.358239131;
            exponent[13] = 62.52179775;
            exponent[14] = 19.07114112;
            exponent[15] = 7.358239131;
            exponent[16] = 6.120693149;
            exponent[17] = 2.383366187;
            exponent[18] = 1.049163663;
            exponent[19] = 6.120693149;
            exponent[20] = 2.383366187;
            exponent[21] = 1.049163663;
            exponent[22] = 0.6529226928;
            exponent[23] = 0.3515585034;
            exponent[24] = 0.1552895732;
            exponent[25] = 0.6529226928;
            exponent[26] = 0.3515585034;
            exponent[27] = 0.1552895732;
            exponent[28] = 62.52179775;
            exponent[29] = 19.07114112;
            exponent[30] = 7.358239131;
            exponent[31] = 6.120693149;
            exponent[32] = 2.383366187;
            exponent[33] = 1.049163663;
        }
        break;
        case 52:
        {
            exponent[1] = 5810.0615910;
            exponent[2] = 1058.3099720;
            exponent[3] = 286.4199797;
            exponent[4] = 512.7541920;
            exponent[5] = 119.1530471;
            exponent[6] = 38.75226900;
            exponent[7] = 512.7541920;
            exponent[8] = 119.1530471;
            exponent[9] = 38.75226900;
            exponent[10] = 65.98556227;
            exponent[11] = 20.12769970;
            exponent[12] = 7.765892279;
            exponent[13] = 65.98556227;
            exponent[14] = 20.12769970;
            exponent[15] = 7.765892279;
            exponent[16] = 6.707956921;
            exponent[17] = 2.612043655;
            exponent[18] = 1.149828048;
            exponent[19] = 6.707956921;
            exponent[20] = 2.612043655;
            exponent[21] = 1.149828048;
            exponent[22] = 0.7012713483;
            exponent[23] = 0.3775912653;
            exponent[24] = 0.1667887020;
            exponent[25] = 0.7012713483;
            exponent[26] = 0.3775912653;
            exponent[27] = 0.1667887020;
            exponent[28] = 65.98556227;
            exponent[29] = 20.12769970;
            exponent[30] = 7.765892279;
            exponent[31] = 6.707956921;
            exponent[32] = 2.612043655;
            exponent[33] = 1.149828048;
        }
        break;
        case 53:
        {
            exponent[1] = 6035.1836230;
            exponent[2] = 1099.3162310;
            exponent[3] = 297.5178737;
            exponent[4] = 533.7366418;
            exponent[5] = 124.0289171;
            exponent[6] = 40.33805328;
            exponent[7] = 533.7366418;
            exponent[8] = 124.0289171;
            exponent[9] = 40.33805328;
            exponent[10] = 69.54270545;
            exponent[11] = 21.21274175;
            exponent[12] = 8.184535234;
            exponent[13] = 69.54270545;
            exponent[14] = 21.21274175;
            exponent[15] = 8.184535234;
            exponent[16] = 7.295991196;
            exponent[17] = 2.841021154;
            exponent[18] = 1.250624506;
            exponent[19] = 7.295991196;
            exponent[20] = 2.841021154;
            exponent[21] = 1.250624506;
            exponent[22] = 0.7900364582;
            exponent[23] = 0.4253857892;
            exponent[24] = 0.1879003836;
            exponent[25] = 0.7900364582;
            exponent[26] = 0.4253857892;
            exponent[27] = 0.1879003836;
            exponent[28] = 69.54270545;
            exponent[29] = 21.21274175;
            exponent[30] = 8.184535234;
            exponent[31] = 7.295991196;
            exponent[32] = 2.841021154;
            exponent[33] = 1.250624506;
        }
        break;
    }
}
