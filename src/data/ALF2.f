
c***********************************************************************
      SUBROUTINE ALF(NDP,RMIN,RH,V,SWF,VLIM,KVMAX,AFLAG,ZMU,EPS,NCN,GV,
     1                                                 INNODE,INNR,IWR)
c***********************************************************************
c   Version 1.0 dated July 6, 2003. Cosmetic formatting changes 11/04/07
c-----------------------------------------------------------------------
c** The subroutine ALF (Automatic vibrational Level Finder) will
c   automatically generate the eigenvalues from the first vibrational
c   level (v=0) to a user specified level (v=KVMAX) or the highest
c   allowed vibrational level of a given smooth single (or double)
c   minimum potential (V). These energies are stored and returned to the
c   calling program in the molecular constants array GV(v=0-KVMAX).
c** For any errors that cannot be resolved within the subroutine, ALF
c   returns AFLAG with a value that defines which error had occured.
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c++   COPYRIGHT 1998 - 2003  by  Jenning Seto and Robert J. Le Roy   +++
c   Dept. of Chemistry, Univ. of Waterloo, Waterloo, Ontario, Canada   +
c    This software may not be sold or any other commercial use made    +
c     of it without the express written permission of the authors.     +
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c+ Please inform me of any bugs, by phone at: (519)888-4567, ext. 4051 +
c++++++++ by e-mail to: leroy@uwaterloo.ca , or write me at: ++++++++++
c+++ Dept. of Chemistry, Univ. Waterloo, Waterloo, Ontario  N2L 3G1 ++++
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** Based on the automatic level finding routine from LEVEL 6.0 written
c   by Robert J. Le Roy
c** Uses the Schrodinger solver subroutine SCHRQ.
c
c** On entry:
c    NDP    is the number of datapoints used for the potential.
c    RMIN   is the inner radial distance of the potential (ang).
c    RH     is the meshvalue (ang).
c           NDP, RMIN, and RH define the radial range over which the
c           potential is defined.
c    V(i)   is the scaled input potential (cm-1).
c           The scaling factor BFCT is (2*mu/hbar^2)*RH^2.
c    VLIM   is the potential asymptote (cm-1).
c    KVMAX  is v for the highest vibrational level we wish to find.
c    AFLAG  is rot.quantum J for the (centrifugally distorted) potential
c    ZMU    is the reduced mass of the diatom (amu).
c    EPS    is the energy convergence criterion (cm-1).
c    NCN    is the near dissociation limit radial exponential.
c    INNODE specifies whether wave fx. initiation @ RMIN starts with a
c        note (normal case: INNODE > 0) or zero slope (when INNODE.le.0)
c    IWR    specifies the level of printing inside SCHRQ
c           <> 0 : print error & warning descriptions.
c           >= 1 : also print final eigenvalues & node count.
c           >= 2 : also show end-of-range wave function amplitudes.
c           >= 3 : print also intermediate trial eigenvalues, etc.
c
c** On exit:
c    KVMAX   is vib.quantum number for the highest allowed vibrational
c            level found (may be less than the input value of KVMAX).
c    AFLAG   returns calculation outcome to calling program.
c            >=  0 : Subroutine found all levels to v=KVMAX(input).
c             = -1 : KVMAX larger than number of allowed levels.
c             = -2 : Initial trial energy is unusable.
c             = -3 : Calculated trial energy is unusable.
c             = -4 : Cannot find first vibrational level.
c             = -5 : Calculated trial energy too low.
c             = -6 : Calculated trial energy too high.
c             = -7 : An impossible situation occured.
c             = -8 : Potential found to have a second minimum.
c    GV(v)   contains the vibrational energy levels found for v=0-KVMAX
c    INNR(v) labels each level as belonging to the inner (INNR = 1) or
c            outer (INNR = 0) well.
c
c** Flags: Modify only when debugging.
c    AWO   specifies the level of printing inside ALF
c          <> 0 : print error & warning descriptions.
c          >  0 : also print intermediate ALF messages.
c    MCO   specifies the level of printing of molecular constants.
c          >  0 : print out vibrational energies to channel-21.
c    INNER specifies wave function matching (& initiation) conditions.
c        .le.0 : Match inward & outward solutions at outermost well t.p.
c          > 0 : Match at innermost well inner turning point
c        For most normal cases set INNER = 0,  but ......
c            To find "inner-well-dominated" solutions of an asymmetric
c            double minimum potential, set  INNER > 0.
c    LPRWF specifies option of printing out generated wavefunction
c          > 0 : print wave function every LPRWF-th  point.
c          < 0 : compactly write to channel-7 every |LPRWF|-th wave
c                function value.
c          A lead "card" identifies the level, gives the position of
c          1-st point and radial mesh, & states No. of  points.
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** The dimensioning parameters must be consistant with the sizes of the
c   arrays used in the calling program.
c
c    NVIBMX  is the maximum number of vibrational levels considered.
c            Note: NVIBMX should be larger than KVMAX.
c
      INTEGER NVIBMX
      PARAMETER (NVIBMX= 400)
c
c** NF counts levels found in automatic search option
c
c** OWL holds the vibrational levels that are contained in the outer
c   well.
c** IWL holds the vibrational levels that are contained in the inner
c   well (if present).
c
      INTEGER NDP,KVMAX,NCN,KV,AFLAG,NF,NBEG,NEND,INNR(0:KVMAX),IWR,
     1  I,IZPE,IVDIF,IVCOR,IQT,IEG,LTRY,TRIALE,AWO,MCO,INNODE,INNER,
     2  NoPRWF,JROT,NPMIN, NPMAX, NIWL,IWL(0:NVIBMX),NOWL,OWL(0:NVIBMX)
c
      REAL*8 RMIN,RMAX,RH,V(NDP),SWF(NDP),VLIM,EO,ZMU,EPS,LHIE,LLOE,
     1  BZ,BFCT,PW,PWI,GAMA,VMIN,VMAX,RE,PMAX,VDMV,VDL,VDU,DRAVOUT,
     2  DRAVIN,AO,VD,GV(0:KVMAX),RAVG(0:NVIBMX),VPMIN(10),RPMIN(10),
     3  VPMAX(10),RPMAX(10)
c
      DATA AWO/-1/,MCO/0/,NoPRWF/0/
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** Check that the array dimensions are adequate.
      IF(KVMAX.GT.NVIBMX) THEN
          WRITE(6,610)
          WRITE(6,613) KVMAX, NVIBMX
          STOP
          ENDIF
c
c** Initialize level counters for each well.
      DO  I= 0,KVMAX
          INNR(I)= -1
          IWL(I)= 0
          OWL(I)= 0
          END DO
c
c** Initialize the remaining variables and flags.
      NF= 0
      NIWL= 0
      NOWL= 0
      KV= 0
      INNER= 0
      LTRY= 0
      LHIE= 1.0d99
      CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c
c** Store rotational quantum number.
      JROT= AFLAG
c
c** Numerical factor  16.85762920 (+/- 0.00000011) based on Compton
c  wavelength of proton & proton mass (u) from 2002 physical constants.
      BZ= ZMU/16.85762920d0
      BFCT= BZ*RH*RH
c
c** RMAX is the outer radial distance over which potential is defined.
      RMAX= RMIN + DBLE(NDP-1)*RH
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** Locate the potential minima.
      NPMIN= 0
      DO  I= 2,NDP-1
          IF((V(I).LT.V(I-1)).AND.(V(I).LT.V(I+1))) THEN
              NPMIN= NPMIN + 1
              RPMIN(NPMIN)= RMIN + DBLE(I-1)*RH
              VPMIN(NPMIN)= V(I) / BFCT
              IF(NPMIN.EQ.10) GOTO 100
              ENDIF
          END DO
c** If NO minimum can be found, then print a warning and stop.
  100 IF(NPMIN.EQ.0) THEN
          IF(V(2).LE.V(1)) THEN
              WRITE(6,614) JROT
              KVMAX= -1
              RETURN
              ENDIF
          NPMIN= 1
          VPMIN(NPMIN)= V(1)/BFCT
          RPMIN(NPMIN)= RMIN
          WRITE(6,618) VPMIN(1),RMIN
          ENDIF
c** If more than two minima are found, then print a warning and hope ...
      IF(NPMIN.GT.2) THEN
          WRITE(6,605)
          WRITE(6,615) NPMIN, 'minima'
c         STOP
          ENDIF
      NPMAX= 0
c** Locate the potential maxima (if it exists).
      DO  I= 2,NDP-1
          IF((V(I).GT.V(I-1)).AND.(V(I).GT.V(I+1))) THEN
              NPMAX= NPMAX + 1
              RPMAX(NPMAX)= RMIN + DBLE(I-1)*RH
              VPMAX(NPMAX)= V(I) / BFCT
              IF(NPMAX.EQ.10) GOTO 150
              ENDIF
          END DO
c
  150 IF(NPMAX.EQ.0) THEN
c** If no maxima were found, then set energy maximum to be the value
c   at the end of the radial range.
          NPMAX= 1
          RPMAX(NPMAX)= RMAX
          VPMAX(NPMAX)= V(NDP) / BFCT
          ENDIF
c
c** If more than three maxima found, then print a warning and hope ...
      IF(NPMAX.GT.3) THEN
          WRITE(6,605)
          WRITE(6,615) NPMAX, 'maxima'
c         STOP
          ENDIF
c
c** If there is no barrier to dissociation, then set the
c   final VPMAX to be the value at the end of the range. [huh ????]
      IF(RPMAX(NPMAX).LT.RPMIN(NPMIN)) THEN
          NPMAX= NPMAX + 1
          RPMAX(NPMAX)= RMAX
          VPMAX(NPMAX)= V(NDP) / BFCT
          ENDIF
c
c** If innermost maximum occurs before innermost minimum, the potential
c   turns over in short range region and should not be used.
c   Print a warning and STOP.
      IF(RPMAX(1).LT.RPMIN(1)) THEN
          WRITE(6,610)
          WRITE(6,616) RPMAX(1)
          STOP
          ENDIF
c
c** Now find the absolute potential minimum.
      VMIN= VPMIN(1)
      RE= RPMIN(1)
      DO  I= 2,NPMIN
          IF(VMIN.GT.VPMIN(I)) THEN
              VMIN= VPMIN(I)
              RE= RPMIN(I)
              ENDIF
          END DO
c
c** Now find the absolute potential maximum.
      VMAX= VPMAX(1)
      DO  I= 2,NPMAX
          IF(VMAX.LT.VPMAX(I)) VMAX= VPMAX(I)
          END DO
c
c** If the absolute potential maximum is lower than the absolute
c   potential minimum, then print out an error statement and quit.
      IF(VMAX.LE.VMIN) THEN
          WRITE(6,610)
          WRITE(6,617)
          STOP
          ENDIF
c
c** Otherwise, print out potential extrema count, if desired.
      IF(AWO.GT.0) THEN
          WRITE(6,650) NPMIN, VMIN
          WRITE(6,651) NPMAX, VMAX
          ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** Calculate 2*NCN/(NCN - 2) for use when calculating trial energies.
      PW= 20.0d0
      IF((NCN.GT.0).AND.(NCN.NE.2)) PW= 2.d0*DBLE(NCN)/(DBLE(NCN)-2.d0)
      IF(VMAX.GT.VLIM) PW= 2.d0
      PWI= 1.d0/PW
c
c** Use Lennard-Jones estimation of zero point energy to determine the
c   initial trial energy.
c                            _____________________________
c            vD + 0.5 = ao \/ZMU * De * Re^2 / 16.85762920
c                 De = A (vD - v)^3 = A (vD + 0.5)^3
c              E(v=0) = VMIN + A [(vD + 0.5)^3 - vD^3]
c** Choose AO to have a value of 0.25.
c
      AO= 0.25d0
      VD= AO*DSQRT(BZ*(VMAX-VMIN))
      VD= VD*RE - 0.5d0
      AO= (VMAX-VMIN)*(1.d0 - (VD/(VD+0.5d0))**3)
      EO= VMIN + AO
c
      IF(MCO.GE.1) THEN
c** If desired, write out SCHRQ control information.
          WRITE(21,2100)
          WRITE(21,2110) RMIN, RMAX, RH, BZ, ZMU
          WRITE(21,2111) EPS
          WRITE(21,2112)
          WRITE(21,2101)
          ENDIF
c=========== Begin Actual Eigenvalue Calculation Loop Here =============
c** Compute eigenvalues ... etc. up to the KVMAX'th vibrational level.
c** When attempts to find the next eigenvalue fails, then perhaps the
c   next level is located in a second (inner) well. If so, then the
c   subroutine will set INNER = 1, and attempt to find that level.
c
   10 IF(AWO.GT.0) THEN
          IF(INNER.EQ.0) WRITE(6,601)
          IF(INNER.EQ.1) WRITE(6,603)
          ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** Call subroutine SCHRQ to find eigenvalue EO and eigenfunction SWF(I).
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      CALL SCHRQ(KV,JROT,EO,GAMA,PMAX,VLIM,V,SWF,BFCT,EPS,RMIN,RH,NDP,
     1                              NBEG,NEND,INNODE,INNER,IWR,NoPRWF)
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If a level higher than NF has already been found and the level found
c   not the correct level, ignore all errors and continue with the
c   binary search.
c
      IF((KV.GE.0).AND.(KV.LT.NF).AND.((IVCOR.GT.0).OR.(IEG.GT.3))) THEN
          KV= NF + 1
          EO= VMAX + 1.0d0
          IF(IVCOR.GT.0) THEN
              LLOE= (LHIE + LLOE) / 2.0d0
            ELSE
              LLOE= GV(NF-1)
              LHIE= VMAX
              IVCOR= 1
            ENDIF
          TRIALE= 0
          ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** The SCHRQ error condition is KV < 0.
c   There are three possible situations to consider:
c     EO > VMAX : Trial energy greater than potential maximum
c     NF = 0 : Looking for the first vibrational level (v = 0)
c     NF > 0 : Looking for the other vibrational levels (v > 0)
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** For the case when the next trial energy is higher than the potential
c   maximum, try one last ditch attempt to find the highest bound level
c   (quasi or otherwise) in the potential.
c
      IF((KV.LT.0).AND.(EO.GT.VMAX)) THEN
          IF(IVCOR.LT.20) THEN
              KV= NF + 1
              IF(IVCOR.EQ.0) THEN
c??????
                  if(nf.eq.0) then
                      lloe= GV(0)
                    else
                      LLOE= GV(NF-1)
                    endif
c??????           LLOE= GV(NF-1)
c??????
                  LHIE= VMAX
                  IVCOR= 1
                  ENDIF
              ENDIF
          IF(LTRY.LT.1) THEN
              LTRY= 1
              KV= 999
              EO= VMAX - 1.0d-2
c
c** If unsuccessful, then print out a warning and exit.
            ELSE
              IF(AWO.NE.0) THEN
                  WRITE(6,605)
                  WRITE(6,606) NF, EO, VMAX
                  ENDIF
              AFLAG= -1
              GOTO 200
            ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If trying to find the first vibrational level (v=0), then double the
c   zero point energy estimation (AO):   E(v=0) = VMIN + IQT*AO
c
        ELSEIF((KV.LT.0).AND.(NF.EQ.0)) THEN
          IF(IQT.GT.1) THEN
              IF(AWO.NE.0) THEN
                  WRITE(6,610)
                  WRITE(6,611)
                  WRITE(6,620) IQT, EO
                  ENDIF
c
c** If this fails, then try changing the wavefunction matching
c   condition (INNER) to see if a possible second minimum contains the
c   zero-point level.
              IF(INNER.EQ.0) THEN
                  INNER= 1
                  CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c** If both attempts fail, then print out warning message and exit the
c   subroutine.
                ELSE
                  AFLAG= -2
                  GOTO 200
                ENDIF
              ENDIF
          IQT= IQT + 1
          EO= VMIN + DBLE(IQT)*AO
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If trying to find other vibrational levels (v > 0) then switch to
c   use of differences for estimating spacing.
c
        ELSEIF((KV.LT.0).AND.(NF.GT.0)) THEN
          IF(IVDIF.GT.0) THEN
              IF(AWO.NE.0) THEN
                  WRITE(6,610)
                  WRITE(6,612)
                  WRITE(6,621) NF,IVDIF
                ENDIF
c
c** If differences fails, then try changing the wavefunction matching
c   condition (INNER) to see if a possible second minimum contains the
c   zero point level.
c
              IF(INNER.EQ.0) THEN
                  INNER= 1
                  CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c
c** If both attempts fail, then print out warning message and exit the
c   subroutine.
                ELSE
                  AFLAG= -3
                  GOTO 200
                ENDIF
              ENDIF
          IVDIF= 1
          IF(INNER.EQ.0) THEN
              CALL DTENG(IEG,NF,NOWL,OWL,NVIBMX,VMIN,GV,EO)
            ELSE
              CALL DTENG(IEG,NF,NIWL,IWL,NVIBMX,VMIN,GV,EO)
            ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If first level found isn't v=0, try up to 3 times to 'harmonically'
c   estimate improved trial ground state energy.
c           E(v=0)= E(v=KV) - (E(v=KV) - VMIN)/(1 + KV/2)
c
        ELSEIF((KV.GT.0).AND.(NF.EQ.0)) THEN
          IF(IZPE.GT.3) THEN
              IF(AWO.NE.0) THEN
                  WRITE(6,610)
                  WRITE(6,611)
                  WRITE(6,622) IZPE,GV(0),KV,EO
                  ENDIF
c
c** If differences fails, then try changing the wavefunction matching
c   condition (INNER) to see if a possible second minimum contains the
c   zero point level.
              IF(INNER.EQ.0) THEN
                  INNER= 1
                  CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c
c** If both attempts fail, then print out warning message and exit the
c   subroutine.
                ELSE
                  AFLAG= -4
                  GOTO 200
                ENDIF
              ENDIF
          IZPE= IZPE + 1
          EO= EO - (EO-VMIN)/(1.d0+0.5d0/KV)
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** For the next three cases, KV >= 0 and NF > 0.
c** If the calculated vibrational level is less than the next expected
c   level, then the estimated trial energy is too low.
c** Perhaps the difference in energy between vibrational levels v and
c   v-1 is much greater than the energy between levels v-1 and v-2.
c                 E(v) - E(v-1) >> E(v-1) - E(v-2)
c   In which case (most likely a potential with a shelf), try twice to
c   estimate a higher trial energy.
c
c   E(v)= E(v-1) + (1+IEG/2) * (2*(E(v-1)-E(v-2)) - (E(v-2)-E(v-3)))
c
        ELSEIF(KV.LT.NF) THEN
          IF(IEG.GT.3) THEN
              IF(AWO.NE.0) THEN
                  WRITE(6,610)
                  WRITE(6,612)
                  WRITE(6,623) NF, KV
                  ENDIF
c
c** If this fails, then try changing the wavefunction matching
c   condition (INNER) to see if a possible second minimum contains the
c   zero point level.
              IF(INNER.EQ.0) THEN
                  INNER= 1
                  CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c
c** If both attempts fail, then print out warning message and exit the
c   subroutine.
                ELSE
                  AFLAG= -5
                  GOTO 200
                ENDIF
              ENDIF
          IEG= IEG + 1
c
c** If a second minimum is present, then the next vibrational level may
c   be in the inner well. If so, use the inner well vibrational levels
c   to estimate the next trial energy.
          IF(INNER.EQ.0) THEN
              CALL DTENG(IEG,NF,NOWL,OWL,NVIBMX,VMIN,GV,EO)
            ELSE
              CALL DTENG(IEG,NF,NIWL,IWL,NVIBMX,VMIN,GV,EO)
            ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If the calculated vibrational level is the next expected level, ...
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ELSEIF(KV.EQ.NF) THEN
          GV(NF)= EO
          INNR(NF)= INNER
          LTRY= 0
          TRIALE= 1
          LLOE= EO
          LHIE= VMAX
          CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c-----------------------------------------------------------------------
c
c** To ease confusion when using a potential with two minima, use
c  <R>=RAVG  to keep track of which is which.
c
   20     RAVG(NF)= 0.5d0*(SWF(NBEG)*(RMIN+DBLE(NBEG-1)*RH)
     1                        + SWF(NEND)*(RMIN+DBLE(NEND-1)*RH))
          DO  I= NBEG+1,NEND-1
              RAVG(NF)= RAVG(NF) + SWF(I)*(RMIN+DBLE(I-1)*RH)
              END DO
          RAVG(NF)= RAVG(NF)*RH
c
c** Double check that the calculated level is in fact located in the
c   correct well. This can be done (for v.ne.0) by comparing <R> for
c   the new level and with previous values in each well. If the
c   difference is greater than 1.5 times the difference in the other
c   well, assume the calculated level is probably in the wrong well.
c
          IF(NOWL.GT.0) THEN
              DRAVOUT= DABS(RAVG(NF) - RAVG(OWL(NOWL-1)))
            ELSE
              DRAVOUT= 9999.9d0
            ENDIF
          IF(NIWL.GT.0) THEN
              DRAVIN= DABS(RAVG(NF) - RAVG(IWL(NIWL-1)))
            ELSE
              DRAVIN= 9999.9d0
            ENDIF
          IF(INNER.EQ.0) THEN
              IF((NOWL.GT.0).AND.(DRAVOUT.GT.(1.5d0*DRAVIN))) THEN
                  IF(MCO.GE.1)
     1             WRITE(21,2113) NF,'Inner',NIWL,GV(NF)-VMIN,RAVG(NF)
                  IWL(NIWL)= NF
                  NIWL= NIWL + 1
                ELSE
                  IF(MCO.GE.1)
     1             WRITE(21,2113) NF,'Outer',NOWL,GV(NF)-VMIN,RAVG(NF)
                  OWL(NOWL)= NF
                  NOWL= NOWL + 1
                ENDIF
            ELSE
              IF((NIWL.GT.0).AND.(DRAVIN.GT.(1.5d0*DRAVOUT))) THEN
                  IF(MCO.GE.1)
     1             WRITE(21,2113) NF,'Outer',NOWL,GV(NF)-VMIN,RAVG(NF)
                  OWL(NOWL)= NF
                  NOWL= NOWL + 1
                ELSE
                  IF(MCO.GE.1)
     1             WRITE(21,2113) NF,'Inner',NIWL,GV(NF)-VMIN,RAVG(NF)
                  IWL(NIWL)= NF
                  NIWL= NIWL + 1
                ENDIF
              INNER= 0
            ENDIF
c
c** Look for the next uncalculated level.
          NF= NF + 1
          IF(NF.LE.KVMAX) THEN
              IF(INNR(NF).GE.0) THEN
c ... if this next level was found earlier, its INNER > initial -1 value
c  so skip up one, but first calculate its Bv on the way.
                  GOTO 20
                  ENDIF
              ENDIF
c-----------------------------------------------------------------------
c** Now estimate trial energy for next higher vibrational energy level
c   by using the Near-Dissociation Theory result that:
c                  (binding energy)**((NCN-2)/(2*NCN))
c   is (at least locally) linear in vibrational quantum number.
c
          IF(NF.EQ.1) THEN
              VDMV= 0.5d0/(((VMAX-VMIN)/(VMAX-GV(0)))**PWI - 1.d0)
            ELSE
              VDMV= 1.d0/(((VMAX-GV(NF-2))/(VMAX-GV(NF-1)))**PWI- 1.d0)
            ENDIF
c
c** If unable to calculate the next trial energy, see if all of the
c   desired levels have been calculated. If not then turn on the warning
c   flag and quit, otherwise print out success message and quit.
c
          IF((VDMV.LT.1.d0).AND.(NCN.GT.2)) THEN
              IF(NF.LE.KVMAX) THEN
                  AFLAG= -1
                  WRITE(6,640) JROT, NF - 1 + VDMV
                ELSEIF(AWO.GT.0) THEN
                  WRITE(6,630) KVMAX
                ENDIF
              GOTO 200
              ENDIF
c
c** Now calculate the next trial energy.
c
          EO= VMAX - (VMAX-GV(NF-1))*(1.d0-1.d0/VDMV)**PW
c
c** However, if the level is above the dissociation limit (for
c   potentials with barriers) then use differences to calculate the
c   next trial energy.
c
          IF(EO.GT.VMAX) CALL DTENG(IEG,NF,NOWL,OWL,NVIBMX,VMIN,GV,EO)
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If the calculated vibrational level is higher then the next expected
c   level, then try once to interpolate harmonically for the missed
c   level:      E(v)= E(v-1) + (E(KV) - E(v-1)) / 2
c
        ELSEIF(KV.GT.NF) THEN
c
c** Record vibrational level (if haven't already) for posterity.
c
          IF((KV.LE.KVMAX).AND.(EO.LT.VMAX)) THEN
              IF(INNR(KV).EQ.-1) THEN
                  GV(KV)= EO
                  INNR(KV)= INNER
                  ENDIF
              ENDIF
          IF(IVCOR.GT.19) THEN
              IF(AWO.NE.0) THEN
                  WRITE(6,610)
                  WRITE(6,612)
                  WRITE(6,624) IVCOR,KV,EO,(NF-1),GV(NF-1)
                  ENDIF
c
c** If interpolation fails, then try changing the wavefunction matching
c   condition (INNER) to see if a possible second minimum contains the
c   missing level.
              IF(INNER.EQ.0) THEN
                  INNER= 1
                  LLOE= GV(NF-1)
                  LHIE= VMAX
                  CALL INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c
c** If both attempts fail, then print a warning message and exit
                ELSE
                  AFLAG= -6
                  GOTO 200
                ENDIF
              ENDIF
c
c** Use NDE theory to predict eigenvalue for the missing level.
          IF(IVCOR.EQ.0) THEN
              VDU= (VMAX-EO)**PWI
              VDL= (VMAX-GV(NF-1))**PWI
              EO= VMAX - (VDL + (VDU - VDL) / DBLE(KV - NF + 1))**PW
c         IF((NPMIN.EQ.1).AND.(IVCOR.EQ.0)) THEN
c             VDU= (VPMAX(1)-EO)**PWI
c             VDL= (VPMAX(1)-GV(OWL(NOWL-1)))**PWI
c             EO= VPMAX(1)- (VDL+ (VDU - VDL)/ DBLE(KV - NF + 1))**PW
c           ELSEIF((((INNER.EQ.1).AND.(NIWL.GT.0)).OR.
c    1          ((INNER.EQ.0).AND.(NOWL.EQ.0))).AND.(IVCOR.EQ.0)) THEN
c             VDU= (VPMAX(1)-EO)**PWI
c             VDL= (VPMAX(1)-GV(IWL(NIWL-1)))**PWI
c             EO= VPMAX(1)- (VDL+ (VDU - VDL)/ DBLE(KV - NF + 1))**PW
c           ELSEIF((((INNER.EQ.0).AND.(NOWL.GT.0)).OR.
c     1         ((INNER.EQ.1).AND.(NIWL.EQ.0))).AND.(IVCOR.EQ.0)) THEN
c             VDU= (VPMAX(2)-EO)**PWI
c             VDL= (VPMAX(2)-GV(OWL(NOWL-1)))**PWI
c             EO= VPMAX(2)- (VDL+ (VDU - VDL)/ DBLE(KV - NF + 1))**PW
c
c** Otherwise use a binary search.
c
            ELSE
              IF((TRIALE.EQ.1).AND.(EO.LT.LHIE)) THEN
                  LHIE= EO
                  IVCOR= 0
                ELSEIF(TRIALE.EQ.1) THEN
                  LHIE= (LHIE + LLOE) / 2.0d0
                ENDIF
              TRIALE= 1
              EO= (LHIE + LLOE) / 2.0d0
            ENDIF
          IVCOR= IVCOR + 1
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** If an unknown case occurs (quite impossible but don't quote me on
c   it) then write out an error message and exit.
        ELSE
          IF(AWO.NE.0) THEN
              WRITE(6,610)
              WRITE(6,666) KV,NF
              ENDIF
          AFLAG= -7
          GOTO 200
        ENDIF
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** Set KV to the next uncalculated vibrational level to be found unless
c   looking for the highest vibrational level.
c
      IF(KV.NE.999) KV= NF
c
c** If still haven't found all of the vibrational levels then
c   look for the next vibrational level.
c
      IF((KV.LE.KVMAX).OR.(KV.EQ.999)) GOTO 10
c
c** Otherwise, print out a message saying that all is well.
c
      IF((KV.GT.KVMAX).AND.(AWO.GT.0)) WRITE(6,630) KVMAX
c
c** If the potential has levels in a second minimum, then print out a
c   list of those levels to channel-21 if desired.
c
      IF((NIWL.GT.0).AND.(NOWL.GT.0)) THEN
          IF(MCO.GE.1) WRITE(21,2114) NIWL, NOWL
          IF(AWO.NE.0) THEN
              WRITE(6,605)
              WRITE(6,607)
              ENDIF
          AFLAG= -8
          ENDIF
c
  200 IF(AFLAG.LT.0) THEN
c** If unable to find all KVMAX+1 levels requested, then return KVMAX as
c  v for the highest vibrational level actually found, and print out the
c  the energy of that level.
          KVMAX= NF - 1
          IF(AWO.NE.0) WRITE(6,626) KVMAX, GV(KVMAX)
          ENDIF
      IF(MCO.GE.1) THEN
c         WRITE(21,2100)
c         DO  I= 0,NF-1
c             IF(INNR(I).EQ.0)WRITE(21,2113)I,'Outer',I,GV(I)-VMIN,RAVG(I)
c             IF(INNR(I).EQ.1)WRITE(21,2113)I,'Inner',I,GV(I)-VMIN,RAVG(I)
c             END DO
          WRITE(21,2100)
          ENDIF
      RETURN
c-----------------------------------------------------------------------
  601 FORMAT(/' Solve by matching inward and outward solutions at the'/
     1  5x,'outermost wave function maximum, S(max), where  R = RR(M)')
  603 FORMAT(/' Solve by matching inward and outward solutions at the'/
     1  5x,'innermost turning point   R1 = R(M)')
  605 FORMAT(/'  *** ALF WARNING ***')
  606 FORMAT(4x,'Next estimated trial energy  E(v=',I3,') =',G15.8/4X,
     1  'lies above potential maximum  VMAX =',G15.8)
  607 FORMAT(4X,'Potential found to have a second minimum.')
  610 FORMAT(/'  *** ALF ERROR ***')
  611 FORMAT(4X,'Attempt to find zero point level fails!')
  612 FORMAT(4X,'Attempt to find next higher vibrational level fails!')
  613 FORMAT(4X,'Number of vib levels requested=',i4,' exceeds internal
     1ALF array dimension  NVIBMX=',i4)
  614 FORMAT(/'  *** ALF ERROR ***   Unable to find a potential minimum
     1 for   J=',i4)
  615 FORMAT(4X,'There are',I3,'  potential ',A6,' in this potential. St
     1op searching after 10.')
  616 FORMAT(4X,'The potential turns over in the short range region at R
     1 = ',G15.8)
  617 FORMAT(4X,'VMAX =',G15.8,' found to be less than VMIN =',G15.8)
  618 FORMAT(/'  ALF  finds onee potential minimum of',1PD15.7,
     1  '  at  R(1)=',0Pf9.6)
  620 FORMAT(4X,'Use of energy ',I1,'0% up the potential well (E =',
     1G15.8,')'/4X,' fails to produce a viable vibrational eigenstate.')
  621 FORMAT(4X,'Use of differences to estimate the energy for the next'
     1/4X,' vibrational level (v=',I3,') failed after',I3,'  attempt.')
  622 FORMAT(4X,'After',I3,' tries to harmonically estimate the zero-poi
     1nt energy,'/4X,' initial trial energy',G15.8,'   had yielded   E(v
     2=',I3,') =',G15.8)
  623 FORMAT(4X,'Expecting to find level (v=',I3,') but found level (v='
     1,I3,')')
  624 FORMAT(4X,'After',I3,' tries, failed to interpolate trial energy b
     1etween'/4X,'E(v=',I3,') =',G15.8,'   and   E(v=',I3,') =',G15.8)
  626 FORMAT(4X,'The highest calculated level is  E(v=',I3,') =',G15.8)
  630 FORMAT(/' ALF successfully finds all vibrational levels up to   v=
     1 KVMAX=',I3)
  640 FORMAT(/' ALF finds all  J=',i3,'  vib. levels below  vD=',F7.3,
     1  '  estimated by N-D theory')
  650 FORMAT(/' There were',I3,'  potential minima found with the absolu
     1te minimum'/4X,'VMIN =',G15.8,'  cm-1.')
  651 FORMAT(/' There were',I3,'  potential maxima found with the absolu
     1te maximum'/4X,'VMAX =',G15.8,'  cm-1.')
  666 FORMAT(4X,'Undefined case for automatic search.'/,4X,'Values of KV
     1 =',I3,'  and NF =',I3)
 2100 FORMAT(/1X,39('=='))
 2101 FORMAT(/1X,39('--'))
 2110 FORMAT(/' Limits and increment of integration (in Angstroms):'
     1 /'    RMIN =',F6.3,'    RMAX =',F7.3,'    RH =',F9.6,
     2 //' Generate    BZ =',G19.12,' ((1/cm-1)(1/Angstroms**2))'
     3 /' from ZMU:',F15.11,' (amu)')
 2111 FORMAT(/' Eigenvalue convergence criterion is   EPS =',G11.4,'(cm-
     11)')
 2112 FORMAT(/' Calculating properties of the potential described above.
     1 '/' Use Airy function at 3-rd turning point as outer boundary'
     2 /' condition for quasibound levels.')
 2113 FORMAT(' v=',I3,4X,'v(',A5,')=',I3,4X,'Gv=',F16.9,4X,'Bv=',F16.12)
 2114 FORMAT(/' Found',I4,' level(s) in the inner well and',I4,' level(s
     1) in the outer well.')
      END
c***********************************************************************
      SUBROUTINE INITVAL(IQT,IVDIF,IZPE,IEG,IVCOR)
c***********************************************************************
c** This subroutine reinitializes the condition flags when considering a
c   new case (found next vibrational level or finding level in inner
c   well - INNER = 1).
c
c** On entry and exit:
c    IQT     Case when KV < 0 and NF = 0
c            determines the value used for the initial trial energy.
c    IVDIF   Case when KV < 0 and NF > 0
c            is the flag denoting the use of differences to calculate
c            trial energies.
c    IZPE    Case when KV > 0 and NF = 0
c            is the number of times the zero point energy (v = 0) has
c            been estimated harmonically.
c    IEG     Case when KV < NF and NF > 0
c            are the number of times that a larger trial energy is used
c            to find the next level.
c    IVCOR   Case when KV > NF and NF > 0
c            are the number of times that a smaller trial energy is used
c            to find the next level.
c
      INTEGER IZPE,IVDIF,IVCOR,IQT,IEG
c
      IQT= 1
      IVDIF= 0
      IZPE= 0
      IEG= 0
      IVCOR= 0
      RETURN
      END
c***********************************************************************
      SUBROUTINE DTENG(IEG,NF,NVEL,VEL,NVIBMX,VMIN,GV,EO)
c***********************************************************************
c** This subroutine calculates the next trial energy using differences.
c
c** On entry:
c    IEG     factor by which a larger trial energy should be calculated:
c              NVEL = 2 : Increase correction by increments of 25%
c              NVEL > 2 : Increase correction by increments of 50%
c    NF      is the highest calculated vibrational level.
c    NVEL    is the number of levels found in the potential well.
c    VEL(v)  keeps track of all levels in the potential well.
c    NVIBMX  is the maximum number of vibrational levels (dimension).
c    VMIN    is the absolute value of the potential minimum (cm-1).
c    GV(v)   contains the vibrational energy level spacings
c            and rotational constants for each level (cm-1).
c
c** On exit:
c    EO      is the calculated trial energy.
c
      INTEGER IEG,NF,NVEL,NVIBMX,VEL(0:NVIBMX)
c
      REAL*8 VMIN,GV(0:NVIBMX),EO
c
c** If determining the first (non-zero point energy) level in the well,
c   then use the last determined level in the other well plus a larger
c   than harmonic correction that becomes smaller with each new
c   iteration:      E(v=0)= E(v=NF-1) + (E(v=NF-1)-VMIN)/(NF-1+IEG/4)
c
      IF(NVEL.EQ.0) THEN
        EO= GV(NF-1) + (GV(NF-1) - VMIN)/(NF - 1 + 0.25d0*DBLE(IEG))
c
c** Try to get v= 1 using smaller-than-harmonic spacing.
c
c              E(v=1)= E(v=0) + (1.0+IEG/4)*(E(v=0)-VMIN)
c
      ELSEIF(NVEL.EQ.1) THEN
        EO= GV(VEL(0)) + (1.d0+DBLE(IEG)*0.25d0)*(GV(VEL(0))-VMIN)
c
c** Try to get v= 2 using a sequentially increasing correction.
c
c             E(v=2)= E(v=1) + (0.8+IEG/4)*(E(v=1)-E(v=0))
c
      ELSEIF(NVEL.EQ.2) THEN
        EO= GV(VEL(1))+ (0.8d0+DBLE(IEG)*0.25d0)*(GV(VEL(1))-GV(VEL(0)))
c
c** Try to get v > 2 using a sequentially increasing correction.
c
c        E(v)= E(v-1) + (1.0+IEG)*(2.0*E(v-1)-3.0*E(v-2)+E(v-3))
c
      ELSE
        EO= GV(VEL(NVEL-1)) + (1.d0+DBLE(IEG))
     1    *(2.d0*GV(VEL(NVEL-1))-3.0d0*GV(VEL(NVEL-2))+GV(VEL(NVEL-3)))
      ENDIF
      RETURN
      END
c23456789 123456789 123456789 123456789 123456789 123456789 123456789 12

c***********************************************************************
c***** R.J. Le Roy  subroutine SCHRQ, last updated  8 April 2007 *******
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c                COPYRIGHT 2007  by  Robert J. Le Roy                  +
c   Dept. of Chemistry, Univ. of Waterloo, Waterloo, Ontario, Canada   +
c    This software may not be sold or any other commercial use made    +
c      of it without the express written permission of the author.     +
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c** SCHRQ solves radial Schrodinger equation in dimensionless form
c  d2WF/dR2 = - (E-V(R))*WF(R) ,  where WF(I) is the wave function.
c** Integrate by Numerov method over N mesh points with increment
c  H=RH across range beginning at RMIN .
c** Input trial energy EO, eigenvalue convergence criterion EEPS
c  potential asymptote VLIM, and all returned energies (EO, GAMA & VMAX)
c  have units (cm-1).
c** On entry, the input potential V(I) must include the centrifugal
c  term and the factor:  'BFCT'=2*mu*(2*pi*RH/hPLANCK)**2  (1/cm-1) ,
c  which is also internally incorporated into EO, VLIM & EEPS.
c* Note that these reduced quantities (& the internal eigenvalue E)
c  contain a factor of the squared integration increment  RH**2 .
c  This saves arithmetic work in the innermost loop of the algorithm.
c** For energy in (cm-1), BFCT=ZMU(u)*H(Angst)**2/16.85762920 (1/cm-1)
c** INNODE > 0  specifies that wavefx. initiates at RMIN with a node
c     (normal default case);  INNODE.le.0  spoecifies  zero slope  at
c     RMIN (for finding symmetric eigenfunctions of symmetric potential
c     with potential mid-point @ RMIN).
c** INNER specifies wave function matching condition: INNER = 0  makes
c     matching of inward & outward solutions occur at outermost turning
c     point;  INNER > 0 makes matching occur at innermost turning point.
c * Normally use  INNER=0 ,  but to find inner-well levels of double
c     minimum potential, set  INNER > 0 .
c----------------------------------------------------------------------
      SUBROUTINE SCHRQ(KV,JROT,EO,GAMA,VMAX,VLIM,V,WF,BFCT,EEPS,RMIN,
     1                          RH,N,NBEG,NEND,INNODE,INNER,IWR,LPRWF)
c----------------------------------------------------------------------
c** Output vibrational quantum number KV, eigenvalue EO, normalized
c  wave function WF(I), and range, NBEG .le. I .le. NEND  over
c  which WF(I) is defined. *** Have set  WF(I)=0  outside this range.
c* (NBEG,NEND), defined by requiring  abs(WF(I)) < RATST=1.D-9  outside.
c** If(LPRWF.gt.0) print wavefunction WF(I) every LPRWF-th point.
c* If(LPRWF.lt.0) "punch" (i.e., WRITE(10,XXX)) every |LPRWF|-th point
c  of the wave function on disk starting at R(NBEG) with step size
c  of  IPSIQ=|LPRWF|*RH.
c** For energies above the potential asymptote VLIM, locate quasibound
c  levels using Airy function boundary condition and return the level
c  width GAMA and barrier height VMAX, as well as EO.
c** ERROR condition on return is  KV < 0 ; usually KV=-1, but return
c  KV=-2 if error appears to arise from too low trial energy.
c** If(IWR.ne.0) print error & warning descriptions
c  If (IWR.gt.0) also print final eigenvalues & node count.
c  If (IWR.ge.2) also show end-of-range wave function amplitudes
c  If (IWR.ge.3) print also intermediate trial eigenvalues, etc.
c** If input KV.ge.998 , tries to find highest bound level, and
c  trial energy should be only slightly less than VLIM.
c** If input KV < -10 , use log-derivative outer boundary condition at
c  mesh point |KV| , based on incoming value of wave function WF(|KV|)
c  and of the wavefunction derivative at that point, SPNEND, which is
c  brought in as WF(|KV|-1).  For a hard wall condition at mesh point
c  |KV|, set WF(|KV|)=0 and WF(|KV|-1)= -1 before entry.
c----------------------------------------------------------------------
c++ "SCHRQ" calls subroutineas "QBOUND" and "WIDTH", and the latter
c++ calls "LEVQAD" .
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      INTEGER  I,IBEGIN,ICOR,IJ,IJK,INNODE,INNER,IPSID,IQTST,IT,
     1         ITER,ITP1,ITP1P,ITP3,IWR,J,JJ,J1,J2,JPSIQ,JQTST,JROT,
     2         KKV,KV,KVIN,LPRWF,M,MS,MSAVE,
     3         N,NBEG,NBEGB,NBEG2,NDN,NEND,NENDCH,NLINES,NPR
      REAL*8  BFCT,DE,DEP,DEPRN,DF,DOLD,DSOC,
     2        E,EEPS,EO,EPS,F,FX,GAMA,GI,GN,H,HT,PROD,PPROD,
     3        RATIN,RATOUT,RATST,RH,RINC,RMIN,RMINN,RR,RSTT,RWR(20),
     4        WF(N),SB,SI,SM,SN,SNEND,SPNEND,SRTGI,SRTGN,SWR(20),
     5        V(N),VLIM,VMAX,VMX,VPR,
     6        WKBTST,XEND,XPR,XPW,DXPW,Y1,Y2,Y3,YIN,YM,YOUT
      DATA RATST/1.D-9/,XPW/20.72d0/
      DATA NDN/15/
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      DXPW= (XPW+ 2.30d0)/NDN
      ICOR= 0
      KVIN= KV
      KV= -1
      RMINN= RMIN-RH
      GAMA= 0.d0
      VMAX= VLIM
      VMX= VMAX*BFCT
      H= RH
      HT= 1.d0/12.D+0
      E= EO*BFCT
      EPS= EEPS*BFCT
      DSOC= VLIM*BFCT
      DE= 0.d0
      RATIN= 0.d0
      RATOUT= 0.d0
      IF(IWR.GT.2) THEN
          IF(KVIN.GE.998) then
              WRITE(6,610) EO
            ELSE
              WRITE(6,601) KVIN,JROT,EO,INNER
            ENDIF
          WRITE(6,602)
        ENDIF
      NEND= N
      IF(KVIN.LT.-10) THEN
          NEND= -KVIN
          SNEND= WF(NEND)
          SPNEND= WF(NEND-1)
          ENDIF
      JQTST = 0
c** Start iterative loop; try to converge for up to 15 iterations.
      DO 90 IT= 1,15
          ITER= IT
          IF(INNER.GT.0) GO TO 38
   10     IF(KVIN.LT.-10) THEN
c** If desired, (KVIN < -10) outer boundary set at NEND=|KVIN| and
c  initialize wavefunction with log-derivative condition based on value
c  WF(NEND) & derivative SPNEND at that mesh point (brought in in CALL)
              GN= V(NEND)-E
              GI= V(NEND-1)-E
              SB= SNEND
              SI= SB*(1.d0+ 0.5d0*GN)- RH*SPNEND
              GO TO 24
              END IF
          IF(E.GE.DSOC) THEN
c** For quasibound levels, initialize wave function in "QBOUND"
              CALL QBOUND(KVIN,JROT,E,EO,VMX,DSOC,V,RMIN,H,GN,GI,
     1                                 SB,SI,N,ITP3,IWR,IQTST,BFCT,IT)
              NEND= ITP3
              VMAX= VMX/BFCT
              IF(IQTST.GT.0) GO TO 24
              IF(IQTST.LT.0) THEN
                  JQTST = JQTST+IQTST
                  IF((JQTST.LE.-2).OR.(VMAX.LT.VLIM)) GO TO 999
c** Try up to once to find level using trial value just below maximum
                  EO = VMAX-0.1D0
                  E = EO*BFCT
                  GO TO 90
                  ENDIF
              GO TO 20
              ENDIF
c** For  E < DSOC  begin inward integration by using JWKB to estimate
c  optimum (minimum) inward starting point which will still give
c  RATOUT < RATST = exp(-XPW) (ca. 1.d-9) [not needed after 1'st 2 ITER]
          IF(ITER.LE.2) THEN
              NEND= N
c ... first do rough inward search for outermost turning point
              DO  M= N,1,-NDN
                  MS= M
                  GI= V(M)- E
                  IF(GI.LE.0.D0) GO TO 12
                  GN= GI
                  ENDDO
              IF(IWR.NE.0) WRITE(6,611) JROT,EO
              GO TO 999
   12         IF(MS.GE.N) GO TO 998
              FX= GN/(GI-GN)
              SM= 0.5d0*(1.d0+ FX)*DSQRT(GN)
              MS= MS+ 2*NDN
              IF(MS.GE.N) GO TO 20
c ... now integrate exponent till JWKB wave fx. would be negligible
              DO  M= MS,N,NDN
                  NEND= M
                  SM= SM+ DSQRT(V(M)- E)
                  IF(SM.GT.DXPW) GO TO 18
                  ENDDO
   18         IF(NEND.LT.N) NEND= NEND+ NDN
              ENDIF
c** For truly bound state initialize wave function as 1-st order WKB
c   solution increasing inward
   20     GN= V(NEND)- E
          GI= V(NEND-1)- E
          MS= NEND-1
          IF(GI.LT.0.d0) GO TO 998
          SRTGN= DSQRT(GN)
          SRTGI= DSQRT(GI)
          SB= 1.d0
          SI= SB*DSQRT(SRTGN/SRTGI)*DEXP((SRTGN+SRTGI)*0.5d0)
          IF(SB.GT.SI) THEN
c WOOPS - JWKB gives inward DEcreasing solution, so initialize with node
              IF(IWR.NE.0) WRITE(6,618) JROT,EO,SB/SI
              SI= 1.d0
              SB= 0.d0
              ENDIF
   24     M= NEND-1
          Y1= (1.d0-HT*GN)*SB
          Y2= (1.d0-HT*GI)*SI
          WF(NEND)= SB
          WF(NEND-1)= SI
          MS= NEND
          NENDCH= NEND
          IBEGIN= 3
          IF(INNER.GT.0) IBEGIN= ITP1+2
c** Actual inward integration loop starts here
          DO  I= IBEGIN,NEND
              M= M-1
              Y3= Y2+Y2-Y1+GI*SI
              GI= V(M)-E
              SB= SI
              SI= Y3/(1.d0-HT*GI)
              WF(M)= SI
              IF(DABS(SI).GE.1.D+17) THEN
c** Renormalize to prevent overflow of  WF(I)  in classically
c  forbidden region where  (V(I) .gt. E)
                  SI= 1.d0/SI
                  DO  J= M,MS
                      WF(J)= WF(J)*SI
                      ENDDO
                  NENDCH= MS
                  MS= M
                  Y2= Y2*SI
                  Y3= Y3*SI
                  SB= SB*SI
                  SI= 1.d0
                  ENDIF
              Y1= Y2
              Y2= Y3
c** Test for outermost maximum of wave function.
c ... old matching condition - turning point works OK & is simpler.
cc            IF((INNER.EQ.0).AND.(SI.LE.SB)) GO TO 32
c** Test for outer well turning point
              IF((INNER.EQ.0).AND.(GI.lt.0.d0)) GO TO 32
              ENDDO
          IF(INNER.EQ.0) THEN
c** Error mode ... inward propagation finds no turning point
              KV= -2
              IF(IWR.NE.0) WRITE(6,616) KV,JROT,EO
              GO TO 999
              ENDIF
c** Scale outer part of wave function before proceding
   32     SI= 1.d0/SI
          MSAVE= M
          RR= RMINN+MSAVE*H
          YIN= Y1*SI
          RATOUT= WF(NEND)*SI
          NEND= NENDCH
          DO  J= MSAVE,NEND
              WF(J)= WF(J)*SI
              ENDDO
          IF(INNER.GT.0) GO TO 70
c-------------------------------------------------------------------
c** Set up to prepare for outward integration **********************
   38     NBEG= 1
          IF(INNODE.LE.0) THEN
c** Option to initialize with zero slope at beginning of the range
              SB= 1.d0
              GN= V(1)-E
              Y1= SB*(1.d0-HT*GN)
              Y2= Y1+GN*SB*0.5d0
              GI= V(2)-E
              SI= Y2/(1.d0-HT*GI)
            ELSE
c** Initialize outward integration with a node at beginning of range
   40         GN= V(NBEG)-E
              IF(GN.GT.10.D0) THEN
c** If potential has [V(1)-E] so high that H is (locally) much too
c  large, then shift inner starting point outward.
                  NBEG= NBEG+1
                  IF(NBEG.LT.N) GO TO 40
                  IF(IWR.NE.0) WRITE(6,613)
                  GO TO 999
                  ENDIF
              IF((ITER.LE.1).AND.(IWR.NE.0)) THEN
                  IF(NBEG.GT.1) WRITE(6,609) JROT,EO,NBEG
                  IF(GN.LE.0.d0) WRITE(6,604) JROT,EO,NBEG,V(NBEG)/BFCT
                  ENDIF
c** Initialize outward wave function with a node:  WF(NBEG) = 0.
              SB= 0.d0
              SI= 1.d0
              GI= V(NBEG+1)-E
              Y1= SB*(1.d0- HT*GN)
              Y2= SI*(1.d0- HT*GI)
            ENDIF
c
          WF(NBEG)= SB
          WF(NBEG+1)= SI
          NBEGB= NBEG
          NBEG2= NBEG+2
          IF(INNER.GT.0) MSAVE= N
c** Actual outward integration loops start here
          DO  I= NBEG2,MSAVE
              Y3= Y2+Y2-Y1+GI*SI
              GI= V(I)-E
              SI= Y3/(1.d0- HT*GI)
              WF(I)= SI
              IF(DABS(SI).GE.1.D+17) THEN
c** Renormalize to prevent overflow of  WF(I)  in classically forbidden
c  region where  V(I) .gt. E
                  SI= 1.d0/SI
                  NBEG= NBEGB
                  DO  J= NBEG,I
                      WF(J)= WF(J)*SI
                      ENDDO
                  NBEGB= I
                  Y2= Y2*SI
                  Y3= Y3*SI
                  SI= 1.d0
                  ENDIF
              Y1= Y2
              Y2= Y3
              ITP1= I
c** Exit from this loop at onset of classically allowed region
              IF(GI.LE.0.d0) GO TO 52
              ENDDO
          MS= MSAVE
          IF((INNER.EQ.0).AND.(GN.LE.0.d0)) GO TO 60
          IF(IWR.NE.0) WRITE(6,612) KVIN,JROT,EO,MSAVE
          GO TO 999
   52     ITP1P= ITP1+1
          MS= ITP1
          IF(INNER.GT.0) GO TO 60
          DO  I= ITP1P,MSAVE
              Y3= Y2+Y2-Y1+GI*SI
              GI= V(I)-E
              SI= Y3/(1.d0- HT*GI)
              WF(I)= SI
              IF(DABS(SI).GT.1.D+17) THEN
c** Renormalize to prevent overflow of  WF(I) , as needed.
                  SI= 1.d0/SI
                  NBEG= NBEGB
                  DO  J= NBEG,I
                      WF(J)= WF(J)*SI
                      ENDDO
                  NBEGB= I
                  Y2= Y2*SI
                  Y3= Y3*SI
                  SI= 1.d0
                  ENDIF
              Y1= Y2
              Y2= Y3
              ENDDO
          MS= MSAVE
c** Finished outward integration.  Normalize w.r.t. WF(MSAVE)
   60     SI= 1.d0/SI
          YOUT= Y1*SI
          YM= Y2*SI
          RATIN= WF(NBEG+1)*SI
          DO  I= NBEG,MS
              WF(I)= WF(I)*SI
              ENDDO
          IF(INNER.GT.0) GO TO 10
c----- Finished numerical integration ... now correct trial energy
c** DF*H  is the integral of  (WF(I))**2 dR
   70     DF= 0.d0
          DO  J= NBEG,NEND
              DF= DF+WF(J)**2
              ENDDO
c** Add edge correction to DF assuming wave function dies off as simple
c  exponential past R(NEND);  matters only if WF(NEND) unusually large.
          IF((E.LE.DSOC).AND.(WF(NEND).NE.0)) THEN
              IF((KVIN.GE.-10).AND.(WF(NEND-1)/WF(NEND).GT.1.d0))
     1              DF= DF+ WF(NEND)**2/(2.d0*DLOG(WF(NEND-1)/WF(NEND)))
              ENDIF
          F= (-YOUT-YIN+2.d0*YM+GI)
          DOLD= DE
          IF(DABS(F).LE.1.D+30) THEN
              DE= F/DF
            ELSE
              F= 9.9D+30
              DF= F
              DE= DABS(0.01D+0 *(DSOC-E))
            ENDIF
          IF(IWR.GT.2) THEN
              DEPRN = DE/BFCT
              XEND= RMINN+NEND*H
c** RATIN & RATOUT  are wave fx. amplitude at inner/outer ends of range
c  relative to its value at outermost extremum.
              WRITE(6,603) IT,EO,F,DF,DEPRN,MSAVE,RR,RATIN,RATOUT,
     1                                                  XEND,NBEG,ITP1
              ENDIF
c** Test trial eigenvalue for convergence
          IF(DABS(DE).LE.DABS(EPS)) GO TO 100
          E= E+DE
c** KV.ge.998  Option ... Search for highest bound level.  Adjust new
c  trial energy downward if it would have been above dissociation.
          IF((KVIN.GE.998).AND.(E.GT.VMX)) E= VMX- 2.d0*(VMX-E+DE)
          EO= E/BFCT
          IF((IT.GT.4).AND.(DABS(DE).GE.DABS(DOLD)).AND.
     1                                       ((DOLD*DE).LE.0.d0)) THEN
c** Adjust energy increment if having convergence difficulties.  Not
c  usually needed except for some quasibounds extremely near  VMAX .
              ICOR= ICOR+1
              DEP= DE/BFCT
              IF(IWR.NE.0) WRITE(6,617) IT,DEP
              DE= 0.5d0*DE
              E= E-DE
              EO= E/BFCT
              ENDIF
   90     CONTINUE
c** End of iterative loop which searches for eigenvalue ************
c-------------------------------------------------------------------*
c** Convergence fails, so return in error condition
      E= E-DE
      EO= E/BFCT
      DEPRN= DE/BFCT
      IF(IWR.NE.0) WRITE(6,620) KVIN,JROT,ITER,DEPRN
      GO TO 999
  100 IF(IWR.NE.0) THEN
          IF(IWR.GE.3) WRITE(6,619)
          IF((DABS(RATIN).GT.RATST).AND.(INNODE.GT.0)
     1                  .AND.(RMIN.GT.0.d0)) WRITE(6,614) JROT,EO,RATIN
          IF((E.LT.DSOC).AND.(DABS(RATOUT).GT.RATST)) THEN
              WKBTST=0.5d0*DABS(V(NEND)-V(NEND-1))/DSQRT((V(NEND)-E)**3)
              IF(WKBTST.GT.1.d-3)WRITE(6,615)JROT,EO,RATOUT,RATST,WKBTST
              ENDIF
          ENDIF
      KKV = 0
c** Perform node count on converged solution
      PROD= WF(ITP1)*WF(ITP1-1)
      J1= ITP1+1
      J2= NEND-1
      DO  J= J1, J2
          PPROD= PROD
          PROD= WF(J)*WF(J-1)
          IF((PPROD.LE.0.d0).AND.(PROD.GT.0.d0)) KKV= KKV+1
          ENDDO
      KV = KKV
c** Normalize & find interval (NBEG,NEND) where WF(I) is non-negligible
      SN= 1.d0/DSQRT(H*DF)
      DO  I= NBEG,NEND
          WF(I)= WF(I)*SN
          ENDDO
      IF(ITP1.LE.1) GO TO 122
      J= ITP1P
      DO  I= 1,ITP1
          J= J-1
          IF(DABS(WF(J)).LT.RATST) GO TO 119
          ENDDO
  119 NBEG= J
      IF(NBEG.LE.1) GO TO 122
      J= J-1
      DO  I= 1,J
          WF(I)= 0.d0
          ENDDO
  122 IF(KVIN.GE.-10) THEN
c** For "non-wall" cases, move NEND inward to where wavefunction
c  "non-negligible"
          J= NEND-1
          DO  I= NBEG,NEND
              IF(DABS(WF(J)).GT.RATST) GO TO 126
              J= J-1
              ENDDO
  126     NEND= J+1
          END IF
      IF(NEND.LT.N) THEN
c** Zero out wavefunction array at distances past NEND
          DO  I= NEND+1,N
              WF(I)= 0.d0
              ENDDO
          ENDIF
      IF(LPRWF.LT.0) THEN
c** If desired, write every |LPRWF|-th point of the wave function
c  to a file on channel-10, starting at the NBEG-th mesh point.
          JPSIQ= -LPRWF
          NPR= 1+(NEND-NBEG)/JPSIQ
          RINC= RH*JPSIQ
          RSTT= RMINN+NBEG*RH
c** Write every JPSIQ-th point of the wave function for level  v=KV
c  J=JROT , beginning at mesh point NBEG & distance RSTT where
c  the NPR values written separated by mesh step RINC=JPSIQ*RH
          WRITE(10,701) KV,JROT,EO,NPR,RSTT,RINC,NBEG,JPSIQ
          WRITE(10,702) (RMINN+I*RH,WF(I),I=NBEG,NEND,JPSIQ)
          GO TO 140
          ENDIF
c** Print solutions every  LPRWF-th  point, 6 to a line, in columns.
      IF(LPRWF.GT.0) THEN
          NLINES= ((1+(NEND-NBEG)/LPRWF)+3)/4
          IPSID= LPRWF*NLINES
          WRITE(6,605) KV,JROT,EO
          DO  J= 1,NLINES
              JJ= NBEG+(J-1)*LPRWF
              IJK= 0
              DO  IJ= JJ,NEND,IPSID
                  IJK= IJK+1
                  RWR(IJK)= RMINN+IJ*H
                  SWR(IJK)= WF(IJ)
                  ENDDO
              WRITE(6,606) (RWR(I),SWR(I),I= 1,IJK)
              ENDDO
          ENDIF
  140 IF(IWR.EQ.1) WRITE(6,607) KV,JROT,EO
cc
cc    IF(IWR.NE.0) WRITE(6,699)  rminn+itp1*rh,eO,rminn+msave*rh,eo
cc699 format('    & turning points:',2(f8.5,f11.4))
cc
      IF(IWR.GE.2) WRITE(6,607) KV,JROT,EO,ITER,RR,RATIN,RATOUT
c** For quasibound levels, calculate width in subroutine "WIDTH"
      IF((E.GT.DSOC).AND.(KVIN.GT.-10)) CALL WIDTH(KV,JROT,E,EO,DSOC,
     1  V,WF,VMX,RMIN,H,BFCT,IWR,ITP1,ITP3,INNER,N,GAMA)
      RETURN
c** ERROR condition if  E.gt.V(R)  at outer end of integration range.
  998 XPR= RMINN+MS*H
      VPR= V(MS)/BFCT
      IF(IWR.NE.0) WRITE(6,608) EO,MS,VPR,XPR,IT
c** Return in error mode
  999 KV= -1
      RETURN
  601 FORMAT(/' Solve for  v=',I3,'   J=',I3,'   ETRIAL=',1PD15.7,
     1   '  INNER=',i2,'   WF(1st) WF(NEND)' )
  602 FORMAT(' ITER    ETRIAL',8X,'F(E)      DF(E)     D(E)',
     1 5X,'M    R(M)  /WF(M)   /WF(M)  R(NEND) NBEG ITP1'/
     2  1X,96('-'))
  603 FORMAT(I4,1PD15.7,3D10.2,I5,0PF7.3,1P2D9.1,0PF8.2,I4,I5)
  604 FORMAT('   NOTE:  for  J=',I3,'   EO=',F12.4,' .ge. V(',i3,')=',
     1  F12.4)
  605 FORMAT(/' Solution of radial Schr. equation for   E(v=',I3,',J=',
     1  I3,') =',F15.7/2x,4('    R(I)   WF(I)   ')/2X,38('--') )
  606 FORMAT(2X,4(F8.3,F11.7))
  607 FORMAT('E(v=',I3,',J=',I3,')=',F11.4,1x,I3,' Iterations',
     1  '   R(M)=',F6.3,'  WF(NBEG)/WF(M)=',1PD8.1/
     2  57x,'WF(NEND)/WF(M)=',D8.1)
  608 FORMAT(' *** SCHRQ Error:  E=',F9.2,' > V(',I5,')=',F9.2,
     1  '  at  Rmax=',F6.2,'  for  IT=',I2)
  609 FORMAT(' *** For  J=',I3,'   E=',1PD15.7,"  integration can't",
     1 ' start till past mesh'/37x,'point',I5,',  so RMIN smaller than n
     2eeded')
  610 FORMAT(/' Attempt to find the highest bound level starting from',
     1 '   ETRIAL =',1PD9.2)
  611 FORMAT(' *** SCHRQ inward search at   J=',i3,'   E=',f11.2,
     1  ' finds no classical region')
  612 FORMAT(/' *** ERROR *** for   v =',I3,'   J =',I3,'   E =',
     1  F12.4,'  Innermost turning point not found by   M = MSAVE =',I5)
  613 FORMAT(/' *** ERROR in potential array ... V(I) everywhere',
     1 ' too big to integrate with given  increment')
  614 FORMAT(' *** CAUTION *** For  J=',I3,'  E=',G15.8/16x,
     1 'WF(first)/WF(Max)=',D9.2,'  suggests  RMIN  may be too large')
  615 FORMAT(' ** CAUTION ** For  J=',I3,'  E=',1PD13.6,
     1 '  WF(NEND)/WF(Max)=',D8.1,' >',D8.1/4X,'& initialization ',
     2 'quality test ',1PD8.1,' > 1.D-3   so RMAX may be too small')
  616 FORMAT(' ** WARNING *** For  v=',I2,', J=',I3,' at  E=',G14.7,
     1  ':  inward propagation finds no turning point ... Energy too low
     2 or potential too weak' )
  617 FORMAT(' *** SCHRQ has a convergence problem, so for  IT=',I2,
     1 '  cut  DE=',1PD10.2,'  in HALF' )
  618 FORMAT(' *** For  J=',I3,'  E=',F9.2,'  JWKB start gives  SB/SI=',
     1  1PD10.3,'  so use a node.')
  619 FORMAT(1X,96('-'))
  620 FORMAT(' *** CAUTION for  v=',I3,'  J=',I3,"  SCHRQ doesn't conver
     1ge by  ITER=",I2,'  DE=',1PD9.2)
  701 FORMAT(/2x,'Level  v=',I3,'   J=',I3,'   E=',F12.4,' ,  wave funct
     1ion at',I6,' points.'/7x,'R(1-st)=',F12.8,'   mesh=',F12.8,
     2  '   NBEG=',I4,'   |LPRWF|=',I3)
  702 FORMAT((1X,4(f9.4,f10.6)))
      END
c23456789 123456789 123456789 123456789 123456789 123456789 123456789 12

c*******************************************************************
      SUBROUTINE QBOUND(KV,JROT,E,EO,VMX,DSOC,V,RMIN,H,GB,GI,SB,SI,N,
     1  ITP3,IWR,IQTST,BFCT,IT)
c*******************************************************************
c** Subroutine to initialize quasibound level wave function as Airy
c  function at third turning point (if possible). For the theory see
c  J.Chem.Phys. 54, 5114 (1971),  J.Chem.Phys. 69, 3622-31 (1978)
c----------------------------------------------------------------------
c** IQTST  is error flag. *** If (IQTST.lt.0) initialization fails
c  so eigenvalue calculation aborts *** (IQTST.gt.0) for successful
c  Airy function initialization. *** (IQTST=0) if Airy function
c  initialization prevented because 3-rd turning point beyond
c  range, so that WKB initialization is used.
c----------------------------------------------------------------------
      INTEGER I,II,IQTST,IT,ITP3,IWR,J,JROT,K,KV,N
      REAL*8  A1,A2,A13,A23,BFCT,
     1        C1A,C2A,DF,DSOC,E,EO,FBA,FIA,FJ,GB,GBA,GI,GIA,H,
     2        RMIN,RMINN,SB,SI,SL,V(N),VMX,VMXPR,XJ1
      DATA C1A/0.355028053887817D0/,C2A/0.258819403792807D0/
c+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      IQTST=1
      RMINN=RMIN-H
c** Start by searching for third turning point.
      J=N
      IF(V(N).GT.E) GO TO 22
      DO  I=2,N
          J=J-1
          IF(V(J).GT.E) GO TO 10
          ENDDO
      GO TO 14
c** Check that there is a classically allowed region inside this point
c  and determine height of barrier maximum.
   10 II=J
      VMX=DSOC
      DO  I=2,J
          II=II-1
          IF(V(II).LE.E) GO TO 16
          IF(V(II).GT.VMX) VMX=V(II)
          ENDDO
c** Energy too high ... find no more than one turning point.
   14 XJ1=RMINN+J*H
c ... Search outward for barrier height to facilitate energy correction
      IF(J.EQ.1) J= 2
      K=J-1
      DO  I=J,N
          IF(V(I).GT.V(K)) GO TO 120
          K=I
          ENDDO
      VMX=V(K)
      GO TO 130
  120 K=K+2
      J=K-1
      DO  I=K,N
          IF(V(I).LT.V(J)) GO TO 126
          J=I
          ENDDO
  126 VMX=V(J)
  130 VMXPR=VMX/BFCT
      IF(IWR.NE.0) WRITE(6,608) JROT,EO,VMXPR,XJ1
      ITP3= J
      IQTST=-1
      GO TO 100
   16 ITP3= J+1
c** ITP3 is the first mesh point outside classically forbidden region
      GB=V(ITP3)-E
      GI=V(ITP3-1)-E
      FJ=GI/(GI-GB)
c** Treat quasibound levels as bound using outer boundary condition
c  of Airy function at third turning point ... as discussed by
c  R.J.Le Roy and R.B.Bernstein  in  J.Chem.Phys. 54,5114(1971).
      SL=(GI-GB)**(1.d0/3.d0)/H
      IF((SL*H).LT.1.d0) THEN
          A1=GI/(SL*H)**2
          A2=GB/(SL*H)**2
          A13=A1*A1*A1
          A23=A2*A2*A2
          FIA= 1.d0+ A13*(A13*(A13+72.D0)+2160.D0)/12960.D0
          GIA=A1+A1*A13*(A13*(A13+90.D0)+3780.D0)/45360.D0
          FBA= 1.d0+ A23*(A23*(A23+72.D0)+2160.D0)/12960.D0
          GBA=A2+A2*A23*(A23*(A23+90.D0)+3780.D0)/45360.D0
c** Airy function  Bi(X)  at points straddling 3-rd turning point
          SI=C1A*FIA+C2A*GIA
          SB=C1A*FBA+C2A*GBA
          GO TO 100
          ENDIF
c** If Airy function expansion unreliable, use zero slope at third
c  turning point as quasibound outer boundary condition.
      DF=GI-GB
      SI= 1.d0+ DF*FJ**3/6.d0
      SB= 1.d0 -DF*(1.d0- FJ)**3/6.d0
      IF(IWR.NE.0) WRITE(6,606) KV,JROT,EO,IT
      GO TO 100
c** If 3-rd turning point beyond range start with WKB wave function
c  at end of range.
   22 IF(IWR.NE.0) WRITE(6,607) JROT,EO
      ITP3= N
      IQTST=0
      GB=V(ITP3)-E
      GI=V(ITP3-1)-E
      VMX=V(ITP3)
      II=ITP3
      DO  I=2,ITP3
          II=II-1
          IF(V(II).LT.VMX) GO TO 100
          VMX=V(II)
          ENDDO
      IF(IWR.NE.0) WRITE(6,604)
c** End of quasibound level initialization schemes.
      IQTST=-9
  100 RETURN
  604 FORMAT(" **** QBOUND doesn't work ... no classically allowed regio
     1n accessible at this energy.")
  606 FORMAT(' *** CAUTION ***  v=',I3,'   J=',I3,'   E=',1PD13.6,
     1 '   IT=',I2/5x,'Airy initialization unstable so use  zero slope',
     2 'at  R(3-rd)' )
  607 FORMAT(' *** For  J=',I3,'  E=',F9.2,
     1  '  R(3-rd) > RMAX  & E < V(N)  so try WKB B.C. @ RMAX')
  608 FORMAT(' For J=',I3,'  ETRY=',F11.4,' > VMAX=',F11.4,
     1  '  find onee turn point:  R=',F6.2)
      END
c23456789 123456789 123456789 123456789 123456789 123456789 123456789 12

c***********************************************************************
c** Subroutine to calculates quasibound level tunneling lifetime/width
c** For relevant theory see Le Roy & Liu [J.Chem.Phys.69,3622-31(1978)]
c  and Connor & Smith [Mol.Phys. 43, 397 (1981)] and Huang & Le Roy
c  [J.Chem.Phys. 119, 7398 (2003); Erratum, ibid, 127, xxxx (2007)]
c** Final level width calculation from Eq.(4.5) of Connor & Smith.
c  Rearranged slightly for consistency with PotFit derivatives 9/05/02
c-----------------------------------------------------------------------
      SUBROUTINE WIDTH(KV,JROT,E,EO,DSOC,V,S,VMX,RMIN,H,BFCT,IWR,ITP1,
     1  ITP3,INNER,N,GAMA)
c++ "WIDTH" calls subroutine "LEVQAD" ++++++++++++++++++++++++++++++++++
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      INTEGER  I,IMM,INNER,IRM,ITP1,ITP1P,ITP1P1,ITP2,ITP2M,ITP2M2,
     1         ITP2P1,ITP2P2,ITP3,IWR,JROT,KV,KVI,KVO,
     2         M,M2,N,NN,NST
      REAL*8  ANS1,ANS2,ARG,BFCT,COR,
     1        D1,D2,D3,DFI,DSGB,DSGN,DSOC,DWEB,OMEGJC,
     2        E,EO,EMSC,EMV,G1,G2,G3,GA,GAMA,GAMALG,
     3        H,H2,HBW,HBWB,PI,PMX,RMIN,RMINN,RMX,RT,RT1,RT2,
     4        S(N),SM,TAU,TAULG,TI,TUN0,U1,U2,V(N),VMAX,VMX,
     7        XJ,XX
      CHARACTER*5 LWELL(2)
      DATA PI/3.141592653589793D0/
      DATA LWELL/'INNER','OUTER'/
      RMINN= RMIN- H
      H2= H*H
c** ITP1 is first mesh point to right of innermost turning point.
   40 ITP1P= ITP1+ 1
      ITP1P1= ITP1P+ 1
      IRM= ITP1- 1
c** Calculate JWKB tunneling probability from quadrature over barrier
c** First must locate 2-nd turning point.
      DO  I= ITP1P1,ITP3
          ITP2= I
          IF(V(I).GT.E) GO TO 202
          ENDDO
      GAMA= 0.d0
      GO TO 250
  202 ITP2P1= ITP2+ 1
      ITP2P2= ITP2+ 2
c** ITP2M is the last mesh point before the 2-nd turning point.
      ITP2M= ITP2- 1
      ITP2M2= ITP2- 2
      G1= V(ITP2M)- E
      G2= V(ITP2)- E
      GA= V(ITP2P1)- E
c** Quadrature over barrier starts here.
      CALL LEVQAD(G1,G2,GA,H,RT,ANS1,ANS2)
      SM= ANS2/H
      IF(GA.LT.0.d0) GO TO 218
      SM= SM+ 0.5d0*DSQRT(GA)
      PMX= VMX
      M2= ITP2P2
  204 DO  I=M2,ITP3
          M= I
          GA= V(I)- E
          IF(V(I).GT.PMX) PMX=V(I)
          IF(GA.LT.0.d0) GO TO 210
          SM= SM+ DSQRT(GA)
          ENDDO
      IF(V(M).GT.V(M-1)) THEN
          IF(IWR.NE.0) WRITE(6,602) KV,JROT
          GO TO 250
          ENDIF
      RMX= RMINN+ M*H
      U1= DSQRT(GA/(V(M)- DSOC))
      U2= DSQRT((E- DSOC)/(V(M)- DSOC))
      SM= SM- 0.5d0*DSQRT(GA)+ (DLOG((1.d0+U1)/U2)-U1)*RMX*
     1                                             DSQRT(V(M)- DSOC)/H
      XJ= (DSQRT(1.d0+ 4.d0*(V(M)-DSOC)*(RMX/H)**2)- 1.d0)*0.5d0
      IF(IWR.NE.0) WRITE(6,603) JROT,EO,XJ,RMX
      GO TO 218
  210 IF(M.LT.ITP3) THEN
c** If encounter a double-humped barrier, take care here.
          IF(IWR.NE.0) WRITE(6,609) KV,JROT,EO,M
          KVO= 0
          DSGN= DSIGN(1.d0,S(M-1))
c** Find the effective quantum number for the outer well
          DO  I= M,ITP3
              DSGB= DSGN
              DSGN= DSIGN(1.d0,S(I))
              IF((DSGN*DSGB).LT.0.d0) KVO=KVO+1
              ENDDO
          KVI= KV- KVO
          IF(INNER.EQ.0) THEN
c** For levels of outer well, get correct width by changing ITP1
              ITP1= M
              IF(IWR.GT.0) WRITE(6,610) KVO,LWELL(2)
              GO TO 40
              ENDIF
          IF(IWR.GT.0) WRITE(6,610) KVI,LWELL(1)
c** For "inner-well" levels, locate outer barrier
          DO  I= M,ITP3
              M2= I
              GA= V(I)- E
              IF(GA.GE.0.d0) GO TO 204
              ENDDO
          GO TO 218
          ENDIF
      G3= V(M-2)- E
      G2= V(M-1)- E
      CALL LEVQAD(GA,G2,G3,H,RT,ANS1,ANS2)
      SM= SM- 0.5d0*DSQRT(G3)-DSQRT(G2) + ANS2/H
  218 EMSC= -SM/PI
      IF(INNER.GT.0) VMX= PMX
      VMAX= VMX/BFCT
c** Tunneling factors calculated here ** TUN0 is simple WKB result
c  as in Child's eqs.(57c) & (59).
c .....  EPSRJ= -2.* PI* EMSC
      TUN0= 0.5d0*DEXP(2.d0*PI*EMSC)
c ... for permeability calculate Connor-Smith's Eq.(3.7) \omega=OMEGJC
      OMEGJC= DSQRT(1.d0+ 2.d0*TUN0) - 1.d0
c ... alternate calculation to give better precision for small TUN0
      IF(TUN0.LT.1.d-5) OMEGJC= TUN0*(1.d0-0.5d0*TUN0*(1.d0-TUN0))
      OMEGJC= 4.d0*OMEGJC/(OMEGJC + 2.d0)
c** Quadrature for JWKB calculation of vibrational spacing in well HBW
      D1= E- V(IRM)
      D2= E- V(ITP1)
      D3= E- V(ITP1P)
      CALL LEVQAD(D1,D2,D3,H,RT,ANS1,ANS2)
      RT1= RT
      SM= ANS1/H
      IF(D3.LT.0.d0) GO TO 228
      SM= SM+ 0.5d0/DSQRT(D3)
      DO  I= ITP1P1,ITP2M2
          IMM= I
          EMV= E- V(I)
          IF(EMV.LT.0.d0) GO TO 222
          SM= SM+ 1.d0/DSQRT(EMV)
          ENDDO
      D3= E- V(ITP2M2)
      D2= E- V(ITP2M)
      D1= E- V(ITP2)
      GO TO 226
c** If encounter a double-minimum well, take care here.
  222 D1= EMV
      D2= E- V(IMM-1)
      D3= E- V(IMM-2)
      IF(IWR.NE.0) WRITE(6,605) KV,JROT,EO
  226 CALL LEVQAD(D1,D2,D3,H,RT,ANS1,ANS2)
      RT2=RT
      SM=SM-0.5d0/DSQRT(D3) + ANS1/H
c** Get HBW in same energy units (1/cm) associated with BFCT
  228 HBW=2.d0*PI/(BFCT*SM)
c** HBW fix up suggested by Child uses his eqs.(48)&(62) for HBW
c** Derivative of complex gamma function argument calculated as
c  per eq.(6.1.27) in Abramowitz and Stegun.
      NST= INT(DABS(EMSC)*1.D2)
      NST= MAX0(NST,4)
      ARG= -1.963510026021423d0
      DO  I= 0,NST
          NN= I
          XX= I + 0.5d0
          TI= 1.d0/(XX*((XX/EMSC)**2 + 1.d0))
          ARG= ARG+TI
          IF(DABS(TI).LT.1.D-10) GO TO 233
          ENDDO
c ... and use continuum approximation for tail of summation (???)
  233 COR= 0.5d0*(EMSC/(NN+1.d0))**2
      ARG= ARG+ COR- COR**2
c** Now use WKL's Weber fx. approx for (?) derivative of barrier integral ..
      DWEB= (EO-VMAX)*BFCT/(H2*EMSC)
      DFI= (DLOG(DABS(EMSC)) - ARG)*BFCT/(H2*DWEB)
      HBWB= 1.d0/(1.d0/HBW + DFI/(2.d0*PI))
c** Width from formula (4.5) of  Connor & Smith, Mol.Phys.43,397(1981)
c [neglect time delay integral past barrier in their Eq.(4.16)].
      IF(EMSC.GT.-25.D0) THEN
          GAMA= (HBWB/(2.d0*PI))* OMEGJC
          TAU= 0.D0
          IF(GAMA.GT.1.D-60) TAU= 5.308837457D-12/GAMA
c** GAM0 = TUN0*HBW/PI  is the simple WKB width GAMMA(0) discussed by
c  Le Roy & Liu in J.C.P.69,3622(1978).
          IF(IWR.GT.0) WRITE(6,601) TAU,GAMA,HBWB,VMAX
        ELSE
          GAMALG= DLOG10(HBWB/(2.d0*PI))+2.d0*PI*EMSC/2.302585093D0
          TAULG= DLOG10(5.308837457D-12)-GAMALG
          IF(IWR.GT.0) WRITE(6,611) TAULG,GAMALG,HBWB,VMAX
        ENDIF
  250 RETURN
  601 FORMAT('    Lifetime=',1PD10.3,'(s)   Width=',D10.3,'   dG/dv=',
     1 0PF7.2,'   V(max)=',F9.2)
  602 FORMAT(' *** WARNING ***  For   v =',I3,'   J =',I3,'   cannot cal
     1culate width since barrier maximum beyond range')
  603 FORMAT(' *** For  J=',I3,'  E=',F9.2,'  R(3-rd) beyond range so tu
     1nneling calculation uses'/8X,'pure centrifugal potential with  J(a
     2pp)=',F7.2,'  for  R > R(max)=',F7.2)
  605 FORMAT(' **** CAUTION *** Width estimate only qualitative, as have
     1 a double-minimum well for   E(v=',I3,', J=',I3,')=',F15.7/15X,
     2 'a more stable result may be obtained by searching for the quasib
     3ound levels using option: INNER > 0 .')
  609 FORMAT(' *** CAUTION - Permeability estimate not exact as have a d
     1ouble-humped barrier:  E(v=',I3,', J=',I3,') =',G15.8,I6)
  610 FORMAT(16X,'(NOTE: this has the node count of a   v=',I3,2X,A5,
     1 '-well level')
  611 FORMAT(12X,'Log10(lifetime/sec)=',F10.5,' ;   Log10(width/cm-1)=',
     1 F10.5,'   Spacing=',G12.5,'   V(max)=',G14.7,'(cm-1)')
      END
c**********************************************************************
