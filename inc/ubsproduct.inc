Def Struct Product
! 2/SRPROD# 1792
! Dir 1=PPPPPPPPPPPP P=Product Code  ? A$[140,151]
! Dir 2=bFPPPPPPPPPPPP b=blank, F=Make/buy code A$[139,139]
! Dir 3=CCCCPPPPPPPPPPPP C=Commodity code A$[152,155]
! Dir 4=VVVVVVVVVVVVVVVVVVVVPPPPPPPPPPPP V=Venodr Item # A$[93,112]
  Member A$[156]            : Item 0
  Member 2%,B[24]           : Item 156
  Member 3%,A[33]           : Item 256
  Member 3%,A1[7]           : Item 460
  Member 2%,A2              : Item 508
  Member 1%,PFU1[20]        : Item 512
  Member 3%,PFU2[6]         : Item 554
  Member 3%,PRPARC[3]       : Item 596
  Member 1%,LM[1]           : Item 620
  Member 1%,PR_PO[2]        : Item 624
  Member 1%,PR_SPARE1       : Item 628
  Member 1%,LLC             : Item 630
  Member PSN$[20]           : Item 632
  Member 2%,PSN[1]          : Item 652
  Member 2%,U2              : Item 660
  Member 3%,LBSORD          : Item 664
  Member 2%,U4[1]           : Item 670
  Member 3%,U3              : Item 678
  Member U3$[60]            : Item 684
  Member HZ$[90]            : Item 744
  Member 2%,A3[2]           : Item 834
  Member 1%,PFTB[3]         : Item 846
  Member 1%,UPCT            : Item 854
  Member C1$[32]            : Item 856
  Member PRSpare1$[6]       : Item 888
  Member 2%,PR_C4[10]       : Item 894
  Member 3%,PF_Load2        : Item 938
  Member PR_A2$[30]         : Item 944
  Member 2%,PFCO[3]         : Item 974
  Member 3%,PLV[1]          : Item 990
  Member 2%,PLC[3]          : Item 1002
  Member 3%,PFN[1]          : Item 1018
  Member 2%,STK[2]          : Item 1030
  Member 3%,PROPEN          : Item 1042
  Member 2%,FDT[1]          : Item 1048
  Member PRFlg$[10]         : Item 1056
  Member 1%,PRBASE          : Item 1066
  Member 2%,PRMKUP[3]       : Item 1068
  Member PRMKUPTYP$[4]      : Item 1084
  Member 3%,FUT[1]          : Item 1088
  Member 1%,PRPARC2[3]      : Item 1100
  Member 3%,PRREDI[1]       : Item 1108
  Member PIC$[50]           : Item 1120
  Member SR_A2$[15]         : Item 1170
  Member 3%,SA[1]           : Item 1185
  Member Spare0$[1]         : Item 1197
  Member 2%,LPMRK[5]        : Item 1198
  Member 2%,SL[2]           : Item 1222
  Member PKDATE$[20]        : Item 1234
  Member 3%,USRDEFCAT       : Item 1254
  Member Spare1$[10]        : Item 1260
  Member 2%,PRD0[2]         : Item 1270
  Member PRIML$[12]         : Item 1282
  Member 1%,PRD1[4]         : Item 1294
  Member 1%,PRD2[3]         : Item 1304
  Member LONGDESC$[50]      : Item 1328
  Member MSDSFILE$[50]      : Item 1378
  Member 3%,PRD3            : Item 1428
  Member Spare2$[106]       : Item 1434
End Def

Def Struct CommCode
! Dir1 = CCCC C=Commodity Code
! 2/CommCode# 2288
  Member D$[36]              : Item 0
  Member 2%,C1[100]          : Item 16
  Member 1%,C2[100]          : Item 440
  Member 1%,C0[100]          : Item 642
  Member 2%,C3[1]            : Item 844
  Member CmdtyUpChg$[101]    : Item 852
  Member 2%,CmdtyUpChg[100]  : Item 953
  Member 1%,CmdtyBrkTbl[100] : Item 1357
  Member Spare1$[1]          : Item 1559
  Member 1%,PRFAC            : Item 1560
  Member Spare2$[238]        : Item 1562
End Def

Def Struct ProdSLS             
! 2/sprodsls# 2080              
  Member P1$[12]             : Item 0
  Member 3%,S1[12,2]         : Item 16
  Member 3%,s2[12,2]         : Item 256
End Def
