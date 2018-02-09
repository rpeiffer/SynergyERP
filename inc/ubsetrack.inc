Def Struct ETrack
! 2/EDITTTRACK#
! Dir 3=   JJJJJJJJHHMMSSOOOOOO?????? J=Julian Date,HHMMSS=Time,O=Order,J=line#
! Dir 5=SSSJJJJJJJJHHMMSSOOOOOO?????? S=Saleman Code
  Member 2%,ETORDER      : Item 0
  Member 1%,ETLINE       : Item 4
  Member 1%,ETSTAT       : Item 6
  Member ETPROD$[12]     : Item 8
  Member 3%,ETOQTY[2]    : Item 20
  Member 3%,ETNQTY[2]    : Item 38
  Member 2%,ETDATE       : Item 56
  Member 2%,ETTIME       : Item 60
  Member 2%,ETPORT       : Item 64
  Member ETUSER$[10]     : Item 68
  Member 2%,ETACTION     : Item 78
  Member 1%,ETUNIT       : Item 82
  Member 1%,ETNONSTOCK   : Item 84
  Member 2%,ETINVOICE    : Item 86
  Member 3%,ETORIGTOT    : Item 90
  Member 2%,ETCUST       : Item 96
  Member 2%,ETSLS        : Item 108
  Member 3%,ETUNITPRICE[1] : Item 112
  Member 1%,ETPUNIT        : Item 124
End Def
