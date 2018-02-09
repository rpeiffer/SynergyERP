Def Struct inInfo
  Member SalesMan$[35]
  Member CustID$[6]
  Member CustName$[30]
  Member OrderNo$[10]
  Member InvoiceNo$[10]
  Member EnteredBy$[20]
  Member InvDate$[12]
  Member Amount$[20]
  Member Weight$[20]
  Member Tax$[20]
  Member Freight$[20]
  Member Misc$[20]
  Member TInvoice$[20]
  Member Cost$[20]
  Member Profit$[20]
  Member TGPP$[10]
  Member Commission$[20]
  Member RPTDate$[12]
  Member PMT$[20]
  Member PMTDate$[12]
  Member CustPO$[50]
End Def

Def Struct totInfo     
  Member totAmount$[30]
  Member totTax$[30]
  Member totFreight$[30]
  Member totMisc$[30]
  Member totTotal$[30]
  Member totCost$[30]
  Member totProfit$[30]
  Member totGp$[30]
  Member totComm$[30]
  Member totPmt$[30]
End Def

Def Struct priceInfo
  Member slsid$[6]   
  Member slsname$[30]
  Member custid$[6]    
  Member custname$[30] 
  Member prodid$[12]   
  Member desc1$[30]    
  Member desc2$[30]    
  Member pricetype$[10]
  Member whse$[2]
  Member vendoritem$[20]
  Member comm$[30]
  Member qtyonhand$[30]
  Member price$[30]
  Member cprice$[30]
  Member sprice$[30]
  Member gpp$[30]
  Member cost$[30] 
  Member ucost$[30]
  Member futurecost$[30] 
  Member futuredate$[10] 
  Member msgdesc$[150]
  Member 3%,price
  Member 3%,cprice
  Member 3%,sprice
  Member 3%,cost
  Member 3%,ucost
  Member 3%,futurecost
  Member 3%,qtyonhand
  Member 1%,punit
  Member 1%,qunit
  Member 3%,l7
  Member 3%,rol0
  Member PPU$[30]            
  Member rebatecontract$[100]
  Member permpricegroup$[50] 
End Def

Def Struct extPriceInfo
  Member rebateContractNo$[10]
  !* note - needed as "rebatecontract" contains add'l info.
  Member rebateContractExpiration$[10]
  Member priceContractNo$[10]
  Member priceContractExpiration$[10]
End Def
