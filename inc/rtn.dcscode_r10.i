! rtn.dcscode.i                                                          
!                                                                        
! This routine is designed to find out the printer is allowed to print   
! the DCS Laser form or not.                                             
! It also find the printer name from printer device, then uses the       
! printer name in DCS channel file                                       
! You must include the following in your main program:                   
!     declare intrinsic function findchannel                                                      
GETDCSPRTRTYPE: ! Need DCS Printer                                       
DCSFNAME$ = " ",DCSFNAME$
DCSLINEIN$ = " ",DCSLINEIN$
dcsPRNTNAME$ = " ",dcsPRNTNAME$
! Find the printer's entry in CNTRL.LPT                                
F = 0
try
	dcsscr$ = Chf$(800)
else
	f = spc(8)
end try
DCSFNAME$ = dcsscr$ To " " !"remove any spaces                        
If F
	! No printer opened - set type to none
	dcsprtrtype = 0
	If F = 49 Let PRNTSCREEN = 1
	Goto end_getdcs
Else
	Call String(1,dcsscr$)
	pos_ = 1;POS1 = 0
	Search dcsscr$[pos_],"REPORTS",POS1
	If POS1 !" print to disk file
		prntdiskfile = 1
		Goto end_getdcs
	End If
	pos_ = 1;POS1 = 0
	GETDCSNXTPATH: ! until Done
		Search dcsscr$[pos_],"/",POS1
		If POS1
			pos_ = pos_ + POS1
			Goto GETDCSNXTPATH
		End If
	dcsx$ = "$" + dcsscr$[pos_]
	pos_ = 1;POS1 = 0
	Search dcsx$[pos_]," ",POS1
	If POS1
		pos_ = pos_ + POS1 - 1
		dcsx$[pos_] = ""
	End If
	chnl = FindChannel()
	Open #chnl,"cntrl/CNTRL.LPT"
	For X3 = 1 To Chf(chnl) - 1
		Mat Read #chnl,X3,0;dcsp1$;
		dcsp1$ = dcsp1$ To " " ! remove any spaces that may exist
		If dcsp1$ = dcsx$ Goto GOTDCSPTYPE
	Next X3
	dcsprtrtype = 0 \ Goto END_DCSPTYPE
	GOTDCSPTYPE: ! got the Record
		Mat Read #chnl,X3,30;dcsP1;
		dcsprtrtype = dcsP1[4]
	END_DCSPTYPE: Close #chnl
End If
!"allow to print the DCS Laser From, find the printer name                
If dcsprtrtype
	Call FindF(DCSFNAME$,FOUND)
	If Not(FOUND)
		dcsprtrtype = 0 \ Goto end_getdcs
	End If
	!
	! locate the printer designation
	! this needs to be in the format:
	! PRINTER_NAME='actual name'
	!
	ch_ini = FindChannel()
	Ropen #ch_ini,DCSFNAME$
	LOOP_INI: Read #ch_ini;DCSLINEIN$;
		DCSLINEIN$ = DCSLINEIN$ To "\15\"
		COUNTLINE = COUNTLINE + 1
		If COUNTLINE > 30 Goto end_getdcs
		! IF DCSLINEIN$[1,6]<>"PTRDEV" AND DCSLINEIN$[1,7]<>"#PTRDEV" GOTO LOOP_INI:
		If DCSLINEIN$[1,14] <> "PRINTER_NAME='" Goto LOOP_INI
	TMPLEN = Len(DCSLINEIN$)
	If TMPLEN <= 0
		dcsprtrtype = 0 \ Goto end_getdcs
	End If
	pos_ = 1;POS1 = 0
	Search DCSLINEIN$[pos_],"PRINTER_NAME='",POS1
	If POS1 = 0
		pos_ = 1
		Search DCSLINEIN$[pos_],"-d",POS1
		If POS1 = 0 Let dcsprtrtype = 0 \ Goto end_getdcs
	End If
	For I = POS1 + 14 To TMPLEN
		If DCSLINEIN$[I,I] = "'" Let POS2 = I \ Goto GOTDCSPRNTNAME
	Next I
	GOTDCSPRNTNAME: !
	dcsPRNTNAME$ = DCSLINEIN$[POS1 + 14,POS2 - 1]
End If
end_getdcs: ! 
If dcsprtrtype Close #ch_ini
Return 