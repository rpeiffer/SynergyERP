  !include "src/callsuberr.inc"
  !
  ! This is NOT a main error routine.  This should be included
  ! in any "sub" or "function" routine (whether it is an intenal
  ! or an external in a lib which is to be pulled into other
  ! "main" routines).
  !
  ! NOTE: Assumes that subroutine / function call is wrapped
  ! in another "try" statement that will catch the returned
  ! error.
  !
  !sub error routine
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
  if err 0 
  error 10000