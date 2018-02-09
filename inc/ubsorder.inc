Def Struct OrdH
! 3/SORDFLEH#
! Dir 1= SSOOOOOO S=Status H0[0] O=Order Number H0[7]
! Dir 2= CCCCCCOOOOOO C=Customer Number H0[4]
! Dir 3= sssOOOOOOb s=Salseman H0[11] b=blank
  Member 2%,H0[12]     : Item 0
  Member 1%,H3[1]      : Item 52
  Member 3%,Tot_Sell   : Item 56
  Member 1%,NU         : Item 62
  Member 1%,LockPort   : Item 64
  Member V0$[12]       : Item 66
  Member 1%,H4[2]      : Item 78
  Member H0$[20]       : Item 84
  Member 2%,H5[16]     : Item 104
  Member 2%,ST3[24]    : Item 172
  Member H1$[6]        : Item 272
  Member 2%,SLSM[9]    : Item 278
  Member 3%,SCOM[4]    : Item 318
  Member 3%,SMER[4]    : Item 348
  Member 3%,SCST[4]    : Item 378
  Member 2%,H6[8]      : Item 408
  Member HMat$[2]      : Item 444
  Member PO$[20]       : Item 446
  Member 2%,HFax[1]    : Item 466
  Member 2%,HSti[1]    : Item 474
  Member 2%,H2         : Item 482
  Member 1%,OWHT[1]    : Item 486
  Member 2%,OWHT1[1]   : Item 490
  Member 3%,TotGL      : Item 498
  Member 1%,PickBy[2]  : Item 504
  Member Spare$[2]     : Item 510
  Member 3%,ORef[5]    : Item 512
  Member 2%,CSPLT[4]   : Item 548
  Member 3%,COMMSVGCHG : Item 568
  Member Spare1$[72]   : Item 574
End Def

Def Struct OrdD
! 3/SORDFLEL#
! Dir 1=OOOOOOLLLb O=order Number L2[1], L=Line Number L3[2], b=blank
! Dir 2=PPPPPPOOOOOOLLLb P=Product Record Number L4[0]
  Member 2%,L2[1]     : Item 0
  Member 1%,L3[3]     : Item 8
  Member 2%,L4[3]     : Item 16
  Member 3%,L5[3]     : Item 32
  Member 2%,L6[5]     : Item 56
  Member L6$[60]      : Item 80
  Member L1$[20]      : Item 140
  Member 2%,L9[1]     : Item 160
  Member 3%,L7[12]    : Item 168
  Member 1%,PL[1]     : Item 246
  Member 1%,UN[2]     : Item 250
  Member 1%,S2[1]     : Item 256
  Member 3%,S3[17]    : Item 260
  Member MT$[2]       : Item 368
  Member S3$[33]      : Item 370
  Member POFlag$[1]   : Item 403
  Member 3%,OLM[6]    : Item 404
  Member 1%,EUN[2]    : Item 446
  Member 3%,UNF[6]    : Item 452
  Member 2%,LCO[1]    : Item 494
  Member 3%,CST       : Item 502
  Member 3%,LTax1     : Item 508
  Member 1%,CTWT[1]   : Item 514
  Member Spare20$[20] : Item 518
  Member 2%,LTax2     : Item 538
  Member 3%,QPB       : Item 542
  Member 1%,LPrinted  : Item 548
  Member 1%,OWHS      : Item 550
  Member 2%,LP_Date   : Item 552
  Member 2%,LP_Time   : Item 556
  Member Spare4$[4]   : Item 560
  Member 3%,Rol0      : Item 564
  Member SDEAL$[10]   : Item 570
  Member 3%,NDPPU     : Item 580
  Member 1%,LBLPRNTED : Item 586
  Member 3%,LBL_DATE  : Item 588
  Member 3%,LBL_TIME  : Item 592
  Member 3%,SEQNUM    : Item 596
  Member Spare5$[38]  : Item 602
End Def

Def Struct OrdT ! Accessed by Header H0[3]
! 3/SORDFLET#
  Member 2%,T1[1]         : Item 0
  Member 3%,T2[25]        : Item 8
  Member 2%,JRNL          : Item 164
  Member 2%,MCode[9]      : Item 168
  Member 3%,MCharge[9,1]  : Item 208
  Member 3%,TOT[4]        : Item 328
  Member 1%,MCTXBL[9]     : Item 358
  Member 1%,DCLVL         : Item 378
  Member 3%,TOT_ORD       : Item 380
  Member 3%,TOT1[1]       : Item 386
  Member 1%,TOTALPAGE     : Item 398
  Member 3%,INVNO         : Item 400
  Member Spare$[106]      : Item 406
End Def

Def Struct OrdS2 ! Order Ship2 Accessed by Rec# OrdHdr H0[2]
! 3/SORDFLES#
  Member 2%,S1[1]         : Item 0
  Member S1$[118]         : Item 8
  Member S2$[20]          : Item 126
  Member 2%,S5            : Item 146
  Member 1%,S6[1]         : Item 150
  Member 3%,SRN[5]        : Item 154
  Member 3%,INVNO         : Item 190
  Member Spare$[60]       : Item 196
End Def

Def Struct ORDM ! Order Message
! 3/SORDFLEM#
! Dir 1=OOOOOOMMMb O=Order, M-Message number, b=blank
  Member M1$[40]          : Item 0
  Member 2%,M1            : Item 40
End Def

Def Struct Lastprice ! Lastprice                        
! 2/LASTPRICE#                                          
! Dir 1=CCCCCCDDDPPPPPPPPPPPPPPPPPPPPVVVVVVMMMMB
! Dir 2=CCCCCCDDDMMMMPPPPPPPPPPPPPPPPPPPPVVVVVVB
! Dir 3=CCCCCCDDDFFFFFFPPPPPPPPPPPPPPPPPPPPVVVVVVMMMMB
! Dir 4=VVVVVVMMMMPPPPPPPPPPPPPPPPPPPPCCCCCCDDDB
  Member LP$[12]          : Item 0
  Member 2%,LPDF          : Item 12
  Member 2%,LPC1[2]       : Item 16
  Member 3%,LPC2[2]       : Item 28
  Member 1%,LPC3[4]       : Item 46
  Member LP2$[84]         : Item 56
  Member 3%,LPC4[3]       : Item 140
  Member LPMT$[2]         : Item 164
  Member 1%,AI            : Item 166
  Member 3%,LPR[4]        : Item 168  
  Member 2%,LPR1[3]       : Item 198
  Member 1%,LPEUN[2]      : Item 214
  Member 3%,LPUNF[6]      : Item 220
  Member 3%,PERM[1]       : Item 262
  Member 1%,LPWH          : Item 274
  Member 2%,LPC5[3]       : Item 276
  Member 2%,LPPCDATE      : Item 292
  Member 3%,LPLPERM       : Item 296
  Member 3%,LPCURR[1]     : Item 302
  Member 1%,LPCPT         : Item 314
  Member 2%,LPCSDT        : Item 316
  Member 3%,LPFPPERM[1]   : Item 324
  Member 1%,PPPUSERID     : Item 336
  Member 3%,LPUNIT[1]     : Item 340
  Member 2%,PPPCID[1]     : Item 352
  Member ABLSUB$[12]      : Item 360
  Member Spare$[228]      : Item 372
End Def                                                
