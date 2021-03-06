Def Struct cInfo
  Member CustNumber$[10]
  Member Billto$[10]
  Member CustName$[30]
  Member Addr1$[30]
  Member Addr2$[30]
  Member Addr3$[30]
  Member City$[15]
  Member State$[2]
  Member Zip$[10]
  Member Phone$[20]
  Member Fax$[20]
  Member SLSNo$[10]
  Member SLSName$[30]
  Member Contact$[20]
  Member LastOrderDT$[10]
  Member CreditLimit$[20]
  Member NetSalesMTD$[30]
  Member NetSalesYTD$[30]
  Member UnitsMTD$[30]
  Member UnitsYTD$[30]
  Member GPMTD$[30]
  Member GPYTD$[30]
  Member Route$[6,4]
  Member Stp$[6,4]
  Member ARS$[5,20]
  Member LastPaidDT$[10]
  Member AvgDays2Pay$[5]
  Member ARBal$[30]
  Member Start$[10]
  Member Other$[30]
End Def

Def Struct cCont
  Member FName$[16]
  Member LName$[20]
  Member Phone$[30]
  Member Pager$[30]
  Member Cell$[30]
  Member Fax1$[30]
  Member Fax2$[30]
  Member EMail$[50]
  Member Title$[20]
  Member Comment1$[40]
  Member Comment2$[40]
  Member Comment3$[40]
End Def

Def Struct slsInfo 
  Member mm$[16]
  Member unitsale$[30]
  Member netsale$[30]
  Member costsale$[30]
  Member profit$[30]
  Member gp$[10]
End Def

Def Struct arInfo
  Member CustNumber$[10]
  Member CustName$[30]
  Member Contact$[20]
  Member Phone$[20]
  Member SLSNo$[10]
  Member SLSName$[30]
  Member ARBal$[30]
  Member Current$[30]
  Member Over30$[30]
  Member Over60$[30]
  Member Over90$[30]
  Member PastDue$[30]
End Def

Def Struct totarInfo      
  Member totTotal$[30]    
  Member totCurrent$[30]
  Member totOver30$[30]   
  Member totOver60$[30]  
  Member totOver90$[30]   
  Member totPastDue$[30]
End Def                 
