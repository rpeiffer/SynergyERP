  !include "src/callmainerrnet.inc"
  !
  ! Main error routine for any DL4 with .NET programs which
  ! are meant to be "called" dl4 programs, I.E.
  !
  ! call "dl4_prog_name",parm1$,parm2...
  !
  ! NOT FOR called subroutines (either internal or external).  For those
  ! use the standard src/callsuberr.inc
  !

  select case spc(8)
	case 10000
		! this is default "message" error
		! e$ should be set with message to display
	case 11000
		! search error
		dim msc4$[100] \ msc4$=msc$(4) 
		if Pos(msc4$, = "/",-1) let msc4$=msc4$[pos(msc4$,="/",-1)+1]
		call env(2,"PROGNAME",msc4$)
		call programdump()
		call searcherr(e$, e, Spc(10))
	case else
		dim msc4$[100] \ msc4$=msc$(4) 
		if Pos(msc4$, = "/",-1) let msc4$=msc4$[pos(msc4$,="/",-1)+1]
		call env(2,"PROGNAME",msc4$)
		call programdump()
		call suberr(e$,Spc(8),Spc(10),Msc$(2))
  end select
  Call mainerr(e$,Spc(8),buttonlist$[],nextlist$[],rstr$)
  if rstr$=""
	call dxget(1,"focus",e$) !dxblockgui coding
	if e$<>"" chain "dxblockgui.dl4"
	chain "MX000.dl4"
  end if