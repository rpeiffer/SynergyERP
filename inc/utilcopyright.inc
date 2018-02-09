!include "src/utilcopyright.inc"
!release 9.0
!
!all rights reserved. (c)copyright 2007 by: Universal Business Systems
!
! *declare common dl4 intrinsic subs & functions
declare intrinsic function trim$,dateusing$,fmtof
declare intrinsic sub programdump,env,SetGlobals,GetGlobals
!
External Lib "utillib.lib"
!
! *declare common external libs & subs & functions
external lib "utillib.lib" !general routines
declare external sub SetUtilSession
declare external sub utilsuberr,utilmainerr,utilsearcherr
