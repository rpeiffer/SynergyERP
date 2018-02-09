Def Struct Zone
! 2/ZONEFLE#
! Dir 1= ZZ Z=Zone code
  Member D$[28]      : Item 0
  Member 2%,D0       : Item 28   ! Lead time
  Member 2%,D1       : Item 32   ! Truck Number
  Member T2$[8]      : Item 36   ! Char 1=sunday,2=Monday ... 7=Saturday
  Member A2$[2]      : Item 44   ! Zone Key
  Member Z2$[30]     : Item 46
  Member Z3$[12]     : Item 76
  Member 1%,Z0       : Item 88
  Member 2%,Z1[4]    : Item 90
  Member 1%,Z2[4]    : Item 110
  Member NotUsed$[8] : Item 120
End Def

Def Struct CSZone
! 3/CSZone#
! Dir 1=CCCCCC.SSSSSS C=Customer Number, S=Ship to Number
  Member 2%,CSZCust[2]   : Item 0   ! 0=cust, 1=ship 2, 3=leadtime
  Member 1%,CSZ1[6]      : Item 12  ! 0=sunday, ..., 6=Saturday
  Member CSZ$[14]        : Item 26  ! [1,2]=Sunday, ..., [13,14]=Saturday
  Member Spare$[24]      : Item 40
End Def