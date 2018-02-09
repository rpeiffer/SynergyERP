  !include "src/utilcallmainerr.inc"
  !
  ! Main error routine for any DL4 utilities running outside of dynamicX
  !
  If Spc(8) <> 10000
	dim msc4$[100] \ msc4$=msc$(4) 
	if Pos(msc4$, = "/",-1) let msc4$=msc4$[pos(msc4$,="/",-1)+1]
	call env(2,"PROGNAME",msc4$)
	if spc(8) = 11000
		call utilsearcherr(e$, e, Spc(10))
	else
		Call utilsuberr(e$,Spc(8),Spc(10),Msc$(2))
	end if
	call programdump()
  End If 
  Call utilmainerr(e$,Spc(8))
  chain ""