Def Struct VENDOR
! 2/A80VM#
! Dir 1=VVVVVV                V=Vendor Code
! Dir 2=NNNNNNNNNNNNNVVVVVV   N=Vendor Name V=Vendor Code
  Member A$[264]         : Item 0
  Member 2%,D1[6]        : Item 264
  Member 3%,A2[11]       : Item 292
  Member 3%,C1[5]        : Item 364
  Member C2$[44]         : Item 400
  Member 2%,V3           : Item 444
  Member 3%,V4[1]        : Item 448
  Member A1$[20]         : Item 460
  Member A2$[8]          : Item 480
  Member 1%,A[4]         : Item 488
  Member 3%,A3[7]        : Item 498
  Member A3$[4]          : Item 546
  Member 2%,M3           : Item 550
  Member 1%,M4[1]        : Item 554
  Member VCTRY$[15]      : Item 558
  Member EXFLG$[1]       : Item 573
  Member 1%,VBNK         : Item 574
  Member A5$[60]         : Item 576
  Member A6$[20]         : Item 636
End Def

Def Struct VENDTAG
! 2/VENDTAG#
! Dir 1=VVVVVV   V=Vendor Code
  Member M1$[200]        : Item 0
  Member 1%,M2[2]        : Item 200
  Member 3%,M1[17]       : Item 206
  Member M2$[72]         : Item 314
  Member 2%,M3[2]        : Item 386
  Member M3$[60]         : Item 398
  Member 2%,VNDGRP       : Item 458
  Member 3%,M4[2]        : Item 462
End Def
