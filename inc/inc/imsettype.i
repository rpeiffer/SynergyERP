! imSetType.i	Include file for defined types

SetType: ! Hard-coded paramaters for recognized form types
DTDescription$ = ""

! DTDescription$ =	Description of type
! Prefix$ =			Type prefix
! DTIndex1$ =		Index element 1 description
! DTIndex2$ =		Index element 2 description
! DTIMode$ = 		Indexing mode; M:manual  B:barcode
! DTLookup$ =		Lookup field description
! DTReffile$=		Reference file

! currently defined reference files:
!	CUST	customer
!	VEND	vendor
!	PROD	product

If Type = 0
	DTDescription$ = "Delivery receipt"
	Prefix$ = "dr"
	DTIndex1$ = "Order number"
	DTIndex2$ = ""
	DTIMode$ = "B"	! default to barcode indexing - Bxx - xx=rotation
	DTLookup$ = ""	! No lookup field
	DTReffile$= ""
End if

If Type = 1
	DTDescription$ = "Product literature"
	Prefix$ = "pl"
	DTIndex1$ = "Item code"
	DTIndex2$ = "Reference code"
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = "Product description"
	DTReffile$= "PROD"
End if

If Type = 2
	DTDescription$ = "Customer document"
	Prefix$ = "cd"
	DTIndex1$ = "Customer#"
	DTIndex2$ = "Reference code"
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = "Customer name"
	DTReffile$= "CUST"
End if


If Type = 3
	DTDescription$ = "Vendor invoice"
	Prefix$ = "vi"
	DTIndex1$ = "Vendor code"
	DTIndex2$ = "Vendor invoice no."
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = "Vendor name"
	DTReffile$= "VEND"
End if

If Type = 4
	DTDescription$ = "Vendor statement"
	Prefix$ = "vs"
	DTIndex1$ = "Vendor code"
	DTIndex2$ = "Date (yymmdd)"
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = "Vendor name"
	DTReffile$= "VEND"
End if

If Type = 5
	DTDescription$ = "Vendor document"
	Prefix$ = "vd"
	DTIndex1$ = "Vendor code"
	DTIndex2$ = "Reference code"
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = "Vendor name"
	DTReffile$= "VEND"
End if

If Type = 6
	DTDescription$ = "MSDS Sheet"
	Prefix$ = "md"
	DTIndex1$ = "MSDS Number"
	DTIndex2$ = ""
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = ""
	DTReffile$= ""
End if

If Type = 7
	DTDescription$ = "Picking document"
	Prefix$ = "pd"
	DTIndex1$ = "Order number"
	DTIndex2$ = ""
	DTIMode$ = "B"	! default to barcode indexing - Bxx - xx=rotation
	DTLookup$ = ""	! No lookup field
	DTReffile$= ""
End if

If Type = 8
	DTDescription$ = "Misc. document"
	Prefix$ = "mi"
	DTIndex1$ = "+subtype"
	DTIndex2$ = "Key"
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = ""
	DTReffile$= ""
End if

! If Type = 9
! 	DTDescription$ = "Credit memo"
! 	Prefix$ = "cm"
! 	DTIndex1$ = "Order number"
! 	DTIndex2$ = ""
! 	DTIMode$ = "B"	! default to barcode indexing - Bxx - xx=rotation
! 	DTLookup$ = ""	! No lookup field
! 	DTReffile$= ""
! End if

If Type = 10
	DTDescription$ = "Concrete ticket"
	Prefix$ = "ct"
	DTIndex1$ = "Date (yymmdd)"
	DTIndex2$ = "Concrete ticket#"
	DTIMode$ = "B"	! default to barcode indexing - Bxx - xx=rotation
	DTLookup$ = ""	! No lookup field
	DTReffile$= ""
End if

If Type = 11
	DTDescription$ = "Order source"
	Prefix$ = "os"
	DTIndex1$ = "Order number"
	DTIndex2$ = ""
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = ""	! No lookup field
	DTReffile$= ""
End if
If Type = 12
	DTDescription$ = "Purchase Order"
	Prefix$ = "po"
	DTIndex1$ = "PO number"
	DTIndex2$ = ""
	DTIMode$ = "M"	! default to manual indexing
	DTLookup$ = ""	! No lookup field
	DTReffile$= ""
End if
Return
