Def Struct WHSE
! 2/SPRODWHSE#
! Dir 1= PPPPPPPPPPPPWW P=Product Code, W=Warehouse
! Dir 2= WWBBBPPPPPPPPPPPPb B=Buyer Code, b=blank
! Dir 3= WWVVVVVVPPPPPPPPPPPP V=Vendor Code
! Dir 4= WWvvvvvvvvvvvvvvvvvvvvPPPPPPPPPPPP v=Vendor item code
! Dir 5= WWPPPPPPPPPPPP
! Dir 6= Nothing (30 char)
! Dir 7= Nothing (30 char)
  Member W1$[32]         : Item 0
  Member 1%,W1[2]        : Item 32
  Member 2%,W2[9]        : Item 38
  Member 3%,W3[24]       : Item 78
  Member 3%,W5[25]       : Item 228
  Member 1%,WHPARC[5]    : Item 384
  Member 2%,WHLPOOL      : Item 396
  Member WComm$[4]       : Item 400
  Member 1%,FCWGT        : Item 404
  Member WHA2$[14]       : Item 406
  Member 1%,W0[3]        : Item 420
  Member 2%,WH7[3]       : Item 428
  Member 1%,WH8[47]      : Item 444
  Member 3%,WH9[25]      : Item 540
  Member 2%,W7[14]       : Item 696
  Member WH3$[24]        : Item 756
  Member 3%,WHLV[2]      : Item 780
  Member 1%,WHRPLN       : Item 798
  Member 3%,WHMISC[6]    : Item 800
  Member 1%,WHLM[1]      : Item 842
  Member 3%,WHMISC2[7]   : Item 846
  Member 1%,Restricted   : Item 894
  Member 3%,WHFUT[2]     : Item 896
  Member 2%,WHFDT[1]     : Item 914
  Member 3%,VLIST        : Item 922
  Member WHFLG$[10]      : Item 928
  Member 1%,WHBASE       : Item 938
  Member 2%,WHMKUP[3]    : Item 940
  Member WHMKUPTYP$[4]   : Item 956
  Member 1%,WHPARC2[3]   : Item 960
  Member 3%,WHREDI[1]    : Item 968
  Member 3%,WHLBS[1]     : Item 980
  Member WHSPare$[12]    : Item 992
  Member 2%,WHPRD0[1]    : Item 1004
  Member 3%,WHCSF[1]     : Item 1012
End Def

Def Struct SprodLot                      
! 3/sprodlot# 2528                       
  Member P0$[66]             : Item 0    
  Member 1%,P1[1]            : Item 66   
  Member 2%,P2[2]            : Item 70   
  Member 3%,P3[4]            : Item 82   
  Member 1%,P4               : Item 112  
  Member P1$[6]              : Item 114  
  Member 3%,PLTR             : Item 120  
End Def                                  

Def Struct SordLot                     
! 2/sordlot#  2320                    
  Member S0$[36]             : Item 0  
  Member 1%,OL1[3]           : Item 36                    
  Member 2%,OL2[3]           : Item 44
  Member 3%,OL3[5]           : Item 60
  Member OL2$[16]            : Item 96
End Def                                
