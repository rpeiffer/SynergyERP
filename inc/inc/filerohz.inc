Def Struct roh ! Order File  generated by dfcreatestruct on 02/26/08
  Member 2%,Status                     : Item 0 ! H0
  Member 2%,BillTo                     : Item 4 ! H0[1]         FROM CUSTOMER
  Member 2%,ShipRec                    : Item 8 ! H0[2]         disp 1856
  Member 2%,TotRec                     : Item 12 ! H0[3]         disp 1872
  Member 2%,CustNum                    : Item 16 ! H0[4]
  Member 2%,BOCTR                      : Item 20 ! H0[5]         TIMES B'ORD
  Member 2%,spare1                     : Item 24 ! H0[6]         MV TO 518
  Member 2%,OrdNum                     : Item 28 ! H0[7]
  Member 2%,InvDate                    : Item 32 ! H0[8]
  Member 2%,OrdDate                    : Item 36 ! H0[9]
  Member 2%,ShipDate                   : Item 40 ! H0[10]
  Member 2%,SLSM                       : Item 44 ! H0[11]
  Member 2%,Terms                      : Item 48 ! H0[12]
  Member 1%,spare2                     : Item 52 ! H3[0]         to d494
  Member 1%,ShipType                   : Item 54 ! H3[1]         CONTROL R107
  Member 3%,TotSellUnits               : Item 56 ! TOT_SELL      added 03/07/94
  Member 1%,spare3                     : Item 62 !               CLP USE
  Member 1%,Lockport                   : Item 64 ! LOCKPORT      RECORD LOCK
  Member ShipVia$[12]                  : Item 66 ! V0$[1,12]
  Member 1%,TaxCode                    : Item 78 ! H4
  Member 1%,StopNum                    : Item 80 ! H4[1]         FR CUST/SHIPLIST
  Member 1%,Wh                         : Item 82 ! H4[2]
  Member Contact$[20]                  : Item 84 ! H0$[1,20]     NSP-10E/VEH&ID
  Member 2%,EntBy                      : Item 104 ! H5[0]
  Member 2%,DueDate                    : Item 108 ! H5[1]
  Member 2%,PoCopyNum                  : Item 112 ! H5[2]
  Member 2%,CommOver                   : Item 116 ! H5[3]         SEE BELOW
  Member 2%,FrgtWait                   : Item 120 ! H5[4]         0=n,1=y,2=got it
  Member 2%,ActWgt                     : Item 124 ! H5[5]         Freight Inv.
  Member 2%,spare4                     : Item 128 ! H5[6]         BO REL/FRT INV
  Member 2%,OrdType                    : Item 132 ! H5[7]         see below
  Member 2%,Div                        : Item 136 ! H5[8]
  Member 2%,Source                     : Item 140 ! H5[9]
  Member 2%,CmInvHist                  : Item 144 ! H5[10]        see below
  Member 2%,ConsWh                     : Item 148 ! H5[11]        see below
  Member 2%,SalesArea                  : Item 152 ! H5[12]        freight add-on's
  Member 2%,TotDol4Prof                : Item 156 ! H5[13]        see below
  Member 2%,TotCost4Prof               : Item 160 ! H5[14]        see below
  Member 2%,DateEnt                    : Item 164 ! H5[15]        $TIME
  Member 2%,TimeEnt                    : Item 168 ! H5[16]        $TIME
  Member 2%,ShipTerm                   : Item 172 ! ST3[0]        BILL & HOLD
  Member 2%,ShipDate1                  : Item 176 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate2                  : Item 180 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate3                  : Item 184 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate4                  : Item 188 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate5                  : Item 192 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate6                  : Item 196 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate7                  : Item 200 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate8                  : Item 204 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate9                  : Item 208 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate10                 : Item 212 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate11                 : Item 216 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate12                 : Item 220 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate13                 : Item 224 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate14                 : Item 228 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate15                 : Item 232 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate16                 : Item 236 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate17                 : Item 240 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate18                 : Item 244 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate19                 : Item 248 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate20                 : Item 252 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate21                 : Item 256 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate22                 : Item 260 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate23                 : Item 264 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member 2%,ShipDate24                 : Item 268 ! ST3[1-24]     H5[7]=4&S3[0]=0
  Member WhStage$[6]                   : Item 272 ! H1$[1,6]      H5[7]=9
  Member 2%,Slsm1                      : Item 278 ! SLSM[0]
  Member 2%,Slsm2                      : Item 282 ! SLSM[1]
  Member 2%,Slsm3                      : Item 286 ! SLSM[2]
  Member 2%,Slsm4                      : Item 290 ! SLSM[3]
  Member 2%,Slsm5                      : Item 294 ! SLSM[4]
  Member 2%,SlsmPct1                   : Item 298 ! SLSM[5]
  Member 2%,SlsmPct2                   : Item 302 ! SLSM[5]
  Member 2%,SlsmPct3                   : Item 306 ! SLSM[7]
  Member 2%,SlsmPct4                   : Item 310 ! SLSM[8]
  Member 2%,SlsmPct5                   : Item 314 ! SLSM[9]
  Member 3%,SlsmComm1                  : Item 318 ! SCOM[0]
  Member 3%,SlsmComm2                  : Item 324 ! SCOM[1]
  Member 3%,SlsmComm3                  : Item 330 ! SCOM[2]
  Member 3%,SlsmComm4                  : Item 336 ! SCOM[3]
  Member 3%,SlsmComm5                  : Item 342 ! SCOM[4]
  Member 3%,SlsmMdse1                  : Item 348 ! SMER[0]
  Member 3%,SlsmMdse2                  : Item 354 ! SMER[1]
  Member 3%,SlsmMdse3                  : Item 360 ! SMER[2]
  Member 3%,SlsmMdse4                  : Item 366 ! SMER[3]
  Member 3%,SlsmMdse5                  : Item 372 ! SMER[4]
  Member 3%,SlsmCost1                  : Item 378 ! SCST[0]
  Member 3%,SlsmCost2                  : Item 384 ! SCST[1]
  Member 3%,SlsmCost3                  : Item 390 ! SCST[2]
  Member 3%,SlsmCost4                  : Item 396 ! SCST[3]
  Member 3%,SlsmCost5                  : Item 402 ! SCST[4]
  Member 2%,PriceType                  : Item 408 ! H6[0]         2/18/92
  Member 2%,HoldOver                   : Item 412 ! H6[1]
  Member 2%,OrgStatus                  : Item 416 ! H6[2]         BEFORE IN PROCES
  Member 2%,PrivateLabel               : Item 420 ! H6[3]         0=N,1=Y
  Member 2%,LastPayDate                : Item 424 ! H6[4]         FROM A/R PURGE
  Member 2%,VendNum                    : Item 428 ! H6[5]         FROM LINES/PO
  Member 2%,TotFrgtAdd                 : Item 432 ! H6[6]         added 03/09/93
  Member 2%,OrdDisc                    : Item 436 ! H6[7]         (TTLS SCRN)
  Member 2%,Contract                   : Item 440 ! H6[8]         FOR PRICING
  Member MatCode$[2]                   : Item 444 ! HMAT$[1,2]    USED FOR COMMISS
  Member CustPO$[20]                   : Item 446 ! P0$           1/14/93
  Member 2%,Fax1                       : Item 466 ! HFAX[0&1]     NPE 12/31/96
  Member 2%,Fax2                       : Item 470 ! HFAX[0&1]     NPE 12/31/96
  Member 2%,CopyInvNum1                : Item 474 ! HSTI[0&1]     FROM HISTORY
  Member 2%,CopyInvNum2                : Item 478 ! HSTI[0&1]     FROM HISTORY
  Member 2%,spare5                     : Item 482 ! H2[0]         see notes
  Member 1%,XferAuth                   : Item 486 ! OWHT[0]       0=REQ,1=AUTH
  Member 1%,AuthBy                     : Item 488 ! OWHT[1]       USERCNTRL REC
  Member 2%,AuthDate                   : Item 490 ! OWHT1         YYMMDD
  Member 2%,Dept                       : Item 494 ! OWHT1[1]      from h3[0]
  Member 3%,TotGlCost                  : Item 498 ! TOTGL         *USED IN INVH
  Member 1%,PickBy                     : Item 504 ! PICKBY        added 08/14/03
  Member 1%,SentToUps                  : Item 506 ! PICKBY[1]     PROG: MX022
  Member 1%,Ot19Comp                   : Item 508 ! PICKBY[2]     0=COMP,1=PARTIAL
  Member SpareFiller$[2]               : Item 510 ! 
  Member 3%,OrderNu                    : Item 512 ! OREF[0]       IS H0[7]
  Member 3%,InvNum                     : Item 518 ! OREF[1]       WAS H0[6]
  Member 3%,OrgOrd                     : Item 524 ! OREF[2]       WAS H5[6]
  Member 3%,OrgOrd1                    : Item 530 ! OREF[3]       WAS H2[0]
  Member 3%,InvsRec                    : Item 536 ! OREF[4]       227 USE
  Member 3%,InvtRec                    : Item 542 ! OREF[5]       227 USE
  Member 2%,SlsmSplt1                  : Item 548 ! CSPLT[0]      P61$[72,72]
  Member 2%,SlsmSplt2                  : Item 552 ! CSPLT[1]      PERCENT
  Member 2%,SlsmSplt3                  : Item 556 ! CSPLT[2]      ALONG WITH
  Member 2%,SlsmSplt4                  : Item 560 ! CSPLT[3]      SLSM[0-4]
  Member 2%,SlsmSplt5                  : Item 564 ! CSPLT[4]      OF TTL COMM$
  Member 3%,COMMSVGCHG                  : Item 568 ! 
  Member ORDLOC$[4]                     : Item 574 ! 
  Member PORDLOC$[4]                    : Item 578 ! 
  Member 2%,ORDCOUNT                    : Item 582 ! 
  Member 3%,PHUP                        : Item 586 ! 
  Member 1%,AKFlag0                     : Item 592 ! 
  Member 1%,AKFlag1                     : Item 594 !
  Member Blankforkey$[2]                : Item 596 !
  Member 1%,SplitFlag			: Item 598
  Member 2%,CommBase1                   : Item 600 !
  Member 2%,CommBase2                   : Item 604 !
  Member 2%,CommBase3                   : Item 608 !
  Member 2%,CommBase4                   : Item 612 !
  Member 2%,CommBase5                   : Item 616 !
  Member 2%,NumberPieces                : Item 620 !
  Member 1%,CurrId                      : Item 624 !
  Member 3%,CurrFact                    : Item 626 !
End Def
!
! ----------------------------------------
!
! external lib statements
!
External Lib "libfileroh.lib"
declare external function filegetroh,fileupdateroh
declare external sub filedroplistroh