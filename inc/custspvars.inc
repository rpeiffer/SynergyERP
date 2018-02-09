! customer special price/contract variables
! this is use for displaying customer special prices and contract info
! this file merges contract and special price file info
! currently used in custm

Def Struct CustspInfo
  Member ProdCode$[12] ! is by commodity code will have "CMDTY (commodity code) "
  Member ProdDesc1$[30]
  Member ProdDesc2$[30]
  Member ContractNo$[6] ! will contain spaces if a special price 
  Member StartDate$[10]
  Member CancelDate$[10]
  Member MinimumQty$[12]
  Member FactorType$[40] ! contain margin/factor/type descriptions
End Def

