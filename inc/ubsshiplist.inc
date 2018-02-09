Def Struct ShipList 
! 2/Shiplist#^M                                  
! Dir 1= CCCCCC.SSSSSS    C=Customer Number .=Period  S=Shiplist#               
! Dir 2= NNNNNNNNNNNNNNNRRRRR  N=Shiplist Name (15) R=Record#  
  Member A$[142]        : Item 0
  Member 4%,C1          : Item 142
  Member R$[33]         : Item 150
  Member 2%,SL2[4]      : Item 184
  Member SI$[120]       : Item 204
  Member 3%,SLUD[6] : Item 324
Member SLUD$[60]  : Item 330
Member 2%,SLSLSM  : Item 390
End Def
