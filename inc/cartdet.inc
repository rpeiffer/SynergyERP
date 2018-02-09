Def Struct cartdet                                                            
! 3/sfcartdet#                                                                  
! Dir 1= UUUUUUUUCCCCCCCCCCTLLLPPPPPPPPPPPP  U=User ID C=Customer ID T=Line Type L=Line Num 
! Dir 2= UUUUUUUUCCCCCCCCCCPPPPPPPPPPPPTLLL                                     
! U=User Id C=Customer Id P=Prod Code T=Line Type L=Line Num                    
Member UserId$[8]      : Item 0        
Member CustId$[10]     : Item 8        
Member Prod$[12]       : Item 18
Member LWH$[2]         : Item 30
Member LType$[1]       : Item 48       
Member QUM$[4]         : Item 50       
Member PUM$[4]         : Item 54       
Member 1%,lineno       : Item 58       
Member 1%,perm         : Item 60       
Member 3%,qty          : Item 62       
Member 3%,price        : Item 68
Member 3%,cost         : Item 74       
Member 3%,gp           : Item 80 
Member Notes$[600]     : Item 86  
Member 3%,ucost        : Item 686
Member 3%,uprice       : Item 692 
Member 2%,taxable      : Item 698
Member 2%,dept         : Item 702
Member 3%,L7           : Item 706
Member 3%,rol0         : Item 712  
Member Rolkey$[10]     : Item 718
Member 3%,PAR           : Item 728
Member 3%,Count         : Item 734
Member CostUM$[4]       : Item 740
End Def                                                                         
