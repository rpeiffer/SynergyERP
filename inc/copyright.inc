!include "src/copyright.inc"
!release 9.0
!
!all rights reserved. (c)copyright 2007 by: Universal Business Systems
!
! *declare common dl4 intrinsic subs & functions
declare intrinsic function trim$,dateusing$,fmtof
declare intrinsic sub dxopen,dxget,dxset,dxclose,dxsave,programdump,env
!
! *declare common external libs & subs & functions
external lib "libgeneral.lib" !general routines
declare external sub suberr,mainerr,searcherr,getsession,setoutput,addtostr
declare external function getmsg$,expandarray
declare external function GetParameter$
declare external sub ERPCronSuccess