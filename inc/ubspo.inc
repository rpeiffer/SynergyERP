Def Struct POHDR
! 3/SPOFLEH#
! Dir 1=SSNNNNNN S=Status, N=PO Number
! Dir 2=VVVVVVNNNNNN V=Vendor Code
  Member 2%,H0[5]        : Item 0
  Member H$[82]          : Item 24
  Member H1$[116]        : Item 106
  Member 2%,H3[4]        : Item 222
  Member 1%,H4[3]        : Item 242
  Member 3%,H8[9]        : Item 250
  Member 2%,PH[4]        : Item 310
  Member 1%,PO1[9]       : Item 330
  Member 3%,PO3[12]      : Item 350
  Member 3%,DelvTime1    : Item 392
  Member ST$[14]         : Item 428
  Member H2$[40]         : Item 442
  Member 1%,H5[10]       : Item 482
  Member 2%,H6[2]        : Item 504
  Member 3%,PWGT[1]      : Item 516
  Member 3%,POH7[2]      : Item 528
  Member Spare0$[18]     : Item 546
  Member 1%,POFRT[1]     : Item 564
  Member Spare1$[24]     : Item 568
  Member POFRT$[6]       : Item 592
  Member Spare2$[20]     : Item 620
End Def

Def Struct PODET
! 3/SPOFLEL#
! Dir 1=NNNNNNLLL N=PO Number, L=Line Number
! Dir 2=PPPPPPNNNNNNLLL P=Product Record #
  Member 1%,L1[5]        : Item 0
  Member 2%,L2[2]        : Item 12
  Member 3%,L3[6]        : Item 24
  Member L1$[120]        : Item 66
  Member 3%,PL[5]        : Item 186
  Member 1%,PL0[4]       : Item 222
  Member 3%,PL4[23]      : Item 232
  Member 1%,POMISC[2]    : Item 376
  Member 3%,PL5[9]       : Item 382
  Member 3%,PL6[9]       : Item 442
  Member 3%,APCHRG       : Item 502
  Member 2%,CNTRL        : Item 508
  Member 3%,GWGT[4]      : Item 512
  Member Spare0$[84]     : Item 556
End Def

Def Struct POMSG
! 3/SPOFLEM#
! Dir 1=TNNNNNNLL T=type, N=PO Number, LL= Line Number
! Type 1=Note, 2=Message
  Member M$[60]          : Item 0
End Def

Def Struct NSTKDESC                                       
! 3/SNSTKDESC#                                           
! Dir 1=PPPPPPPPPPPPTT   P=Product Code, T=Tie-breaker
  Member NSD$[96]        : Item 0                     
  Member 1%,NSD1[7]      : Item 96
  Member 2%,NSD2[4]      : Item 112
  Member 3%,NSD3[10]     : Item 132
  Member Spare0$[48]     : Item 210
End Def                                                
