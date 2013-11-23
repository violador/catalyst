#include "periodic_table.hpp"
//
//
//
void periodic_table::database(const unsigned int &given_element)
{
    std_database_ready = true;
    switch(given_element)
    {
    case 1:
    {
        element_symbol            = "H";
        element_name              = "hydrogen";
	element_mass              = 1.007940;
        element_core_electrons    = 0;
        element_valence_electrons = 1;
        element_config            = "1s^1";
        covalent_radius           = 0.32;
        total_orbitals            = 1;
    }
    break;
    case 2:
    {
        element_symbol            = "He";
        element_name              = "helium";
	element_mass              = 4.002602;
        element_core_electrons    = 2;
        element_valence_electrons = 0;
        element_config            = "1s^2";
        covalent_radius           = 0.93;
    }
    break;
    case 3:
    {
        element_symbol            = "Li";
        element_name              = "3-name";
        element_mass              = 6.941000;
        element_core_electrons    = 2;
        element_valence_electrons = 1;
        element_config            = "[He] 2s^1";
        covalent_radius           = 1.23;
    }
    break;
    case 4:
    {
        element_symbol            = "Be";
        element_name              = "4-name";
        element_mass              = 9.012182;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[He] 2s^2";
        covalent_radius           = 0.90;
    }
    break;
    case 5:
    {
        element_symbol            = "B";
        element_name              = "5-name";
        element_mass              = 10.811000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[He] 2s^2 2p^1";
        covalent_radius           = 0.82;
    }
    case 6:
    {
        element_symbol            = "C";
        element_name              = "carbom";
	element_mass              = 12.011000;
        element_core_electrons    = 2;
        element_valence_electrons = 4;
        element_config            = "[He] 2s^2 2p^2";
        covalent_radius           = 0.77;
    }
    break;
    case 7:
    {
        element_symbol            = "N";
        element_name              = "7-name";
        element_mass              = 14.006740;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[He] 2s^2 2p^3";
        covalent_radius           = 0.75;
    }
    break;
    case 8:
    {
        element_symbol            = "O";
        element_name              = "8-name";
        element_mass              = 15.999400;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[He] 2s^2 2p^4";
        covalent_radius           = 0.73;
        total_orbitals            = 5;
    }
    break;
    case 9:
    {
        element_symbol            = "F";
        element_name              = "9-name";
        element_mass              = 18.998400;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[He] 2s^2 2p^5";
        covalent_radius           = 0.72;
    }
    break;
    case 10:
    {
        element_symbol            = "Ne";
        element_name              = "10-name";
        element_mass              = 20.179700;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[He] 2s^2 2p^6";
        covalent_radius           = 0.71;
    }
    break;
    case 11:
    {
        element_symbol            = "Na";
        element_name              = "11-name";
        element_mass              = 22.989768;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^1";
        covalent_radius           = 1.54;
    }
    break;
    case 12:
    {
        element_symbol            = "Mg";
        element_name              = "12-name";
        element_mass              = 24.305000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2";
        covalent_radius           = 1.36;
    }
    break;
    case 13:
    {
        element_symbol            = "Al";
        element_name              = "13-name";
        element_mass              = 26.981539;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2 3p^1";
        covalent_radius           = 1.18;
    }
    break;
    case 14:
    {
        element_symbol            = "Si";
        element_name              = "14-name";
        element_mass              = 28.085500;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2 3p^2";
        covalent_radius           = 1.11;
    }
    break;
    case 15:
    {
        element_symbol            = "P";
        element_name              = "15-name";
        element_mass              = 30.973762;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2 3p^3";
        covalent_radius           = 1.06;
    }
    break;
    case 16:
    {
        element_symbol            = "S";
        element_name              = "16-name";
        element_mass              = 32.066000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2 3p^4";
        covalent_radius           = 1.02;
    }
    break;
    case 17:
    {
        element_symbol            = "Cl";
        element_name              = "17-name";
        element_mass              = 35.452700;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2 3p^5";
        covalent_radius           = 0.99;
    }
    break;
    case 18:
    {
        element_symbol            = "Ar";
        element_name              = "18-name";
        element_mass              = 39.948000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ne] 3s^2 3p^6";
        covalent_radius           = 0.98;
    }
    break;
    case 19:
    {
        element_symbol            = "K";
        element_name              = "19-name";
        element_mass              = 39.098300;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 4s^1";
        covalent_radius           = 2.03;
    }
    break;
    case 20:
    {
        element_symbol            = "Ca";
        element_name              = "20-name";
        element_mass              = 40.078000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 4s^2";
        covalent_radius           = 1.74;
    }
    break;
    case 21:
    {
        element_symbol            = "Sc";
        element_name              = "21-name";
        element_mass              = 44.955910;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^1 4s^2";
        covalent_radius           = 1.44;
    }
    break;
    case 22:
    {
        element_symbol            = "Ti";
        element_name              = "22-name";
        element_mass              = 47.880000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^2 4s^2";
        covalent_radius           = 1.32;
    }
    break;
    case 23:
    {
        element_symbol            = "V";
        element_name              = "23-name";
        element_mass              = 50.941500;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^3 4s^2";
        covalent_radius           = 1.22;
    }
    break;
    case 24:
    {
        element_symbol            = "Cr";
        element_name              = "24-name";
        element_mass              = 51.996100;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^5 4s^1";
        covalent_radius           = 1.18;
    }
    break;
    case 25:
    {
        element_symbol            = "Mn";
        element_name              = "25-name";
        element_mass              = 54.938050;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^5 4s^2";
        covalent_radius           = 1.17;
    }
    break;
    case 26:
    {
        element_symbol            = "Fe";
        element_name              = "26-name";
        element_mass              = 55.847000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^6 4s^2";
        covalent_radius           = 1.17;
    }
    break;
    case 27:
    {
        element_symbol            = "Co";
        element_name              = "27-name";
        element_mass              = 58.933200;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^7 4s^2";
        covalent_radius           = 1.16;
    }
    break;
    case 28:
    {
        element_symbol            = "Ni";
        element_name              = "28-name";
        element_mass              = 58.693400;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^8 4s^2";
        covalent_radius           = 1.15;
    }
    break;
    case 29:
    {
        element_symbol            = "Cu";
        element_name              = "29-name";
        element_mass              = 63.546000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^1";
        covalent_radius           = 1.17;
    }
    break;
    case 30:
    {
        element_symbol            = "Zn";
        element_name              = "30-name";
        element_mass              = 65.390000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2";
        covalent_radius           = 1.25;
    }
    break;
    case 31:
    {
        element_symbol            = "Ga";
        element_name              = "31-name";
        element_mass              = 69.723000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2 4p^1";
        covalent_radius           = 1.26;
    }
    break;
    case 32:
    {
        element_symbol            = "Ge";
        element_name              = "32-name";
        element_mass              = 72.610000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2 4p^2";
        covalent_radius           = 1.22;
    }
    break;
    case 33:
    {
        element_symbol            = "As";
        element_name              = "33-name";
        element_mass              = 74.921590;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2 4p^3";
        covalent_radius           = 1.20;
    }
    break;
    case 34:
    {
        element_symbol            = "Se";
        element_name              = "34-name";
        element_mass              = 78.960000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2 4p^4";
        covalent_radius           = 1.16;
    }
    break;
    case 35:
    {
        element_symbol            = "Br";
        element_name              = "35-name";
        element_mass              = 79.904000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2 4p^5";
        covalent_radius           = 1.14;
    }
    break;
    case 36:
    {
        element_symbol            = "Kr";
        element_name              = "36-name";
        element_mass              = 83.800000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Ar] 3d^10 4s^2 4p^6";
        covalent_radius           = 1.12;
    }
    break;
    case 37:
    {
        element_symbol            = "Rb";
        element_name              = "37-name";
        element_mass              = 85.467800;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 5s^1";
        covalent_radius           = 2.16;
    }
    break;
    case 38:
    {
        element_symbol            = "Sr";
        element_name              = "38-name";
        element_mass              = 87.620000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 5s^2";
        covalent_radius           = 1.91;
    }
    break;
    case 39:
    {
        element_symbol            = "Y";
        element_name              = "39-name";
        element_mass              = 88.905850;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^1 5s^2";
        covalent_radius           = 1.62;
    }
    break;
    case 40:
    {
        element_symbol            = "Zr";
        element_name              = "40-name";
        element_mass              = 91.224000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^2 5s^2";
        covalent_radius           = 1.45;
    }
    break;
    case 41:
    {
        element_symbol            = "Nb";
        element_name              = "41-name";
        element_mass              = 92.906380;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^4 5s^1";
        covalent_radius           = 1.34;
    }
    break;
    case 42:
    {
        element_symbol            = "Mo";
        element_name              = "42-name";
        element_mass              = 95.940000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^5 5s^1";
        covalent_radius           = 1.30;
    }
    break;
    case 43:
    {
        element_symbol            = "Tc";
        element_name              = "43-name";
        element_mass              = 98.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^5 5s^2";
        covalent_radius           = 1.27;
    }
    break;
    case 44:
    {
        element_symbol            = "Ru";
        element_name              = "44-name";
        element_mass              = 101.070000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^7 5s^1";
        covalent_radius           = 1.25;
    }
    break;
    case 45:
    {
        element_symbol            = "Rh";
        element_name              = "45-name";
        element_mass              = 102.905500;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^8 5s^1";
        covalent_radius           = 1.25;
    }
    break;
    case 46:
    {
        element_symbol            = "Pd";
        element_name              = "46-name";
        element_mass              = 106.420000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10";
        covalent_radius           = 1.28;
    }
    break;
    case 47:
    {
        element_symbol            = "Ag";
        element_name              = "47-name";
        element_mass              = 107.868200;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^1";
        covalent_radius           = 1.34;
    }
    break;
    case 48:
    {
        element_symbol            = "Cd";
        element_name              = "48-name";
        element_mass              = 112.411000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2";
        covalent_radius           = 1.48;
    }
    break;
    case 49:
    {
        element_symbol            = "In";
        element_name              = "49-name";
        element_mass              = 114.820000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2 5p^1";
        covalent_radius           = 1.44;
    }
    break;
    case 50:
    {
        element_symbol            = "Sn";
        element_name              = "50-name";
        element_mass              = 118.710000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2 5p^2";
        covalent_radius           = 1.41;
    }
    break;
    case 51:
    {
        element_symbol            = "Sb";
        element_name              = "51-name";
        element_mass              = 121.757000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2 5p^3";
        covalent_radius           = 1.40;
    }
    break;
    case 52:
    {
        element_symbol            = "Te";
        element_name              = "52-name";
        element_mass              = 127.600000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2 5p^4";
        covalent_radius           = 1.36;
    }
    break;
    case 53:
    {
        element_symbol            = "I";
        element_name              = "53-name";
        element_mass              = 126.904470;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2 5p^5";
        covalent_radius           = 1.33;
    }
    break;
    case 54:
    {
        element_symbol            = "Xe";
        element_name              = "54-name";
        element_mass              = 131.290000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Kr] 4d^10 5s^2 5p^6";
        covalent_radius           = 1.31;
    }
    break;
    case 55:
    {
        element_symbol            = "Cs";
        element_name              = "55-name";
        element_mass              = 132.905430;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 6s^1";
        covalent_radius           = 2.35;
    }
    break;
    case 56:
    {
        element_symbol            = "Ba";
        element_name              = "56-name";
        element_mass              = 137.327000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 6s^2";
        covalent_radius           = 1.98;
    }
    break;
    case 57:
    {
        element_symbol            = "La";
        element_name              = "57-name";
        element_mass              = 138.905500;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 5d^1 6s^2";
        covalent_radius           = 1.69;
    }
    break;
    case 58:
    {
        element_symbol            = "Ce";
        element_name              = "58-name";
        element_mass              = 140.115000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^1 5d^1 6s^2";
        covalent_radius           = 1.65;
    }
    break;
    case 59:
    {
        element_symbol            = "Pr";
        element_name              = "59-name";
        element_mass              = 140.907650;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^3 6s^2";
        covalent_radius           = 1.65;
    }
    break;
    case 60:
    {
        element_symbol            = "Nd";
        element_name              = "60-name";
        element_mass              = 144.240000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^4 6s^2";
        covalent_radius           = 1.64;
    }
    break;
    case 61:
    {
        element_symbol            = "Pm";
        element_name              = "61-name";
        element_mass              = 145.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^5 6s^2";
        covalent_radius           = 1.63;
    }
    break;
    case 62:
    {
        element_symbol            = "Sm";
        element_name              = "62-name";
        element_mass              = 150.360000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^6 6s^2";
        covalent_radius           = 1.62;
    }
    break;
    case 63:
    {
        element_symbol            = "Eu";
        element_name              = "63-name";
        element_mass              = 151.965000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^7 6s^2";
        covalent_radius           = 1.85;
    }
    break;
    case 64:
    {
        element_symbol            = "Gd";
        element_name              = "64-name";
        element_mass              = 157.250000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^7 5d^1 6s^2";
        covalent_radius           = 1.61;
    }
    break;
    case 65:
    {
        element_symbol            = "Tb";
        element_name              = "65-name";
        element_mass              = 158.925340;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^9 6s^2";
        covalent_radius           = 1.59;
    }
    break;
    case 66:
    {
        element_symbol            = "Dy";
        element_name              = "66-name";
        element_mass              = 162.500000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^10 6s^2";
        covalent_radius           = 1.59;
    }
    break;
    case 67:
    {
        element_symbol            = "Ho";
        element_name              = "67-name";
        element_mass              = 164.930320;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^11 6s^2";
        covalent_radius           = 1.58;
    }
    break;
    case 68:
    {
        element_symbol            = "Er";
        element_name              = "68-name";
        element_mass              = 167.260000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^12 6s^2";
        covalent_radius           = 1.57;
    }
    break;
    case 69:
    {
        element_symbol            = "Tm";
        element_name              = "69-name";
        element_mass              = 168.934210;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^13 6s^2";
        covalent_radius           = 1.56;
    }
    break;
    case 70:
    {
        element_symbol            = "Yb";
        element_name              = "70-name";
        element_mass              = 173.040000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 6s^2";
        covalent_radius           = 1.74;
    }
    break;
    case 71:
    {
        element_symbol            = "Lu";
        element_name              = "71-name";
        element_mass              = 174.967000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^1 6s^2";
        covalent_radius           = 1.56;
    }
    break;
    case 72:
    {
        element_symbol            = "Hf";
        element_name              = "72-name";
        element_mass              = 178.490000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^2 6s^2";
        covalent_radius           = 1.44;
    }
    break;
    case 73:
    {
        element_symbol            = "Ta";
        element_name              = "73-name";
        element_mass              = 180.947900;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^3 6s^2";
        covalent_radius           = 1.34;
    }
    break;
    case 74:
    {
        element_symbol            = "W";
        element_name              = "74-name";
        element_mass              = 183.850000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^4 6s^2";
        covalent_radius           = 1.30;
    }
    break;
    case 75:
    {
        element_symbol            = "Re";
        element_name              = "75-name";
        element_mass              = 186.207000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^5 6s^2";
        covalent_radius           = 1.28;
    }
    break;
    case 76:
    {
        element_symbol            = "Os";
        element_name              = "76-name";
        element_mass              = 190.200000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^6 6s^2";
        covalent_radius           = 1.26;
    }
    break;
    case 77:
    {
        element_symbol            = "Ir";
        element_name              = "77-name";
        element_mass              = 192.220000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^7 6s^2";
        covalent_radius           = 1.27;
    }
    break;
    case 78:
    {
        element_symbol            = "Pt";
        element_name              = "78-name";
        element_mass              = 195.080000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^9 6s^1";
        covalent_radius           = 1.30;
    }
    break;
    case 79:
    {
        element_symbol            = "Au";
        element_name              = "79-name";
        element_mass              = 196.966540;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^1";
        covalent_radius           = 1.34;
    }
    break;
    case 80:
    {
        element_symbol            = "Hg";
        element_name              = "80-name";
        element_mass              = 200.590000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2";
        covalent_radius           = 1.49;
    }
    break;
    case 81:
    {
        element_symbol            = "Tl";
        element_name              = "81-name";
        element_mass              = 204.383300;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2 6p^1";
        covalent_radius           = 1.48;
    }
    break;
    case 82:
    {
        element_symbol            = "Pb";
        element_name              = "82-name";
        element_mass              = 207.200000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2 6p^2";
        covalent_radius           = 1.47;
    }
    break;
    case 83:
    {
        element_symbol            = "Bi";
        element_name              = "83-name";
        element_mass              = 208.980370;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2 6p^3";
        covalent_radius           = 1.46;
    }
    break;
    case 84:
    {
        element_symbol            = "Po";
        element_name              = "84-name";
        element_mass              = 209.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2 6p^4";
        covalent_radius           = 1.46;
    }
    break;
    case 85:
    {
        element_symbol            = "At";
        element_name              = "85-name";
        element_mass              = 210.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2 6p^5";
        covalent_radius           = 1.45;
    }
    break;
    case 86:
    {
        element_symbol            = "Rn";
        element_name              = "86-name";
        element_mass              = 222.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Xe] 4f^14 5d^10 6s^2 6p^6";
        covalent_radius           = 1.90;
    }
    break;
    case 87:
    {
        element_symbol            = "Fr";
        element_name              = "87-name";
        element_mass              = 223.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 7s^1";
        covalent_radius           = 0;
    }
    break;
    case 88:
    {
        element_symbol            = "Ra";
        element_name              = "88-name";
        element_mass              = 226.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 7s^2";
        covalent_radius           = 0;
    }
    break;
    case 89:
    {
        element_symbol            = "Ac";
        element_name              = "89-name";
        element_mass              = 227.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 6d^1 7s^2";
        covalent_radius           = 0;
    }
    break;
    case 90:
    {
        element_symbol            = "Th";
        element_name              = "90-name";
        element_mass              = 232.038100;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 6d^2 7s^2";
        covalent_radius           = 1.65;
    }
    break;
    case 91:
    {
        element_symbol            = "Pa";
        element_name              = "91-name";
        element_mass              = 231.035880;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^2 6d^1 7s^2";
        covalent_radius           = 0;
    }
    break;
    case 92:
    {
        element_symbol            = "U";
        element_name              = "92-name";
        element_mass              = 238.028900;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^3 6d^1 7s^2";
        covalent_radius           = 1.42;
    }
    break;
    case 93:
    {
        element_symbol            = "Np";
        element_name              = "93-name";
        element_mass              = 237.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^4 6d^1 7s^2";
        covalent_radius           = 1.34;
    }
    break;
    case 94:
    {
        element_symbol            = "Pu";
        element_name              = "94-name";
        element_mass              = 244.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^6 7s^2";
        covalent_radius           = 1.55;
    }
    break;
    case 95:
    {
        element_symbol            = "Am";
        element_name              = "95-name";
        element_mass              = 243.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^7 7s^2";
        covalent_radius           = 1.89;
    }
    break;
    case 96:
    {
        element_symbol            = "Cm";
        element_name              = "96-name";
        element_mass              = 247.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^7 6d^1 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 97:
    {
        element_symbol            = "Bk";
        element_name              = "97-name";
        element_mass              = 247.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^9 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 98:
    {
        element_symbol            = "Cf";
        element_name              = "98-name";
        element_mass              = 251.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^10 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 99:
    {
        element_symbol            = "Es";
        element_name              = "99-name";
        element_mass              = 252.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^11 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 100:
    {
        element_symbol            = "Fm";
        element_name              = "100-name";
        element_mass              = 257.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^12 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 101:
    {
        element_symbol            = "Md";
        element_name              = "101-name";
        element_mass              = 258.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^13 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 102:
    {
        element_symbol            = "No";
        element_name              = "102-name";
        element_mass              = 259.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^14 7s^2";
        covalent_radius           = 2.00;
    }
    break;
    case 103:
    {
        element_symbol            = "Lr";
        element_name              = "103-name";
        element_mass              = 262.000000;
        element_core_electrons    = 0;
        element_valence_electrons = 0;
        element_config            = "[Rn] 5f^14 7s^2 7p^1";
        covalent_radius           = 2.00;
    }
    break;
    };
}
