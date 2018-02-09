Def Struct INVH
! 4/SORDFLEHH#
! Dir 1= SSIIIIII S=Status H0[0] I=Invoice Number H0[6]
! Dir 2= CCCCCCIIIIII C=Customer Number H0[4]
! Dir 3= sssIIIIIIb s=Salseman H0[11] b=blank
  Member 2%,H0[12]       : Item 0
  Member 1%,H3[1]        : Item 52
  Member 3%,Tot_Sell     : Item 56
  Member 1%,NU           : Item 62
  Member 1%,LockPort     : Item 64
  Member V0$[12]         : Item 66
  Member 1%,H4[2]        : Item 78
  Member H0$[20]         : Item 84
  Member 2%,H5[16]       : Item 104
  Member 2%,ST3[24]      : Item 172
  Member H1$[6]          : Item 272
  Member 2%,SLSM[9]      : Item 278
  Member 3%,SCOM[4]      : Item 318
  Member 3%,SMER[4]      : Item 348
  Member 3%,SCST[4]      : Item 378
  Member 2%,H6[8]        : Item 408
  Member HMat$[2]        : Item 444
  Member PO$[20]         : Item 446
  Member 2%,HFax[1]      : Item 466
  Member 2%,HSti[1]      : Item 474
  Member 2%,H2           : Item 482
  Member 1%,OWHT[1]      : Item 486
  Member 2%,OWHT1[1]     : Item 490
  Member 3%,TotGL        : Item 498
  Member 1%,PickBy[2]    : Item 504
  Member Spare$[2]       : Item 510
  Member 3%,OREF[5]      : Item 512
  Member 2%,CSPLT[4]     : Item 548
  Member 3%,COMMSRVCHG   : Item 568
  Member Spare1$[72]     : Item 574
End Def

Def Struct INVD
! 4/SORDFLELH#
! Dir 1=IIIIIILLLb I=Invoice Number L2[1], L=Line Number L3[2], b=blank
! Dir 2=PPPPPPIIIIIILLLb P=Product Record Number L4[0]
  Member 2%,L2[1]        : Item 0
  Member 1%,L3[3]        : Item 8
  Member 2%,L4[3]        : Item 16
  Member 3%,L5[3]        : Item 32
  Member 2%,L6[5]        : Item 56
  Member L6$[60]         : Item 80
  Member L1$[20]         : Item 140
  Member 2%,L9[1]        : Item 160
  Member 3%,L7[12]       : Item 168
  Member 1%,PL[1]        : Item 246
  Member 1%,UN[2]        : Item 250
  Member 1%,S2[1]        : Item 256
  Member 3%,S3[17]       : Item 260
  Member MT$[2]          : Item 368
  Member S3$[33]         : Item 370
  Member POFlag$[1]      : Item 403
  Member 3%,OLM[6]       : Item 404
  Member 1%,EUN[2]       : Item 446
  Member 3%,UNF[6]       : Item 452
  Member 2%,LCO[1]       : Item 494
  Member 3%,CST          : Item 502
  Member 3%,LTax1        : Item 508
  Member 1%,CTWT         : Item 514
  Member Spare22$[22]    : Item 516
  Member 2%,LTax2        : Item 538
  Member 3%,QPB          : Item 542
  Member 1%,LPrinted     : Item 548
  Member 1%,OWHS         : Item 550
  Member 2%,LP_Date      : Item 552
  Member 2%,LP_Time      : Item 556
  Member Spare4$[4]      : Item 560
  Member 3%,Rol0         : Item 564
  Member SDEAL$[10]     : Item 570
  Member 3%,NDPPU        : Item 580
  Member 3%,SEQNUM       : Item 596
  Member Spare2$[38]     : Item 602
End Def

Def Struct INVT ! Accessed by Header ORef[5]
! 4/SORDFLETH#
  Member 2%,T1[1]        : Item 0
  Member 3%,T2[25]       : Item 8
  Member 2%,JRNL         : Item 164
  Member 2%,MCode[9]     : Item 168
  Member 3%,MCharge[9,1] : Item 208
  Member 3%,TOT[4]       : Item 328
  Member 1%,MCTXBL[9]    : Item 358
  Member 1%,DCLVL        : Item 378
  Member 3%,TOT_ORD      : Item 380
  Member Spare0$[12]     : Item 386
  Member 1%,TOTALPAE     : Item 398
  Member 3%,INVNO        : Item 400
  Member Spare1$[106]    : Item 406
End Def

Def Struct INVS2 ! Order Ship2 Accessed by Rec# OrdHdr ORef[4]
! 4/SORDFLESH#
  Member 2%,S1[1]        : Item 0
  Member S1$[118]        : Item 8
  Member S2$[20]         : Item 126
  Member 2%,S5           : Item 146
  Member 1%,S6[1]        : Item 150
  Member 3%,SRN[5]       : Item 154
  Member 3%,INVNO        : Item 190
  Member Spare0$[60]     : Item 196
End Def

Def Struct INVM ! Invoice Message
! 4/SORDFLEMH#
! Dir 1=IIIIIIMMMb I=Invoice, M-Message number, b=blank
  Member M1$[40]         : Item 0
  Member 2%,M1           : Item 40
End Def
