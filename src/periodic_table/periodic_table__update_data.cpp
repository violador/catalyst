#include "periodic_table.hpp"
//
//
//
/// @brief Checks the current element and updates the internal data.
//
/// @return None.
//
void periodic_table::update_data()
{
	switch(current_element)
	{
	case 1:
	{
		current_symbol            = "H";
		current_name              = "hydrogen";
		current_mass              = 1.007940;
		current_core_electrons    = 0;
		current_valence_electrons = 1;
		current_electronic_config = "1s^1";
		current_covalent_radius   = 0.32;
		current_orbitals          = 1;
	}
	break;
	case 2:
	{
		current_symbol            = "He";
		current_name              = "helium";
	    current_mass              = 4.002602;
		current_core_electrons    = 2;
		current_valence_electrons = 0;
		current_electronic_config = "1s^2";
		current_covalent_radius   = 0.93;
	}
	break;
	case 3:
	{
		current_symbol            = "Li";
		current_name              = "3-name";
		current_mass              = 6.941000;
		current_core_electrons    = 2;
		current_valence_electrons = 1;
		current_electronic_config = "[He] 2s^1";
		current_covalent_radius   = 1.23;
	}
	break;
	case 4:
	{
		current_symbol            = "Be";
		current_name              = "4-name";
		current_mass              = 9.012182;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[He] 2s^2";
		current_covalent_radius   = 0.90;
	}
	break;
	case 5:
	{
		current_symbol            = "B";
		current_name              = "5-name";
		current_mass              = 10.811000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[He] 2s^2 2p^1";
		current_covalent_radius   = 0.82;
	}
	case 6:
	{
		current_symbol            = "C";
		current_name              = "carbom";
	current_mass              = 12.011000;
		current_core_electrons    = 2;
		current_valence_electrons = 4;
		current_electronic_config = "[He] 2s^2 2p^2";
		current_covalent_radius   = 0.77;
	}
	break;
	case 7:
	{
		current_symbol            = "N";
		current_name              = "7-name";
		current_mass              = 14.006740;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[He] 2s^2 2p^3";
		current_covalent_radius   = 0.75;
	}
	break;
	case 8:
	{
		current_symbol            = "O";
		current_name              = "8-name";
		current_mass              = 15.999400;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[He] 2s^2 2p^4";
		current_covalent_radius   = 0.73;
		current_orbitals          = 5;
	}
	break;
	case 9:
	{
		current_symbol            = "F";
		current_name              = "9-name";
		current_mass              = 18.998400;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[He] 2s^2 2p^5";
		current_covalent_radius   = 0.72;
	}
	break;
	case 10:
	{
		current_symbol            = "Ne";
		current_name              = "10-name";
		current_mass              = 20.179700;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[He] 2s^2 2p^6";
		current_covalent_radius   = 0.71;
	}
	break;
	case 11:
	{
		current_symbol            = "Na";
		current_name              = "11-name";
		current_mass              = 22.989768;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^1";
		current_covalent_radius   = 1.54;
	}
	break;
	case 12:
	{
		current_symbol            = "Mg";
		current_name              = "12-name";
		current_mass              = 24.305000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2";
		current_covalent_radius   = 1.36;
	}
	break;
	case 13:
	{
		current_symbol            = "Al";
		current_name              = "13-name";
		current_mass              = 26.981539;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2 3p^1";
		current_covalent_radius   = 1.18;

	break;
	case 14:
	{
		current_symbol            = "Si";
		current_name              = "14-name";
		current_mass              = 28.085500;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2 3p^2";
		current_covalent_radius   = 1.11;
	}
	break;
	case 15:
	{
		current_symbol            = "P";
		current_name              = "15-name";
		current_mass              = 30.973762;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2 3p^3";
		current_covalent_radius   = 1.06;
	}
	break;
	case 16:
	{
		current_symbol            = "S";
		current_name              = "16-name";
		current_mass              = 32.066000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2 3p^4";
		current_covalent_radius   = 1.02;
	}
	break;
	case 17:
	{
		current_symbol            = "Cl";
		current_name              = "17-name";
		current_mass              = 35.452700;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2 3p^5";
		current_covalent_radius   = 0.99;
	}
	break;
	case 18:
	{
		current_symbol            = "Ar";
		current_name              = "18-name";
		current_mass              = 39.948000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ne] 3s^2 3p^6";
		current_covalent_radius   = 0.98;
	}
	break;
	case 19:
	{
		current_symbol            = "K";
		current_name              = "19-name";
		current_mass              = 39.098300;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 4s^1";
		current_covalent_radius   = 2.03;
	}
	break;
	case 20:
	{
		current_symbol            = "Ca";
		current_name              = "20-name";
		current_mass              = 40.078000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 4s^2";
		current_covalent_radius   = 1.74;
	}
	break;
	case 21:
	{
		current_symbol            = "Sc";
		current_name              = "21-name";
		current_mass              = 44.955910;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^1 4s^2";
		current_covalent_radius   = 1.44;
	}
	break;
	case 22:
	{
		current_symbol            = "Ti";
		current_name              = "22-name";
		current_mass              = 47.880000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^2 4s^2";
		current_covalent_radius   = 1.32;
	}
	break;
	case 23:
	{
		current_symbol            = "V";
		current_name              = "23-name";
		current_mass              = 50.941500;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^3 4s^2";
		current_covalent_radius   = 1.22;
	}
	break;
	case 24:
	{
		current_symbol            = "Cr";
		current_name              = "24-name";
		current_mass              = 51.996100;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^5 4s^1";
		current_covalent_radius   = 1.18;
	}
	break;
	case 25:
	{
		current_symbol            = "Mn";
		current_name              = "25-name";
		current_mass              = 54.938050;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^5 4s^2";
		current_covalent_radius   = 1.17;
	}
	break;
	case 26:
	{
		current_symbol            = "Fe";
		current_name              = "26-name";
		current_mass              = 55.847000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^6 4s^2";
		current_covalent_radius   = 1.17;
	}
	break;
	case 27:
	{
		current_symbol            = "Co";
		current_name              = "27-name";
		current_mass              = 58.933200;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^7 4s^2";
		current_covalent_radius   = 1.16;
	}
	break;
	case 28:
	{
		current_symbol            = "Ni";
		current_name              = "28-name";
		current_mass              = 58.693400;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^8 4s^2";
		current_covalent_radius   = 1.15;
	}
	break;
	case 29:
	{
		current_symbol            = "Cu";
		current_name              = "29-name";
		current_mass              = 63.546000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^1";
		current_covalent_radius   = 1.17;
	}
	break;
	case 30:
	{
		current_symbol            = "Zn";
		current_name              = "30-name";
		current_mass              = 65.390000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2";
		current_covalent_radius   = 1.25;
	}
	break;
	case 31:
	{
		current_symbol            = "Ga";
		current_name              = "31-name";
		current_mass              = 69.723000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2 4p^1";
		current_covalent_radius   = 1.26;
	}
	break;
	case 32:
	{
		current_symbol            = "Ge";
		current_name              = "32-name";
		current_mass              = 72.610000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2 4p^2";
		current_covalent_radius   = 1.22;
	}
	break;
	case 33:
	{
		current_symbol            = "As";
		current_name              = "33-name";
		current_mass              = 74.921590;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2 4p^3";
		current_covalent_radius   = 1.20;
	}
	break;
	case 34:
	{
		current_symbol            = "Se";
		current_name              = "34-name";
		current_mass              = 78.960000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2 4p^4";
		current_covalent_radius   = 1.16;
	}
	break;
	case 35:
	{
		current_symbol            = "Br";
		current_name              = "35-name";
		current_mass              = 79.904000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2 4p^5";
		current_covalent_radius   = 1.14;
	}
	break;
	case 36:
	{
		current_symbol            = "Kr";
		current_name              = "36-name";
		current_mass              = 83.800000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Ar] 3d^10 4s^2 4p^6";
		current_covalent_radius   = 1.12;
	}
	break;
	case 37:
	{
		current_symbol            = "Rb";
		current_name              = "37-name";
		current_mass              = 85.467800;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 5s^1";
		current_covalent_radius   = 2.16;
	}
	break;
	case 38:
	{
		current_symbol            = "Sr";
		current_name              = "38-name";
		current_mass              = 87.620000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 5s^2";
		current_covalent_radius   = 1.91;
	}
	break;
	case 39:
	{
		current_symbol            = "Y";
		current_name              = "39-name";
		current_mass              = 88.905850;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^1 5s^2";
		current_covalent_radius   = 1.62;
	}
	break;
	case 40:
	{
		current_symbol            = "Zr";
		current_name              = "40-name";
		current_mass              = 91.224000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^2 5s^2";
		current_covalent_radius   = 1.45;
	}
	break;
	case 41:
	{
		current_symbol            = "Nb";
		current_name              = "41-name";
		current_mass              = 92.906380;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^4 5s^1";
		current_covalent_radius   = 1.34;
	}
	break;
	case 42:
	{
		current_symbol            = "Mo";
		current_name              = "42-name";
		current_mass              = 95.940000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^5 5s^1";
		current_covalent_radius   = 1.30;
	}
	break;
	case 43:
	{
		current_symbol            = "Tc";
		current_name              = "43-name";
		current_mass              = 98.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^5 5s^2";
		current_covalent_radius   = 1.27;
	}
	break;
	case 44:
	{
		current_symbol            = "Ru";
		current_name              = "44-name";
		current_mass              = 101.070000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^7 5s^1";
		current_covalent_radius   = 1.25;
	}
	break;
	case 45:
	{
		current_symbol            = "Rh";
		current_name              = "45-name";
		current_mass              = 102.905500;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^8 5s^1";
		current_covalent_radius   = 1.25;
	}
	break;
	case 46:
	{
		current_symbol            = "Pd";
		current_name              = "46-name";
		current_mass              = 106.420000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10";
		current_covalent_radius   = 1.28;
	}
	break;
	case 47:
	{
		current_symbol            = "Ag";
		current_name              = "47-name";
		current_mass              = 107.868200;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^1";
		current_covalent_radius   = 1.34;
	}
	break;
	case 48:
	{
		current_symbol            = "Cd";
		current_name              = "48-name";
		current_mass              = 112.411000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2";
		current_covalent_radius   = 1.48;
	}
	break;
	case 49:
	{
		current_symbol            = "In";
		current_name              = "49-name";
		current_mass              = 114.820000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2 5p^1";
		current_covalent_radius   = 1.44;
	}
	break;
	case 50:
	{
		current_symbol            = "Sn";
		current_name              = "50-name";
		current_mass              = 118.710000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2 5p^2";
		current_covalent_radius   = 1.41;
	}
	break;
	case 51:
	{
		current_symbol            = "Sb";
		current_name              = "51-name";
		current_mass              = 121.757000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2 5p^3";
		current_covalent_radius   = 1.40;
	}
	break;
	case 52:
	{
		current_symbol            = "Te";
		current_name              = "52-name";
		current_mass              = 127.600000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2 5p^4";
		current_covalent_radius   = 1.36;
	}
	break;
	case 53:
	{
		current_symbol            = "I";
		current_name              = "53-name";
		current_mass              = 126.904470;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2 5p^5";
		current_covalent_radius   = 1.33;
	}
	break;
	case 54:
	{
		current_symbol            = "Xe";
		current_name              = "54-name";
		current_mass              = 131.290000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Kr] 4d^10 5s^2 5p^6";
		current_covalent_radius   = 1.31;
	}
	break;
	case 55:
	{
		current_symbol            = "Cs";
		current_name              = "55-name";
		current_mass              = 132.905430;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 6s^1";
		current_covalent_radius   = 2.35;
	}
	break;
	case 56:
	{
		current_symbol            = "Ba";
		current_name              = "56-name";
		current_mass              = 137.327000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 6s^2";
		current_covalent_radius   = 1.98;
	}
	break;
	case 57:
	{
		current_symbol            = "La";
		current_name              = "57-name";
		current_mass              = 138.905500;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 5d^1 6s^2";
		current_covalent_radius   = 1.69;
	}
	break;
	case 58:
	{
		current_symbol            = "Ce";
		current_name              = "58-name";
		current_mass              = 140.115000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^1 5d^1 6s^2";
		current_covalent_radius   = 1.65;
	}
	break;
	case 59:
	{
		current_symbol            = "Pr";
		current_name              = "59-name";
		current_mass              = 140.907650;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^3 6s^2";
		current_covalent_radius   = 1.65;
	}
	break;
	case 60:
	{
		current_symbol            = "Nd";
		current_name              = "60-name";
		current_mass              = 144.240000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^4 6s^2";
		current_covalent_radius   = 1.64;
	}
	break;
	case 61:
	{
		current_symbol            = "Pm";
		current_name              = "61-name";
		current_mass              = 145.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^5 6s^2";
		current_covalent_radius   = 1.63;
	}
	break;
	case 62:
	{
		current_symbol            = "Sm";
		current_name              = "62-name";
		current_mass              = 150.360000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^6 6s^2";
		current_covalent_radius   = 1.62;
	}
	break;
	case 63:
	{
		current_symbol            = "Eu";
		current_name              = "63-name";
		current_mass              = 151.965000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^7 6s^2";
		current_covalent_radius   = 1.85;
	}
	break;
	case 64:
	{
		current_symbol            = "Gd";
		current_name              = "64-name";
		current_mass              = 157.250000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^7 5d^1 6s^2";
		current_covalent_radius   = 1.61;
	}
	break;
	case 65:
	{
		current_symbol            = "Tb";
		current_name              = "65-name";
		current_mass              = 158.925340;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^9 6s^2";
		current_covalent_radius   = 1.59;
	}
	break;
	case 66:
	{
		current_symbol            = "Dy";
		current_name              = "66-name";
		current_mass              = 162.500000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^10 6s^2";
		current_covalent_radius   = 1.59;
	}
	break;
	case 67:
	{
		current_symbol            = "Ho";
		current_name              = "67-name";
		current_mass              = 164.930320;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^11 6s^2";
		current_covalent_radius   = 1.58;
	}
	break;
	case 68:
	{
		current_symbol            = "Er";
		current_name              = "68-name";
		current_mass              = 167.260000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^12 6s^2";
		current_covalent_radius   = 1.57;
	}
	break;
	case 69:
	{
		current_symbol            = "Tm";
		current_name              = "69-name";
		current_mass              = 168.934210;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^13 6s^2";
		current_covalent_radius   = 1.56;
	}
	break;
	case 70:
	{
		current_symbol            = "Yb";
		current_name              = "70-name";
		current_mass              = 173.040000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 6s^2";
		current_covalent_radius   = 1.74;
	}
	break;
	case 71:
	{
		current_symbol            = "Lu";
		current_name              = "71-name";
		current_mass              = 174.967000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^1 6s^2";
		current_covalent_radius   = 1.56;
	}
	break;
	case 72:
	{
		current_symbol            = "Hf";
		current_name              = "72-name";
		current_mass              = 178.490000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^2 6s^2";
		current_covalent_radius   = 1.44;
	}
	break;
	case 73:
	{
		current_symbol            = "Ta";
		current_name              = "73-name";
		current_mass              = 180.947900;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^3 6s^2";
		current_covalent_radius   = 1.34;
	}
	break;
	case 74:
	{
		current_symbol            = "W";
		current_name              = "74-name";
		current_mass              = 183.850000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^4 6s^2";
		current_covalent_radius   = 1.30;
	}
	break;
	case 75:
	{
		current_symbol            = "Re";
		current_name              = "75-name";
		current_mass              = 186.207000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^5 6s^2";
		current_covalent_radius   = 1.28;
	}
	break;
	case 76:
	{
		current_symbol            = "Os";
		current_name              = "76-name";
		current_mass              = 190.200000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^6 6s^2";
		current_covalent_radius   = 1.26;
	}
	break;
	case 77:
	{
		current_symbol            = "Ir";
		current_name              = "77-name";
		current_mass              = 192.220000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^7 6s^2";
		current_covalent_radius   = 1.27;
	}
	break;
	case 78:
	{
		current_symbol            = "Pt";
		current_name              = "78-name";
		current_mass              = 195.080000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^9 6s^1";
		current_covalent_radius   = 1.30;
	}
	break;
	case 79:
	{
		current_symbol            = "Au";
		current_name              = "79-name";
		current_mass              = 196.966540;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^1";
		current_covalent_radius   = 1.34;
	}
	break;
	case 80:
	{
		current_symbol            = "Hg";
		current_name              = "80-name";
		current_mass              = 200.590000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2";
		current_covalent_radius   = 1.49;
	}
	break;
	case 81:
	{
		current_symbol            = "Tl";
		current_name              = "81-name";
		current_mass              = 204.383300;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2 6p^1";
		current_covalent_radius   = 1.48;
	}
	break;
	case 82:
	{
		current_symbol            = "Pb";
		current_name              = "82-name";
		current_mass              = 207.200000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2 6p^2";
		current_covalent_radius   = 1.47;
	}
	break;
	case 83:
	{
		current_symbol            = "Bi";
		current_name              = "83-name";
		current_mass              = 208.980370;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2 6p^3";
		current_covalent_radius   = 1.46;
	}
	break;
	case 84:
	{
		current_symbol            = "Po";
		current_name              = "84-name";
		current_mass              = 209.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2 6p^4";
		current_covalent_radius   = 1.46;
	}
	break;
	case 85:
	{
		current_symbol            = "At";
		current_name              = "85-name";
		current_mass              = 210.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2 6p^5";
		current_covalent_radius   = 1.45;
	}
	break;
	case 86:
	{
		current_symbol            = "Rn";
		current_name              = "86-name";
		current_mass              = 222.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Xe] 4f^14 5d^10 6s^2 6p^6";
		current_covalent_radius   = 1.90;
	}
	break;
	case 87:
	{
		current_symbol            = "Fr";
		current_name              = "87-name";
		current_mass              = 223.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 7s^1";
		current_covalent_radius   = 0;
	}
	break;
	case 88:
	{
		current_symbol            = "Ra";
		current_name              = "88-name";
		current_mass              = 226.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 7s^2";
		current_covalent_radius   = 0;
	}
	break;
	case 89:
	{
		current_symbol            = "Ac";
		current_name              = "89-name";
		current_mass              = 227.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 6d^1 7s^2";
		current_covalent_radius   = 0;
	}
	break;
	case 90:
	{
		current_symbol            = "Th";
		current_name              = "90-name";
		current_mass              = 232.038100;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 6d^2 7s^2";
		current_covalent_radius   = 1.65;
	}
	break;
	case 91:
	{
		current_symbol            = "Pa";
		current_name              = "91-name";
		current_mass              = 231.035880;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^2 6d^1 7s^2";
		current_covalent_radius   = 0;
	}
	break;
	case 92:
	{
		current_symbol            = "U";
		current_name              = "92-name";
		current_mass              = 238.028900;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^3 6d^1 7s^2";
		current_covalent_radius   = 1.42;
	}
	break;
	case 93:
	{
		current_symbol            = "Np";
		current_name              = "93-name";
		current_mass              = 237.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^4 6d^1 7s^2";
		current_covalent_radius   = 1.34;
	}
	break;
	case 94:
	{
		current_symbol            = "Pu";
		current_name              = "94-name";
		current_mass              = 244.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^6 7s^2";
		current_covalent_radius   = 1.55;
	}
	break;
	case 95:
	{
		current_symbol            = "Am";
		current_name              = "95-name";
		current_mass              = 243.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^7 7s^2";
		current_covalent_radius   = 1.89;
	}
	break;
	case 96:
	{
		current_symbol            = "Cm";
		current_name              = "96-name";
		current_mass              = 247.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^7 6d^1 7s^2";
		current_covalent_radius   = 2.00;
	}
	break;
	case 97:
	{
		current_symbol            = "Bk";
		current_name              = "97-name";
		current_mass              = 247.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^9 7s^2";
		current_covalent_radius   = 2.00;
	}
	break;
	case 98:
	{
		current_symbol            = "Cf";
		current_name              = "98-name";
		current_mass              = 251.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^10 7s^2";
		current_covalent_radius   = 2.00;
	}
	break;
	case 99:
	{
		current_symbol            = "Es";
		current_name              = "99-name";
		current_mass              = 252.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^11 7s^2";
		current_covalent_radius   = 2.00;
	}
	break;
	case 100:
	{
		current_symbol            = "Fm";
		current_name              = "100-name";
		current_mass              = 257.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^12 7s^2";
		current_covalent_radius   = 2.00;
	}
	break;
	case 101:
	{
		current_symbol            = "Md";
		current_name              = "101-name";
		current_mass              = 258.000000;
		current_core_electrons    = 0;
		current_valence_electrons = 0;
		current_electronic_config = "[Rn] 5f^13 7s^2";
		current_covalent_radius   = 2.00;
	}
	break;
		case 102:
		{
			current_symbol            = "No";
			current_name              = "102-name";
			current_mass              = 259.000000;
			current_core_electrons    = 0;
			current_valence_electrons = 0;
			current_electronic_config = "[Rn] 5f^14 7s^2";
			current_covalent_radius   = 2.00;
		}
		break;
		case 103:
		{
			current_symbol            = "Lr";
			current_name              = "103-name";
			current_mass              = 262.000000;
			current_core_electrons    = 0;
			current_valence_electrons = 0;
			current_electronic_config = "[Rn] 5f^14 7s^2 7p^1";
			current_covalent_radius   = 2.00;
		}
		break;
	}
}
}
