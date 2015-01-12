/* ALF2.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__400 = 400;
static doublereal c_b317 = .33333333333333331;
static doublereal c_b353 = 1.;
static doublereal c_b376 = 5.308837457e-12;

/* *********************************************************************** */
/* Subroutine */ int alf_(integer *ndp, doublereal *rmin, doublereal *rh, 
	doublereal *v, doublereal *swf, doublereal *vlim, integer *kvmax, 
	integer *aflag, doublereal *zmu, doublereal *eps, integer *ncn, 
	doublereal *gv, integer *innode, integer *innr, integer *iwr)
{
    /* Initialized data */

    static integer awo = -1;
    static integer mco = 0;
    static integer noprwf = 0;

    /* Format strings */
    static char fmt_610[] = "(/\002  *** ALF ERROR ***\002)";
    static char fmt_613[] = "(4x,\002Number of vib levels requested=\002,i4"
	    ",\002 exceeds internal ALF array dimension  NVIBMX=\002,i4)";
    static char fmt_614[] = "(/\002  *** ALF ERROR ***   Unable to find a po"
	    "tential minimum  for   J=\002,i4)";
    static char fmt_618[] = "(/\002  ALF  finds onee potential minimum of"
	    "\002,1pd15.7,\002  at  R(1)=\002,0pf9.6)";
    static char fmt_605[] = "(/\002  *** ALF WARNING ***\002)";
    static char fmt_615[] = "(4x,\002There are\002,i3,\002  potential \002,a"
	    "6,\002 in this potential. Stop searching after 10.\002)";
    static char fmt_616[] = "(4x,\002The potential turns over in the short r"
	    "ange region at R = \002,g15.8)";
    static char fmt_617[] = "(4x,\002VMAX =\002,g15.8,\002 found to be less "
	    "than VMIN =\002,g15.8)";
    static char fmt_650[] = "(/\002 There were\002,i3,\002  potential minima"
	    " found with the absolute minimum\002/4x,\002VMIN =\002,g15.8,"
	    "\002  cm-1.\002)";
    static char fmt_651[] = "(/\002 There were\002,i3,\002  potential maxima"
	    " found with the absolute maximum\002/4x,\002VMAX =\002,g15.8,"
	    "\002  cm-1.\002)";
    static char fmt_2100[] = "(/1x,39(\002==\002))";
    static char fmt_2110[] = "(/\002 Limits and increment of integration (in"
	    " Angstroms):\002/\002    RMIN =\002,f6.3,\002    RMAX =\002,f7.3,"
	    "\002    RH =\002,f9.6,//\002 Generate    BZ =\002,g19.12,\002 (("
	    "1/cm-1)(1/Angstroms**2))\002/\002 from ZMU:\002,f15.11,\002 (amu)"
	    "\002)";
    static char fmt_2111[] = "(/\002 Eigenvalue convergence criterion is   E"
	    "PS =\002,g11.4,\002(cm-1)\002)";
    static char fmt_2112[] = "(/\002 Calculating properties of the potential"
	    " described above. \002/\002 Use Airy function at 3-rd turning po"
	    "int as outer boundary\002/\002 condition for quasibound levels"
	    ".\002)";
    static char fmt_2101[] = "(/1x,39(\002--\002))";
    static char fmt_601[] = "(/\002 Solve by matching inward and outward sol"
	    "utions at the\002/5x,\002outermost wave function maximum, S(max)"
	    ", where  R = RR(M)\002)";
    static char fmt_603[] = "(/\002 Solve by matching inward and outward sol"
	    "utions at the\002/5x,\002innermost turning point   R1 = R(M)\002)"
	    ;
    static char fmt_606[] = "(4x,\002Next estimated trial energy  E(v=\002,i"
	    "3,\002) =\002,g15.8/4x,\002lies above potential maximum  VMAX "
	    "=\002,g15.8)";
    static char fmt_611[] = "(4x,\002Attempt to find zero point level fails"
	    "!\002)";
    static char fmt_620[] = "(4x,\002Use of energy \002,i1,\0020% up the pot"
	    "ential well (E =\002,g15.8,\002)\002/4x,\002 fails to produce a "
	    "viable vibrational eigenstate.\002)";
    static char fmt_612[] = "(4x,\002Attempt to find next higher vibrational"
	    " level fails!\002)";
    static char fmt_621[] = "(4x,\002Use of differences to estimate the ener"
	    "gy for the next\002/4x,\002 vibrational level (v=\002,i3,\002) f"
	    "ailed after\002,i3,\002  attempt.\002)";
    static char fmt_622[] = "(4x,\002After\002,i3,\002 tries to harmonically"
	    " estimate the zero-point energy,\002/4x,\002 initial trial energy"
	    "\002,g15.8,\002   had yielded   E(v=\002,i3,\002) =\002,g15.8)";
    static char fmt_623[] = "(4x,\002Expecting to find level (v=\002,i3,\002"
	    ") but found level (v=\002,i3,\002)\002)";
    static char fmt_2113[] = "(\002 v=\002,i3,4x,\002v(\002,a5,\002)=\002,i3"
	    ",4x,\002Gv=\002,f16.9,4x,\002Bv=\002,f16.12)";
    static char fmt_640[] = "(/\002 ALF finds all  J=\002,i3,\002  vib. leve"
	    "ls below  vD=\002,f7.3,\002  estimated by N-D theory\002)";
    static char fmt_630[] = "(/\002 ALF successfully finds all vibrational l"
	    "evels up to   v= KVMAX=\002,i3)";
    static char fmt_624[] = "(4x,\002After\002,i3,\002 tries, failed to inte"
	    "rpolate trial energy between\002/4x,\002E(v=\002,i3,\002) =\002,"
	    "g15.8,\002   and   E(v=\002,i3,\002) =\002,g15.8)";
    static char fmt_666[] = "(4x,\002Undefined case for automatic search."
	    "\002/,4x,\002Values of KV =\002,i3,\002  and NF =\002,i3)";
    static char fmt_2114[] = "(/\002 Found\002,i4,\002 level(s) in the inner"
	    " well and\002,i4,\002 level(s) in the outer well.\002)";
    static char fmt_607[] = "(4x,\002Potential found to have a second minimu"
	    "m.\002)";
    static char fmt_626[] = "(4x,\002The highest calculated level is  E(v"
	    "=\002,i3,\002) =\002,g15.8)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal ao;
    static integer nf;
    static doublereal eo, re, vd, bz;
    static integer kv;
    static doublereal pw;
    static integer ieg;
    static doublereal vdl;
    static integer iwl[401], iqt;
    static doublereal vdu, pwi;
    static integer owl[401];
    static doublereal gama;
    static integer nbeg;
    static doublereal bfct, lhie;
    static integer nend;
    static doublereal lloe, ravg[401];
    static integer izpe, niwl;
    static doublereal rmax, vmin, vmax, pmax;
    static integer jrot, nowl;
    static doublereal vdmv;
    static integer ltry, ivdif;
    extern /* Subroutine */ int dteng_(integer *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *);
    static integer inner;
    extern /* Subroutine */ int schrq_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *);
    static integer npmin, ivcor, npmax;
    static doublereal rpmin[10], rpmax[10], vpmin[10], vpmax[10];
    static integer triale;
    static doublereal dravin;
    extern /* Subroutine */ int initval_(integer *, integer *, integer *, 
	    integer *, integer *);
    static doublereal dravout;

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___5 = { 0, 6, 0, fmt_613, 0 };
    static cilist io___28 = { 0, 6, 0, fmt_614, 0 };
    static cilist io___29 = { 0, 6, 0, fmt_618, 0 };
    static cilist io___30 = { 0, 6, 0, fmt_605, 0 };
    static cilist io___31 = { 0, 6, 0, fmt_615, 0 };
    static cilist io___35 = { 0, 6, 0, fmt_605, 0 };
    static cilist io___36 = { 0, 6, 0, fmt_615, 0 };
    static cilist io___37 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___38 = { 0, 6, 0, fmt_616, 0 };
    static cilist io___42 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___43 = { 0, 6, 0, fmt_617, 0 };
    static cilist io___44 = { 0, 6, 0, fmt_650, 0 };
    static cilist io___45 = { 0, 6, 0, fmt_651, 0 };
    static cilist io___51 = { 0, 21, 0, fmt_2100, 0 };
    static cilist io___52 = { 0, 21, 0, fmt_2110, 0 };
    static cilist io___53 = { 0, 21, 0, fmt_2111, 0 };
    static cilist io___54 = { 0, 21, 0, fmt_2112, 0 };
    static cilist io___55 = { 0, 21, 0, fmt_2101, 0 };
    static cilist io___56 = { 0, 6, 0, fmt_601, 0 };
    static cilist io___57 = { 0, 6, 0, fmt_603, 0 };
    static cilist io___64 = { 0, 6, 0, fmt_605, 0 };
    static cilist io___65 = { 0, 6, 0, fmt_606, 0 };
    static cilist io___66 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___67 = { 0, 6, 0, fmt_611, 0 };
    static cilist io___68 = { 0, 6, 0, fmt_620, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___70 = { 0, 6, 0, fmt_612, 0 };
    static cilist io___71 = { 0, 6, 0, fmt_621, 0 };
    static cilist io___72 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___73 = { 0, 6, 0, fmt_611, 0 };
    static cilist io___74 = { 0, 6, 0, fmt_622, 0 };
    static cilist io___75 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___76 = { 0, 6, 0, fmt_612, 0 };
    static cilist io___77 = { 0, 6, 0, fmt_623, 0 };
    static cilist io___81 = { 0, 21, 0, fmt_2113, 0 };
    static cilist io___82 = { 0, 21, 0, fmt_2113, 0 };
    static cilist io___83 = { 0, 21, 0, fmt_2113, 0 };
    static cilist io___84 = { 0, 21, 0, fmt_2113, 0 };
    static cilist io___86 = { 0, 6, 0, fmt_640, 0 };
    static cilist io___87 = { 0, 6, 0, fmt_630, 0 };
    static cilist io___88 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___89 = { 0, 6, 0, fmt_612, 0 };
    static cilist io___90 = { 0, 6, 0, fmt_624, 0 };
    static cilist io___93 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___94 = { 0, 6, 0, fmt_666, 0 };
    static cilist io___95 = { 0, 6, 0, fmt_630, 0 };
    static cilist io___96 = { 0, 21, 0, fmt_2114, 0 };
    static cilist io___97 = { 0, 6, 0, fmt_605, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_607, 0 };
    static cilist io___99 = { 0, 6, 0, fmt_626, 0 };
    static cilist io___100 = { 0, 21, 0, fmt_2100, 0 };


/* *********************************************************************** */
/*   Version 1.0 dated July 6, 2003. Cosmetic formatting changes 11/04/07 */
/* ----------------------------------------------------------------------- */
/* ** The subroutine ALF (Automatic vibrational Level Finder) will */
/*   automatically generate the eigenvalues from the first vibrational */
/*   level (v=0) to a user specified level (v=KVMAX) or the highest */
/*   allowed vibrational level of a given smooth single (or double) */
/*   minimum potential (V). These energies are stored and returned to the */
/*   calling program in the molecular constants array GV(v=0-KVMAX). */
/* ** For any errors that cannot be resolved within the subroutine, ALF */
/*   returns AFLAG with a value that defines which error had occured. */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ++   COPYRIGHT 1998 - 2003  by  Jenning Seto and Robert J. Le Roy   +++ */
/*   Dept. of Chemistry, Univ. of Waterloo, Waterloo, Ontario, Canada   + */
/*    This software may not be sold or any other commercial use made    + */
/*     of it without the express written permission of the authors.     + */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* + Please inform me of any bugs, by phone at: (519)888-4567, ext. 4051 + */
/* ++++++++ by e-mail to: leroy@uwaterloo.ca , or write me at: ++++++++++ */
/* +++ Dept. of Chemistry, Univ. Waterloo, Waterloo, Ontario  N2L 3G1 ++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** Based on the automatic level finding routine from LEVEL 6.0 written */
/*   by Robert J. Le Roy */
/* ** Uses the Schrodinger solver subroutine SCHRQ. */

/* ** On entry: */
/*    NDP    is the number of datapoints used for the potential. */
/*    RMIN   is the inner radial distance of the potential (ang). */
/*    RH     is the meshvalue (ang). */
/*           NDP, RMIN, and RH define the radial range over which the */
/*           potential is defined. */
/*    V(i)   is the scaled input potential (cm-1). */
/*           The scaling factor BFCT is (2*mu/hbar^2)*RH^2. */
/*    VLIM   is the potential asymptote (cm-1). */
/*    KVMAX  is v for the highest vibrational level we wish to find. */
/*    AFLAG  is rot.quantum J for the (centrifugally distorted) potential */
/*    ZMU    is the reduced mass of the diatom (amu). */
/*    EPS    is the energy convergence criterion (cm-1). */
/*    NCN    is the near dissociation limit radial exponential. */
/*    INNODE specifies whether wave fx. initiation @ RMIN starts with a */
/*        note (normal case: INNODE > 0) or zero slope (when INNODE.le.0) */
/*    IWR    specifies the level of printing inside SCHRQ */
/*           <> 0 : print error & warning descriptions. */
/*           >= 1 : also print final eigenvalues & node count. */
/*           >= 2 : also show end-of-range wave function amplitudes. */
/*           >= 3 : print also intermediate trial eigenvalues, etc. */

/* ** On exit: */
/*    KVMAX   is vib.quantum number for the highest allowed vibrational */
/*            level found (may be less than the input value of KVMAX). */
/*    AFLAG   returns calculation outcome to calling program. */
/*            >=  0 : Subroutine found all levels to v=KVMAX(input). */
/*             = -1 : KVMAX larger than number of allowed levels. */
/*             = -2 : Initial trial energy is unusable. */
/*             = -3 : Calculated trial energy is unusable. */
/*             = -4 : Cannot find first vibrational level. */
/*             = -5 : Calculated trial energy too low. */
/*             = -6 : Calculated trial energy too high. */
/*             = -7 : An impossible situation occured. */
/*             = -8 : Potential found to have a second minimum. */
/*    GV(v)   contains the vibrational energy levels found for v=0-KVMAX */
/*    INNR(v) labels each level as belonging to the inner (INNR = 1) or */
/*            outer (INNR = 0) well. */

/* ** Flags: Modify only when debugging. */
/*    AWO   specifies the level of printing inside ALF */
/*          <> 0 : print error & warning descriptions. */
/*          >  0 : also print intermediate ALF messages. */
/*    MCO   specifies the level of printing of molecular constants. */
/*          >  0 : print out vibrational energies to channel-21. */
/*    INNER specifies wave function matching (& initiation) conditions. */
/*        .le.0 : Match inward & outward solutions at outermost well t.p. */
/*          > 0 : Match at innermost well inner turning point */
/*        For most normal cases set INNER = 0,  but ...... */
/*            To find "inner-well-dominated" solutions of an asymmetric */
/*            double minimum potential, set  INNER > 0. */
/*    LPRWF specifies option of printing out generated wavefunction */
/*          > 0 : print wave function every LPRWF-th  point. */
/*          < 0 : compactly write to channel-7 every |LPRWF|-th wave */
/*                function value. */
/*          A lead "card" identifies the level, gives the position of */
/*          1-st point and radial mesh, & states No. of  points. */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** The dimensioning parameters must be consistant with the sizes of the */
/*   arrays used in the calling program. */

/*    NVIBMX  is the maximum number of vibrational levels considered. */
/*            Note: NVIBMX should be larger than KVMAX. */


/* ** NF counts levels found in automatic search option */

/* ** OWL holds the vibrational levels that are contained in the outer */
/*   well. */
/* ** IWL holds the vibrational levels that are contained in the inner */
/*   well (if present). */



    /* Parameter adjustments */
    --swf;
    --v;

    /* Function Body */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** Check that the array dimensions are adequate. */
    if (*kvmax > 400) {
	s_wsfe(&io___4);
	e_wsfe();
	s_wsfe(&io___5);
	do_fio(&c__1, (char *)&(*kvmax), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__400, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/* ** Initialize level counters for each well. */
    i__1 = *kvmax;
    for (i__ = 0; i__ <= i__1; ++i__) {
	innr[i__] = -1;
	iwl[i__] = 0;
	owl[i__] = 0;
    }

/* ** Initialize the remaining variables and flags. */
    nf = 0;
    niwl = 0;
    nowl = 0;
    kv = 0;
    inner = 0;
    ltry = 0;
    lhie = 1e99;
    initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);

/* ** Store rotational quantum number. */
    jrot = *aflag;

/* ** Numerical factor  16.85762920 (+/- 0.00000011) based on Compton */
/*  wavelength of proton & proton mass (u) from 2002 physical constants. */
    bz = *zmu / 16.8576292;
    bfct = bz * *rh * *rh;

/* ** RMAX is the outer radial distance over which potential is defined. */
    rmax = *rmin + (doublereal) (*ndp - 1) * *rh;
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** Locate the potential minima. */
    npmin = 0;
    i__1 = *ndp - 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (v[i__] < v[i__ - 1] && v[i__] < v[i__ + 1]) {
	    ++npmin;
	    rpmin[npmin - 1] = *rmin + (doublereal) (i__ - 1) * *rh;
	    vpmin[npmin - 1] = v[i__] / bfct;
	    if (npmin == 10) {
		goto L100;
	    }
	}
    }
/* ** If NO minimum can be found, then print a warning and stop. */
L100:
    if (npmin == 0) {
	if (v[2] <= v[1]) {
	    s_wsfe(&io___28);
	    do_fio(&c__1, (char *)&jrot, (ftnlen)sizeof(integer));
	    e_wsfe();
	    *kvmax = -1;
	    return 0;
	}
	npmin = 1;
	vpmin[npmin - 1] = v[1] / bfct;
	rpmin[npmin - 1] = *rmin;
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&vpmin[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*rmin), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* ** If more than two minima are found, then print a warning and hope ... */
    if (npmin > 2) {
	s_wsfe(&io___30);
	e_wsfe();
	s_wsfe(&io___31);
	do_fio(&c__1, (char *)&npmin, (ftnlen)sizeof(integer));
	do_fio(&c__1, "minima", (ftnlen)6);
	e_wsfe();
/*         STOP */
    }
    npmax = 0;
/* ** Locate the potential maxima (if it exists). */
    i__1 = *ndp - 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (v[i__] > v[i__ - 1] && v[i__] > v[i__ + 1]) {
	    ++npmax;
	    rpmax[npmax - 1] = *rmin + (doublereal) (i__ - 1) * *rh;
	    vpmax[npmax - 1] = v[i__] / bfct;
	    if (npmax == 10) {
		goto L150;
	    }
	}
    }

L150:
    if (npmax == 0) {
/* ** If no maxima were found, then set energy maximum to be the value */
/*   at the end of the radial range. */
	npmax = 1;
	rpmax[npmax - 1] = rmax;
	vpmax[npmax - 1] = v[*ndp] / bfct;
    }

/* ** If more than three maxima found, then print a warning and hope ... */
    if (npmax > 3) {
	s_wsfe(&io___35);
	e_wsfe();
	s_wsfe(&io___36);
	do_fio(&c__1, (char *)&npmax, (ftnlen)sizeof(integer));
	do_fio(&c__1, "maxima", (ftnlen)6);
	e_wsfe();
/*         STOP */
    }

/* ** If there is no barrier to dissociation, then set the */
/*   final VPMAX to be the value at the end of the range. [huh ????] */
    if (rpmax[npmax - 1] < rpmin[npmin - 1]) {
	++npmax;
	rpmax[npmax - 1] = rmax;
	vpmax[npmax - 1] = v[*ndp] / bfct;
    }

/* ** If innermost maximum occurs before innermost minimum, the potential */
/*   turns over in short range region and should not be used. */
/*   Print a warning and STOP. */
    if (rpmax[0] < rpmin[0]) {
	s_wsfe(&io___37);
	e_wsfe();
	s_wsfe(&io___38);
	do_fio(&c__1, (char *)&rpmax[0], (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/* ** Now find the absolute potential minimum. */
    vmin = vpmin[0];
    re = rpmin[0];
    i__1 = npmin;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (vmin > vpmin[i__ - 1]) {
	    vmin = vpmin[i__ - 1];
	    re = rpmin[i__ - 1];
	}
    }

/* ** Now find the absolute potential maximum. */
    vmax = vpmax[0];
    i__1 = npmax;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (vmax < vpmax[i__ - 1]) {
	    vmax = vpmax[i__ - 1];
	}
    }

/* ** If the absolute potential maximum is lower than the absolute */
/*   potential minimum, then print out an error statement and quit. */
    if (vmax <= vmin) {
	s_wsfe(&io___42);
	e_wsfe();
	s_wsfe(&io___43);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/* ** Otherwise, print out potential extrema count, if desired. */
    if (awo > 0) {
	s_wsfe(&io___44);
	do_fio(&c__1, (char *)&npmin, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vmin, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___45);
	do_fio(&c__1, (char *)&npmax, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vmax, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** Calculate 2*NCN/(NCN - 2) for use when calculating trial energies. */
    pw = 20.;
    if (*ncn > 0 && *ncn != 2) {
	pw = (doublereal) (*ncn) * 2. / ((doublereal) (*ncn) - 2.);
    }
    if (vmax > *vlim) {
	pw = 2.;
    }
    pwi = 1. / pw;

/* ** Use Lennard-Jones estimation of zero point energy to determine the */
/*   initial trial energy. */
/*                            _____________________________ */
/*            vD + 0.5 = ao \/ZMU * De * Re^2 / 16.85762920 */
/*                 De = A (vD - v)^3 = A (vD + 0.5)^3 */
/*              E(v=0) = VMIN + A [(vD + 0.5)^3 - vD^3] */
/* ** Choose AO to have a value of 0.25. */

    ao = .25;
    vd = ao * sqrt(bz * (vmax - vmin));
    vd = vd * re - .5;
/* Computing 3rd power */
    d__1 = vd / (vd + .5);
    ao = (vmax - vmin) * (1. - d__1 * (d__1 * d__1));
    eo = vmin + ao;

    if (mco >= 1) {
/* ** If desired, write out SCHRQ control information. */
	s_wsfe(&io___51);
	e_wsfe();
	s_wsfe(&io___52);
	do_fio(&c__1, (char *)&(*rmin), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*rh), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&bz, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*zmu), (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___53);
	do_fio(&c__1, (char *)&(*eps), (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___54);
	e_wsfe();
	s_wsfe(&io___55);
	e_wsfe();
    }
/* =========== Begin Actual Eigenvalue Calculation Loop Here ============= */
/* ** Compute eigenvalues ... etc. up to the KVMAX'th vibrational level. */
/* ** When attempts to find the next eigenvalue fails, then perhaps the */
/*   next level is located in a second (inner) well. If so, then the */
/*   subroutine will set INNER = 1, and attempt to find that level. */

L10:
    if (awo > 0) {
	if (inner == 0) {
	    s_wsfe(&io___56);
	    e_wsfe();
	}
	if (inner == 1) {
	    s_wsfe(&io___57);
	    e_wsfe();
	}
    }
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** Call subroutine SCHRQ to find eigenvalue EO and eigenfunction SWF(I). */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
    schrq_(&kv, &jrot, &eo, &gama, &pmax, vlim, &v[1], &swf[1], &bfct, eps, 
	    rmin, rh, ndp, &nbeg, &nend, innode, &inner, iwr, &noprwf);
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If a level higher than NF has already been found and the level found */
/*   not the correct level, ignore all errors and continue with the */
/*   binary search. */

    if (kv >= 0 && kv < nf && (ivcor > 0 || ieg > 3)) {
	kv = nf + 1;
	eo = vmax + 1.;
	if (ivcor > 0) {
	    lloe = (lhie + lloe) / 2.;
	} else {
	    lloe = gv[nf - 1];
	    lhie = vmax;
	    ivcor = 1;
	}
	triale = 0;
    }
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** The SCHRQ error condition is KV < 0. */
/*   There are three possible situations to consider: */
/*     EO > VMAX : Trial energy greater than potential maximum */
/*     NF = 0 : Looking for the first vibrational level (v = 0) */
/*     NF > 0 : Looking for the other vibrational levels (v > 0) */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** For the case when the next trial energy is higher than the potential */
/*   maximum, try one last ditch attempt to find the highest bound level */
/*   (quasi or otherwise) in the potential. */

    if (kv < 0 && eo > vmax) {
	if (ivcor < 20) {
	    kv = nf + 1;
	    if (ivcor == 0) {
/* ?????? */
		if (nf == 0) {
		    lloe = gv[0];
		} else {
		    lloe = gv[nf - 1];
		}
/* ??????           LLOE= GV(NF-1) */
/* ?????? */
		lhie = vmax;
		ivcor = 1;
	    }
	}
	if (ltry < 1) {
	    ltry = 1;
	    kv = 999;
	    eo = vmax - .01;

/* ** If unsuccessful, then print out a warning and exit. */
	} else {
	    if (awo != 0) {
		s_wsfe(&io___64);
		e_wsfe();
		s_wsfe(&io___65);
		do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&eo, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&vmax, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    *aflag = -1;
	    goto L200;
	}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If trying to find the first vibrational level (v=0), then double the */
/*   zero point energy estimation (AO):   E(v=0) = VMIN + IQT*AO */

    } else if (kv < 0 && nf == 0) {
	if (iqt > 1) {
	    if (awo != 0) {
		s_wsfe(&io___66);
		e_wsfe();
		s_wsfe(&io___67);
		e_wsfe();
		s_wsfe(&io___68);
		do_fio(&c__1, (char *)&iqt, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&eo, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }

/* ** If this fails, then try changing the wavefunction matching */
/*   condition (INNER) to see if a possible second minimum contains the */
/*   zero-point level. */
	    if (inner == 0) {
		inner = 1;
		initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);
/* ** If both attempts fail, then print out warning message and exit the */
/*   subroutine. */
	    } else {
		*aflag = -2;
		goto L200;
	    }
	}
	++iqt;
	eo = vmin + (doublereal) iqt * ao;
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If trying to find other vibrational levels (v > 0) then switch to */
/*   use of differences for estimating spacing. */

    } else if (kv < 0 && nf > 0) {
	if (ivdif > 0) {
	    if (awo != 0) {
		s_wsfe(&io___69);
		e_wsfe();
		s_wsfe(&io___70);
		e_wsfe();
		s_wsfe(&io___71);
		do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&ivdif, (ftnlen)sizeof(integer));
		e_wsfe();
	    }

/* ** If differences fails, then try changing the wavefunction matching */
/*   condition (INNER) to see if a possible second minimum contains the */
/*   zero point level. */

	    if (inner == 0) {
		inner = 1;
		initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);

/* ** If both attempts fail, then print out warning message and exit the */
/*   subroutine. */
	    } else {
		*aflag = -3;
		goto L200;
	    }
	}
	ivdif = 1;
	if (inner == 0) {
	    dteng_(&ieg, &nf, &nowl, owl, &c__400, &vmin, gv, &eo);
	} else {
	    dteng_(&ieg, &nf, &niwl, iwl, &c__400, &vmin, gv, &eo);
	}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If first level found isn't v=0, try up to 3 times to 'harmonically' */
/*   estimate improved trial ground state energy. */
/*           E(v=0)= E(v=KV) - (E(v=KV) - VMIN)/(1 + KV/2) */

    } else if (kv > 0 && nf == 0) {
	if (izpe > 3) {
	    if (awo != 0) {
		s_wsfe(&io___72);
		e_wsfe();
		s_wsfe(&io___73);
		e_wsfe();
		s_wsfe(&io___74);
		do_fio(&c__1, (char *)&izpe, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&gv[0], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&kv, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&eo, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }

/* ** If differences fails, then try changing the wavefunction matching */
/*   condition (INNER) to see if a possible second minimum contains the */
/*   zero point level. */
	    if (inner == 0) {
		inner = 1;
		initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);

/* ** If both attempts fail, then print out warning message and exit the */
/*   subroutine. */
	    } else {
		*aflag = -4;
		goto L200;
	    }
	}
	++izpe;
	eo -= (eo - vmin) / (.5 / kv + 1.);
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** For the next three cases, KV >= 0 and NF > 0. */
/* ** If the calculated vibrational level is less than the next expected */
/*   level, then the estimated trial energy is too low. */
/* ** Perhaps the difference in energy between vibrational levels v and */
/*   v-1 is much greater than the energy between levels v-1 and v-2. */
/*                 E(v) - E(v-1) >> E(v-1) - E(v-2) */
/*   In which case (most likely a potential with a shelf), try twice to */
/*   estimate a higher trial energy. */

/*   E(v)= E(v-1) + (1+IEG/2) * (2*(E(v-1)-E(v-2)) - (E(v-2)-E(v-3))) */

    } else if (kv < nf) {
	if (ieg > 3) {
	    if (awo != 0) {
		s_wsfe(&io___75);
		e_wsfe();
		s_wsfe(&io___76);
		e_wsfe();
		s_wsfe(&io___77);
		do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&kv, (ftnlen)sizeof(integer));
		e_wsfe();
	    }

/* ** If this fails, then try changing the wavefunction matching */
/*   condition (INNER) to see if a possible second minimum contains the */
/*   zero point level. */
	    if (inner == 0) {
		inner = 1;
		initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);

/* ** If both attempts fail, then print out warning message and exit the */
/*   subroutine. */
	    } else {
		*aflag = -5;
		goto L200;
	    }
	}
	++ieg;

/* ** If a second minimum is present, then the next vibrational level may */
/*   be in the inner well. If so, use the inner well vibrational levels */
/*   to estimate the next trial energy. */
	if (inner == 0) {
	    dteng_(&ieg, &nf, &nowl, owl, &c__400, &vmin, gv, &eo);
	} else {
	    dteng_(&ieg, &nf, &niwl, iwl, &c__400, &vmin, gv, &eo);
	}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If the calculated vibrational level is the next expected level, ... */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
    } else if (kv == nf) {
	gv[nf] = eo;
	innr[nf] = inner;
	ltry = 0;
	triale = 1;
	lloe = eo;
	lhie = vmax;
	initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);
/* ----------------------------------------------------------------------- */

/* ** To ease confusion when using a potential with two minima, use */
/*  <R>=RAVG  to keep track of which is which. */

L20:
	ravg[nf] = (swf[nbeg] * (*rmin + (doublereal) (nbeg - 1) * *rh) + swf[
		nend] * (*rmin + (doublereal) (nend - 1) * *rh)) * .5;
	i__1 = nend - 1;
	for (i__ = nbeg + 1; i__ <= i__1; ++i__) {
	    ravg[nf] += swf[i__] * (*rmin + (doublereal) (i__ - 1) * *rh);
	}
	ravg[nf] *= *rh;

/* ** Double check that the calculated level is in fact located in the */
/*   correct well. This can be done (for v.ne.0) by comparing <R> for */
/*   the new level and with previous values in each well. If the */
/*   difference is greater than 1.5 times the difference in the other */
/*   well, assume the calculated level is probably in the wrong well. */

	if (nowl > 0) {
	    dravout = (d__1 = ravg[nf] - ravg[owl[nowl - 1]], abs(d__1));
	} else {
	    dravout = 9999.9;
	}
	if (niwl > 0) {
	    dravin = (d__1 = ravg[nf] - ravg[iwl[niwl - 1]], abs(d__1));
	} else {
	    dravin = 9999.9;
	}
	if (inner == 0) {
	    if (nowl > 0 && dravout > dravin * 1.5) {
		if (mco >= 1) {
		    s_wsfe(&io___81);
		    do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		    do_fio(&c__1, "Inner", (ftnlen)5);
		    do_fio(&c__1, (char *)&niwl, (ftnlen)sizeof(integer));
		    d__1 = gv[nf] - vmin;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&ravg[nf], (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		}
		iwl[niwl] = nf;
		++niwl;
	    } else {
		if (mco >= 1) {
		    s_wsfe(&io___82);
		    do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		    do_fio(&c__1, "Outer", (ftnlen)5);
		    do_fio(&c__1, (char *)&nowl, (ftnlen)sizeof(integer));
		    d__1 = gv[nf] - vmin;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&ravg[nf], (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		}
		owl[nowl] = nf;
		++nowl;
	    }
	} else {
	    if (niwl > 0 && dravin > dravout * 1.5) {
		if (mco >= 1) {
		    s_wsfe(&io___83);
		    do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		    do_fio(&c__1, "Outer", (ftnlen)5);
		    do_fio(&c__1, (char *)&nowl, (ftnlen)sizeof(integer));
		    d__1 = gv[nf] - vmin;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&ravg[nf], (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		}
		owl[nowl] = nf;
		++nowl;
	    } else {
		if (mco >= 1) {
		    s_wsfe(&io___84);
		    do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
		    do_fio(&c__1, "Inner", (ftnlen)5);
		    do_fio(&c__1, (char *)&niwl, (ftnlen)sizeof(integer));
		    d__1 = gv[nf] - vmin;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&ravg[nf], (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		}
		iwl[niwl] = nf;
		++niwl;
	    }
	    inner = 0;
	}

/* ** Look for the next uncalculated level. */
	++nf;
	if (nf <= *kvmax) {
	    if (innr[nf] >= 0) {
/* ... if this next level was found earlier, its INNER > initial -1 value */
/*  so skip up one, but first calculate its Bv on the way. */
		goto L20;
	    }
	}
/* ----------------------------------------------------------------------- */
/* ** Now estimate trial energy for next higher vibrational energy level */
/*   by using the Near-Dissociation Theory result that: */
/*                  (binding energy)**((NCN-2)/(2*NCN)) */
/*   is (at least locally) linear in vibrational quantum number. */

	if (nf == 1) {
	    d__1 = (vmax - vmin) / (vmax - gv[0]);
	    vdmv = .5 / (pow_dd(&d__1, &pwi) - 1.);
	} else {
	    d__1 = (vmax - gv[nf - 2]) / (vmax - gv[nf - 1]);
	    vdmv = 1. / (pow_dd(&d__1, &pwi) - 1.);
	}

/* ** If unable to calculate the next trial energy, see if all of the */
/*   desired levels have been calculated. If not then turn on the warning */
/*   flag and quit, otherwise print out success message and quit. */

	if (vdmv < 1. && *ncn > 2) {
	    if (nf <= *kvmax) {
		*aflag = -1;
		s_wsfe(&io___86);
		do_fio(&c__1, (char *)&jrot, (ftnlen)sizeof(integer));
		d__1 = nf - 1 + vdmv;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else if (awo > 0) {
		s_wsfe(&io___87);
		do_fio(&c__1, (char *)&(*kvmax), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	    goto L200;
	}

/* ** Now calculate the next trial energy. */

	d__1 = 1. - 1. / vdmv;
	eo = vmax - (vmax - gv[nf - 1]) * pow_dd(&d__1, &pw);

/* ** However, if the level is above the dissociation limit (for */
/*   potentials with barriers) then use differences to calculate the */
/*   next trial energy. */

	if (eo > vmax) {
	    dteng_(&ieg, &nf, &nowl, owl, &c__400, &vmin, gv, &eo);
	}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If the calculated vibrational level is higher then the next expected */
/*   level, then try once to interpolate harmonically for the missed */
/*   level:      E(v)= E(v-1) + (E(KV) - E(v-1)) / 2 */

    } else if (kv > nf) {

/* ** Record vibrational level (if haven't already) for posterity. */

	if (kv <= *kvmax && eo < vmax) {
	    if (innr[kv] == -1) {
		gv[kv] = eo;
		innr[kv] = inner;
	    }
	}
	if (ivcor > 19) {
	    if (awo != 0) {
		s_wsfe(&io___88);
		e_wsfe();
		s_wsfe(&io___89);
		e_wsfe();
		s_wsfe(&io___90);
		do_fio(&c__1, (char *)&ivcor, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&kv, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&eo, (ftnlen)sizeof(doublereal));
		i__1 = nf - 1;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&gv[nf - 1], (ftnlen)sizeof(doublereal))
			;
		e_wsfe();
	    }

/* ** If interpolation fails, then try changing the wavefunction matching */
/*   condition (INNER) to see if a possible second minimum contains the */
/*   missing level. */
	    if (inner == 0) {
		inner = 1;
		lloe = gv[nf - 1];
		lhie = vmax;
		initval_(&iqt, &ivdif, &izpe, &ieg, &ivcor);

/* ** If both attempts fail, then print a warning message and exit */
	    } else {
		*aflag = -6;
		goto L200;
	    }
	}

/* ** Use NDE theory to predict eigenvalue for the missing level. */
	if (ivcor == 0) {
	    d__1 = vmax - eo;
	    vdu = pow_dd(&d__1, &pwi);
	    d__1 = vmax - gv[nf - 1];
	    vdl = pow_dd(&d__1, &pwi);
	    d__1 = vdl + (vdu - vdl) / (doublereal) (kv - nf + 1);
	    eo = vmax - pow_dd(&d__1, &pw);
/*         IF((NPMIN.EQ.1).AND.(IVCOR.EQ.0)) THEN */
/*             VDU= (VPMAX(1)-EO)**PWI */
/*             VDL= (VPMAX(1)-GV(OWL(NOWL-1)))**PWI */
/*             EO= VPMAX(1)- (VDL+ (VDU - VDL)/ DBLE(KV - NF + 1))**PW */
/*           ELSEIF((((INNER.EQ.1).AND.(NIWL.GT.0)).OR. */
/*    1          ((INNER.EQ.0).AND.(NOWL.EQ.0))).AND.(IVCOR.EQ.0)) THEN */
/*             VDU= (VPMAX(1)-EO)**PWI */
/*             VDL= (VPMAX(1)-GV(IWL(NIWL-1)))**PWI */
/*             EO= VPMAX(1)- (VDL+ (VDU - VDL)/ DBLE(KV - NF + 1))**PW */
/*           ELSEIF((((INNER.EQ.0).AND.(NOWL.GT.0)).OR. */
/*     1         ((INNER.EQ.1).AND.(NIWL.EQ.0))).AND.(IVCOR.EQ.0)) THEN */
/*             VDU= (VPMAX(2)-EO)**PWI */
/*             VDL= (VPMAX(2)-GV(OWL(NOWL-1)))**PWI */
/*             EO= VPMAX(2)- (VDL+ (VDU - VDL)/ DBLE(KV - NF + 1))**PW */

/* ** Otherwise use a binary search. */

	} else {
	    if (triale == 1 && eo < lhie) {
		lhie = eo;
		ivcor = 0;
	    } else if (triale == 1) {
		lhie = (lhie + lloe) / 2.;
	    }
	    triale = 1;
	    eo = (lhie + lloe) / 2.;
	}
	++ivcor;
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** If an unknown case occurs (quite impossible but don't quote me on */
/*   it) then write out an error message and exit. */
    } else {
	if (awo != 0) {
	    s_wsfe(&io___93);
	    e_wsfe();
	    s_wsfe(&io___94);
	    do_fio(&c__1, (char *)&kv, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nf, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	*aflag = -7;
	goto L200;
    }
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** Set KV to the next uncalculated vibrational level to be found unless */
/*   looking for the highest vibrational level. */

    if (kv != 999) {
	kv = nf;
    }

/* ** If still haven't found all of the vibrational levels then */
/*   look for the next vibrational level. */

    if (kv <= *kvmax || kv == 999) {
	goto L10;
    }

/* ** Otherwise, print out a message saying that all is well. */

    if (kv > *kvmax && awo > 0) {
	s_wsfe(&io___95);
	do_fio(&c__1, (char *)&(*kvmax), (ftnlen)sizeof(integer));
	e_wsfe();
    }

/* ** If the potential has levels in a second minimum, then print out a */
/*   list of those levels to channel-21 if desired. */

    if (niwl > 0 && nowl > 0) {
	if (mco >= 1) {
	    s_wsfe(&io___96);
	    do_fio(&c__1, (char *)&niwl, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nowl, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (awo != 0) {
	    s_wsfe(&io___97);
	    e_wsfe();
	    s_wsfe(&io___98);
	    e_wsfe();
	}
	*aflag = -8;
    }

L200:
    if (*aflag < 0) {
/* ** If unable to find all KVMAX+1 levels requested, then return KVMAX as */
/*  v for the highest vibrational level actually found, and print out the */
/*  the energy of that level. */
	*kvmax = nf - 1;
	if (awo != 0) {
	    s_wsfe(&io___99);
	    do_fio(&c__1, (char *)&(*kvmax), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&gv[*kvmax], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    if (mco >= 1) {
/*         WRITE(21,2100) */
/*         DO  I= 0,NF-1 */
/*             IF(INNR(I).EQ.0)WRITE(21,2113)I,'Outer',I,GV(I)-VMIN,RAVG(I) */
/*             IF(INNR(I).EQ.1)WRITE(21,2113)I,'Inner',I,GV(I)-VMIN,RAVG(I) */
/*             END DO */
	s_wsfe(&io___100);
	e_wsfe();
    }
    return 0;
/* ----------------------------------------------------------------------- */
} /* alf_ */

/* *********************************************************************** */
/* Subroutine */ int initval_(integer *iqt, integer *ivdif, integer *izpe, 
	integer *ieg, integer *ivcor)
{
/* *********************************************************************** */
/* ** This subroutine reinitializes the condition flags when considering a */
/*   new case (found next vibrational level or finding level in inner */
/*   well - INNER = 1). */

/* ** On entry and exit: */
/*    IQT     Case when KV < 0 and NF = 0 */
/*            determines the value used for the initial trial energy. */
/*    IVDIF   Case when KV < 0 and NF > 0 */
/*            is the flag denoting the use of differences to calculate */
/*            trial energies. */
/*    IZPE    Case when KV > 0 and NF = 0 */
/*            is the number of times the zero point energy (v = 0) has */
/*            been estimated harmonically. */
/*    IEG     Case when KV < NF and NF > 0 */
/*            are the number of times that a larger trial energy is used */
/*            to find the next level. */
/*    IVCOR   Case when KV > NF and NF > 0 */
/*            are the number of times that a smaller trial energy is used */
/*            to find the next level. */


    *iqt = 1;
    *ivdif = 0;
    *izpe = 0;
    *ieg = 0;
    *ivcor = 0;
    return 0;
} /* initval_ */

/* *********************************************************************** */
/* Subroutine */ int dteng_(integer *ieg, integer *nf, integer *nvel, integer 
	*vel, integer *nvibmx, doublereal *vmin, doublereal *gv, doublereal *
	eo)
{
/* *********************************************************************** */
/* ** This subroutine calculates the next trial energy using differences. */

/* ** On entry: */
/*    IEG     factor by which a larger trial energy should be calculated: */
/*              NVEL = 2 : Increase correction by increments of 25% */
/*              NVEL > 2 : Increase correction by increments of 50% */
/*    NF      is the highest calculated vibrational level. */
/*    NVEL    is the number of levels found in the potential well. */
/*    VEL(v)  keeps track of all levels in the potential well. */
/*    NVIBMX  is the maximum number of vibrational levels (dimension). */
/*    VMIN    is the absolute value of the potential minimum (cm-1). */
/*    GV(v)   contains the vibrational energy level spacings */
/*            and rotational constants for each level (cm-1). */

/* ** On exit: */
/*    EO      is the calculated trial energy. */



/* ** If determining the first (non-zero point energy) level in the well, */
/*   then use the last determined level in the other well plus a larger */
/*   than harmonic correction that becomes smaller with each new */
/*   iteration:      E(v=0)= E(v=NF-1) + (E(v=NF-1)-VMIN)/(NF-1+IEG/4) */

    if (*nvel == 0) {
	*eo = gv[*nf - 1] + (gv[*nf - 1] - *vmin) / (*nf - 1 + (doublereal) (*
		ieg) * .25);

/* ** Try to get v= 1 using smaller-than-harmonic spacing. */

/*              E(v=1)= E(v=0) + (1.0+IEG/4)*(E(v=0)-VMIN) */

    } else if (*nvel == 1) {
	*eo = gv[vel[0]] + ((doublereal) (*ieg) * .25 + 1.) * (gv[vel[0]] - *
		vmin);

/* ** Try to get v= 2 using a sequentially increasing correction. */

/*             E(v=2)= E(v=1) + (0.8+IEG/4)*(E(v=1)-E(v=0)) */

    } else if (*nvel == 2) {
	*eo = gv[vel[1]] + ((doublereal) (*ieg) * .25 + .8) * (gv[vel[1]] - 
		gv[vel[0]]);

/* ** Try to get v > 2 using a sequentially increasing correction. */

/*        E(v)= E(v-1) + (1.0+IEG)*(2.0*E(v-1)-3.0*E(v-2)+E(v-3)) */

    } else {
	*eo = gv[vel[*nvel - 1]] + ((doublereal) (*ieg) + 1.) * (gv[vel[*nvel 
		- 1]] * 2. - gv[vel[*nvel - 2]] * 3. + gv[vel[*nvel - 3]]);
    }
    return 0;
} /* dteng_ */

/* 23456789 123456789 123456789 123456789 123456789 123456789 123456789 12 */
/* *********************************************************************** */
/* ***** R.J. Le Roy  subroutine SCHRQ, last updated  8 April 2007 ******* */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*                COPYRIGHT 2007  by  Robert J. Le Roy                  + */
/*   Dept. of Chemistry, Univ. of Waterloo, Waterloo, Ontario, Canada   + */
/*    This software may not be sold or any other commercial use made    + */
/*      of it without the express written permission of the author.     + */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ** SCHRQ solves radial Schrodinger equation in dimensionless form */
/*  d2WF/dR2 = - (E-V(R))*WF(R) ,  where WF(I) is the wave function. */
/* ** Integrate by Numerov method over N mesh points with increment */
/*  H=RH across range beginning at RMIN . */
/* ** Input trial energy EO, eigenvalue convergence criterion EEPS */
/*  potential asymptote VLIM, and all returned energies (EO, GAMA & VMAX) */
/*  have units (cm-1). */
/* ** On entry, the input potential V(I) must include the centrifugal */
/*  term and the factor:  'BFCT'=2*mu*(2*pi*RH/hPLANCK)**2  (1/cm-1) , */
/*  which is also internally incorporated into EO, VLIM & EEPS. */
/* * Note that these reduced quantities (& the internal eigenvalue E) */
/*  contain a factor of the squared integration increment  RH**2 . */
/*  This saves arithmetic work in the innermost loop of the algorithm. */
/* ** For energy in (cm-1), BFCT=ZMU(u)*H(Angst)**2/16.85762920 (1/cm-1) */
/* ** INNODE > 0  specifies that wavefx. initiates at RMIN with a node */
/*     (normal default case);  INNODE.le.0  spoecifies  zero slope  at */
/*     RMIN (for finding symmetric eigenfunctions of symmetric potential */
/*     with potential mid-point @ RMIN). */
/* ** INNER specifies wave function matching condition: INNER = 0  makes */
/*     matching of inward & outward solutions occur at outermost turning */
/*     point;  INNER > 0 makes matching occur at innermost turning point. */
/* * Normally use  INNER=0 ,  but to find inner-well levels of double */
/*     minimum potential, set  INNER > 0 . */
/* ---------------------------------------------------------------------- */
/* Subroutine */ int schrq_(integer *kv, integer *jrot, doublereal *eo, 
	doublereal *gama, doublereal *vmax, doublereal *vlim, doublereal *v, 
	doublereal *wf, doublereal *bfct, doublereal *eeps, doublereal *rmin, 
	doublereal *rh, integer *n, integer *nbeg, integer *nend, integer *
	innode, integer *inner, integer *iwr, integer *lprwf)
{
    /* Initialized data */

    static doublereal ratst = 1e-9;
    static doublereal xpw = 20.72;
    static integer ndn = 15;

    /* Format strings */
    static char fmt_610[] = "(/\002 Attempt to find the highest bound level "
	    "starting from\002,\002   ETRIAL =\002,1pd9.2)";
    static char fmt_601[] = "(/\002 Solve for  v=\002,i3,\002   J=\002,i3"
	    ",\002   ETRIAL=\002,1pd15.7,\002  INNER=\002,i2,\002   WF(1st) W"
	    "F(NEND)\002)";
    static char fmt_602[] = "(\002 ITER    ETRIAL\002,8x,\002F(E)      DF(E)"
	    "     D(E)\002,5x,\002M    R(M)  /WF(M)   /WF(M)  R(NEND) NBEG IT"
	    "P1\002/1x,96(\002-\002))";
    static char fmt_611[] = "(\002 *** SCHRQ inward search at   J=\002,i3"
	    ",\002   E=\002,f11.2,\002 finds no classical region\002)";
    static char fmt_618[] = "(\002 *** For  J=\002,i3,\002  E=\002,f9.2,\002"
	    "  JWKB start gives  SB/SI=\002,1pd10.3,\002  so use a node.\002)";
    static char fmt_616[] = "(\002 ** WARNING *** For  v=\002,i2,\002, J="
	    "\002,i3,\002 at  E=\002,g14.7,\002:  inward propagation finds no"
	    " turning point ... Energy too low or potential too weak\002)";
    static char fmt_613[] = "(/\002 *** ERROR in potential array ... V(I) ev"
	    "erywhere\002,\002 too big to integrate with given  increment\002)"
	    ;
    static char fmt_609[] = "(\002 *** For  J=\002,i3,\002   E=\002,1pd15.7"
	    ",\002  integration can't\002,\002 start till past mesh\002/37x"
	    ",\002point\002,i5,\002,  so RMIN smaller than needed\002)";
    static char fmt_604[] = "(\002   NOTE:  for  J=\002,i3,\002   EO=\002,f1"
	    "2.4,\002 .ge. V(\002,i3,\002)=\002,f12.4)";
    static char fmt_612[] = "(/\002 *** ERROR *** for   v =\002,i3,\002   "
	    "J =\002,i3,\002   E =\002,f12.4,\002  Innermost turning point no"
	    "t found by   M = MSAVE =\002,i5)";
    static char fmt_603[] = "(i4,1pd15.7,3d10.2,i5,0pf7.3,1p2d9.1,0pf8.2,i4,"
	    "i5)";
    static char fmt_617[] = "(\002 *** SCHRQ has a convergence problem, so f"
	    "or  IT=\002,i2,\002  cut  DE=\002,1pd10.2,\002  in HALF\002)";
    static char fmt_620[] = "(\002 *** CAUTION for  v=\002,i3,\002  J=\002,i"
	    "3,\002  SCHRQ doesn't converge by  ITER=\002,i2,\002  DE=\002,1p"
	    "d9.2)";
    static char fmt_619[] = "(1x,96(\002-\002))";
    static char fmt_614[] = "(\002 *** CAUTION *** For  J=\002,i3,\002  E"
	    "=\002,g15.8/16x,\002WF(first)/WF(Max)=\002,d9.2,\002  suggests  "
	    "RMIN  may be too large\002)";
    static char fmt_615[] = "(\002 ** CAUTION ** For  J=\002,i3,\002  E=\002"
	    ",1pd13.6,\002  WF(NEND)/WF(Max)=\002,d8.1,\002 >\002,d8.1/4x,"
	    "\002& initialization \002,\002quality test \002,1pd8.1,\002 > 1."
	    "D-3   so RMAX may be too small\002)";
    static char fmt_701[] = "(/2x,\002Level  v=\002,i3,\002   J=\002,i3,\002"
	    "   E=\002,f12.4,\002 ,  wave function at\002,i6,\002 points.\002"
	    "/7x,\002R(1-st)=\002,f12.8,\002   mesh=\002,f12.8,\002   NBEG"
	    "=\002,i4,\002   |LPRWF|=\002,i3)";
    static char fmt_702[] = "((1x,4(f9.4,f10.6)))";
    static char fmt_605[] = "(/\002 Solution of radial Schr. equation for   "
	    "E(v=\002,i3,\002,J=\002,i3,\002) =\002,f15.7/2x,4(\002    R(I)  "
	    " WF(I)   \002)/2x,38(\002--\002))";
    static char fmt_606[] = "(2x,4(f8.3,f11.7))";
    static char fmt_607[] = "(\002E(v=\002,i3,\002,J=\002,i3,\002)=\002,f11."
	    "4,1x,i3,\002 Iterations\002,\002   R(M)=\002,f6.3,\002  WF(NBEG)"
	    "/WF(M)=\002,1pd8.1/57x,\002WF(NEND)/WF(M)=\002,d8.1)";
    static char fmt_608[] = "(\002 *** SCHRQ Error:  E=\002,f9.2,\002 > V"
	    "(\002,i5,\002)=\002,f9.2,\002  at  Rmax=\002,f6.2,\002  for  IT"
	    "=\002,i2)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), exp(doublereal), log(doublereal);

    /* Local variables */
    static doublereal e, f, h__;
    static integer i__, j, m, j1, j2;
    static doublereal y1, y2, y3, de, df, gi;
    static integer ij, jj;
    static doublereal gn, sb, ht;
    static integer it;
    static doublereal fx;
    static integer ms;
    static doublereal si, sm, rr, sn, ym, dep;
    static integer ijk;
    static doublereal eps;
    static integer kkv, npr;
    static doublereal yin, vpr, xpr, rwr[20], swr[20], vmx;
    static integer itp1, itp3;
    static doublereal dold, dsoc, rinc;
    static integer icor;
    static doublereal xend;
    static integer iter;
    static doublereal prod;
    static integer kvin;
    static doublereal dxpw, rstt;
    static integer nbeg2;
    static doublereal yout;
    static integer itp1p, nbegb;
    static doublereal snend;
    static integer ipsid;
    static doublereal deprn;
    static integer msave;
    static doublereal ratin;
    extern /* Subroutine */ int width_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, doublereal *);
    static doublereal rminn, pprod;
    static integer jpsiq;
    static doublereal srtgi, srtgn;
    static integer iqtst, jqtst, ibegin, nendch;
    static doublereal spnend;
    static integer nlines;
    extern /* Subroutine */ int qbound_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, doublereal *, integer *);
    static doublereal ratout, wkbtst;

    /* Fortran I/O blocks */
    static cilist io___117 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___118 = { 0, 6, 0, fmt_601, 0 };
    static cilist io___119 = { 0, 6, 0, fmt_602, 0 };
    static cilist io___133 = { 0, 6, 0, fmt_611, 0 };
    static cilist io___138 = { 0, 6, 0, fmt_618, 0 };
    static cilist io___147 = { 0, 6, 0, fmt_616, 0 };
    static cilist io___151 = { 0, 6, 0, fmt_613, 0 };
    static cilist io___152 = { 0, 6, 0, fmt_609, 0 };
    static cilist io___153 = { 0, 6, 0, fmt_604, 0 };
    static cilist io___156 = { 0, 6, 0, fmt_612, 0 };
    static cilist io___165 = { 0, 6, 0, fmt_603, 0 };
    static cilist io___167 = { 0, 6, 0, fmt_617, 0 };
    static cilist io___168 = { 0, 6, 0, fmt_620, 0 };
    static cilist io___169 = { 0, 6, 0, fmt_619, 0 };
    static cilist io___170 = { 0, 6, 0, fmt_614, 0 };
    static cilist io___172 = { 0, 6, 0, fmt_615, 0 };
    static cilist io___183 = { 0, 10, 0, fmt_701, 0 };
    static cilist io___184 = { 0, 10, 0, fmt_702, 0 };
    static cilist io___187 = { 0, 6, 0, fmt_605, 0 };
    static cilist io___193 = { 0, 6, 0, fmt_606, 0 };
    static cilist io___194 = { 0, 6, 0, fmt_607, 0 };
    static cilist io___195 = { 0, 6, 0, fmt_607, 0 };
    static cilist io___198 = { 0, 6, 0, fmt_608, 0 };


/* ---------------------------------------------------------------------- */
/* ** Output vibrational quantum number KV, eigenvalue EO, normalized */
/*  wave function WF(I), and range, NBEG .le. I .le. NEND  over */
/*  which WF(I) is defined. *** Have set  WF(I)=0  outside this range. */
/* * (NBEG,NEND), defined by requiring  abs(WF(I)) < RATST=1.D-9  outside. */
/* ** If(LPRWF.gt.0) print wavefunction WF(I) every LPRWF-th point. */
/* * If(LPRWF.lt.0) "punch" (i.e., WRITE(10,XXX)) every |LPRWF|-th point */
/*  of the wave function on disk starting at R(NBEG) with step size */
/*  of  IPSIQ=|LPRWF|*RH. */
/* ** For energies above the potential asymptote VLIM, locate quasibound */
/*  levels using Airy function boundary condition and return the level */
/*  width GAMA and barrier height VMAX, as well as EO. */
/* ** ERROR condition on return is  KV < 0 ; usually KV=-1, but return */
/*  KV=-2 if error appears to arise from too low trial energy. */
/* ** If(IWR.ne.0) print error & warning descriptions */
/*  If (IWR.gt.0) also print final eigenvalues & node count. */
/*  If (IWR.ge.2) also show end-of-range wave function amplitudes */
/*  If (IWR.ge.3) print also intermediate trial eigenvalues, etc. */
/* ** If input KV.ge.998 , tries to find highest bound level, and */
/*  trial energy should be only slightly less than VLIM. */
/* ** If input KV < -10 , use log-derivative outer boundary condition at */
/*  mesh point |KV| , based on incoming value of wave function WF(|KV|) */
/*  and of the wavefunction derivative at that point, SPNEND, which is */
/*  brought in as WF(|KV|-1).  For a hard wall condition at mesh point */
/*  |KV|, set WF(|KV|)=0 and WF(|KV|-1)= -1 before entry. */
/* ---------------------------------------------------------------------- */
/* ++ "SCHRQ" calls subroutineas "QBOUND" and "WIDTH", and the latter */
/* ++ calls "LEVQAD" . */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
    /* Parameter adjustments */
    --wf;
    --v;

    /* Function Body */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
    dxpw = (xpw + 2.3) / ndn;
    icor = 0;
    kvin = *kv;
    *kv = -1;
    rminn = *rmin - *rh;
    *gama = 0.;
    *vmax = *vlim;
    vmx = *vmax * *bfct;
    h__ = *rh;
    ht = .083333333333333329;
    e = *eo * *bfct;
    eps = *eeps * *bfct;
    dsoc = *vlim * *bfct;
    de = 0.;
    ratin = 0.;
    ratout = 0.;
    if (*iwr > 2) {
	if (kvin >= 998) {
	    s_wsfe(&io___117);
	    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else {
	    s_wsfe(&io___118);
	    do_fio(&c__1, (char *)&kvin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*inner), (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	s_wsfe(&io___119);
	e_wsfe();
    }
    *nend = *n;
    if (kvin < -10) {
	*nend = -kvin;
	snend = wf[*nend];
	spnend = wf[*nend - 1];
    }
    jqtst = 0;
/* ** Start iterative loop; try to converge for up to 15 iterations. */
    for (it = 1; it <= 15; ++it) {
	iter = it;
	if (*inner > 0) {
	    goto L38;
	}
L10:
	if (kvin < -10) {
/* ** If desired, (KVIN < -10) outer boundary set at NEND=|KVIN| and */
/*  initialize wavefunction with log-derivative condition based on value */
/*  WF(NEND) & derivative SPNEND at that mesh point (brought in in CALL) */
	    gn = v[*nend] - e;
	    gi = v[*nend - 1] - e;
	    sb = snend;
	    si = sb * (gn * .5 + 1.) - *rh * spnend;
	    goto L24;
	}
	if (e >= dsoc) {
/* ** For quasibound levels, initialize wave function in "QBOUND" */
	    qbound_(&kvin, jrot, &e, eo, &vmx, &dsoc, &v[1], rmin, &h__, &gn, 
		    &gi, &sb, &si, n, &itp3, iwr, &iqtst, bfct, &it);
	    *nend = itp3;
	    *vmax = vmx / *bfct;
	    if (iqtst > 0) {
		goto L24;
	    }
	    if (iqtst < 0) {
		jqtst += iqtst;
		if (jqtst <= -2 || *vmax < *vlim) {
		    goto L999;
		}
/* ** Try up to once to find level using trial value just below maximum */
		*eo = *vmax - .1;
		e = *eo * *bfct;
		goto L90;
	    }
	    goto L20;
	}
/* ** For  E < DSOC  begin inward integration by using JWKB to estimate */
/*  optimum (minimum) inward starting point which will still give */
/*  RATOUT < RATST = exp(-XPW) (ca. 1.d-9) [not needed after 1'st 2 ITER] */
	if (iter <= 2) {
	    *nend = *n;
/* ... first do rough inward search for outermost turning point */
	    i__1 = -ndn;
	    for (m = *n; i__1 < 0 ? m >= 1 : m <= 1; m += i__1) {
		ms = m;
		gi = v[m] - e;
		if (gi <= 0.) {
		    goto L12;
		}
		gn = gi;
	    }
	    if (*iwr != 0) {
		s_wsfe(&io___133);
		do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    goto L999;
L12:
	    if (ms >= *n) {
		goto L998;
	    }
	    fx = gn / (gi - gn);
	    sm = (fx + 1.) * .5 * sqrt(gn);
	    ms += ndn << 1;
	    if (ms >= *n) {
		goto L20;
	    }
/* ... now integrate exponent till JWKB wave fx. would be negligible */
	    i__1 = *n;
	    i__2 = ndn;
	    for (m = ms; i__2 < 0 ? m >= i__1 : m <= i__1; m += i__2) {
		*nend = m;
		sm += sqrt(v[m] - e);
		if (sm > dxpw) {
		    goto L18;
		}
	    }
L18:
	    if (*nend < *n) {
		*nend += ndn;
	    }
	}
/* ** For truly bound state initialize wave function as 1-st order WKB */
/*   solution increasing inward */
L20:
	gn = v[*nend] - e;
	gi = v[*nend - 1] - e;
	ms = *nend - 1;
	if (gi < 0.) {
	    goto L998;
	}
	srtgn = sqrt(gn);
	srtgi = sqrt(gi);
	sb = 1.;
	si = sb * sqrt(srtgn / srtgi) * exp((srtgn + srtgi) * .5);
	if (sb > si) {
/* WOOPS - JWKB gives inward DEcreasing solution, so initialize with node */
	    if (*iwr != 0) {
		s_wsfe(&io___138);
		do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
		d__1 = sb / si;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    si = 1.;
	    sb = 0.;
	}
L24:
	m = *nend - 1;
	y1 = (1. - ht * gn) * sb;
	y2 = (1. - ht * gi) * si;
	wf[*nend] = sb;
	wf[*nend - 1] = si;
	ms = *nend;
	nendch = *nend;
	ibegin = 3;
	if (*inner > 0) {
	    ibegin = itp1 + 2;
	}
/* ** Actual inward integration loop starts here */
	i__2 = *nend;
	for (i__ = ibegin; i__ <= i__2; ++i__) {
	    --m;
	    y3 = y2 + y2 - y1 + gi * si;
	    gi = v[m] - e;
	    sb = si;
	    si = y3 / (1. - ht * gi);
	    wf[m] = si;
	    if (abs(si) >= 1e17) {
/* ** Renormalize to prevent overflow of  WF(I)  in classically */
/*  forbidden region where  (V(I) .gt. E) */
		si = 1. / si;
		i__1 = ms;
		for (j = m; j <= i__1; ++j) {
		    wf[j] *= si;
		}
		nendch = ms;
		ms = m;
		y2 *= si;
		y3 *= si;
		sb *= si;
		si = 1.;
	    }
	    y1 = y2;
	    y2 = y3;
/* ** Test for outermost maximum of wave function. */
/* ... old matching condition - turning point works OK & is simpler. */
/* c            IF((INNER.EQ.0).AND.(SI.LE.SB)) GO TO 32 */
/* ** Test for outer well turning point */
	    if (*inner == 0 && gi < 0.) {
		goto L32;
	    }
	}
	if (*inner == 0) {
/* ** Error mode ... inward propagation finds no turning point */
	    *kv = -2;
	    if (*iwr != 0) {
		s_wsfe(&io___147);
		do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    goto L999;
	}
/* ** Scale outer part of wave function before proceding */
L32:
	si = 1. / si;
	msave = m;
	rr = rminn + msave * h__;
	yin = y1 * si;
	ratout = wf[*nend] * si;
	*nend = nendch;
	i__2 = *nend;
	for (j = msave; j <= i__2; ++j) {
	    wf[j] *= si;
	}
	if (*inner > 0) {
	    goto L70;
	}
/* ------------------------------------------------------------------- */
/* ** Set up to prepare for outward integration ********************** */
L38:
	*nbeg = 1;
	if (*innode <= 0) {
/* ** Option to initialize with zero slope at beginning of the range */
	    sb = 1.;
	    gn = v[1] - e;
	    y1 = sb * (1. - ht * gn);
	    y2 = y1 + gn * sb * .5;
	    gi = v[2] - e;
	    si = y2 / (1. - ht * gi);
	} else {
/* ** Initialize outward integration with a node at beginning of range */
L40:
	    gn = v[*nbeg] - e;
	    if (gn > 10.) {
/* ** If potential has [V(1)-E] so high that H is (locally) much too */
/*  large, then shift inner starting point outward. */
		++(*nbeg);
		if (*nbeg < *n) {
		    goto L40;
		}
		if (*iwr != 0) {
		    s_wsfe(&io___151);
		    e_wsfe();
		}
		goto L999;
	    }
	    if (iter <= 1 && *iwr != 0) {
		if (*nbeg > 1) {
		    s_wsfe(&io___152);
		    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&(*nbeg), (ftnlen)sizeof(integer));
		    e_wsfe();
		}
		if (gn <= 0.) {
		    s_wsfe(&io___153);
		    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&(*nbeg), (ftnlen)sizeof(integer));
		    d__1 = v[*nbeg] / *bfct;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    e_wsfe();
		}
	    }
/* ** Initialize outward wave function with a node:  WF(NBEG) = 0. */
	    sb = 0.;
	    si = 1.;
	    gi = v[*nbeg + 1] - e;
	    y1 = sb * (1. - ht * gn);
	    y2 = si * (1. - ht * gi);
	}

	wf[*nbeg] = sb;
	wf[*nbeg + 1] = si;
	nbegb = *nbeg;
	nbeg2 = *nbeg + 2;
	if (*inner > 0) {
	    msave = *n;
	}
/* ** Actual outward integration loops start here */
	i__2 = msave;
	for (i__ = nbeg2; i__ <= i__2; ++i__) {
	    y3 = y2 + y2 - y1 + gi * si;
	    gi = v[i__] - e;
	    si = y3 / (1. - ht * gi);
	    wf[i__] = si;
	    if (abs(si) >= 1e17) {
/* ** Renormalize to prevent overflow of  WF(I)  in classically forbidden */
/*  region where  V(I) .gt. E */
		si = 1. / si;
		*nbeg = nbegb;
		i__1 = i__;
		for (j = *nbeg; j <= i__1; ++j) {
		    wf[j] *= si;
		}
		nbegb = i__;
		y2 *= si;
		y3 *= si;
		si = 1.;
	    }
	    y1 = y2;
	    y2 = y3;
	    itp1 = i__;
/* ** Exit from this loop at onset of classically allowed region */
	    if (gi <= 0.) {
		goto L52;
	    }
	}
	ms = msave;
	if (*inner == 0 && gn <= 0.) {
	    goto L60;
	}
	if (*iwr != 0) {
	    s_wsfe(&io___156);
	    do_fio(&c__1, (char *)&kvin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&msave, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	goto L999;
L52:
	itp1p = itp1 + 1;
	ms = itp1;
	if (*inner > 0) {
	    goto L60;
	}
	i__2 = msave;
	for (i__ = itp1p; i__ <= i__2; ++i__) {
	    y3 = y2 + y2 - y1 + gi * si;
	    gi = v[i__] - e;
	    si = y3 / (1. - ht * gi);
	    wf[i__] = si;
	    if (abs(si) > 1e17) {
/* ** Renormalize to prevent overflow of  WF(I) , as needed. */
		si = 1. / si;
		*nbeg = nbegb;
		i__1 = i__;
		for (j = *nbeg; j <= i__1; ++j) {
		    wf[j] *= si;
		}
		nbegb = i__;
		y2 *= si;
		y3 *= si;
		si = 1.;
	    }
	    y1 = y2;
	    y2 = y3;
	}
	ms = msave;
/* ** Finished outward integration.  Normalize w.r.t. WF(MSAVE) */
L60:
	si = 1. / si;
	yout = y1 * si;
	ym = y2 * si;
	ratin = wf[*nbeg + 1] * si;
	i__2 = ms;
	for (i__ = *nbeg; i__ <= i__2; ++i__) {
	    wf[i__] *= si;
	}
	if (*inner > 0) {
	    goto L10;
	}
/* ----- Finished numerical integration ... now correct trial energy */
/* ** DF*H  is the integral of  (WF(I))**2 dR */
L70:
	df = 0.;
	i__2 = *nend;
	for (j = *nbeg; j <= i__2; ++j) {
/* Computing 2nd power */
	    d__1 = wf[j];
	    df += d__1 * d__1;
	}
/* ** Add edge correction to DF assuming wave function dies off as simple */
/*  exponential past R(NEND);  matters only if WF(NEND) unusually large. */
	if (e <= dsoc && wf[*nend] != 0.) {
	    if (kvin >= -10 && wf[*nend - 1] / wf[*nend] > 1.) {
/* Computing 2nd power */
		d__1 = wf[*nend];
		df += d__1 * d__1 / (log(wf[*nend - 1] / wf[*nend]) * 2.);
	    }
	}
	f = -yout - yin + ym * 2. + gi;
	dold = de;
	if (abs(f) <= 1e30) {
	    de = f / df;
	} else {
	    f = 9.9e30;
	    df = f;
	    de = (d__1 = (dsoc - e) * .01, abs(d__1));
	}
	if (*iwr > 2) {
	    deprn = de / *bfct;
	    xend = rminn + *nend * h__;
/* ** RATIN & RATOUT  are wave fx. amplitude at inner/outer ends of range */
/*  relative to its value at outermost extremum. */
	    s_wsfe(&io___165);
	    do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&df, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&deprn, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&msave, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&rr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ratin, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ratout, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xend, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*nbeg), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&itp1, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* ** Test trial eigenvalue for convergence */
	if (abs(de) <= abs(eps)) {
	    goto L100;
	}
	e += de;
/* ** KV.ge.998  Option ... Search for highest bound level.  Adjust new */
/*  trial energy downward if it would have been above dissociation. */
	if (kvin >= 998 && e > vmx) {
	    e = vmx - (vmx - e + de) * 2.;
	}
	*eo = e / *bfct;
	if (it > 4 && abs(de) >= abs(dold) && dold * de <= 0.) {
/* ** Adjust energy increment if having convergence difficulties.  Not */
/*  usually needed except for some quasibounds extremely near  VMAX . */
	    ++icor;
	    dep = de / *bfct;
	    if (*iwr != 0) {
		s_wsfe(&io___167);
		do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&dep, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    de *= .5;
	    e -= de;
	    *eo = e / *bfct;
	}
L90:
	;
    }
/* ** End of iterative loop which searches for eigenvalue ************ */
/* -------------------------------------------------------------------* */
/* ** Convergence fails, so return in error condition */
    e -= de;
    *eo = e / *bfct;
    deprn = de / *bfct;
    if (*iwr != 0) {
	s_wsfe(&io___168);
	do_fio(&c__1, (char *)&kvin, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&deprn, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    goto L999;
L100:
    if (*iwr != 0) {
	if (*iwr >= 3) {
	    s_wsfe(&io___169);
	    e_wsfe();
	}
	if (abs(ratin) > ratst && *innode > 0 && *rmin > 0.) {
	    s_wsfe(&io___170);
	    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ratin, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (e < dsoc && abs(ratout) > ratst) {
/* Computing 3rd power */
	    d__2 = v[*nend] - e;
	    wkbtst = (d__1 = v[*nend] - v[*nend - 1], abs(d__1)) * .5 / sqrt(
		    d__2 * (d__2 * d__2));
	    if (wkbtst > .001) {
		s_wsfe(&io___172);
		do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&ratout, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&ratst, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&wkbtst, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	}
    }
    kkv = 0;
/* ** Perform node count on converged solution */
    prod = wf[itp1] * wf[itp1 - 1];
    j1 = itp1 + 1;
    j2 = *nend - 1;
    i__2 = j2;
    for (j = j1; j <= i__2; ++j) {
	pprod = prod;
	prod = wf[j] * wf[j - 1];
	if (pprod <= 0. && prod > 0.) {
	    ++kkv;
	}
    }
    *kv = kkv;
/* ** Normalize & find interval (NBEG,NEND) where WF(I) is non-negligible */
    sn = 1. / sqrt(h__ * df);
    i__2 = *nend;
    for (i__ = *nbeg; i__ <= i__2; ++i__) {
	wf[i__] *= sn;
    }
    if (itp1 <= 1) {
	goto L122;
    }
    j = itp1p;
    i__2 = itp1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	--j;
	if ((d__1 = wf[j], abs(d__1)) < ratst) {
	    goto L119;
	}
    }
L119:
    *nbeg = j;
    if (*nbeg <= 1) {
	goto L122;
    }
    --j;
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
	wf[i__] = 0.;
    }
L122:
    if (kvin >= -10) {
/* ** For "non-wall" cases, move NEND inward to where wavefunction */
/*  "non-negligible" */
	j = *nend - 1;
	i__2 = *nend;
	for (i__ = *nbeg; i__ <= i__2; ++i__) {
	    if ((d__1 = wf[j], abs(d__1)) > ratst) {
		goto L126;
	    }
	    --j;
	}
L126:
	*nend = j + 1;
    }
    if (*nend < *n) {
/* ** Zero out wavefunction array at distances past NEND */
	i__2 = *n;
	for (i__ = *nend + 1; i__ <= i__2; ++i__) {
	    wf[i__] = 0.;
	}
    }
    if (*lprwf < 0) {
/* ** If desired, write every |LPRWF|-th point of the wave function */
/*  to a file on channel-10, starting at the NBEG-th mesh point. */
	jpsiq = -(*lprwf);
	npr = (*nend - *nbeg) / jpsiq + 1;
	rinc = *rh * jpsiq;
	rstt = rminn + *nbeg * *rh;
/* ** Write every JPSIQ-th point of the wave function for level  v=KV */
/*  J=JROT , beginning at mesh point NBEG & distance RSTT where */
/*  the NPR values written separated by mesh step RINC=JPSIQ*RH */
	s_wsfe(&io___183);
	do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&npr, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rstt, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rinc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*nbeg), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jpsiq, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___184);
	i__2 = *nend;
	i__1 = jpsiq;
	for (i__ = *nbeg; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) {
	    d__1 = rminn + i__ * *rh;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&wf[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	goto L140;
    }
/* ** Print solutions every  LPRWF-th  point, 6 to a line, in columns. */
    if (*lprwf > 0) {
	nlines = ((*nend - *nbeg) / *lprwf + 4) / 4;
	ipsid = *lprwf * nlines;
	s_wsfe(&io___187);
	do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	e_wsfe();
	i__1 = nlines;
	for (j = 1; j <= i__1; ++j) {
	    jj = *nbeg + (j - 1) * *lprwf;
	    ijk = 0;
	    i__2 = *nend;
	    i__3 = ipsid;
	    for (ij = jj; i__3 < 0 ? ij >= i__2 : ij <= i__2; ij += i__3) {
		++ijk;
		rwr[ijk - 1] = rminn + ij * h__;
		swr[ijk - 1] = wf[ij];
	    }
	    s_wsfe(&io___193);
	    i__3 = ijk;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		do_fio(&c__1, (char *)&rwr[i__ - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&swr[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
    }
L140:
    if (*iwr == 1) {
	s_wsfe(&io___194);
	do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* c */
/* c    IF(IWR.NE.0) WRITE(6,699)  rminn+itp1*rh,eO,rminn+msave*rh,eo */
/* c699 format('    & turning points:',2(f8.5,f11.4)) */
/* c */
    if (*iwr >= 2) {
	s_wsfe(&io___195);
	do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ratin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ratout, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* ** For quasibound levels, calculate width in subroutine "WIDTH" */
    if (e > dsoc && kvin > -10) {
	width_(kv, jrot, &e, eo, &dsoc, &v[1], &wf[1], &vmx, rmin, &h__, bfct,
		 iwr, &itp1, &itp3, inner, n, gama);
    }
    return 0;
/* ** ERROR condition if  E.gt.V(R)  at outer end of integration range. */
L998:
    xpr = rminn + ms * h__;
    vpr = v[ms] / *bfct;
    if (*iwr != 0) {
	s_wsfe(&io___198);
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ms, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vpr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xpr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	e_wsfe();
    }
/* ** Return in error mode */
L999:
    *kv = -1;
    return 0;
} /* schrq_ */

/* 23456789 123456789 123456789 123456789 123456789 123456789 123456789 12 */
/* ******************************************************************* */
/* Subroutine */ int qbound_(integer *kv, integer *jrot, doublereal *e, 
	doublereal *eo, doublereal *vmx, doublereal *dsoc, doublereal *v, 
	doublereal *rmin, doublereal *h__, doublereal *gb, doublereal *gi, 
	doublereal *sb, doublereal *si, integer *n, integer *itp3, integer *
	iwr, integer *iqtst, doublereal *bfct, integer *it)
{
    /* Initialized data */

    static doublereal c1a = .355028053887817;
    static doublereal c2a = .258819403792807;

    /* Format strings */
    static char fmt_608[] = "(\002 For J=\002,i3,\002  ETRY=\002,f11.4,\002 "
	    "> VMAX=\002,f11.4,\002  find onee turn point:  R=\002,f6.2)";
    static char fmt_606[] = "(\002 *** CAUTION ***  v=\002,i3,\002   J=\002,"
	    "i3,\002   E=\002,1pd13.6,\002   IT=\002,i2/5x,\002Airy initializ"
	    "ation unstable so use  zero slope\002,\002at  R(3-rd)\002)";
    static char fmt_607[] = "(\002 *** For  J=\002,i3,\002  E=\002,f9.2,\002"
	    "  R(3-rd) > RMAX  & E < V(N)  so try WKB B.C. @ RMAX\002)";
    static char fmt_604[] = "(\002 **** QBOUND doesn't work ... no classical"
	    "ly allowed region accessible at this energy.\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k;
    static doublereal a1, a2, a13, a23, df, fj;
    static integer ii;
    static doublereal sl, xj1, fba, gba, fia, gia, rminn, vmxpr;

    /* Fortran I/O blocks */
    static cilist io___208 = { 0, 6, 0, fmt_608, 0 };
    static cilist io___220 = { 0, 6, 0, fmt_606, 0 };
    static cilist io___221 = { 0, 6, 0, fmt_607, 0 };
    static cilist io___222 = { 0, 6, 0, fmt_604, 0 };


/* ******************************************************************* */
/* ** Subroutine to initialize quasibound level wave function as Airy */
/*  function at third turning point (if possible). For the theory see */
/*  J.Chem.Phys. 54, 5114 (1971),  J.Chem.Phys. 69, 3622-31 (1978) */
/* ---------------------------------------------------------------------- */
/* ** IQTST  is error flag. *** If (IQTST.lt.0) initialization fails */
/*  so eigenvalue calculation aborts *** (IQTST.gt.0) for successful */
/*  Airy function initialization. *** (IQTST=0) if Airy function */
/*  initialization prevented because 3-rd turning point beyond */
/*  range, so that WKB initialization is used. */
/* ---------------------------------------------------------------------- */
    /* Parameter adjustments */
    --v;

    /* Function Body */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
    *iqtst = 1;
    rminn = *rmin - *h__;
/* ** Start by searching for third turning point. */
    j = *n;
    if (v[*n] > *e) {
	goto L22;
    }
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	--j;
	if (v[j] > *e) {
	    goto L10;
	}
    }
    goto L14;
/* ** Check that there is a classically allowed region inside this point */
/*  and determine height of barrier maximum. */
L10:
    ii = j;
    *vmx = *dsoc;
    i__1 = j;
    for (i__ = 2; i__ <= i__1; ++i__) {
	--ii;
	if (v[ii] <= *e) {
	    goto L16;
	}
	if (v[ii] > *vmx) {
	    *vmx = v[ii];
	}
    }
/* ** Energy too high ... find no more than one turning point. */
L14:
    xj1 = rminn + j * *h__;
/* ... Search outward for barrier height to facilitate energy correction */
    if (j == 1) {
	j = 2;
    }
    k = j - 1;
    i__1 = *n;
    for (i__ = j; i__ <= i__1; ++i__) {
	if (v[i__] > v[k]) {
	    goto L120;
	}
	k = i__;
    }
    *vmx = v[k];
    goto L130;
L120:
    k += 2;
    j = k - 1;
    i__1 = *n;
    for (i__ = k; i__ <= i__1; ++i__) {
	if (v[i__] < v[j]) {
	    goto L126;
	}
	j = i__;
    }
L126:
    *vmx = v[j];
L130:
    vmxpr = *vmx / *bfct;
    if (*iwr != 0) {
	s_wsfe(&io___208);
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vmxpr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xj1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    *itp3 = j;
    *iqtst = -1;
    goto L100;
L16:
    *itp3 = j + 1;
/* ** ITP3 is the first mesh point outside classically forbidden region */
    *gb = v[*itp3] - *e;
    *gi = v[*itp3 - 1] - *e;
    fj = *gi / (*gi - *gb);
/* ** Treat quasibound levels as bound using outer boundary condition */
/*  of Airy function at third turning point ... as discussed by */
/*  R.J.Le Roy and R.B.Bernstein  in  J.Chem.Phys. 54,5114(1971). */
    d__1 = *gi - *gb;
    sl = pow_dd(&d__1, &c_b317) / *h__;
    if (sl * *h__ < 1.) {
/* Computing 2nd power */
	d__1 = sl * *h__;
	a1 = *gi / (d__1 * d__1);
/* Computing 2nd power */
	d__1 = sl * *h__;
	a2 = *gb / (d__1 * d__1);
	a13 = a1 * a1 * a1;
	a23 = a2 * a2 * a2;
	fia = a13 * (a13 * (a13 + 72.) + 2160.) / 12960. + 1.;
	gia = a1 + a1 * a13 * (a13 * (a13 + 90.) + 3780.) / 45360.;
	fba = a23 * (a23 * (a23 + 72.) + 2160.) / 12960. + 1.;
	gba = a2 + a2 * a23 * (a23 * (a23 + 90.) + 3780.) / 45360.;
/* ** Airy function  Bi(X)  at points straddling 3-rd turning point */
	*si = c1a * fia + c2a * gia;
	*sb = c1a * fba + c2a * gba;
	goto L100;
    }
/* ** If Airy function expansion unreliable, use zero slope at third */
/*  turning point as quasibound outer boundary condition. */
    df = *gi - *gb;
/* Computing 3rd power */
    d__1 = fj;
    *si = df * (d__1 * (d__1 * d__1)) / 6. + 1.;
/* Computing 3rd power */
    d__1 = 1. - fj;
    *sb = 1. - df * (d__1 * (d__1 * d__1)) / 6.;
    if (*iwr != 0) {
	s_wsfe(&io___220);
	do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*it), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    goto L100;
/* ** If 3-rd turning point beyond range start with WKB wave function */
/*  at end of range. */
L22:
    if (*iwr != 0) {
	s_wsfe(&io___221);
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    *itp3 = *n;
    *iqtst = 0;
    *gb = v[*itp3] - *e;
    *gi = v[*itp3 - 1] - *e;
    *vmx = v[*itp3];
    ii = *itp3;
    i__1 = *itp3;
    for (i__ = 2; i__ <= i__1; ++i__) {
	--ii;
	if (v[ii] < *vmx) {
	    goto L100;
	}
	*vmx = v[ii];
    }
    if (*iwr != 0) {
	s_wsfe(&io___222);
	e_wsfe();
    }
/* ** End of quasibound level initialization schemes. */
    *iqtst = -9;
L100:
    return 0;
} /* qbound_ */

/* 23456789 123456789 123456789 123456789 123456789 123456789 123456789 12 */
/* *********************************************************************** */
/* ** Subroutine to calculates quasibound level tunneling lifetime/width */
/* ** For relevant theory see Le Roy & Liu [J.Chem.Phys.69,3622-31(1978)] */
/*  and Connor & Smith [Mol.Phys. 43, 397 (1981)] and Huang & Le Roy */
/*  [J.Chem.Phys. 119, 7398 (2003); Erratum, ibid, 127, xxxx (2007)] */
/* ** Final level width calculation from Eq.(4.5) of Connor & Smith. */
/*  Rearranged slightly for consistency with PotFit derivatives 9/05/02 */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int width_(integer *kv, integer *jrot, doublereal *e, 
	doublereal *eo, doublereal *dsoc, doublereal *v, doublereal *s, 
	doublereal *vmx, doublereal *rmin, doublereal *h__, doublereal *bfct, 
	integer *iwr, integer *itp1, integer *itp3, integer *inner, integer *
	n, doublereal *gama)
{
    /* Initialized data */

    static doublereal pi = 3.141592653589793;
    static char lwell[5*2] = "INNER" "OUTER";

    /* Format strings */
    static char fmt_602[] = "(\002 *** WARNING ***  For   v =\002,i3,\002   "
	    "J =\002,i3,\002   cannot calculate width since barrier maximum b"
	    "eyond range\002)";
    static char fmt_603[] = "(\002 *** For  J=\002,i3,\002  E=\002,f9.2,\002"
	    "  R(3-rd) beyond range so tunneling calculation uses\002/8x,\002"
	    "pure centrifugal potential with  J(app)=\002,f7.2,\002  for  R >"
	    " R(max)=\002,f7.2)";
    static char fmt_609[] = "(\002 *** CAUTION - Permeability estimate not e"
	    "xact as have a double-humped barrier:  E(v=\002,i3,\002, J=\002,"
	    "i3,\002) =\002,g15.8,i6)";
    static char fmt_610[] = "(16x,\002(NOTE: this has the node count of a   "
	    "v=\002,i3,2x,a5,\002-well level\002)";
    static char fmt_605[] = "(\002 **** CAUTION *** Width estimate only qual"
	    "itative, as have a double-minimum well for   E(v=\002,i3,\002, J="
	    "\002,i3,\002)=\002,f15.7/15x,\002a more stable result may be obt"
	    "ained by searching for the quasibound levels using option: INNER"
	    " > 0 .\002)";
    static char fmt_601[] = "(\002    Lifetime=\002,1pd10.3,\002(s)   Width"
	    "=\002,d10.3,\002   dG/dv=\002,0pf7.2,\002   V(max)=\002,f9.2)";
    static char fmt_611[] = "(12x,\002Log10(lifetime/sec)=\002,f10.5,\002 ; "
	    "  Log10(width/cm-1)=\002,f10.5,\002   Spacing=\002,g12.5,\002   "
	    "V(max)=\002,g14.7,\002(cm-1)\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double log(doublereal), d_sign(doublereal *, doublereal *), exp(
	    doublereal), d_lg10(doublereal *);

    /* Local variables */
    static integer i__, m;
    static doublereal d1, d2, d3, g1, g2, g3, h2;
    static integer m2;
    static doublereal u1, u2, ga;
    static integer nn;
    static doublereal ti, sm, xj, rt, xx, rt1, rt2, dfi, arg, hbw;
    static integer imm;
    static doublereal cor;
    static integer irm;
    static doublereal emv;
    static integer kvi;
    static doublereal tau;
    static integer kvo, nst;
    static doublereal pmx, rmx, ans1, ans2;
    static integer itp2;
    static doublereal tun0, dsgb, dweb, hbwb, emsc, dsgn, vmax;
    static integer itp2m, itp1p;
    static doublereal taulg;
    static integer itp2m2, itp1p1, itp2p1, itp2p2;
    static doublereal rminn, gamalg, omegjc;
    extern /* Subroutine */ int levqad_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);

    /* Fortran I/O blocks */
    static cilist io___246 = { 0, 6, 0, fmt_602, 0 };
    static cilist io___251 = { 0, 6, 0, fmt_603, 0 };
    static cilist io___252 = { 0, 6, 0, fmt_609, 0 };
    static cilist io___257 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___258 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___270 = { 0, 6, 0, fmt_605, 0 };
    static cilist io___283 = { 0, 6, 0, fmt_601, 0 };
    static cilist io___286 = { 0, 6, 0, fmt_611, 0 };


/* ++ "WIDTH" calls subroutine "LEVQAD" ++++++++++++++++++++++++++++++++++ */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
    /* Parameter adjustments */
    --s;
    --v;

    /* Function Body */
    rminn = *rmin - *h__;
    h2 = *h__ * *h__;
/* ** ITP1 is first mesh point to right of innermost turning point. */
L40:
    itp1p = *itp1 + 1;
    itp1p1 = itp1p + 1;
    irm = *itp1 - 1;
/* ** Calculate JWKB tunneling probability from quadrature over barrier */
/* ** First must locate 2-nd turning point. */
    i__1 = *itp3;
    for (i__ = itp1p1; i__ <= i__1; ++i__) {
	itp2 = i__;
	if (v[i__] > *e) {
	    goto L202;
	}
    }
    *gama = 0.;
    goto L250;
L202:
    itp2p1 = itp2 + 1;
    itp2p2 = itp2 + 2;
/* ** ITP2M is the last mesh point before the 2-nd turning point. */
    itp2m = itp2 - 1;
    itp2m2 = itp2 - 2;
    g1 = v[itp2m] - *e;
    g2 = v[itp2] - *e;
    ga = v[itp2p1] - *e;
/* ** Quadrature over barrier starts here. */
    levqad_(&g1, &g2, &ga, h__, &rt, &ans1, &ans2);
    sm = ans2 / *h__;
    if (ga < 0.) {
	goto L218;
    }
    sm += sqrt(ga) * .5;
    pmx = *vmx;
    m2 = itp2p2;
L204:
    i__1 = *itp3;
    for (i__ = m2; i__ <= i__1; ++i__) {
	m = i__;
	ga = v[i__] - *e;
	if (v[i__] > pmx) {
	    pmx = v[i__];
	}
	if (ga < 0.) {
	    goto L210;
	}
	sm += sqrt(ga);
    }
    if (v[m] > v[m - 1]) {
	if (*iwr != 0) {
	    s_wsfe(&io___246);
	    do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	goto L250;
    }
    rmx = rminn + m * *h__;
    u1 = sqrt(ga / (v[m] - *dsoc));
    u2 = sqrt((*e - *dsoc) / (v[m] - *dsoc));
    sm = sm - sqrt(ga) * .5 + (log((u1 + 1.) / u2) - u1) * rmx * sqrt(v[m] - *
	    dsoc) / *h__;
/* Computing 2nd power */
    d__1 = rmx / *h__;
    xj = (sqrt((v[m] - *dsoc) * 4. * (d__1 * d__1) + 1.) - 1.) * .5;
    if (*iwr != 0) {
	s_wsfe(&io___251);
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xj, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rmx, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    goto L218;
L210:
    if (m < *itp3) {
/* ** If encounter a double-humped barrier, take care here. */
	if (*iwr != 0) {
	    s_wsfe(&io___252);
	    do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&m, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	kvo = 0;
	dsgn = d_sign(&c_b353, &s[m - 1]);
/* ** Find the effective quantum number for the outer well */
	i__1 = *itp3;
	for (i__ = m; i__ <= i__1; ++i__) {
	    dsgb = dsgn;
	    dsgn = d_sign(&c_b353, &s[i__]);
	    if (dsgn * dsgb < 0.) {
		++kvo;
	    }
	}
	kvi = *kv - kvo;
	if (*inner == 0) {
/* ** For levels of outer well, get correct width by changing ITP1 */
	    *itp1 = m;
	    if (*iwr > 0) {
		s_wsfe(&io___257);
		do_fio(&c__1, (char *)&kvo, (ftnlen)sizeof(integer));
		do_fio(&c__1, lwell + 5, (ftnlen)5);
		e_wsfe();
	    }
	    goto L40;
	}
	if (*iwr > 0) {
	    s_wsfe(&io___258);
	    do_fio(&c__1, (char *)&kvi, (ftnlen)sizeof(integer));
	    do_fio(&c__1, lwell, (ftnlen)5);
	    e_wsfe();
	}
/* ** For "inner-well" levels, locate outer barrier */
	i__1 = *itp3;
	for (i__ = m; i__ <= i__1; ++i__) {
	    m2 = i__;
	    ga = v[i__] - *e;
	    if (ga >= 0.) {
		goto L204;
	    }
	}
	goto L218;
    }
    g3 = v[m - 2] - *e;
    g2 = v[m - 1] - *e;
    levqad_(&ga, &g2, &g3, h__, &rt, &ans1, &ans2);
    sm = sm - sqrt(g3) * .5 - sqrt(g2) + ans2 / *h__;
L218:
    emsc = -sm / pi;
    if (*inner > 0) {
	*vmx = pmx;
    }
    vmax = *vmx / *bfct;
/* ** Tunneling factors calculated here ** TUN0 is simple WKB result */
/*  as in Child's eqs.(57c) & (59). */
/* .....  EPSRJ= -2.* PI* EMSC */
    tun0 = exp(pi * 2. * emsc) * .5;
/* ... for permeability calculate Connor-Smith's Eq.(3.7) \omega=OMEGJC */
    omegjc = sqrt(tun0 * 2. + 1.) - 1.;
/* ... alternate calculation to give better precision for small TUN0 */
    if (tun0 < 1e-5) {
	omegjc = tun0 * (1. - tun0 * .5 * (1. - tun0));
    }
    omegjc = omegjc * 4. / (omegjc + 2.);
/* ** Quadrature for JWKB calculation of vibrational spacing in well HBW */
    d1 = *e - v[irm];
    d2 = *e - v[*itp1];
    d3 = *e - v[itp1p];
    levqad_(&d1, &d2, &d3, h__, &rt, &ans1, &ans2);
    rt1 = rt;
    sm = ans1 / *h__;
    if (d3 < 0.) {
	goto L228;
    }
    sm += .5 / sqrt(d3);
    i__1 = itp2m2;
    for (i__ = itp1p1; i__ <= i__1; ++i__) {
	imm = i__;
	emv = *e - v[i__];
	if (emv < 0.) {
	    goto L222;
	}
	sm += 1. / sqrt(emv);
    }
    d3 = *e - v[itp2m2];
    d2 = *e - v[itp2m];
    d1 = *e - v[itp2];
    goto L226;
/* ** If encounter a double-minimum well, take care here. */
L222:
    d1 = emv;
    d2 = *e - v[imm - 1];
    d3 = *e - v[imm - 2];
    if (*iwr != 0) {
	s_wsfe(&io___270);
	do_fio(&c__1, (char *)&(*kv), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*jrot), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*eo), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
L226:
    levqad_(&d1, &d2, &d3, h__, &rt, &ans1, &ans2);
    rt2 = rt;
    sm = sm - .5 / sqrt(d3) + ans1 / *h__;
/* ** Get HBW in same energy units (1/cm) associated with BFCT */
L228:
    hbw = pi * 2. / (*bfct * sm);
/* ** HBW fix up suggested by Child uses his eqs.(48)&(62) for HBW */
/* ** Derivative of complex gamma function argument calculated as */
/*  per eq.(6.1.27) in Abramowitz and Stegun. */
    nst = (integer) (abs(emsc) * 100.);
    nst = max(nst,4);
    arg = -1.963510026021423;
    i__1 = nst;
    for (i__ = 0; i__ <= i__1; ++i__) {
	nn = i__;
	xx = i__ + .5;
/* Computing 2nd power */
	d__1 = xx / emsc;
	ti = 1. / (xx * (d__1 * d__1 + 1.));
	arg += ti;
	if (abs(ti) < 1e-10) {
	    goto L233;
	}
    }
/* ... and use continuum approximation for tail of summation (???) */
L233:
/* Computing 2nd power */
    d__1 = emsc / (nn + 1.);
    cor = d__1 * d__1 * .5;
/* Computing 2nd power */
    d__1 = cor;
    arg = arg + cor - d__1 * d__1;
/* ** Now use WKL's Weber fx. approx for (?) derivative of barrier integral .. */
    dweb = (*eo - vmax) * *bfct / (h2 * emsc);
    dfi = (log((abs(emsc))) - arg) * *bfct / (h2 * dweb);
    hbwb = 1. / (1. / hbw + dfi / (pi * 2.));
/* ** Width from formula (4.5) of  Connor & Smith, Mol.Phys.43,397(1981) */
/* [neglect time delay integral past barrier in their Eq.(4.16)]. */
    if (emsc > -25.) {
	*gama = hbwb / (pi * 2.) * omegjc;
	tau = 0.;
	if (*gama > 1e-60) {
	    tau = 5.308837457e-12 / *gama;
	}
/* ** GAM0 = TUN0*HBW/PI  is the simple WKB width GAMMA(0) discussed by */
/*  Le Roy & Liu in J.C.P.69,3622(1978). */
	if (*iwr > 0) {
	    s_wsfe(&io___283);
	    do_fio(&c__1, (char *)&tau, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*gama), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&hbwb, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&vmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    } else {
	d__1 = hbwb / (pi * 2.);
	gamalg = d_lg10(&d__1) + pi * 2. * emsc / 2.302585093;
	taulg = d_lg10(&c_b376) - gamalg;
	if (*iwr > 0) {
	    s_wsfe(&io___286);
	    do_fio(&c__1, (char *)&taulg, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&gamalg, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&hbwb, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&vmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
L250:
    return 0;
} /* width_ */

