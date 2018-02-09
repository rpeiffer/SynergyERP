! -- utilerr.i
!
! utility error routines - include inside "try" and else should goto Err_trap
!
Declare Intrinsic Sub InpBuf,String


ERR_TRAP: Rem *Error routine (escape trap)   V3.1 8/94 G.DOSCHER/REK
	If Spc(8) = 99 ! "escape hit/return back
		Print 'RB ML';" ";'ML';
		Return -1
	End If 
	If Spc(8) = 123 ! "record lock
		Escdis 
		Window Open @0,0; Size 30,3; Using ""
		Print @0,0;'RB BR';"RECORD LOCKED - PLEASE WAIT";'ER';
		Signal 3,50
		Window Close 
		Escclr 
		Return -1
	End If 
	Dim 2%
	Window Off 
	Print @0,Msc(34) - 1;'CR RB';"*********** BASIC ERROR ************";'CE RB'
	ENUM = Spc(8);ELINE = Spc(10);CTERR = 0
	If ENUM = 157 Let CTERR = Err(8)
	Print 'UK RB';"ERROR ";(ENUM + (CTERR * .001));"HAS OCCURRED ";
	Print "AT LINE";ELINE;'CL CR';"IN PROGRAM ";
Goto ERR_MAIN

ERR_SEARCH: Rem *Error routine (search error)   V3.1 8/94 G.DOSCHER/REK
	Dim 2%
	Window Off 
	Print @0,Msc(34) - 1;'CR RB';"*********** SEARCH  ERROR **********";'CE RB'
	ENUM = E + 1000;ELINE = Spc(16);CTERR = 0
	If E = 5 Let CTERR = Err(8)
	Print 'RB';"RETURN STATUS";(E + (CTERR * .001));
	Print "/ STATEMENT";ELINE;'CL CR';"IN PROGRAM ";
Goto ERR_MAIN

ERR_ESCAPE: Rem *Error routine (escape abort)   V3.1 8/94 G.DOSCHER/REK
	If Spc(8) <> 99 Goto ERR_TRAP
	If Err 0 Rem
	CNTRLB_ERR_ESCAPE: Dim ABREQ$[10]
	If Err 0 Gosub ERR_TRAP
	Print @0,Msc(34) - 1;"DO YOU WISH TO ABORT THIS PROGRAM (Y/N)?  ";'RB CL';
	Input Len 16385;""ABREQ$
	Call String(1,ABREQ$)
	Print @0,Msc(34) - 1;'CL';
	If Err 0 Gosub ERR_ESCAPE
	If ABREQ$ <> "Y"
		Print 'ML';" ";'ML';
		Return -1
	End If 
Goto OUTEND

ERR_MAIN: Rem "main error handling logic
	If Err 0 Rem
	Dim PNAME$[50],PNAME1$[50],PNAME2$[80]
	PNAME$ = Msc$(4)
	Call String(1,PNAME$)
	POS_ = 1;POS1 = 0
	NAMEPARSE: Rem "get program name from path
	Search PNAME$[POS_],"/",POS1
	If POS1
		POS_ = (POS_ + POS1)
		Goto NAMEPARSE
	End If 
	Print "NAME: ''";PNAME$[POS_];"''";'CL CR';
	Print "PLEASE CALL UNIVERSAL FOR ASSISTANCE!";'CL'
	Print "TRACE: ";'CL';
	STACKLOOP: Rem "print nesting information
	Print Using "<#####> ";Spc(16);
	If Spc(14) Goto STACKLOOP
	Print 'CR';"************************************"
	Close #0
	Open #0,"errorlog"
	Write #0,Chf(0);PNAME$[POS_],ENUM,ELINE,Spc(5),Spc(6),Spc(2),Spc(3),CTERR;
	Close #0
	Input Tim 6000;'CR';"PLEASE HIT <CR> TO CONTINUE: ";PNAME1$
	PNAME1$ = " ",PNAME1$;PNAME1$ = "HOME"
	Call String(2,PNAME$)
	System 28,PNAME1$
	Call String(5,PNAME2$)
	PNAME2$ = " ",PNAME2$
	PNAME2$ = "CHAIN ''SAVE <00>",PNAME1$,"/",PNAME$[POS_],".save!''\15\"
	Call InpBuf(PNAME2$)
Stop 

