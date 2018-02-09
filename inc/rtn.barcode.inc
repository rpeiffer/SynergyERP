Declare Intrinsic Sub MiscStr,String
! Option Default Dialect IRIS1
! rtn.barcode.i
! DO NOT DELETE FEATURES FROM THE ROUTINE! CUSTOMERS ARE USING THIS STUFF!
! INCLUDE GETPRTRTYPE, ETC.
!GED:05/28/97:Added support for MTally LPC printers, cleaned-up & commented
!             some code.
!NPE:06/03/97:CCT#103726: Fix bug in the routine matching the printer driver
!             name in "cntrl.lpt" and the printer driver name in "chf(800)".
!             E.G. It considered "SPT2" a match for "SPT".
!GED:06/06/97:Major code cleanup/change.
!GED:06/06/97:Added minor support for MTally GPL printers (Type=6).
!JCS:07/09/98:Full support for MTally GPL printers (type=6).
!JCS:08/28/00:added option for Coding to be in-program (Type=7).
!#comment
!  This routine is designed to have standard strings defined for printers
!  that print Bar Codes, Etc.
!  Initially done for Genicom 3xxx Series Printers
!  If Customer has other types - set up in appropriate Set_BCV routine
!  and Set up a Printer Type Variable
!
!  You must include the following in your main program:
!    dim.barcode.i
!    dim.getchan.i
!    rtn.getchan.i
!
!
!Print the barcode using the following code:
!
!  Gosub Start_barcode:
!  Print #0;BARCODE$; ! "fill BARcode$ in program
!  Gosub End_barcode:
!
!#endcomment
! ===============================================================
! ----- Program parameters --------------------------------------
! ===============================================================
! (This is a partial list of what I've found so far - GED)
! bctype[1] = barcode type - see below
! bctype[2] = #/12 " height
! bctype[3] = human readable on/off
! bctype[4] = narrow bar width (norm=2)
! bctype[5] = wide bar width (norm=6)
! bctype[6] = narrow space width (norm=2)
! bctype[7] = wide space width (norm=6)
! bctype[8] = intercharacter gap (norm=2)
! bctype[9] = rotation (0-4)
! bctype[10]= density (0 for default, suggest 1 for High)
! bctype[11]= check digit print on/off
! bctype[12]= the tab position to start Barcode
! bctype[15]= MTally whether Printer save space(1) or not(0) for barcode
!
! --- barcode types -----  Warning!: not all are implemented!
!        Note: types are derived from Genicom printer
! bctype[1]    Description
! ---------    ------------------------------
!  0     Interleaved 2 of 5
!  1     Bidirectional 2 of 5
!  2     Matrix 2 of 5
!  3     Industrial 2 of 5
!  4     Code 3 of 9
!  5     EAN-8
!  6     EAN-13
!  7     Code 11
!  9     Codeabar (default start/stop = a/t)
!  10      Codeabar (default start/stop = b/n)
!  11      Codeabar (default start/stop = c/*)
!  12      Codeabar (default start/stop = d/e)
!  13      UPC-A
!  14      UPC-E
!  15      Code 93
!  16      Code 128 (subsets A/B/C)
!  17      Code 128
!  18      Code 128
!  19      MSI
!  20      UPC 2 Supplemental
!  21      UPC 5 Supplemental
!  22      EAN 2 Supplemental
!  23      EAN 5 Supplemental
!  50      Postnet
! ======================================================
GETPRTRTYPE: ! Need BarCode Printer Type
! Find the printer's entry in CNTRL.LPT
!IF ERR 0 LET F=SPC(8)
F = 0
Try BCScr$ = Chf$(800)  Else let f=SPC(8)
! IF ERR 0 GOSUB Err_Trap:
If F
  ! No printer opened - set type to none
  PrtrType = 0
Else 
  Call String(1,BCScr$)
  POS_ = 1;POS1 = 0
GETNXTPATH: ! until Done
  Search BCScr$[POS_],"/",POS1
  If POS1
    POS_ = POS_ + POS1
    Goto GETNXTPATH
  End If 
  bcx$ = "$" + BCScr$[POS_]
  POS_ = 1;POS1 = 0
  Search bcx$[POS_]," ",POS1
  If POS1
    POS_ = POS_ + POS1 - 1
    bcx$[POS_] = ""
  End If 
  chnl = 99 \ Gosub getchan
  Open #chnl,"cntrl/CNTRL.LPT"
  For X3 = 1 To Chf(chnl) - 1
    Mat Read #chnl,X3,0;bcp1$;
    bcp1$ = bcp1$ To " " ! remove any spaces that may exist
    If bcp1$ = bcx$ Goto GOTPTYPE
  Next X3
  PrtrType = 0 \ Goto FINPTYPE
GOTPTYPE: ! got the Record
  Mat Read #chnl,X3,30;bcP1;
  PrtrType = bcP1[2]
FINPTYPE: Close #chnl
End If 
GotBCPrtr: ! "entrance for programs that got prtrtype already LEAVE IN!!!
! Got Prtrtype - set & init
! LOAD PRTR VARS (FOR GENICOM 3480 series)
! Note: Where Printhead is after Barcode(and Oversize)
!  Prints is controlled by menu item called Software Option 2
!  This is Enb=End at Top, DIS=End AFTER -- ALWAYS ENABLE
!  TO AVOID HAVING STRANGE EXTRA SPACE AFTER BC/OSIZE
!  This extra space is 0.1" or 4/72" below bottom of Print
If PrtrType = 1 ! "Genicom
  If LPI <> 6 If LPI <> 8 Let LPI = 6 ! "only 6 or 8 valid
  If CPI < 6 Or CPI > 20 Or Fra(CPI) Let CPI = 10
  ! If Size<=0 Let Size=3 ! "3 inch top to bottom default?
  ! If Length<=0 Let Length=5 ! "5 inch wide Default?
  SetEmul$ = "\33\[0;0 ~" ! "ansi mode ; no reset
  !LET SETRLF$="\233\[>3h" ! "allow reverse lf (Genicom 3840)
  Call MiscStr(1,BCScr$)
  BCScr$ = "\33\]6;4;1;26\33\\\" ! "set SWO #2(see above)
  BCScr$[Len(BCScr$) + 1] = "\33\]6;4;1;27\33\\\" !SWO #3on
  BCScr$[Len(BCScr$) + 1] = "\33\]6;4;1;25\33\\\" !SWO #1on
  BCScr$[Len(BCScr$) + 1] = "\33\]6;4;0;42\33\\\" !SWO?(allow ANSI Escape Seq)
  BCScr$[Len(BCScr$) + 1] = "\33\]6;4;1;19\33\\\" !UDO#7on
  SETTOF$ = "\33\[0d" ! "set tof position 
  ! LET ENDRLF$="\233\[>3l" ! "back to standardmode (Genicom 3840)
  EndEmul$ = "\33\[24;0 ~" ! "back to Epson
  EndSiz$ = "\33\[100;100 B" ! "100% size
  EndMode$ = "\33\[0t" ! "end modes (bc,exp, etc)
  If Size_ > 0 ! "Only if needed (whole form is BCoded)
    ResetFrm$ = "\33\[7920;0;0r" ! "set to 11"        
    SetFrm$ = "\33\[####;0;0r" ! "set to SIZE*720 decipoints length 
    SetFrm$[3,6] = Int(Size_ * 720) Using "&&&&"
  End If 
  SetBC$ = "\33\[3t" ! "start bc - print after set bc style
  SetUPBC$ = "\33\[" ! "Beginning of BarCode Definition
  OvrSz$ = "\33\[200;200 B" ! "oversize 200% high & wide
  LENGTH = LENGTH * 720 ! "set label length in decipoints (720/inch)
  SETOS$ = "\33\[1t" ! "start oversize no rotate  
  EndOs$ = "\33\[0t" ! "end oversize 
  !Let ResetPtr$="\233\@" ! "reset to Power on Defaults
  ResetPtr$ = "\33\c" ! "the above may reset to FactDefaults
  SetFntSz$ = "\33\[###;### G" ! "LPI first, then CPI
  EndFntSz$ = "\33\[120;72 G" ! "6 lpi, 10 cpi
  MoveForm$ = "\33\[####;####f" ! "Form Movement String
End If 
! Set Variables for Mannesman Tally
! Bugs - 1) ALWAYS creeps down page. 2:skips line before
!       Barcode. 3. Loses Tab after Barcode
!     May creep no matter what the setting of BCType[15] - be wary!
!     \233\[##t to set form, \233\66t for 11inch reset
If PrtrType = 2 ! "MTally 1
  SetEmul$ = "\33\[?6~" ! "use Mtpl & Epson Char Sets
  ResetPtr$ = "\33\[6~" ! "init Printer
  SETRLF$ = "\33\[1k" ! "MT skips a line before Barcode!?
  SetBC$ = "\33\[?11~" ! "start BC interpretation
  SetUPBC$ = "\32\" ! " start of BC HEader
  EndMode$ = "\33\[?10~" ! "end BC/Large Mode
  EndFntSz$ = "\33\[0 K\33\[0 L" ! "10 cpi / 6 lpi
End If 
! "Set Variables for Datasouth
If PrtrType = 3
  ! If any emulation commands need to be defined
  SetUPBC$ = "^H" ! "height
  SetBC$ = "^B" ! "start BarCode
  EndMode$ = "^G" ! "end of barcode data
End If 
! "Set Variables for OKIData (Uses CHR$(x))
If PrtrType = 4 ! "OKI
  Call MiscStr(1,BCScr$)
  For BCV = 0 To 255 ! "Need to convert in ALL 256 ASCII Chars
    If BCV = 10 Or BCV = 13 ! "CR & LF switch
      Call String(4,BCV,BCScr$[BCV + 1])
    Else 
      If BCV < 127 Call String(4,128 + BCV,BCScr$[BCV + 1])
      If BCV > 128 Call String(4,BCV - 128,BCScr$[BCV + 1])
    End If 
  Next BCV
  SetEmul$ = "\33\{" + BCScr$[66 + 1,66 + 1] ! "Epson LQ Mode
  SETRLF$ = "\33\j" + BCScr$[30 + 1,30 + 1] ! "1/6 in Rev Line Feed
  SETTOF$ = "\33\O" ! "cancel Skip over Perf
  EndSiz$ = "\33\W" + BCScr$[0 + 1,0 + 1] ! "end Double Wide
  EndSiz$[4] = "\33\w" + BCScr$[0 + 1,0 + 1] ! "end Double Height
  ResetFrm$ = "\33\C\200\" + BCScr$[11 + 1,11 + 1] ! "reset to 11" form
  SetFrm$ = "\33\C\200\##" ! "Set form to ## inches
  If Size_ Let SetFrm$[4] = BCScr$[Size_ + 1,Size_ + 1] Else Let SetFrm$ = "";ResetFrm$ = ""
  SetBC$ = "\33\\20\B" ! "needs length(m) and (n=65) if BC 128
  SetUPBC$ = "\33\\20\A" ! "Needs Number params(m) and params(n)
  OvrSz$ = "\33\W" + BCScr$[1 + 1,1 + 1] ! "Start Double Wide
  OvrSz$[4] = "\33\w" + BCScr$[1 + 1,1 + 1] ! "Start Double High(at same time?)
  ResetPtr$ = "\33\@" ! "Resets to Menu
  SetFntSz$ = "\33\2\33\P" ! "set to 6lpi, 10cpi
  EndFntSz$ = "\33\q" + BCScr$[0 + 1,0 + 1] ! "Normal Char Style
End If 
! "Set Vars for Printronix w/ IGP Board
If PrtrType = 5 ! "GBurg P300 w/IGP
  ! IGP Board needs to Create Forms for BarCodes to Work
  SetEmul$ = "^PY^-" ! "Enable Graphics Mode
  OvrSz$ = "^M####000" ! "Oversize Vert & Horiz in 10ths
  EndSiz$ = "^-" ! "Normal Mode - for most modes
  EndOs$ = EndSiz$;EndFntSz$ = EndSiz$
  ResetPtr$ = "" ! "Reset to Power On
  EndEmul$ = "^PN^-"
  SetFrm$ = "~CREATE;" ! "create form - give Name
  ResetFrm$ = "END" ! "end form 
  SetUPBC$ = "BARCODE" ! "Start of BarCode
  SetBC$ = "" ! Refer to Instructions (multi Line Command)
  EndMode$ = "STOP" ! "Ends Barcode, Alpha, etc Modes
End If 
! "Set Vars MTally GPL 
! Note: the Printer will be on a New Line after Barcode Prints
!       So doubtful if anything can print after Barcode on same line
!  **** ALWAYS CREEPS UNLESS BARCODE = MULTIPLE OF 1/6" (.5,1,etc) ****
!       And Loses Tab of next line unless blank line After BCode
If PrtrType = 6 ! "MTally GPL
  SetEmul$ = "^PY^-" ! "Enable Graphics Mode
  OvrSz$ = "" ! "Oversize Vert & Horiz in 10ths
  EndSiz$ = "^-" ! "Normal Mode - for most modes
  EndOs$ = EndSiz$;EndFntSz$ = EndSiz$
  ResetPtr$ = "" ! "Reset to Power On
  EndEmul$ = "^PN^-"
  SetFrm$ = "" ! "create form - give Name
  ResetFrm$ = "" ! "end form 
  SetUPBC$ = "^M####000^IBARC," ! "Start of BarCode
  SetBC$ = "" ! Setup Barcode Stuff
  EndMode$ = "^G" ! "Ends Barcode
End If 
If PrtrType = 7 ! "ALL CODING, etc done In program
  ! For all those 1 time deals on 1 printer
  ! It's up to you to handle this type
  ! If 2 printers use this type for 2 different codes
  !  then you got to do something else!
End If 
Gosub Init_Printer
Return 
Mov_Pos_Line: ! "Move to Position and Line
If PrtrType = 1 And LPI > 0 And CPI > 0 ! "for Genicom
  LINE_ = LINE_ - 1 \ If LINE_ < 0 Let LINE_ = 0
  DOWN = LINE_ * (720 / LPI)
  POS_ = SPOS + (bcTABS * (720 / CPI))
  MoveForm$[3,6] = DOWN Using "&&&&"
  MoveForm$[8,11] = POS_ Using "&&&&"
  Print #0;MoveForm$;
End If 
Return 
Start_BarCode: ! "start Barcode Print
! ---- set barcode characteristics (independent of printer type) ------
! start/stop code
BCStart$ = "";BCStop$ = ""
! 2/5 codes
If BCType[1] = 0 Let BCStart$ = ":";BCStop$ = ";"
If BCType[1] = 2 Let BCStart$ = ":";BCStop$ = ":"
If BCType[1] = 3 Let BCStart$ = ":";BCStop$ = ";"
! Code 3 of 9
If BCType[1] = 4 Let BCStart$ = "*";BCStop$ = "*"
! Code 11
If BCType[1] = 7 Let BCStart$ = ":";BCStop$ = ":"
! Codabar types
If BCType[1] = 9 Let BCStart$ = "a";BCStop$ = "t"
If BCType[1] = 10 Let BCStart$ = "b";BCStop$ = "n"
If BCType[1] = 11 Let BCStart$ = "c";BCStop$ = "*"
If BCType[1] = 12 Let BCStart$ = "d";BCStop$ = "e"
! EAN codes
If BCType[1] >= 5 And BCType[1] <= 6
  BCStart$ = ":";BCStop$ = ":"
End If 
! UPC codes
If BCType[1] >= 13 And BCType[1] <= 14
  BCStart$ = ":";BCStop$ = ":"
End If 
! ---- Printer-specific settings -------------------------------
If PrtrType = 1 ! "Genicom
  SetUPBC$[3] = Str$(BCType[1]) + ";" ! "BCType 4=39, 13/14=UPC, 16=128
  If BCType[2] ! "Bar Code Size 1/12 inch increments
    SetUPBC$ = SetUPBC$ + Str$(BCType[2]) + ";"
  Else 
    SetUPBC$ = SetUPBC$ + "12;" ! "1 inch default
  End If 
  SetUPBC$ = SetUPBC$ + Str$(BCType[3]) + ";" ! "Human Readable
  For BCV = 4 To 9 ! "Bar & Space Widths 
    If BCType[BCV]
      SetUPBC$ = SetUPBC$ + Str$(BCType[BCV])
    End If 
    SetUPBC$ = SetUPBC$ + ";"
  Next BCV
  If BCType[10] = 0 Let BCType[10] = 1 ! "Print Density 
  SetUPBC$ = SetUPBC$ + Str$(BCType[10]) + ";"
  SetUPBC$ = SetUPBC$ + Str$(BCType[11]) + ";" ! "Check Digit
  SetUPBC$ = SetUPBC$ + "}" ! "final Character
  Print #0;SetUPBC$; ! "print command
  Print #0;SetBC$;
End If 
! findme !
If PrtrType = 2 ! " M Tally (skips Line before BarCode, creeps, loses Tab)
  SetUPBC$[2] = "       " ! "clear previous
  If BCType[3]
    ! Setup type with HRI
    If BCType[1] = 0 Let SetUPBC$[2,3] = "''C" ! 2/5 interleaved
    If BCType[1] = 2 Let SetUPBC$[2,3] = "''A" ! 2/5 matrix
    If BCType[1] = 3 Let SetUPBC$[2,3] = "''B" ! 2/5 industrial
    If BCType[1] = 4 Let SetUPBC$[2,3] = "''F" ! "3 of 9
    If BCType[1] = 13 Let SetUPBC$[2,3] = "''N" ! "UPCA
    If BCType[1] = 14 Let SetUPBC$[2,3] = "''P" ! "UPC E
    If BCType[1] = 16 Let SetUPBC$[2,3] = "&S" ! "128
  Else 
    ! Setup type w/o HRI
    If BCType[1] = 0 Let SetUPBC$[2,3] = " C" ! 2/5 interleaved
    If BCType[1] = 2 Let SetUPBC$[2,3] = " A" ! 2/5 matrix
    If BCType[1] = 3 Let SetUPBC$[2,3] = " B" ! 2/5 industrial
    If BCType[1] = 4 Let SetUPBC$[2,3] = " F" ! "3 of 9
    If BCType[1] = 13 Let SetUPBC$[2,3] = " O" ! "UPCA
    If BCType[1] = 14 Let SetUPBC$[2,3] = " Q" ! "UPC E
    If BCType[1] = 16 Let SetUPBC$[2,3] = "$S" ! "128
  End If 
  If BCType[2] ! "Height (MT in 6ths)
    BCV = BCType[2] / 2 \ BCV = Int(BCV + .2) ! "round down
    SetUPBC$[4] = Str$(BCV)
  Else 
    SetUPBC$[4] = "6" ! "6/6 = 1 inch Default
  End If 
  If BCType[10] And SetUPBC$[2,2] = " " Let SetUPBC$[2,2] = "$" !HRI off
  If BCType[10] And SetUPBC$[2,2] = "''" Let SetUPBC$[2,2] = "&" ! "HRI on
  If BCType[4] Or BCType[6] Or BCType[5] Or BCType[7] ! "calc wide to narrow
    BCV = 0 \ If BCType[4] Let BCV = BCType[5] / BCType[4]
    If BCV = 0 And BCType[6] Let BCV = BCType[7] / BCType[6]
    If BCV And BCType[10] Let BCV = BCV - 1 ! "Higher Density
    If BCV <= 2 Let BCV = 0
    If BCV >= 2.3 And BCV < 2.8 Let SetUPBC$ = SetUPBC$ + ";001"
    If BCV >= 2.8 And BCV < 3.3 Let SetUPBC$ = SetUPBC$ + ";002"
    If BCV >= 3.3 Let SetUPBC$ = SetUPBC$ + ";003"
  End If 
  If BCType[1] >= 0 And BCType[1] <= 3
    If BCType[10] = 0 Let SetUPBC$[5] = ";222" ! 2/5 size
    If BCType[10] <> 0 Let SetUPBC$[5] = ";000" ! "High Density!
  End If 
  If BCType[1] = 16 Let SetUPBC$[5] = ";000" ! "128 always High Dens
  Print #0;SETRLF$; ! "ALWAYS move up a Line on MTally
  SetUPBC$ = SetUPBC$ + "\31\" ! "end of BCHeader (same as \231\)
  Print #0;SetBC$; ! "BC Mode ON
  If BCType[15] Print #0;"\33\PSC1\33\\\"; ! "end at Top (Use to prevent page creeping)
  If Not(BCType[15]) Print #0;"\33\PSC0\33\\\"; ! "end at Bottom(not recommended)
  Print #0;SetUPBC$; ! "Send BC Header
  Print #0;"\24\"; ! "Barcode 'bracket' followed by data
End If 
If PrtrType = 3 ! "DataSouth (Feature 70 MUST =1) Height is 10th inch
  SetUPBC$ = "^H" ! "per book 1/10 approx 7/72 actual
  BCH = Int((10 * (BCType[2] / 12)) + .5) ! "BC Height (from 12ths)
  If BCH < 1 Or BCH > 99 Let BCH = 2 ! "approx 1 line (6ths)
  SetUPBC$[3] = BCH Using "&&"
  SetBC$ = "^B";EndMode$ = "^G"
  SetBC$[3,3] = "N"
  If BCType[3] Let SetBC$[3,3] = "Y"
  If BCType[1] = 4 Let SetBC$[4] = "A" ! "BC 39
  If BCType[1] = 4 And BCType[10] Let SetBC$[4] = "C" ! High Den 39
  If BCType[1] = 16 Let SetBC$[4] = "Z" ! "BC 128
  If BCType[15] Print #0;"\33\$H"; ! "save Start Position
  Print #0;SetUPBC$; ! "Height of BarCode
  Print #0;SetBC$; ! "Start of BC Code
End If 
If PrtrType = 4 ! "OKI (Oki ends Barcode at the Original Start Line)
  ! Bugs -  Loses Tab after BarCode prints
  SetUPBC$[4] = BCScr$[9,9] ! "Set 8 Vars As Default
  If BCType[1] = 4 Let SetUPBC$[5] = BCScr$[2 + 1,2 + 1] + BCScr$[0 + 1,0 + 1] ! "BC 39
  If BCType[1] = 13 Let SetUPBC$[5] = BCScr$[1 + 1,1 + 1] + BCScr$[0 + 1,0 + 1] ! "UPC A
  If BCType[1] = 14 Let SetUPBC$[5] = BCScr$[1 + 1,1 + 1] + BCScr$[4 + 1,4 + 1] ! "UPC E
  If BCType[1] = 16 Let SetUPBC$[5] = BCScr$[4 + 1,4 + 1] + BCScr$[0 + 1,0 + 1] ! "BC 128
  If BCType[2] ! "Height in 1/12's Uses 2 Vars 1 for 10's 2 for 1's
    SetUPBC$[7] = BCScr$[1,1] + BCScr$[BCType[2] + 1,BCType[2] + 1]
  Else 
    SetUPBC$[7] = BCScr$[1 + 1,1 + 1] + BCScr$[2 + 1,2 + 1] ! "1 Inch Default
  End If 
  SetUPBC$[9] = BCScr$[1 + 1,1 + 1] + BCScr$[1,1] + BCScr$[1,1] ! "High Density
  If BCType[3] Let SetUPBC$[12] = BCScr$[3,3] Else Let SetUPBC$[12] = BCScr$[1,1]
  Print #0;SetUPBC$; ! "Set BarCode
  SetBC$[4] = BCScr$[Len(BarCode$) + 1,Len(BarCode$) + 1]
  If BCType[1] = 16 Let SetBC$[4] = BCScr$[Len(BarCode$) + 3,Len(BarCode$) + 3]
  If BCType[1] = 16 Let SetBC$[5] = "B" ! "use 128B - for A its "A"
  Print #0;SetBC$; ! "follow by Data
End If 
If PrtrType = 6 ! "MTally GPL
  BCType[14] = Int((BCType[2] / 12) / 1 * 10 + .5) ! "get in 10'ths
  If BCType[14] <= 0 Let BCType = 10 ! " 1 inch default
  If BCType[14] < 2 Let BCType[14] = 2 ! "Min is 2/10" (about 1 line)
  EndMode$ = "^G" ! "on all versions
  If BCType[9] > 0 ! "rotation - use version 1 BC
    SetUPBC$ = "^M####000^C"
    If BCType[12] ! "Need tab in command
      SetUPBC$[10] = "^T&&&0^C"
      SetUPBC$[12,14] = BCType[12] Using "&&&"
    End If 
    If BCType[3] Let SetBC$ = "Y" Else Let SetBC$ = "N"
    If BCType[1] = 0 Let SetBC$[2] = "K"
    If BCType[1] = 1 Let SetBC$[2] = "L"
    If BCType[1] = 4 Let SetBC$[2] = "A"
    If BCType[1] = 5 Let SetBC$[2] = "U"
    If BCType[1] = 6 Let SetBC$[2] = "T"
    If BCType[1] = 9 Let SetBC$[2] = "D"
    If BCType[1] = 13 Let SetBC$[2] = "P"
    If BCType[1] = 14 Let SetBC$[2] = "Q"
    If BCType[1] = 16 Let SetBC$[2] = "Z"
    If BCType[1] = 19 Let SetBC$[2] = "F"
  Else ! "can use version 2 Barcode Commands?
    SetUPBC$ = "^M####000^IBARC,"
    If BCType[12] ! "add tab to command
      SetUPBC$[10] = "^T&&&0^IBARC,"
      SetUPBC$[12,14] = BCType[12] Using "&&&"
    End If 
    If BCType[10] ! "High Dens
      SetUPBC$ = "^M####000^KF^IBARC,"
      If BCType[12] ! "add Tab to command
        SetUPBC$[10] = "^T&&&0^KF^IBARC,"
        SetUPBC$[12,14] = BCType[12] Using "&&&"
      End If 
      EndMode$ = "^G^KF"
    End If 
    If BCType[1] = 0 Let SetBC$ = "INT2/5,"
    If BCType[1] = 1 Let SetBC$ = "INT2/5A,"
    If BCType[1] = 4 Let SetBC$ = "C39,"
    If BCType[1] = 5 Let SetBC$ = "EAN8,"
    If BCType[1] = 6 Let SetBC$ = "EAN13,"
    If BCType[1] = 9 Let SetBC$ = "CBAR,"
    If BCType[1] = 13 Let SetBC$ = "UPCA,"
    If BCType[1] = 14 Let SetBC$ = "UPCE,"
    If BCType[1] = 16 Let SetBC$ = "C128,"
    If BCType[1] = 19 Let SetBC$ = "MSI,"
    If BCType[3] Let SetBC$[Len(SetBC$) + 1] = "B," Else Let SetBC$[Len(SetBC$) + 1] = "N,"
  End If 
  SetUPBC$[3,4] = BCType[14] Using "&&" ! "Height in 10ths
  SetUPBC$[5,6] = BCType[14] Using "&&" ! "Normally width
  Print #0;SetUPBC$;
  Print #0;SetBC$; ! "follow by Data
End If 
If PrtrType = 7 ! "Refer to specific manual
  ! "you chose to do in-program, so do it yourself!
End If 
If BCType[1] <> 16 ! "128 DOES NOT use Start or End!
  If PrtrType <> 6 ! "adds automatically - MTGPL
    Print #0;BCStart$;
  End If 
End If 
Return 
End_BarCode: ! "end barcode print
If BCType[1] <> 16 ! "again 128 doesn't use this
  If PrtrType <> 6 ! "adds automatically MTGPL
    Print #0;BCStop$;
  End If 
End If 
If PrtrType = 1 ! "genicom
  Print #0;EndMode$;
End If 
If PrtrType = 2 ! " Mannesman Tally
  Print #0;"\24\"; ! "end of BC 'bracket'
  Print #0;EndMode$; ! "End BC Mode
End If 
If PrtrType = 3 ! "DataSouth XL300
  Print #0;EndMode$; ! "2 chars ^G
  If BCType[15] Print #0;"\33\$B"; ! "return to saved position
End If 
If PrtrType = 4 ! "oki
  !  If BCTYpe[11] ! "Have to Send Check Digit?
  If BCType[1] = 4 Print #0;"@"; ! "bc 39
  If BCType[1] = 13 Print #0;"@"; ! "BC UPC A
  If BCType[1] = 16 Print #0;"\30\"; ! "BC 128B - for 128A "g"
  !  Endif
End If 
If PrtrType = 6 ! "Mt GPL
  Print #0;EndMode$;
  Print #0;EndSiz$; ! "Need the ^- ?? (Lets try it)
End If 
Return 
Set_Font_Size: ! "PITCH/LPI SIZE (for Genicom)
If PrtrType = 1 And LPI > 0 And CPI > 0 ! "Genicom
  SetFntSz$[3,5] = Int(720 / LPI) Using "&&&"
  SetFntSz$[7,9] = Int(720 / CPI) Using "&&&"
End If 
Print #0;SetFntSz$; ! " lpi &  cpi 
Return 
ReSet_Font_Size: ! "set back Font Size
Print #0;EndFntSz$; ! "6 lpi ; 10 cpi 
Return 
Init_Printer: ! INITIALIZE PRINTER
If PrtrType = 1 ! "genicom
  Print #0;SetEmul$; ! "ansi mode
  Print #0;SETRLF$; ! "allow reverse lf's
  Print #0;BCScr$; ! "3800 series (after 1992) - set needed options
  If Size_ > 0 Print #0;SetFrm$; ! "set form size
  If Size_ > 0 Print #0;SETTOF$; ! "set tof pos
  Gosub Set_Font_Size
End If 
If PrtrType = 2 ! "MTally
  Print #0;SetEmul$;
  Print #0;"\33\[3g"; ! "Can set Tabs here (MTally loses 'em)
End If 
If PrtrType = 3 ! "DataSouth - needs anything?
  Print #0;"\33\$s70"; ! activate feature 70 - Barcodes
End If 
If PrtrType = 4 ! "OkiData
  Print #0;SetEmul$; ! "Epson LQ
  Print #0;SETTOF$; ! "Cancel Skip over Perf
  Gosub Set_Font_Size
  Print #0;SetFrm$; ! "Set Form Length (based on Font)
End If 
If PrtrType = 5 ! "Printronix
  Print #0;SetEmul$; ! "start Graphics Mode
End If 
If PrtrType = 6 ! MTally GPL
  Print #0;SetEmul$; ! "start Graphics Mode
End If 
If PrtrType = 7 ! "In-program
End If 
Return 
Reset_Printer: !  RESET PRINT
If PrtrType = 1 ! "genicom
  Gosub ReSet_Font_Size ! "reset cpi&lpi to 10 & 6 
  Print #0;EndSiz$; ! "set to 100%
  Print #0;ENDRLF$; ! "end Special Mode
  Print #0;EndMode$; ! "end all modes
  If Size_ > 0 Print #0;ResetFrm$; ! "back to 11"
  If Size_ > 0 Print #0;SETTOF$; ! "set tof for 11"
  ! PRINT #0;ENDEMUL$; ! "reset to std emul(If running Epson)
  Print #0;ResetPtr$; ! "this may reset emul also?
End If 
If PrtrType = 2 ! "MTally
  Gosub ReSet_Font_Size
  Print #0;EndMode$;
  Print #0;ResetFrm$;
  Print #0;ResetPtr$;
End If 
If PrtrType = 3 ! "Datasouth - if needed
  Print #0;"\33\$c70"; ! unactivate feature 70?
End If 
If PrtrType = 4 ! "oki
  Gosub ReSet_Font_Size
  Print #0;EndSiz$;
  Print #0;ResetFrm$;
  Print #0;ResetPtr$;
End If 
If PrtrType = 5 ! "printronix
  Print #0;EndEmul$;
  Print #0;ResetPtr$;
End If 
If PrtrType = 6 ! "MTally GPL
  Print #0;EndEmul$;
  Print #0;ResetPtr$;
End If 
If PrtrType = 7 ! "In-program Coding
End If 
Return 
