#include "basis_set.hpp"
//
//
//
/// @brief Initializes the default STO-3G set of exponent values
///        for the current atom type, from H to I (1 - 53).
//
/// @return None.
//
void basis_set::init_sto3g_expon()
{
	switch(current_element <= sto3g_limit)
	{
		case false:
		{
			return;
		}
		break;
		case true:
		{
			expon = new double[current_set_size + 1];
			expon[0] = 0.0;
		}
		break;
	}
//
	switch(current_element)
	{
		case 1:
		{
			expon[1] = 3.42525091;
			expon[2] = 0.62391373;
			expon[3] = 0.16885540;
		}
		break;
		case 2:
		{
			expon[1] = 6.36242139;
			expon[2] = 1.15892300;
			expon[3] = 0.31364979;
		}
		break;
		case 3:
		{
			expon[1] = 16.1195750;
			expon[2] = 2.9362007;
			expon[3] = 0.7946505;
			expon[4] = 0.6362897;
			expon[5] = 0.1478601;
			expon[6] = 0.0480887;
			expon[7] = 0.6362897;
			expon[8] = 0.1478601;
			expon[9] = 0.0480887;
		}
		break;
		case 4:
		{
			expon[1] = 30.1678710;
			expon[2] = 5.4951153;
			expon[3] = 1.4871927;
			expon[4] = 1.3148331;
			expon[5] = 0.3055389;
			expon[6] = 0.0993707;
			expon[7] = 1.3148331;
			expon[8] = 0.3055389;
			expon[9] = 0.0993707;
		}
		break;
		case 5:
		{
			expon[1] = 48.7911130;
			expon[2] = 8.8873622;
			expon[3] = 2.4052670;
			expon[4] = 2.2369561;
			expon[5] = 0.5198205;
			expon[6] = 0.1690618;
			expon[7] = 2.2369561;
			expon[8] = 0.5198205;
			expon[9] = 0.1690618;
		}
		break;
		case 6:
		{
			expon[1] = 71.6168370;
			expon[2] = 13.0450960;
			expon[3] = 3.5305122;
			expon[4] = 2.9412494;
			expon[5] = 0.6834831;
			expon[6] = 0.2222899;
			expon[7] = 2.9412494;
			expon[8] = 0.6834831;
			expon[9] = 0.2222899;
		}
		break;
		case 7:
		{
			expon[1] = 99.1061690;
			expon[2] = 18.0523120;
			expon[3] = 4.8856602;
			expon[4] = 3.7804559;
			expon[5] = 0.8784966;
			expon[6] = 0.2857144;
			expon[7] = 3.7804559;
			expon[8] = 0.8784966;
			expon[9] = 0.2857144;
		}
		break;
		case 8:
		{
			expon[1] = 130.7093200;
			expon[2] = 23.8088610;
			expon[3] = 6.4436083;
			expon[4] = 5.0331513;
			expon[5] = 1.1695961;
			expon[6] = 0.3803890;
			expon[7] = 5.0331513;
			expon[8] = 1.1695961;
			expon[9] = 0.3803890;
		}
		break;
		case 9:
		{
			expon[1] = 166.6791300;
			expon[2] = 30.3608120;
			expon[3] = 8.2168207;
			expon[4] = 6.4648032;
			expon[5] = 1.5022812;
			expon[6] = 0.4885885;
			expon[7] = 6.4648032;
			expon[8] = 1.5022812;
			expon[9] = 0.4885885;
		}
		break;
		case 10:
		{
			expon[1] = 207.0156100;
			expon[2] = 37.7081510;
			expon[3] = 10.2052970;
			expon[4] = 8.2463151;
			expon[5] = 1.9162662;
			expon[6] = 0.6232293;
			expon[7] = 8.2463151;
			expon[8] = 1.9162662;
			expon[9] = 0.6232293;
		}
		break;
		case 11:
		{
			expon[1] = 250.7724300;
			expon[2] = 45.6785110;
			expon[3] = 12.3623880;
			expon[4] = 12.0401930;
			expon[5] = 2.7978819;
			expon[6] = 0.9099580;
			expon[7] = 12.0401930;
			expon[8] = 2.7978819;
			expon[9] = 0.9099580;
			expon[10] = 1.47874069;
			expon[11] = 0.41256490;
			expon[12] = 0.16147510;
			expon[13] = 1.47874069;
			expon[14] = 0.41256490;
			expon[15] = 0.16147510;
		}
		break;
		case 12:
		{
			expon[1] = 299.2374000;
			expon[2] = 54.5064700;
			expon[3] = 14.7515800;
			expon[4] = 15.1218200;
			expon[5] = 3.5139870;
			expon[6] = 1.1428570;
			expon[7] = 15.1218200;
			expon[8] = 3.5139870;
			expon[9] = 1.1428570;
			expon[10] = 1.39544809;
			expon[11] = 0.38932600;
			expon[12] = 0.15238000;
			expon[13] = 1.39544809;
			expon[14] = 0.38932600;
			expon[15] = 0.15238000;
		}
		break;
		case 13:
		{
			expon[1] = 351.4214767;
			expon[2] = 64.01186067;
			expon[3] = 17.32410761;
			expon[4] = 18.89939621;
			expon[5] = 4.391813233;
			expon[6] = 1.428353970;
			expon[7] = 18.89939621;
			expon[8] = 4.391813233;
			expon[9] = 1.428353970;
			expon[10] = 1.39544829309;
			expon[11] = 0.38932653180;
			expon[12] = 0.15237976590;
			expon[13] = 1.39544829309;
			expon[14] = 0.38932653180;
			expon[15] = 0.15237976590;
		}
		break;
		case 14:
		{
			expon[1] = 407.7975514;
			expon[2] = 74.28083305;
			expon[3] = 20.10329229;
			expon[4] = 23.19365606;
			expon[5] = 5.389706871;
			expon[6] = 1.752899952;
			expon[7] = 23.19365606;
			expon[8] = 5.389706871;
			expon[9] = 1.752899952;
			expon[10] = 1.47874062209;
			expon[11] = 0.41256488010;
			expon[12] = 0.16147509790;
			expon[13] = 1.47874062209;
			expon[14] = 0.41256488010;
			expon[15] = 0.16147509790;
		}
		break;
		case 15:
		{
			expon[1] = 468.3656378;
			expon[2] = 85.31338559;
			expon[3] = 23.08913156;
			expon[4] = 28.03263958;
			expon[5] = 6.514182577;
			expon[6] = 2.118614352;
			expon[7] = 28.03263958;
			expon[8] = 6.514182577;
			expon[9] = 2.118614352;
			expon[10] = 1.74310323109;
			expon[11] = 0.48632137710;
			expon[12] = 0.19034289090;
			expon[13] = 1.74310323109;
			expon[14] = 0.48632137710;
			expon[15] = 0.19034289090;
		}
		break;
		case 16:
		{
			expon[1] = 533.1257359;
			expon[2] = 97.10951830;
			expon[3] = 26.28162542;
			expon[4] = 33.32975173;
			expon[5] = 7.745117521;
			expon[6] = 2.518952599;
			expon[7] = 33.32975173;
			expon[8] = 7.745117521;
			expon[9] = 2.518952599;
			expon[10] = 2.02919427409;
			expon[11] = 0.56614005180;
			expon[12] = 0.22158337920;
			expon[13] = 2.02919427409;
			expon[14] = 0.56614005180;
			expon[15] = 0.22158337920;
		}
		break;
		case 17:
		{
			expon[1] = 601.3456136;
			expon[2] = 109.5358542;
			expon[3] = 29.64467686;
			expon[4] = 38.96041889;
			expon[5] = 9.053563477;
			expon[6] = 2.944499834;
			expon[7] = 38.96041889;
			expon[8] = 9.053563477;
			expon[9] = 2.944499834;
			expon[10] = 2.12938649509;
			expon[11] = 0.59409342740;
			expon[12] = 0.23252414100;
			expon[13] = 2.12938649509;
			expon[14] = 0.59409342740;
			expon[15] = 0.23252414100;
		}
		break;
		case 18:
		{
			expon[1] = 674.4465184;
			expon[2] = 122.8512753;
			expon[3] = 33.24834945;
			expon[4] = 45.16424392;
			expon[5] = 10.49519900;
			expon[6] = 3.413364448;
			expon[7] = 45.16424392;
			expon[8] = 10.49519900;
			expon[9] = 3.413364448;
			expon[10] = 2.62136651809;
			expon[11] = 0.73135460500;
			expon[12] = 0.28624723560;
			expon[13] = 2.62136651809;
			expon[14] = 0.73135460500;
			expon[15] = 0.28624723560;
		}
		break;
		case 19:
		{
			expon[1] = 771.5103681;
			expon[2] = 140.5315766;
			expon[3] = 38.03332899;
			expon[4] = 52.40203979;
			expon[5] = 12.17710710;
			expon[6] = 3.960373165;
			expon[7] = 52.40203979;
			expon[8] = 12.17710710;
			expon[9] = 3.960373165;
			expon[10] = 3.651583985;
			expon[11] = 1.018782663;
			expon[12] = 0.3987446295;
			expon[13] = 3.651583985;
			expon[14] = 1.018782663;
			expon[15] = 0.3987446295;
			expon[16] = 0.5039822505;
			expon[17] = 0.1860011465;
			expon[18] = 0.08214006743;
			expon[19] = 0.5039822505;
			expon[20] = 0.1860011465;
			expon[21] = 0.08214006743;
		}
		break;
		case 20:
		{
			expon[1] = 854.0324951;
			expon[2] = 155.5630851;
			expon[3] = 42.10144179;
			expon[4] = 59.56029944;
			expon[5] = 13.84053270;
			expon[6] = 4.501370797;
			expon[7] = 59.56029944;
			expon[8] = 13.84053270;
			expon[9] = 4.501370797;
			expon[10] = 4.374706256;
			expon[11] = 1.220531941;
			expon[12] = 0.477707930;
			expon[13] = 4.374706256;
			expon[14] = 1.220531941;
			expon[15] = 0.477707930;
			expon[16] = 0.4558489757;
			expon[17] = 0.1682369410;
			expon[18] = 0.0742952070;
			expon[19] = 0.4558489757;
			expon[20] = 0.1682369410;
			expon[21] = 0.0742952070;
		}
		break;
		case 21:
		{
			expon[1] = 941.6624250;
			expon[2] = 171.5249862;
			expon[3] = 46.42135516;
			expon[4] = 67.17668771;
			expon[5] = 15.61041754;
			expon[6] = 5.076992278;
			expon[7] = 67.17668771;
			expon[8] = 15.61041754;
			expon[9] = 5.076992278;
			expon[10] = 4.698159231;
			expon[11] = 1.433088313;
			expon[12] = 0.552930024;
			expon[13] = 4.698159231;
			expon[14] = 1.433088313;
			expon[15] = 0.552930024;
			expon[16] = 0.6309328384;
			expon[17] = 0.2328538976;
			expon[18] = 0.1028307363;
			expon[19] = 0.6309328384;
			expon[20] = 0.2328538976;
			expon[21] = 0.1028307363;
			expon[22] = 0.5517000679;
			expon[23] = 0.1682861055;
			expon[24] = 0.0649300112;
		}
		break;
		case 22:
		{
			expon[1] = 1033.5712450;
			expon[2] = 188.2662926;
			expon[3] = 50.95220601;
			expon[4] = 75.25120460;
			expon[5] = 17.48676162;
			expon[6] = 5.687237606;
			expon[7] = 75.25120460;
			expon[8] = 17.48676162;
			expon[9] = 5.687237606;
			expon[10] = 5.395535474;
			expon[11] = 1.645810296;
			expon[12] = 0.635004777;
			expon[13] = 5.395535474;
			expon[14] = 1.645810296;
			expon[15] = 0.635004777;
			expon[16] = 0.7122640246;
			expon[17] = 0.2628702203;
			expon[18] = 0.1160862609;
			expon[19] = 0.7122640246;
			expon[20] = 0.2628702203;
			expon[21] = 0.1160862609;
			expon[22] = 1.645981194;
			expon[23] = 0.502076728;
			expon[24] = 0.193716810;
		}
		break;
		case 23:
		{
			expon[1] = 1130.7625170;
			expon[2] = 205.9698041;
			expon[3] = 55.74346711;
			expon[4] = 83.78385011;
			expon[5] = 19.46956493;
			expon[6] = 6.332106784;
			expon[7] = 83.78385011;
			expon[8] = 19.46956493;
			expon[9] = 6.332106784;
			expon[10] = 6.141151276;
			expon[11] = 1.873246881;
			expon[12] = 0.7227568825;
			expon[13] = 6.141151276;
			expon[14] = 1.873246881;
			expon[15] = 0.7227568825;
			expon[16] = 0.7122640246;
			expon[17] = 0.2628702203;
			expon[18] = 0.1160862609;
			expon[19] = 0.7122640246;
			expon[20] = 0.2628702203;
			expon[21] = 0.1160862609;
			expon[22] = 2.964817927;
			expon[23] = 0.9043639676;
			expon[24] = 0.3489317337;
		}
		break;
		case 24:
		{
			expon[1] = 1232.3204500;
			expon[2] = 224.4687082;
			expon[3] = 60.74999251;
			expon[4] = 92.77462423;
			expon[5] = 21.55882749;
			expon[6] = 7.011599810;
			expon[7] = 92.77462423;
			expon[8] = 21.55882749;
			expon[9] = 7.011599810;
			expon[10] = 6.899488096;
			expon[11] = 2.104563782;
			expon[12] = 0.8120061343;
			expon[13] = 6.899488096;
			expon[14] = 2.104563782;
			expon[15] = 0.8120061343;
			expon[16] = 0.7547780537;
			expon[17] = 0.2785605708;
			expon[18] = 0.1230152851;
			expon[19] = 0.7547780537;
			expon[20] = 0.2785605708;
			expon[21] = 0.1230152851;
			expon[22] = 4.241479241;
			expon[23] = 1.293786360;
			expon[24] = 0.4991829993;
		}
		break;
		case 25:
		{
			expon[1] = 1337.1532660;
			expon[2] = 243.5641365;
			expon[3] = 65.91796062;
			expon[4] = 102.0220021;
			expon[5] = 23.70771923;
			expon[6] = 7.710486098;
			expon[7] = 102.0220021;
			expon[8] = 23.70771923;
			expon[9] = 7.710486098;
			expon[10] = 7.701960922;
			expon[11] = 2.349343572;
			expon[12] = 0.906449787;
			expon[13] = 7.701960922;
			expon[14] = 2.349343572;
			expon[15] = 0.906449787;
			expon[16] = 0.670982286;
			expon[17] = 0.247634663;
			expon[18] = 0.109358078;
			expon[19] = 0.670982286;
			expon[20] = 0.247634663;
			expon[21] = 0.109358078;
			expon[22] = 5.426950461;
			expon[23] = 1.655392868;
			expon[24] = 0.638702032;
		}
		break;
		case 26:
		{
			expon[1] = 1447.4004110;
			expon[2] = 263.6457916;
			expon[3] = 71.35284019;
			expon[4] = 111.9194891;
			expon[5] = 26.00768236;
			expon[6] = 8.458505490;
			expon[7] = 111.9194891;
			expon[8] = 26.00768236;
			expon[9] = 8.458505490;
			expon[10] = 8.548569754;
			expon[11] = 2.607586250;
			expon[12] = 1.006087840;
			expon[13] = 8.548569754;
			expon[14] = 2.607586250;
			expon[15] = 1.006087840;
			expon[16] = 0.5921156814;
			expon[17] = 0.2185279254;
			expon[18] = 0.0965042359;
			expon[19] = 0.5921156814;
			expon[20] = 0.2185279254;
			expon[21] = 0.0965042359;
			expon[22] = 6.411803475;
			expon[23] = 1.955804428;
			expon[24] = 0.754610151;
		}
		break;
		case 27:
		{
			expon[1] = 1557.2987040;
			expon[2] = 283.6639029;
			expon[3] = 76.77052234;
			expon[4] = 121.8344741;
			expon[5] = 28.31171164;
			expon[6] = 9.207847321;
			expon[7] = 121.8344741;
			expon[8] = 28.31171164;
			expon[9] = 9.207847321;
			expon[10] = 9.480851678;
			expon[11] = 2.891961952;
			expon[12] = 1.115808827;
			expon[13] = 9.480851678;
			expon[14] = 2.891961952;
			expon[15] = 1.115808827;
			expon[16] = 0.5921156814;
			expon[17] = 0.2185279254;
			expon[18] = 0.0965042359;
			expon[19] = 0.5921156814;
			expon[20] = 0.2185279254;
			expon[21] = 0.0965042359;
			expon[22] = 7.664527389;
			expon[23] = 2.337925151;
			expon[24] = 0.902044205;
		}
		break;
		case 28:
		{
			expon[1] = 1679.7710280;
			expon[2] = 305.9723896;
			expon[3] = 82.80806943;
			expon[4] = 132.8588899;
			expon[5] = 30.87354878;
			expon[6] = 10.04103627;
			expon[7] = 132.8588899;
			expon[8] = 30.87354878;
			expon[9] = 10.04103627;
			expon[10] = 10.33074335;
			expon[11] = 3.151206003;
			expon[12] = 1.215833241;
			expon[13] = 10.33074335;
			expon[14] = 3.151206003;
			expon[15] = 1.215833241;
			expon[16] = 0.6309328384;
			expon[17] = 0.2328538976;
			expon[18] = 0.1028307363;
			expon[19] = 0.6309328384;
			expon[20] = 0.2328538976;
			expon[21] = 0.1028307363;
			expon[22] = 8.627722755;
			expon[23] = 2.631730438;
			expon[24] = 1.015403419;
		}
		break;
		case 29:
		{
			expon[1] = 1801.8067300;
			expon[2] = 328.2013450;
			expon[3] = 88.82409228;
			expon[4] = 144.1212184;
			expon[5] = 33.49067173;
			expon[6] = 10.89220588;
			expon[7] = 144.1212184;
			expon[8] = 33.49067173;
			expon[9] = 10.89220588;
			expon[10] = 11.30775402;
			expon[11] = 3.449225397;
			expon[12] = 1.330818388;
			expon[13] = 11.30775402;
			expon[14] = 3.449225397;
			expon[15] = 1.330818388;
			expon[16] = 0.6309328384;
			expon[17] = 0.2328538976;
			expon[18] = 0.1028307363;
			expon[19] = 0.6309328384;
			expon[20] = 0.2328538976;
			expon[21] = 0.1028307363;
			expon[22] = 9.647911930;
			expon[23] = 2.942920654;
			expon[24] = 1.135470278;
		}
		break;
		case 30:
		{
			expon[1] = 1929.4323010;
			expon[2] = 351.4485021;
			expon[3] = 95.11568021;
			expon[4] = 155.8416755;
			expon[5] = 36.21425391;
			expon[6] = 11.77799934;
			expon[7] = 155.8416755;
			expon[8] = 36.21425391;
			expon[9] = 11.77799934;
			expon[10] = 12.28152744;
			expon[11] = 3.746257327;
			expon[12] = 1.445422541;
			expon[13] = 12.28152744;
			expon[14] = 3.746257327;
			expon[15] = 1.445422541;
			expon[16] = 0.8897138854;
			expon[17] = 0.3283603790;
			expon[18] = 0.1450074055;
			expon[19] = 0.8897138854;
			expon[20] = 0.3283603790;
			expon[21] = 0.1450074055;
			expon[22] = 10.94737077;
			expon[23] = 3.339297018;
			expon[24] = 1.288404602;
		}
		break;
		case 31:
		{
			expon[1] = 2061.4245320;
			expon[2] = 375.4910517;
			expon[3] = 101.6225324;
			expon[4] = 167.7618680;
			expon[5] = 38.98425028;
			expon[6] = 12.67888813;
			expon[7] = 167.7618680;
			expon[8] = 38.98425028;
			expon[9] = 12.67888813;
			expon[10] = 12.61505520;
			expon[11] = 3.847993927;
			expon[12] = 1.484675684;
			expon[13] = 12.61505520;
			expon[14] = 3.847993927;
			expon[15] = 1.484675684;
			expon[16] = 0.7985243736;
			expon[17] = 0.2947057141;
			expon[18] = 0.1301451506;
			expon[19] = 0.7985243736;
			expon[20] = 0.2947057141;
			expon[21] = 0.1301451506;
			expon[22] = 12.61505520;
			expon[23] = 3.847993927;
			expon[24] = 1.484675684;
		}
		break;
		case 32:
		{
			expon[1] = 2196.3842290;
			expon[2] = 400.0741292;
			expon[3] = 108.2756726;
			expon[4] = 180.3890380;
			expon[5] = 41.91853304;
			expon[6] = 13.63320795;
			expon[7] = 180.3890380;
			expon[8] = 41.91853304;
			expon[9] = 13.63320795;
			expon[10] = 14.19665619;
			expon[11] = 4.330432640;
			expon[12] = 1.670815538;
			expon[13] = 14.19665619;
			expon[14] = 4.330432640;
			expon[15] = 1.670815538;
			expon[16] = 0.9858325600;
			expon[17] = 0.3638342150;
			expon[18] = 0.1606730254;
			expon[19] = 0.9858325600;
			expon[20] = 0.3638342150;
			expon[21] = 0.1606730254;
			expon[22] = 14.19665619;
			expon[23] = 4.330432640;
			expon[24] = 1.670815538;
		}
		break;
		case 33:
		{
			expon[1] = 2337.0656730;
			expon[2] = 425.6994298;
			expon[3] = 115.2108790;
			expon[4] = 193.1970535;
			expon[5] = 44.89484040;
			expon[6] = 14.60119548;
			expon[7] = 193.1970535;
			expon[8] = 44.89484040;
			expon[9] = 14.60119548;
			expon[10] = 15.87163584;
			expon[11] = 4.841354819;
			expon[12] = 1.867945198;
			expon[13] = 15.87163584;
			expon[14] = 4.841354819;
			expon[15] = 1.867945198;
			expon[16] = 1.1076814640;
			expon[17] = 0.4088041239;
			expon[18] = 0.1805322114;
			expon[19] = 1.1076814640;
			expon[20] = 0.4088041239;
			expon[21] = 0.1805322114;
			expon[22] = 15.87163584;
			expon[23] = 4.841354819;
			expon[24] = 1.867945198;
		}
		break;
		case 34:
		{
			expon[1] = 2480.6268140;
			expon[2] = 451.8492708;
			expon[3] = 122.2880464;
			expon[4] = 206.1578780;
			expon[5] = 47.90665727;
			expon[6] = 15.58073180;
			expon[7] = 206.1578780;
			expon[8] = 47.90665727;
			expon[9] = 15.58073180;
			expon[10] = 17.63999414;
			expon[11] = 5.380760465;
			expon[12] = 2.076064666;
			expon[13] = 17.63999414;
			expon[14] = 5.380760465;
			expon[15] = 2.076064666;
			expon[16] = 1.2146442970;
			expon[17] = 0.4482801363;
			expon[18] = 0.1979652346;
			expon[19] = 1.2146442970;
			expon[20] = 0.4482801363;
			expon[21] = 0.1979652346;
			expon[22] = 17.63999414;
			expon[23] = 5.380760465;
			expon[24] = 2.076064666;
		}
		break;
		case 35:
		{
			expon[1] = 2629.9974710;
			expon[2] = 479.0573224;
			expon[3] = 129.6516070;
			expon[4] = 219.8350255;
			expon[5] = 51.08493222;
			expon[6] = 16.61440546;
			expon[7] = 219.8350255;
			expon[8] = 51.08493222;
			expon[9] = 16.61440546;
			expon[10] = 19.50173109;
			expon[11] = 5.948649577;
			expon[12] = 2.295173940;
			expon[13] = 19.50173109;
			expon[14] = 5.948649577;
			expon[15] = 2.295173940;
			expon[16] = 1.3960374880;
			expon[17] = 0.5152256318;
			expon[18] = 0.2275290713;
			expon[19] = 1.3960374880;
			expon[20] = 0.5152256318;
			expon[21] = 0.2275290713;
			expon[22] = 19.50173109;
			expon[23] = 5.948649577;
			expon[24] = 2.295173940;
		}
		break;
		case 36:
		{
			expon[1] = 2782.1600550;
			expon[2] = 506.7739270;
			expon[3] = 137.1528019;
			expon[4] = 233.9514118;
			expon[5] = 54.36527681;
			expon[6] = 17.68127533;
			expon[7] = 233.9514118;
			expon[8] = 54.36527681;
			expon[9] = 17.68127533;
			expon[10] = 21.45684671;
			expon[11] = 6.545022156;
			expon[12] = 2.525273021;
			expon[13] = 21.45684671;
			expon[14] = 6.545022156;
			expon[15] = 2.525273021;
			expon[16] = 1.5900493360;
			expon[17] = 0.5868282053;
			expon[18] = 0.2591495227;
			expon[19] = 1.5900493360;
			expon[20] = 0.5868282053;
			expon[21] = 0.2591495227;
			expon[22] = 21.45684671;
			expon[23] = 6.545022156;
			expon[24] = 2.525273021;
		}
		break;
		case 37:
		{
			expon[1] = 2938.6015290;
			expon[2] = 535.2699370;
			expon[3] = 144.8649340;
			expon[4] = 248.5070370;
			expon[5] = 57.7476910;
			expon[6] = 18.7813410;
			expon[7] = 248.5070370;
			expon[8] = 57.7476910;
			expon[9] = 18.7813410;
			expon[10] = 23.50534097;
			expon[11] = 7.169878201;
			expon[12] = 2.766361909;
			expon[13] = 23.50534097;
			expon[14] = 7.169878201;
			expon[15] = 2.766361909;
			expon[16] = 2.247796820;
			expon[17] = 0.829578393;
			expon[18] = 0.366350565;
			expon[19] = 2.247796820;
			expon[20] = 0.829578393;
			expon[21] = 0.366350565;
			expon[22] = 0.4869939919;
			expon[23] = 0.2622161565;
			expon[24] = 0.1158254875;
			expon[25] = 0.4869939919;
			expon[26] = 0.2622161565;
			expon[27] = 0.1158254875;
			expon[28] = 23.50534097;
			expon[29] = 7.169878201;
			expon[30] = 2.766361909;
		}
		break;
		case 38:
		{
			expon[1] = 3100.9839510;
			expon[2] = 564.8480978;
			expon[3] = 152.8699389;
			expon[4] = 263.5019007;
			expon[5] = 61.23217493;
			expon[6] = 19.91460372;
			expon[7] = 263.5019007;
			expon[8] = 61.23217493;
			expon[9] = 19.91460372;
			expon[10] = 25.57886692;
			expon[11] = 7.802369707;
			expon[12] = 3.010396794;
			expon[13] = 25.57886692;
			expon[14] = 7.802369707;
			expon[15] = 3.010396794;
			expon[16] = 2.461032403;
			expon[17] = 0.908275734;
			expon[18] = 0.401104140;
			expon[19] = 2.461032403;
			expon[20] = 0.908275734;
			expon[21] = 0.401104140;
			expon[22] = 0.4370804803;
			expon[23] = 0.2353408164;
			expon[24] = 0.1039541771;
			expon[25] = 0.4370804803;
			expon[26] = 0.2353408164;
			expon[27] = 0.1039541771;
			expon[28] = 25.57886692;
			expon[29] = 7.802369707;
			expon[30] = 3.010396794;
		}
		break;
		case 39:
		{
			expon[1] = 3266.0268690;
			expon[2] = 594.9108710;
			expon[3] = 161.0060990;
			expon[4] = 277.9377240;
			expon[5] = 64.5867500;
			expon[6] = 21.0056160;
			expon[7] = 277.9377240;
			expon[8] = 64.5867500;
			expon[9] = 21.0056160;
			expon[10] = 30.6713260;
			expon[11] = 8.5572220;
			expon[12] = 3.3492390;
			expon[13] = 30.6713260;
			expon[14] = 8.5572220;
			expon[15] = 3.3492390;
			expon[16] = 2.6676880;
			expon[17] = 0.9845440;
			expon[18] = 0.4347850;
			expon[19] = 2.6676880;
			expon[20] = 0.9845440;
			expon[21] = 0.4347850;
			expon[22] = 0.2074240;
			expon[23] = 0.1116850;
			expon[24] = 0.0493330;
			expon[25] = 0.2074240;
			expon[26] = 0.1116850;
			expon[27] = 0.0493330;
			expon[28] = 5.6600430;
			expon[29] = 1.7747150;
			expon[30] = 0.6912950;
			expon[31] = 2.1282120;
			expon[32] = 0.9625940;
			expon[33] = 0.4728610;
		}
		break;
		case 40:
		{
			expon[1] = 3435.3486770;
			expon[2] = 625.7530498;
			expon[3] = 169.3531958;
			expon[4] = 293.7830292;
			expon[5] = 68.26885797;
			expon[6] = 22.20315144;
			expon[7] = 293.7830292;
			expon[8] = 68.26885797;
			expon[9] = 22.20315144;
			expon[10] = 30.73293103;
			expon[11] = 9.374523538;
			expon[12] = 3.616982618;
			expon[13] = 30.73293103;
			expon[14] = 9.374523538;
			expon[15] = 3.616982618;
			expon[16] = 2.827607815;
			expon[17] = 1.101055827;
			expon[18] = 0.4846874856;
			expon[19] = 2.827607815;
			expon[20] = 1.101055827;
			expon[21] = 0.4846874856;
			expon[22] = 0.8878301887;
			expon[23] = 0.3457164736;
			expon[24] = 0.1521852428;
			expon[25] = 0.8878301887;
			expon[26] = 0.3457164736;
			expon[27] = 0.1521852428;
			expon[28] = 30.73293103;
			expon[29] = 9.374523538;
			expon[30] = 3.616982618;
			expon[31] = 0.4869939919;
			expon[32] = 0.2622161565;
			expon[33] = 0.1158254875;
		}
		break;
		case 41:
		{
			expon[1] = 3610.7428640;
			expon[2] = 657.7013201;
			expon[3] = 177.9996445;
			expon[4] = 310.0675728;
			expon[5] = 72.05303569;
			expon[6] = 23.43388348;
			expon[7] = 310.0675728;
			expon[8] = 72.05303569;
			expon[9] = 23.43388348;
			expon[10] = 33.01997858;
			expon[11] = 10.07214594;
			expon[12] = 3.886147028;
			expon[13] = 33.01997858;
			expon[14] = 10.07214594;
			expon[15] = 3.886147028;
			expon[16] = 3.144798430;
			expon[17] = 1.224568208;
			expon[18] = 0.5390579399;
			expon[19] = 3.144798430;
			expon[20] = 1.224568208;
			expon[21] = 0.5390579399;
			expon[22] = 0.4869939919;
			expon[23] = 0.2622161565;
			expon[24] = 0.1158254875;
			expon[25] = 0.4869939919;
			expon[26] = 0.2622161565;
			expon[27] = 0.1158254875;
			expon[28] = 33.01997858;
			expon[29] = 10.07214594;
			expon[30] = 3.886147028;
			expon[31] = 1.344878866;
			expon[32] = 0.5236888594;
			expon[33] = 0.2305291251;
		}
		break;
		case 42:
		{
			expon[1] = 3788.6661150;
			expon[2] = 690.1102623;
			expon[3] = 186.7707691;
			expon[4] = 326.4309567;
			expon[5] = 75.85553420;
			expon[6] = 24.67057401;
			expon[7] = 326.4309567;
			expon[8] = 75.85553420;
			expon[9] = 24.67057401;
			expon[10] = 35.46948129;
			expon[11] = 10.81932234;
			expon[12] = 4.174430912;
			expon[13] = 35.46948129;
			expon[14] = 10.81932234;
			expon[15] = 4.174430912;
			expon[16] = 3.496895188;
			expon[17] = 1.361672861;
			expon[18] = 0.5994117456;
			expon[19] = 3.496895188;
			expon[20] = 1.361672861;
			expon[21] = 0.5994117456;
			expon[22] = 0.5129625081;
			expon[23] = 0.2761985970;
			expon[24] = 0.1220017773;
			expon[25] = 0.5129625081;
			expon[26] = 0.2761985970;
			expon[27] = 0.1220017773;
			expon[28] = 35.46948129;
			expon[29] = 10.81932234;
			expon[30] = 4.174430912;
			expon[31] = 1.702112315;
			expon[32] = 0.6627937127;
			expon[33] = 0.2917634240;
		}
		break;
		case 43:
		{
			expon[1] = 3970.8682570;
			expon[2] = 723.2986098;
			expon[3] = 195.7528311;
			expon[4] = 343.5846323;
			expon[5] = 79.84167952;
			expon[6] = 25.96699219;
			expon[7] = 343.5846323;
			expon[8] = 79.84167952;
			expon[9] = 25.96699219;
			expon[10] = 38.08991983;
			expon[11] = 11.61863962;
			expon[12] = 4.482832367;
			expon[13] = 38.08991983;
			expon[14] = 11.61863962;
			expon[15] = 4.482832367;
			expon[16] = 3.829752708;
			expon[17] = 1.491285854;
			expon[18] = 0.6564677040;
			expon[19] = 3.829752708;
			expon[20] = 1.491285854;
			expon[21] = 0.6564677040;
			expon[22] = 0.4616999826;
			expon[23] = 0.2485968963;
			expon[24] = 0.1098096207;
			expon[25] = 0.4616999826;
			expon[26] = 0.2485968963;
			expon[27] = 0.1098096207;
			expon[28] = 38.08991983;
			expon[29] = 11.61863962;
			expon[30] = 4.482832367;
			expon[31] = 2.101373228;
			expon[32] = 0.8182638428;
			expon[33] = 0.3602017580;
		}
		break;
		case 44:
		{
			expon[1] = 4159.2742100;
			expon[2] = 757.6169894;
			expon[3] = 205.0407239;
			expon[4] = 360.7986561;
			expon[5] = 83.84184843;
			expon[6] = 27.26797127;
			expon[7] = 360.7986561;
			expon[8] = 83.84184843;
			expon[9] = 27.26797127;
			expon[10] = 40.71751678;
			expon[11] = 12.42014044;
			expon[12] = 4.792076302;
			expon[13] = 40.71751678;
			expon[14] = 12.42014044;
			expon[15] = 4.792076302;
			expon[16] = 4.197516371;
			expon[17] = 1.634491118;
			expon[18] = 0.7195070139;
			expon[19] = 4.197516371;
			expon[20] = 1.634491118;
			expon[21] = 0.7195070139;
			expon[22] = 0.4131354848;
			expon[23] = 0.2224479167;
			expon[24] = 0.0982591566;
			expon[25] = 0.4131354848;
			expon[26] = 0.2224479167;
			expon[27] = 0.0982591566;
			expon[28] = 40.71751678;
			expon[29] = 12.42014044;
			expon[30] = 4.792076302;
			expon[31] = 2.390895761;
			expon[32] = 0.9310024167;
			expon[33] = 0.4098295558;
		}
		break;
		case 45:
		{
			expon[1] = 4350.0777940;
			expon[2] = 792.3721005;
			expon[3] = 214.4468133;
			expon[4] = 378.4334264;
			expon[5] = 87.93978981;
			expon[6] = 28.60074899;
			expon[7] = 378.4334264;
			expon[8] = 87.93978981;
			expon[9] = 28.60074899;
			expon[10] = 43.52179455;
			expon[11] = 13.27553454;
			expon[12] = 5.122113939;
			expon[13] = 43.52179455;
			expon[14] = 13.27553454;
			expon[15] = 5.122113939;
			expon[16] = 4.540857408;
			expon[17] = 1.768186338;
			expon[18] = 0.7783599789;
			expon[19] = 4.540857408;
			expon[20] = 1.768186338;
			expon[21] = 0.7783599789;
			expon[22] = 0.4131354848;
			expon[23] = 0.2224479167;
			expon[24] = 0.0982591566;
			expon[25] = 0.4131354848;
			expon[26] = 0.2224479167;
			expon[27] = 0.0982591566;
			expon[28] = 43.52179455;
			expon[29] = 13.27553454;
			expon[30] = 5.122113939;
			expon[31] = 2.779066094;
			expon[32] = 1.082153932;
			expon[33] = 0.4763668250;
		}
		break;
		case 46:
		{
			expon[1] = 4545.1602690;
			expon[2] = 827.9066168;
			expon[3] = 224.0638402;
			expon[4] = 396.4889433;
			expon[5] = 92.13550365;
			expon[6] = 29.96532535;
			expon[7] = 396.4889433;
			expon[8] = 92.13550365;
			expon[9] = 29.96532535;
			expon[10] = 46.41945097;
			expon[11] = 14.15941211;
			expon[12] = 5.463141383;
			expon[13] = 46.41945097;
			expon[14] = 14.15941211;
			expon[15] = 5.463141383;
			expon[16] = 4.919104589;
			expon[17] = 1.915473830;
			expon[18] = 0.8431962954;
			expon[19] = 4.919104589;
			expon[20] = 1.915473830;
			expon[21] = 0.8431962954;
			expon[22] = 0.4370804803;
			expon[23] = 0.2353408164;
			expon[24] = 0.1039541771;
			expon[25] = 0.4370804803;
			expon[26] = 0.2353408164;
			expon[27] = 0.1039541771;
			expon[28] = 46.41945097;
			expon[29] = 14.15941211;
			expon[30] = 5.463141383;
			expon[31] = 3.025977448;
			expon[32] = 1.178299934;
			expon[33] = 0.5186905316;
		}
		break;
		case 47:
		{
			expon[1] = 4744.5216340;
			expon[2] = 864.2205383;
			expon[3] = 233.8918045;
			expon[4] = 414.9652069;
			expon[5] = 96.42898995;
			expon[6] = 31.36170035;
			expon[7] = 414.9652069;
			expon[8] = 96.42898995;
			expon[9] = 31.36170035;
			expon[10] = 49.41048605;
			expon[11] = 15.07177314;
			expon[12] = 5.815158634;
			expon[13] = 49.41048605;
			expon[14] = 15.07177314;
			expon[15] = 5.815158634;
			expon[16] = 5.290230450;
			expon[17] = 2.059988316;
			expon[18] = 0.9068119281;
			expon[19] = 5.290230450;
			expon[20] = 2.059988316;
			expon[21] = 0.9068119281;
			expon[22] = 0.4370804803;
			expon[23] = 0.2353408164;
			expon[24] = 0.1039541771;
			expon[25] = 0.4370804803;
			expon[26] = 0.2353408164;
			expon[27] = 0.1039541771;
			expon[28] = 49.41048605;
			expon[29] = 15.07177314;
			expon[30] = 5.815158634;
			expon[31] = 3.283395668;
			expon[32] = 1.278537254;
			expon[33] = 0.5628152469;
		}
		break;
		case 48:
		{
			expon[1] = 4950.2619050;
			expon[2] = 901.6963856;
			expon[3] = 244.0342313;
			expon[4] = 433.4469385;
			expon[5] = 100.7237469;
			expon[6] = 32.75848861;
			expon[7] = 433.4469385;
			expon[8] = 100.7237469;
			expon[9] = 32.75848861;
			expon[10] = 52.59279235;
			expon[11] = 16.04247800;
			expon[12] = 6.189686744;
			expon[13] = 52.59279235;
			expon[14] = 16.04247800;
			expon[15] = 6.189686744;
			expon[16] = 5.674851796;
			expon[17] = 2.209757875;
			expon[18] = 0.9727408566;
			expon[19] = 5.674851796;
			expon[20] = 2.209757875;
			expon[21] = 0.9727408566;
			expon[22] = 0.5949150981;
			expon[23] = 0.3203250000;
			expon[24] = 0.1414931855;
			expon[25] = 0.5949150981;
			expon[26] = 0.3203250000;
			expon[27] = 0.1414931855;
			expon[28] = 52.59279235;
			expon[29] = 16.04247800;
			expon[30] = 6.189686744;
			expon[31] = 3.642963976;
			expon[32] = 1.418551290;
			expon[33] = 0.6244497700;
		}
		break;
		case 49:
		{
			expon[1] = 5158.2247140;
			expon[2] = 939.5770707;
			expon[3] = 254.2862231;
			expon[4] = 452.3313223;
			expon[5] = 105.1120716;
			expon[6] = 34.18570799;
			expon[7] = 452.3313223;
			expon[8] = 105.1120716;
			expon[9] = 34.18570799;
			expon[10] = 55.97539769;
			expon[11] = 17.07428044;
			expon[12] = 6.587788204;
			expon[13] = 55.97539769;
			expon[14] = 17.07428044;
			expon[15] = 6.587788204;
			expon[16] = 5.048549180;
			expon[17] = 1.965878882;
			expon[18] = 0.8653847237;
			expon[19] = 5.048549180;
			expon[20] = 1.965878882;
			expon[21] = 0.8653847237;
			expon[22] = 0.5669230612;
			expon[23] = 0.3052530187;
			expon[24] = 0.1348356264;
			expon[25] = 0.5669230612;
			expon[26] = 0.3052530187;
			expon[27] = 0.1348356264;
			expon[28] = 55.97539769;
			expon[29] = 17.07428044;
			expon[30] = 6.587788204;
			expon[31] = 5.048549180;
			expon[32] = 1.965878882;
			expon[33] = 0.8653847237;
		}
		break;
		case 50:
		{
			expon[1] = 5370.4664130;
			expon[2] = 978.2371611;
			expon[3] = 264.7491522;
			expon[4] = 472.0515322;
			expon[5] = 109.6946243;
			expon[6] = 35.67609636;
			expon[7] = 472.0515322;
			expon[8] = 109.6946243;
			expon[9] = 35.67609636;
			expon[10] = 59.15141188;
			expon[11] = 18.04306600;
			expon[12] = 6.961575790;
			expon[13] = 59.15141188;
			expon[14] = 18.04306600;
			expon[15] = 6.961575790;
			expon[16] = 5.583138529;
			expon[17] = 2.174045204;
			expon[18] = 0.9570200509;
			expon[19] = 5.583138529;
			expon[20] = 2.174045204;
			expon[21] = 0.9570200509;
			expon[22] = 0.6235816420;
			expon[23] = 0.3357601616;
			expon[24] = 0.1483111678;
			expon[25] = 0.6235816420;
			expon[26] = 0.3357601616;
			expon[27] = 0.1483111678;
			expon[28] = 59.15141188;
			expon[29] = 18.04306600;
			expon[30] = 6.961575790;
			expon[31] = 5.583138529;
			expon[32] = 2.174045204;
			expon[33] = 0.9570200509;
		}
		break;
		case 51:
		{
			expon[1] = 5586.9870020;
			expon[2] = 1017.6766570;
			expon[3] = 275.4230189;
			expon[4] = 492.1924888;
			expon[5] = 114.3749494;
			expon[6] = 37.19828336;
			expon[7] = 492.1924888;
			expon[8] = 114.3749494;
			expon[9] = 37.19828336;
			expon[10] = 62.52179775;
			expon[11] = 19.07114112;
			expon[12] = 7.358239131;
			expon[13] = 62.52179775;
			expon[14] = 19.07114112;
			expon[15] = 7.358239131;
			expon[16] = 6.120693149;
			expon[17] = 2.383366187;
			expon[18] = 1.049163663;
			expon[19] = 6.120693149;
			expon[20] = 2.383366187;
			expon[21] = 1.049163663;
			expon[22] = 0.6529226928;
			expon[23] = 0.3515585034;
			expon[24] = 0.1552895732;
			expon[25] = 0.6529226928;
			expon[26] = 0.3515585034;
			expon[27] = 0.1552895732;
			expon[28] = 62.52179775;
			expon[29] = 19.07114112;
			expon[30] = 7.358239131;
			expon[31] = 6.120693149;
			expon[32] = 2.383366187;
			expon[33] = 1.049163663;
		}
		break;
		case 52:
		{
			expon[1] = 5810.0615910;
			expon[2] = 1058.3099720;
			expon[3] = 286.4199797;
			expon[4] = 512.7541920;
			expon[5] = 119.1530471;
			expon[6] = 38.75226900;
			expon[7] = 512.7541920;
			expon[8] = 119.1530471;
			expon[9] = 38.75226900;
			expon[10] = 65.98556227;
			expon[11] = 20.12769970;
			expon[12] = 7.765892279;
			expon[13] = 65.98556227;
			expon[14] = 20.12769970;
			expon[15] = 7.765892279;
			expon[16] = 6.707956921;
			expon[17] = 2.612043655;
			expon[18] = 1.149828048;
			expon[19] = 6.707956921;
			expon[20] = 2.612043655;
			expon[21] = 1.149828048;
			expon[22] = 0.7012713483;
			expon[23] = 0.3775912653;
			expon[24] = 0.1667887020;
			expon[25] = 0.7012713483;
			expon[26] = 0.3775912653;
			expon[27] = 0.1667887020;
			expon[28] = 65.98556227;
			expon[29] = 20.12769970;
			expon[30] = 7.765892279;
			expon[31] = 6.707956921;
			expon[32] = 2.612043655;
			expon[33] = 1.149828048;
		}
		break;
		case 53:
		{
			expon[1] = 6035.1836230;
			expon[2] = 1099.3162310;
			expon[3] = 297.5178737;
			expon[4] = 533.7366418;
			expon[5] = 124.0289171;
			expon[6] = 40.33805328;
			expon[7] = 533.7366418;
			expon[8] = 124.0289171;
			expon[9] = 40.33805328;
			expon[10] = 69.54270545;
			expon[11] = 21.21274175;
			expon[12] = 8.184535234;
			expon[13] = 69.54270545;
			expon[14] = 21.21274175;
			expon[15] = 8.184535234;
			expon[16] = 7.295991196;
			expon[17] = 2.841021154;
			expon[18] = 1.250624506;
			expon[19] = 7.295991196;
			expon[20] = 2.841021154;
			expon[21] = 1.250624506;
			expon[22] = 0.7900364582;
			expon[23] = 0.4253857892;
			expon[24] = 0.1879003836;
			expon[25] = 0.7900364582;
			expon[26] = 0.4253857892;
			expon[27] = 0.1879003836;
			expon[28] = 69.54270545;
			expon[29] = 21.21274175;
			expon[30] = 8.184535234;
			expon[31] = 7.295991196;
			expon[32] = 2.841021154;
			expon[33] = 1.250624506;
		}
		break;
	}
}
