#ifndef __TOOLS_HPP
    #define __TOOLS_HPP
    #include "globals.hpp"
//
//
//
struct tools
{
//
//  The speed of light in vacuum, c: 
    static const double c = GSL_CONST_MKSA_SPEED_OF_LIGHT;
//
//  Planck's constant, h: 
    static const double h = GSL_CONST_MKSA_PLANCKS_CONSTANT_H;
//
//  Planck's constant divided by 2\pi, h_bar:
    static const double h_bar = GSL_CONST_MKSA_PLANCKS_CONSTANT_HBAR; 
//
//  Avogadro's number, mol: 
    static const double mol = GSL_CONST_NUM_AVOGADRO;
//
//  The Boltzmann constant, k:
    static const double k = GSL_CONST_MKSA_BOLTZMANN;
//
//  The charge of the electron, e: 
    static const double e = GSL_CONST_MKSA_ELECTRON_CHARGE;
//
//  The energy of 1 electron volt, ev: 
    static const double ev = GSL_CONST_MKSA_ELECTRON_VOLT;
//
//  The unified atomic mass, amu:
    static const double amu = GSL_CONST_MKSA_UNIFIED_ATOMIC_MASS;
//
//  The mass of the electron, electron_mass:
    static const double electron_mass = GSL_CONST_MKSA_MASS_ELECTRON;
//
//  The mass of the proton, proton_mass:
    static const double proton_mass = GSL_CONST_MKSA_MASS_PROTON;
//
//  The mass of the neutron, neutron_mass:
    static const double neutron_mass = GSL_CONST_MKSA_MASS_NEUTRON;
//
//  The electromagnetic fine structure constant, alpha: 
    static const double alpha = GSL_CONST_NUM_FINE_STRUCTURE;
//
//  The Bohr radius, bohr_radius: 
    static const double bohr_radius = GSL_CONST_MKSA_BOHR_RADIUS;
//
//  The length of 1 angstrom:
    static const double ang = GSL_CONST_MKSA_ANGSTROM;
//
//  The pi number, pi:
    static const double pi = M_PI;
//
//  Declaring data members to unit conversion:
    static const double ang_to_au = 1.0/0.529177208;        // From angstron to atomic unit.
    static const double au_to_ang = 0.529177208;            // From atomic unit to angstron.
    static const double ev_to_au  = 1.0/27.211396;          // From electron volt to atomic unit.
    static const double au_to_ev  = 27.211396;              // From atomic unit to electron volt.
    static const double s_to_au   = 1.0/2.418884326505e-17; // From second to atomic unit.
    static const double au_to_s   = 2.418884326505e-17;     // From atomic unit to second.
//
//  module() and square_module(): A set of overloaded template member functions to calculate
//                                the module of numbers and vectors.
    #include "tools__module.cpp"
//
//  Defining some alias for the generate_integral_type() and generate_double_type() member function options
//  (random number generators):
    #define TAUS2     1
    #define MT19937   2
    #define RANLXS0   3
    #define RANLXS2   4
    #define RANLXD2   5
    #define RANLUX389 6
    #define GFSR4     7
//
//  generate_integral_type(): To generate a long integral random number for a given (not mandatory) seed number and
//                            random number generator algorithm.
    unsigned long int generate_integral_type(const unsigned long int seed = time(NULL), const unsigned int option = 1);
//
//  generate_double_type(): To generate a double random number for a given (not mandatory) seed number and
//                          random number generator algorithm.
    double generate_double_type(const unsigned long int seed = time(NULL), const unsigned int option = 1);
//
//
    #include "tools__to_string_from.cpp"
//
//
    #include "tools__to_number_from.cpp"
//
//
};
#endif
