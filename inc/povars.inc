Def Struct poInfo
  Member PO$[10]
  Member Status$[50]
  Member OrderDate$[20]
  Member DueDate$[20]
  Member ConfDate$[20]
  Member Term$[14]
  Member Buyer$[30]
  Member ShipVia$[10]
  Member Type$[10]
  Member Whse$[2]
  Member TotAmt$[30]
  Member TotWt$[30]
  Member TotCube$[30]
  Member TotPc$[30]
  Member Vend$[6]
  Member VendName$[30]
  Member SoldAddr1$[50]
  Member SoldAddr2$[50]
  Member SoldAddr3$[50]
  Member SoldAddr4$[50]
  Member ShipAddr1$[50]
  Member ShipAddr2$[50]
  Member ShipAddr3$[50]
  Member ShipAddr4$[50]
End Def

Def Struct poItem
  Member Li$[10]
  Member Item$[12]
  Member Desc1$[80]
  Member Desc2$[80]
  Member QtyOrd$[20]
  Member QtyShp$[20]
  Member QtyRcv$[20]
  Member UoM$[10]
  Member UnitCost$[30]
  Member Cunit$[10]
  Member ExtCost$[30]
  Member Zline$[1]
End Def
