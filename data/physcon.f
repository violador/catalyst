      SUBROUTINE PHYSCON
C
C     Purpose: Initialization of physical constants.
C
C     Lit.: CODATA constants from http://www.codata.org (1986)
C
C     History: - Creation (28.05.97, MK)
C                         (24.06.00, AMK)
C
C     ******************************************************************
C
C     List of variables
C
C     ABOHR   : Bohr radius [m].
C     AFINE   : Fine-structure constant.
C     AOSYM   : Atomic orbital symbols.
C     BOHR    : Conversion factor [Angstrom] -> [Bohr].
C     CLIGHT  : Speed of light in vacuum [m/s].
C     COVRAD  : Atomic covalent radii [Angstrom] -> [Bohr].
C     ECHARGE : Elementary charge [C].
C     ELCONF  : Element configuration.
C     ELSYM   : Element symbols.
C     EMASS   : Electron mass [kg].
C     EPSI0   : Electric field constant [F/m].
C     ESU     : Conversion factors [Hartree] -> [esu].
C     EVOLT   : Conversion factor [Hartree] -> [eV].
C     HPLANCK : Planck constant [J*s].
C     HZ      : Conversion factor [Hartree] -> [Hz].
C     KBOLTZ  : Boltzmann constant [J/K].
C     KCALMOL : Conversion factor [Hartree] -> [kcal/mol].
C     KJMOL   : Conversion factor [Hartree] -> [kJ/mol].
C     JOULE   : Conversion factor [Hartree] -> [J].
C     MHZ     : Conversion factor [Hartree] -> [MHz].
C     MUPERM  : Permeability of vacuum [N/A**2].
C     NAVOG   : Avogrado constant [1/mol].
C     PRESSURE: Standard pressure [Pa].
C     RGAS    : Gas constant [J/(K*mol)].
C     RYDBERG : Rydberg constant [1/m].
C     STDMATOM: Standard atomic masses.
C     TRIVV   : Names of trivial vibrations.
C     UKG     : Conversion factor [u] -> [kg].
C     VIBFAC  : Conversion factor [Hartree/Bohr**2] -> [1/cm].
C     WAVENUM : Conversion factor [Hartree] -> [1/cm] (wave numbers).
C     WAVESEC : Conversion factor [1/cm] -> [1/sec].
C     XYZ     : Labels for the Cartesian components.
C     CTAU    : Conversion 1 fs to a.u.
C
C     ------------------------------------------------------------------
C
      IMPLICIT NONE
C
      INCLUDE 'parameter.h'
C
      INCLUDE 'math.h'
      INCLUDE 'physic.h'
      INCLUDE 'strings.h'
C
      INTEGER LM,Z
C
C     ------------------------------------------------------------------
C
C     *** Definition of standard covalent radii [Angstrom] ***
C     *** Lit.: R.T. Sanderson, Inorganic Chemistry, Reinhold 1967 ***
C
      COVRAD(0:103) = 1.5
      COVRAD(0)  = 0.00
      COVRAD(1)  = 0.32
      COVRAD(2)  = 0.93
      COVRAD(3)  = 1.23
      COVRAD(4)  = 0.90
      COVRAD(5)  = 0.82
      COVRAD(6)  = 0.77
      COVRAD(7)  = 0.75
      COVRAD(8)  = 0.73
      COVRAD(9)  = 0.72
      COVRAD(10) = 0.71
      COVRAD(11) = 1.54
      COVRAD(12) = 1.36
      COVRAD(13) = 1.18
      COVRAD(14) = 1.11
      COVRAD(15) = 1.06
      COVRAD(16) = 1.02
      COVRAD(17) = 0.99
      COVRAD(18) = 0.98
      COVRAD(19) = 2.03
      COVRAD(20) = 1.74
      COVRAD(21) = 1.44
      COVRAD(22) = 1.32
      COVRAD(23) = 1.22
      COVRAD(24) = 1.18
      COVRAD(25) = 1.17
      COVRAD(26) = 1.17
      COVRAD(27) = 1.16
      COVRAD(28) = 1.15
      COVRAD(29) = 1.17
      COVRAD(30) = 1.25
      COVRAD(31) = 1.26
      COVRAD(32) = 1.22
      COVRAD(33) = 1.20
      COVRAD(34) = 1.16
      COVRAD(35) = 1.14
      COVRAD(36) = 1.12
      COVRAD(37) = 2.16
      COVRAD(38) = 1.91
      COVRAD(39) = 1.62
      COVRAD(40) = 1.45
      COVRAD(41) = 1.34
      COVRAD(42) = 1.30
      COVRAD(43) = 1.27
      COVRAD(44) = 1.25
      COVRAD(45) = 1.25
      COVRAD(46) = 1.28
      COVRAD(47) = 1.34
      COVRAD(48) = 1.48
      COVRAD(49) = 1.44
      COVRAD(50) = 1.41
      COVRAD(51) = 1.40
      COVRAD(52) = 1.36
      COVRAD(53) = 1.33
      COVRAD(54) = 1.31
      COVRAD(55) = 2.35
      COVRAD(56) = 1.98
      COVRAD(57) = 1.69
      COVRAD(58) = 1.65
      COVRAD(59) = 1.65
      COVRAD(60) = 1.64
      COVRAD(61) = 1.63
      COVRAD(62) = 1.62
      COVRAD(63) = 1.85
      COVRAD(64) = 1.61
      COVRAD(65) = 1.59
      COVRAD(66) = 1.59
      COVRAD(67) = 1.58
      COVRAD(68) = 1.57
      COVRAD(69) = 1.56
      COVRAD(70) = 1.74
      COVRAD(71) = 1.56
      COVRAD(72) = 1.44
      COVRAD(73) = 1.34
      COVRAD(74) = 1.30
      COVRAD(75) = 1.28
      COVRAD(76) = 1.26
      COVRAD(77) = 1.27
      COVRAD(78) = 1.30
      COVRAD(79) = 1.34
      COVRAD(80) = 1.49
      COVRAD(81) = 1.48
      COVRAD(82) = 1.47
      COVRAD(83) = 1.46
      COVRAD(84) = 1.46
      COVRAD(85) = 1.45
      COVRAD(86) = 1.90
      COVRAD(90) = 1.65
      COVRAD(92) = 1.42
      COVRAD(93) = 1.34
      COVRAD(94) = 1.55
      COVRAD(95) = 1.89
      COVRAD(96) = 2.00
      COVRAD(97) = 2.00
      COVRAD(98) = 2.00
      COVRAD(99) = 2.00
      COVRAD(100) = 2.00
      COVRAD(101) = 2.00
      COVRAD(102) = 2.00
      COVRAD(103) = 2.00
C
C     *** Definition of element configuration ***
C
      ELCONF(0)  = '1s^1'
      ELCONF(1)  = '1s^1'
      ELCONF(2)  = '1s^2'
      ELCONF(3)  = '[He] 2s^1'
      ELCONF(4)  = '[He] 2s^2'
      ELCONF(5)  = '[He] 2s^2 2p^1'
      ELCONF(6)  = '[He] 2s^2 2p^2'
      ELCONF(7)  = '[He] 2s^2 2p^3'
      ELCONF(8)  = '[He] 2s^2 2p^4'  
      ELCONF(9)  = '[He] 2s^2 2p^5'
      ELCONF(10) = '[He] 2s^2 2p^6'
      ELCONF(11) = '[Ne] 3s^1'
      ELCONF(12) = '[Ne] 3s^2'
      ELCONF(13) = '[Ne] 3s^2 3p^1'
      ELCONF(14) = '[Ne] 3s^2 3p^2'
      ELCONF(15) = '[Ne] 3s^2 3p^3'
      ELCONF(16) = '[Ne] 3s^2 3p^4'
      ELCONF(17) = '[Ne] 3s^2 3p^5'
      ELCONF(18) = '[Ne] 3s^2 3p^6'
      ELCONF(19) = '[Ar] 4s^1'
      ELCONF(20) = '[Ar] 4s^2'
      ELCONF(21) = '[Ar] 3d^1 4s^2'
      ELCONF(22) = '[Ar] 3d^2 4s^2' 
      ELCONF(23) = '[Ar] 3d^3 4s^2'
      ELCONF(24) = '[Ar] 3d^5 4s^1'
      ELCONF(25) = '[Ar] 3d^5 4s^2'
      ELCONF(26) = '[Ar] 3d^6 4s^2'
      ELCONF(27) = '[Ar] 3d^7 4s^2'
      ELCONF(28) = '[Ar] 3d^8 4s^2'
      ELCONF(29) = '[Ar] 3d^10 4s^1'
      ELCONF(30) = '[Ar] 3d^10 4s^2'
      ELCONF(31) = '[Ar] 3d^10 4s^2 4p^1' 
      ELCONF(32) = '[Ar] 3d^10 4s^2 4p^2' 
      ELCONF(33) = '[Ar] 3d^10 4s^2 4p^3'
      ELCONF(34) = '[Ar] 3d^10 4s^2 4p^4'
      ELCONF(35) = '[Ar] 3d^10 4s^2 4p^5'
      ELCONF(36) = '[Ar] 3d^10 4s^2 4p^6'
      ELCONF(37) = '[Kr] 5s^1'
      ELCONF(38) = '[Kr] 5s^2'
      ELCONF(39) = '[Kr] 4d^1 5s^2'
      ELCONF(40) = '[Kr] 4d^2 5s^2'
      ELCONF(41) = '[Kr] 4d^4 5s^1'
      ELCONF(42) = '[Kr] 4d^5 5s^1'
      ELCONF(43) = '[Kr] 4d^5 5s^2'
      ELCONF(44) = '[Kr] 4d^7 5s^1'
      ELCONF(45) = '[Kr] 4d^8 5s^1'
      ELCONF(46) = '[Kr] 4d^10'
      ELCONF(47) = '[Kr] 4d^10 5s^1'
      ELCONF(48) = '[Kr] 4d^10 5s^2'
      ELCONF(49) = '[Kr] 4d^10 5s^2 5p^1'
      ELCONF(50) = '[Kr] 4d^10 5s^2 5p^2'
      ELCONF(51) = '[Kr] 4d^10 5s^2 5p^3'
      ELCONF(52) = '[Kr] 4d^10 5s^2 5p^4'
      ELCONF(53) = '[Kr] 4d^10 5s^2 5p^5'
      ELCONF(54) = '[Kr] 4d^10 5s^2 5p^6'
      ELCONF(55) = '[Xe] 6s^1'
      ELCONF(56) = '[Xe] 6s^2'
      ELCONF(57) = '[Xe] 5d^1 6s^2'
      ELCONF(58) = '[Xe] 4f^1 5d^1 6s^2'
      ELCONF(59) = '[Xe] 4f^3 6s^2'
      ELCONF(60) = '[Xe] 4f^4 6s^2'
      ELCONF(61) = '[Xe] 4f^5 6s^2'
      ELCONF(62) = '[Xe] 4f^6 6s^2'
      ELCONF(63) = '[Xe] 4f^7 6s^2'
      ELCONF(64) = '[Xe] 4f^7 5d^1 6s^2'
      ELCONF(65) = '[Xe] 4f^9 6s^2'
      ELCONF(66) = '[Xe] 4f^10 6s^2'
      ELCONF(67) = '[Xe] 4f^11 6s^2'
      ELCONF(68) = '[Xe] 4f^12 6s^2'
      ELCONF(69) = '[Xe] 4f^13 6s^2'
      ELCONF(70) = '[Xe] 4f^14 6s^2'
      ELCONF(71) = '[Xe] 4f^14 5d^1 6s^2'
      ELCONF(72) = '[Xe] 4f^14 5d^2 6s^2'
      ELCONF(73) = '[Xe] 4f^14 5d^3 6s^2'
      ELCONF(74) = '[Xe] 4f^14 5d^4 6s^2'
      ELCONF(75) = '[Xe] 4f^14 5d^5 6s^2'
      ELCONF(76) = '[Xe] 4f^14 5d^6 6s^2'
      ELCONF(77) = '[Xe] 4f^14 5d^7 6s^2'
      ELCONF(78) = '[Xe] 4f^14 5d^9 6s^1'
      ELCONF(79) = '[Xe] 4f^14 5d^10 6s^1'
      ELCONF(80) = '[Xe] 4f^14 5d^10 6s^2'
      ELCONF(81) = '[Xe] 4f^14 5d^10 6s^2 6p^1'
      ELCONF(82) = '[Xe] 4f^14 5d^10 6s^2 6p^2'
      ELCONF(83) = '[Xe] 4f^14 5d^10 6s^2 6p^3'
      ELCONF(84) = '[Xe] 4f^14 5d^10 6s^2 6p^4'
      ELCONF(85) = '[Xe] 4f^14 5d^10 6s^2 6p^5'
      ELCONF(86) = '[Xe] 4f^14 5d^10 6s^2 6p^6'
      ELCONF(87) = '[Rn] 7s^1'
      ELCONF(88) = '[Rn] 7s^2'
      ELCONF(89) = '[Rn] 6d^1 7s^2'
      ELCONF(90) = '[Rn] 6d^2 7s^2'
      ELCONF(91) = '[Rn] 5f^2 6d^1 7s^2'
      ELCONF(92) = '[Rn] 5f^3 6d^1 7s^2'
      ELCONF(93) = '[Rn] 5f^4 6d^1 7s^2'
      ELCONF(94) = '[Rn] 5f^6 7s^2'
      ELCONF(95) = '[Rn] 5f^7 7s^2'
      ELCONF(96) = '[Rn] 5f^7 6d^1 7s^2'
      ELCONF(97) = '[Rn] 5f^9 7s^2'
      ELCONF(98) = '[Rn] 5f^10 7s^2'
      ELCONF(99) = '[Rn] 5f^11 7s^2'
      ELCONF(100) = '[Rn] 5f^12 7s^2'
      ELCONF(101) = '[Rn] 5f^13 7s^2'
      ELCONF(102) = '[Rn] 5f^14 7s^2'
      ELCONF(103) = '[Rn] 5f^14 7s^2 7p^1'
C
C     *** Definition of element symbols ***
C
      ELSYM(0)  = ' X'
      ELSYM(1)  = ' H'
      ELSYM(2)  = 'He'
      ELSYM(3)  = 'Li'
      ELSYM(4)  = 'Be'
      ELSYM(5)  = ' B'
      ELSYM(6)  = ' C'
      ELSYM(7)  = ' N'
      ELSYM(8)  = ' O'
      ELSYM(9)  = ' F'
      ELSYM(10) = 'Ne'
      ELSYM(11) = 'Na'
      ELSYM(12) = 'Mg'
      ELSYM(13) = 'Al'
      ELSYM(14) = 'Si'
      ELSYM(15) = ' P'
      ELSYM(16) = ' S'
      ELSYM(17) = 'Cl'
      ELSYM(18) = 'Ar'
      ELSYM(19) = ' K'
      ELSYM(20) = 'Ca'
      ELSYM(21) = 'Sc'
      ELSYM(22) = 'Ti'
      ELSYM(23) = ' V'
      ELSYM(24) = 'Cr'
      ELSYM(25) = 'Mn'
      ELSYM(26) = 'Fe'
      ELSYM(27) = 'Co'
      ELSYM(28) = 'Ni'
      ELSYM(29) = 'Cu'
      ELSYM(30) = 'Zn'
      ELSYM(31) = 'Ga'
      ELSYM(32) = 'Ge'
      ELSYM(33) = 'As'
      ELSYM(34) = 'Se'
      ELSYM(35) = 'Br'
      ELSYM(36) = 'Kr'
      ELSYM(37) = 'Rb'
      ELSYM(38) = 'Sr'
      ELSYM(39) = ' Y'
      ELSYM(40) = 'Zr'
      ELSYM(41) = 'Nb'
      ELSYM(42) = 'Mo'
      ELSYM(43) = 'Tc'
      ELSYM(44) = 'Ru'
      ELSYM(45) = 'Rh'
      ELSYM(46) = 'Pd'
      ELSYM(47) = 'Ag'
      ELSYM(48) = 'Cd'
      ELSYM(49) = 'In'
      ELSYM(50) = 'Sn'
      ELSYM(51) = 'Sb'
      ELSYM(52) = 'Te'
      ELSYM(53) = ' I'
      ELSYM(54) = 'Xe'
      ELSYM(55) = 'Cs'
      ELSYM(56) = 'Ba'
      ELSYM(57) = 'La'
      ELSYM(58) = 'Ce'
      ELSYM(59) = 'Pr'
      ELSYM(60) = 'Nd'
      ELSYM(61) = 'Pm'
      ELSYM(62) = 'Sm'
      ELSYM(63) = 'Eu'
      ELSYM(64) = 'Gd'
      ELSYM(65) = 'Tb'
      ELSYM(66) = 'Dy'
      ELSYM(67) = 'Ho'
      ELSYM(68) = 'Er'
      ELSYM(69) = 'Tm'
      ELSYM(70) = 'Yb'
      ELSYM(71) = 'Lu'
      ELSYM(72) = 'Hf'
      ELSYM(73) = 'Ta'
      ELSYM(74) = ' W'
      ELSYM(75) = 'Re'
      ELSYM(76) = 'Os'
      ELSYM(77) = 'Ir'
      ELSYM(78) = 'Pt'
      ELSYM(79) = 'Au'
      ELSYM(80) = 'Hg'
      ELSYM(81) = 'Tl'
      ELSYM(82) = 'Pb'
      ELSYM(83) = 'Bi'
      ELSYM(84) = 'Po'
      ELSYM(85) = 'At'
      ELSYM(86) = 'Rn'
      ELSYM(87) = 'Fr'
      ELSYM(88) = 'Ra'
      ELSYM(89) = 'Ac'
      ELSYM(90) = 'Th'
      ELSYM(91) = 'Pa'
      ELSYM(92) = ' U'
      ELSYM(93) = 'Np'
      ELSYM(94) = 'Pu'
      ELSYM(95) = 'Am'
      ELSYM(96) = 'Cm'
      ELSYM(97) = 'Bk'
      ELSYM(98) = 'Cf'
      ELSYM(99) = 'Es'
      ELSYM(100) = 'Fm'
      ELSYM(101) = 'Md'
      ELSYM(102) = 'No'
      ELSYM(103) = 'Lr'
C
C     *** Definition of standard isotopic masses ***
C     *** Lit.: CRC Handbook of Chemistry and Physics, 1989 ***
C
      STDMATOM(0)  =  0.000000
      STDMATOM(1)  =  1.007940
      STDMATOM(2)  =  4.002602
      STDMATOM(3)  =  6.941000
      STDMATOM(4)  =  9.012182
      STDMATOM(5)  = 10.811000
      STDMATOM(6)  = 12.011000
      STDMATOM(7)  = 14.006740
      STDMATOM(8)  = 15.999400
      STDMATOM(9)  = 18.998400
      STDMATOM(10) = 20.179700
      STDMATOM(11) = 22.989768
      STDMATOM(12) = 24.305000
      STDMATOM(13) = 26.981539
      STDMATOM(14) = 28.085500
      STDMATOM(15) = 30.973762
      STDMATOM(16) = 32.066000
      STDMATOM(17) = 35.452700
      STDMATOM(18) = 39.948000
      STDMATOM(19) = 39.098300
      STDMATOM(20) = 40.078000
      STDMATOM(21) = 44.955910
      STDMATOM(22) = 47.880000
      STDMATOM(23) = 50.941500
      STDMATOM(24) = 51.996100
      STDMATOM(25) = 54.938050
      STDMATOM(26) = 55.847000
      STDMATOM(27) = 58.933200
      STDMATOM(28) = 58.693400
      STDMATOM(29) = 63.546000
      STDMATOM(30) = 65.390000
      STDMATOM(31) = 69.723000
      STDMATOM(32) = 72.610000
      STDMATOM(33) = 74.921590
      STDMATOM(34) = 78.960000
      STDMATOM(35) = 79.904000
      STDMATOM(36) = 83.800000
      STDMATOM(37) = 85.467800
      STDMATOM(38) = 87.620000
      STDMATOM(39) = 88.905850
      STDMATOM(40) = 91.224000
      STDMATOM(41) = 92.906380
      STDMATOM(42) = 95.940000
      STDMATOM(43) = 98.000000
      STDMATOM(44) = 101.070000
      STDMATOM(45) = 102.905500
      STDMATOM(46) = 106.420000
      STDMATOM(47) = 107.868200
      STDMATOM(48) = 112.411000
      STDMATOM(49) = 114.820000
      STDMATOM(50) = 118.710000
      STDMATOM(51) = 121.757000
      STDMATOM(52) = 127.600000
      STDMATOM(53) = 126.904470
      STDMATOM(54) = 131.290000
      STDMATOM(55) = 132.905430
      STDMATOM(56) = 137.327000
      STDMATOM(57) = 138.905500
      STDMATOM(58) = 140.115000
      STDMATOM(59) = 140.907650
      STDMATOM(60) = 144.240000
      STDMATOM(61) = 145.000000
      STDMATOM(62) = 150.360000
      STDMATOM(63) = 151.965000
      STDMATOM(64) = 157.250000
      STDMATOM(65) = 158.925340
      STDMATOM(66) = 162.500000
      STDMATOM(67) = 164.930320
      STDMATOM(68) = 167.260000
      STDMATOM(69) = 168.934210
      STDMATOM(70) = 173.040000
      STDMATOM(71) = 174.967000
      STDMATOM(72) = 178.490000
      STDMATOM(73) = 180.947900
      STDMATOM(74) = 183.850000
      STDMATOM(75) = 186.207000
      STDMATOM(76) = 190.200000
      STDMATOM(77) = 192.220000
      STDMATOM(78) = 195.080000
      STDMATOM(79) = 196.966540
      STDMATOM(80) = 200.590000
      STDMATOM(81) = 204.383300
      STDMATOM(82) = 207.200000
      STDMATOM(83) = 208.980370
      STDMATOM(84) = 209.000000
      STDMATOM(85) = 210.000000
      STDMATOM(86) = 222.000000
      STDMATOM(87) = 223.000000
      STDMATOM(88) = 226.000000
      STDMATOM(89) = 227.000000
      STDMATOM(90) = 232.038100
      STDMATOM(91) = 231.035880
      STDMATOM(92) = 238.028900
      STDMATOM(93) = 237.000000
      STDMATOM(94) = 244.000000
      STDMATOM(95) = 243.000000
      STDMATOM(96) = 247.000000
      STDMATOM(97) = 247.000000
      STDMATOM(98) = 251.000000
      STDMATOM(99) = 252.000000
      STDMATOM(100) = 257.000000
      STDMATOM(101) = 258.000000
      STDMATOM(102) = 259.000000
      STDMATOM(103) = 262.000000
C
C     ------------------------------------------------------------------
C
C     *** Definition of atomic orbital symbols ***
C
      AOSYM(0)  = 's'
      AOSYM(1)  = 'p'
      AOSYM(2)  = 'd'
      AOSYM(3)  = 'f'
      AOSYM(4)  = 'g'
      AOSYM(5)  = 'h'
      AOSYM(6)  = 'i'
      AOSYM(7)  = 'j'
      AOSYM(8)  = 'k'
      AOSYM(9)  = 'l'
      AOSYM(10) = 'm'
      AOSYM(11) = 'n'
      AOSYM(12) = 'o'
C
C     *** Names of trivial vibrations ***
C
      TRIVV(1) = 'Tx'
      TRIVV(2) = 'Ty'
      TRIVV(3) = 'Tz'
      TRIVV(4) = 'Rx'
      TRIVV(5) = 'Ry'
      TRIVV(6) = 'Rz'
C
C     *** Basic labels for the generation of Cartesian components ***
C
      XYZ(1) = 'x'
      XYZ(2) = 'y'
      XYZ(3) = 'z'
C
C     ------------------------------------------------------------------
C
C     ***     Fundamental physical constants (SI units)    ***
C     *** The CODATA recommended values of the fundamental ***
C     ***   physical constants; E.R. Cohen, B.N. Taylor,   ***
C     ***     J. Res. Natl. Bur. Stand. 92(2), 1 (1987)    ***
C
C     *** Speed of light in vacuum [m/s] ***
C
      CLIGHT = 2.99792458E8
C
C     *** Elementary charge [C] ***
C
      ECHARGE = 1.60217733E-19
C
C     *** Electron mass [kg] ***
C
      EMASS = 9.1093897E-31
C
C     *** Electric field constant [F/m] ***
C
      EPSI0 = 8.854187817E-12
C
C     *** Planck constant [J*s] ***
C
      HPLANCK = 6.6260755E-34
C
C     *** Boltzmann constant [J/K] ***
C
      KBOLTZ = 1.380658E-23
C
C     *** Permeability of vacuum [N/A**2] ***
C
      MUPERM = 4.0*PI*1.0E-7
C
C     *** Avogradro constant [1/mol] ***
C
      NAVOG  = 6.0221367E23
C
C     *** Standard pressure [Pa] ***
C
      PRESSURE = 101325.0
C
C     *** Fine-structure constant ***
C
      AFINE = 0.5*MUPERM*CLIGHT*ECHARGE**2/HPLANCK
C
C     *** Gas constant ***
C
      RGAS = NAVOG*KBOLTZ
C
C     *** Rydberg constant [1/m] ***
C
      RYDBERG = 0.5*EMASS*CLIGHT*AFINE**2/HPLANCK
C
C     *** Bohr radius [m] ***
C
      ABOHR = AFINE/(4.0*PI*RYDBERG)
C
C     ------------------------------------------------------------------
C
C     *** Conversion factors ***
C
C     *** [Angstrom] -> [Bohr] ***
C
      BOHR = 1.0E-10/ABOHR
C
C     *** [Hartree] -> [J] ***
C
      JOULE = 2.0*RYDBERG*HPLANCK*CLIGHT
C
C     *** [Hartree] -> [kJ/mol] ***
C
      KJMOL = 0.001*JOULE*NAVOG
C
C     *** [Hartree] -> [kcal/mol] ***
C
      KCALMOL = KJMOL/4.184
C
C     *** [Hartree] -> [eV] ***
C
      EVOLT = JOULE/ECHARGE
C
C     *** [Hartree] -> [Hz] ***
C
      HZ = JOULE/HPLANCK
      MHZ = 1.0E-6*HZ
C
C     *** [u] -> [kg] ***
C
      UKG = 1.6605402E-27
C     
C     *** Electron mass to atomic mass units ***
C     
      EMASS2U = UKG/EMASS
C
C     *** [Hartree] -> [1/cm] (wave numbers) ***
C
      WAVENUM = 0.02*RYDBERG
C
C     *** [1/cm] -> [1/sec] ***
C
      WAVESEC = 100*CLIGHT
C
C     *** [Hartree/Bohr**2] -> [1/cm] (wave numbers) ***
C
      VIBFAC = 5.0*SQRT(KJMOL)/(PI*ABOHR*CLIGHT)
C
C     *** [Hartree] -> [esu] (electrostatic units) ***
C
      ESU(1) = 1.0E21*ABOHR*CLIGHT*ECHARGE
C
      DO 10 LM=2,MAX(2,MAXMOM)
        ESU(LM) = ESU(LM-1)/BOHR
   10 CONTINUE
C
C     *** fs -> [a.u.] (atomic units, _not_ electronic units)
C     
      CTAU = 41.34137314
C
C     *** convert MPa --> a.u. 
C
C     1 MPa = 10^6 Pa = 10^6 N / m^2 = 10^6 Nm / m^3 = 10^6 J / m^3 =
C           = 10^6 / JOULE Hartree / (10^30 Angstrom^3)
C           = 10^-24 (1 / JOULE) ( 1 / BOHR^3) Hartree/Bohr   
C
      MPA2AU = 1.0E-24/(JOULE*BOHR**3)
C
C     ------------------------------------------------------------------
C
C     *** Transform covalent radii [Angstrom] -> [Bohr] ***
C
      DO 20 Z=1,92
        COVRAD(Z) = COVRAD(Z)*BOHR
   20 CONTINUE
C
C     ------------------------------------------------------------------
C
C     *** End of SUBROUTINE PHYSCON ***
C
      END
