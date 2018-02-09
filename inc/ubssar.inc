Def Struct SarAct
! 2/saract#
! Dir 1=CCCCCCRRRRRRTb C=Cust, R=Ref#, T=Type, b=blank
! Dir 2=CCCCCCJJJJJJRRRRRRTb J=Julian Date (A2[4])
! Dir 3=PPPPPPCCCCCCJJJJJJttttttTb  P=Posting cust, t=transaction #
! type codes: 1=Invoice, 2=Service Crg, 3=NSF (returned check), 4=debit adj
!             5=Late Charge, 6=credit Memo, 7=Unapplied payment
!             8=credit adj (write off), 9=Payment
  Member 2%,A2[5]     : Item 0
  Member 3%,A3[13]    : Item 24
  Member A3$[16]      : Item 108
  Member 1%,A0[14]    : Item 124
  Member 2%,A4[8]     : Item 154
  Member 2%,A1[2]     : Item 190
  Member 3%,A5[8]     : Item 202
  Member A4$[60]      : Item 256
  Member 3%,ARREF[1]  : Item 316
End Def