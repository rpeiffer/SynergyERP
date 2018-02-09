  !include "src/callmainerr.inc"
  !
  ! Main error routine for any DL4 NOT part of .NET programs
  ! Do NOT use for ERP programs that interface with the front end (.NET).
  !
  If Spc(8) <> 10000
	dim msc4$[100] \ msc4$=msc$(4) 
	if Pos(msc4$, = "/",-1) let msc4$=msc4$[pos(msc4$,="/",-1)+1]
	call env(2,"PROGNAME",msc4$)
	call programdump()
	Call suberr(e$,Spc(8),Spc(10),Msc$(2))
  End If 
  Call mainerr(e$,Spc(8),buttonlist$[],nextlist$[])
  if rstr$=""
	call dxget(1,"focus",e$)
	if e$<>"" chain "dxblockgui.dl4"
	chain "MX000.dl4"
  end if