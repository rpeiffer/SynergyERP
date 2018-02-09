!ubscust.inc customer file structure
Def Struct Customer
! 2/SCustomer#
! Dir 1= CCCCCC C=Customer Number
! Dir 2= NNNNNNNNNNNNNNCCCCCC N=Customer Name
! Dir 3= AAAAAA A=Customer Code (Alpha)
! Dir 4= rrrrrrrrrraaaaaaaaaaCCCCCC r=bank routing #, a= bank account
! Dir 5= SSSSSCCCCCC S=Salesman using #####
Member A1$[142] : Item 0
Member 2%,C1[12] : Item 142
Member 1%,C2[2] : Item 194
Member 2%,C3[1] : Item 200
Member 1%,C0 : Item 208
Member 3%,C4[6] : Item 210
Member 3%,C5[5] : Item 252
Member 3%,C6[9] : Item 288
Member A2$[30] : Item 348
Member 1%,C7[4] : Item 378
Member A3$[22] : Item 388
Member 1%,C8 : Item 410
Member 3%,C9 : Item 412
Member 1%,CSub : Item 418
Member 3%,U1 : Item 420
Member U2$[60] : Item 426
Member 2%,A0[3] : Item 486
Member 1%,S0[20] : Item 502
Member 3%,CFIN[8] : Item 544
Member 1%,SZN : Item 598
Member BT$[20] : Item 600
Member 2%,REC : Item 620
Member 3%,C10[5] : Item 624
Member 1%,C11[3] : Item 660
Member 3%,C12[3] : Item 668
Member 2%,C13 : Item 692
Member 1%,DefaultWhse : Item 696 ! DWH    
Member Resvd$[102] : Item 698
Member 2%,LPPPCUST : Item 724
Member PPU$[1] : Item 728
End Def 
