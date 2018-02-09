Def Struct cartsp                                                            
! 3/sfcartsp#                                                                  
! Dir 1= UUUUUUUUCCCCCCCCCCTLLL  U=User ID C=Customer ID T=SP MSg Type 
! L=Line Num 
Member UserId$[8]      : Item 0        
Member CustId$[10]     : Item 8        
Member SPType$[1]      : Item 18       
Member SP1$[40]        : Item 20       
Member SP2$[40]        : Item 60       
Member 1%,lineno       : Item 100       
End Def                                                           
