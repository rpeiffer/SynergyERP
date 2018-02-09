Def Struct cust ! CUSTOMER FILE  generated by dfcreatestruct on 11/26/07
  Member Contact$[20]                  : Item 0 ! A1$[1,20]
  Member Phone$[10]                    : Item 20 ! A1$[21,30]    AAANNNNNNN
  Member Name$[30]                     : Item 30 ! A1$[31,60]
  Member Addr1$[30]                    : Item 60 ! A1$[61,90]
  Member Addr2$[30]                    : Item 90 ! A1$[91,120]
  Member City$[15]                     : Item 120 ! A1$[121,135]
  Member State$[2]                     : Item 135 ! A1$[136,137]
  Member AuthBuyList$[1]               : Item 137 ! A1$[138,138]  see below
  Member NoDupInvToPrt$[1]             : Item 138 ! A1$[139,139]  see below
  Member FaxOrdersYN$[1]               : Item 139 ! A1$[140,140]  added 1/3/97 NPE
  Member ShpWithInvoiceYN$[1]          : Item 140 ! A1$[141,141]  5/6/03 see note
  Member NetworkAsn$[1]                : Item 141 ! A1$[142,142]  12/04
  Member 2%,CreditCode                 : Item 142 ! C1[0]
  Member 2%,CustomerCode               : Item 146 ! C1[1]
  Member 2%,SalesmanCode               : Item 150 ! C1[2]
  Member 2%,CreditCheckDays            : Item 154 ! C1[3]
  Member 2%,CustomerBillTo             : Item 158 ! C1[4]
  Member 2%,LastOrderDate              : Item 162 ! C1[5]
  Member 2%,LastEditDate               : Item 166 ! C1[6]         yymmdd
  Member 2%,PriceType                  : Item 170 ! C1[7]
  Member 2%,PreventMassDelete          : Item 174 ! C1[8]         #176101 Spicer
  Member 2%,CustomerCategory           : Item 178 ! C1[9]
  Member 2%,AvgPayDays                 : Item 182 ! C1[10]        FROM MX305
  Member 2%,Pays                       : Item 186 ! C1[11]        FOR AVG PAID
  Member 2%,YtdCashDisc                : Item 190 ! C1[12]        rec#20 age buck2
  Member 1%,Terms                      : Item 194 ! C2[0]
  Member 1%,TaxCode                    : Item 196 ! C2[1]         CHF(STAXCODE)
  Member 1%,StmtType                   : Item 198 ! C2[2]
  Member 2%,LastInvoiceDate            : Item 200 ! C3[0]
  Member 2%,LastPayDate                : Item 204 ! C3[1]
  Member 1%,SCStatus                   : Item 208 ! C0            see below
  Member 3%,CurrentArAgeBal            : Item 210 ! C4[0]
  Member 3%,UnappliedCredit            : Item 216 ! C4[1]
  Member 3%,AgeArAmt1                  : Item 222 ! C4[2]         rec#20 age buck1
  Member 3%,AgeArAmt2                  : Item 228 ! C4[3]         rec#20 age buck2
  Member 3%,AgeArAmt3                  : Item 234 ! C4[4]         rec#20 age buck3
  Member 3%,AgeArAmt4                  : Item 240 ! C4[5]         rec#20 age buck4
  Member 3%,LastAmountPaid             : Item 246 ! C4[6]
  Member 3%,UnitsMtd                   : Item 252 ! C5[0]
  Member 3%,UnitsYtd                   : Item 258 ! C5[1]
  Member 3%,NetSalesMtd                : Item 264 ! C5[2]
  Member 3%,NetSalesYtd                : Item 270 ! C5[3]
  Member 3%,GrProfitMtd                : Item 276 ! C5[4]
  Member 3%,GrProfitYtd                : Item 282 ! C5[5]
  Member 3%,SalesTxMtd                 : Item 288 ! C6[0]
  Member 3%,SlsTxYtd                   : Item 294 ! C6[1]
  Member 3%,FreightSalesMtd            : Item 300 ! C6[2]         from t2[5]
  Member 3%,FreightSalesYtd            : Item 306 ! C6[3]         from t2[5]
  Member 3%,DiscountMtd                : Item 312 ! C6[4]
  Member 3%,DiscountYtd                : Item 318 ! C6[5]
  Member 3%,MiscChrgMtd                : Item 324 ! C6[6]
  Member 3%,MiscChgYtd                 : Item 330 ! C6[7]
  Member 3%,SvcMtd                     : Item 336 ! C6[8]
  Member 3%,SvcYtd                     : Item 342 ! C6[9]
  Member Zip4$[10]                     : Item 348 ! A2$[1,10]     ZZZZZ-ZZZZ
  Member TaxExemp$[18]                 : Item 358 ! A2$[11,28]
  Member ZoneNumber$[2]                : Item 376 ! A2$[29,30]
  Member 1%,BoSAllowedFlag             : Item 378 ! C7[0]
  Member 1%,PoRequiredFlag             : Item 380 ! C7[1]
  Member 1%,KeepDetailSales            : Item 382 ! C7[2]         see below
  Member 1%,Priority                   : Item 384 ! C7[3]         (1-9)
  Member 1%,sStop                      : Item 386 ! C7[4]         (1-6999)
  Member s2ndCust$[6]                  : Item 388 ! A3$[1,6]      ALPHA/NUM
  Member Country$[15]                  : Item 394 ! A3$[7,21]
  Member PersnlGuaranty$[1]            : Item 409 ! A3$[22,22]
  Member 1%,PrintOrderPrices           : Item 410 ! C8            MX203A
  Member 3%,OpenOrder                  : Item 412 ! C9            FOR CREDIT CHK
  Member 1%,Substitutes                : Item 418 ! SUB
  Member 3%,UserDefined4               : Item 420 ! U1
  Member UserDefined1$[20]             : Item 426 ! U2$[1,20]
  Member UserDefined2$[20]             : Item 446 ! U2$[21,40]
  Member UserDefined3$[20]             : Item 466 ! U2$[41,60]
  Member 2%,SicCode                    : Item 486 ! A0[0]
  Member 2%,ConsignWh                  : Item 490 ! A0[1]
  Member 2%,NotifyPriceChg             : Item 494 ! A0[2]         N/Y/F
  Member 2%,TaxType                    : Item 498 ! A0[3]
  Member 1%,MultiSlsmList1             : Item 502 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList2             : Item 504 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList3             : Item 506 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList4             : Item 508 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList5             : Item 510 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList6             : Item 512 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList7             : Item 514 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList8             : Item 516 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList9             : Item 518 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList10            : Item 520 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList11            : Item 522 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList12            : Item 524 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList13            : Item 526 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList14            : Item 528 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList15            : Item 530 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList16            : Item 532 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList17            : Item 534 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList18            : Item 536 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList19            : Item 538 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList20            : Item 540 ! S0[0-20]      21x1%(slsctgy)
  Member 1%,MultiSlsmList21            : Item 542 ! S0[0-20]      21x1%(slsctgy)
  Member 3%,InvoiceMtd                 : Item 544 ! CFIN[0]
  Member 3%,InvoiceYtd                 : Item 550 ! CFIN[1]
  Member 3%,CreditsMtd                 : Item 556 ! CFIN[2]
  Member 3%,CreditsYtd                 : Item 562 ! CFIN[3]
  Member 3%,Division                   : Item 568 ! CFIN[4]
  Member 3%,FollowUpDate               : Item 574 ! CFIN[5]       FROM CALL NOTES
  Member 3%,CollectionAgent            : Item 580 ! CFIN[6]       see below
  Member 3%,DateEdit                   : Item 586 ! CFIN[7]       ADD 02/23/93
  Member 3%,SlsComServiceChar          : Item 592 ! CFIN[8]       ADD 06/01/93
  Member 1%,CustSalesZone              : Item 598 ! SZN           ADD 9/24/92
  Member BankTransit$[10]              : Item 600 ! BT$[1,10]     *DIR 4 LCKBX
  Member BankAcct$[10]                 : Item 610 ! BT$[11,20]    *DIR 4 LCKBX
  Member 2%,sRecord                    : Item 620 ! REC           for iq links
  Member 3%,FreightCostMtd             : Item 624 ! C10[0]        from t2[20]
  Member 3%,FreightCostYtd             : Item 630 ! C10[1]        from t2[20]
  Member 3%,MtdPayments                : Item 636 ! C10[2]        ADD 10/10/94
  Member 3%,DateEditUps                : Item 642 ! C10[3]        UPS DOWNLOAD
  Member 3%,CustomerDiscount           : Item 648 ! C10[4]        ADD 06/22/00
  Member 3%,OmahaCPMup                 : Item 654 ! C10[5]        IN USE @ FALCON
  Member 1%,DeliverChgLevel            : Item 660 ! C11[0]        see ut914
  Member 1%,EccosFlag                  : Item 662 ! C11[1]        2/14/00 WEB FLAG
  Member 1%,CommissionGrid             : Item 664 ! C11[2]        IN USE @ SWP
  Member 1%,ManualShiplist             : Item 666 ! C11[3]        ALLOW MANUAL SL?
  Member 3%,CreditLimit                : Item 668 ! C12[0]        mvd 05/14/01
  Member 3%,ARPostCust                 : Item 674 ! C12[1]        add 12/13/01
  Member 3%,AbcOverheadFactor          : Item 680 ! C12[2]        add 12/24/01
  Member 3%,AbcScore                   : Item 686 ! C12[3]        add 12/24/01
  Member 2%,DefaultOrderType           : Item 692 ! C13[0]        add 10/08/02
  Member 1%,DefaultWhse                : Item 696 ! DWH           cct182003
  Member 3%,PrepaidMin                 : Item 698 ! PPDMIN        AWM
  Member 2%,CreditApplicatDate         : Item 704 ! CRD_APP_DATE  cct121885-zephyr
  Member 2%,MastercustLpabl            : Item 708 ! MCLPF         DADE187517
  Member 1%,LpSecure                   : Item 712 ! LPSEC         DADE 187517
  Member 2%,CustomerGroup              : Item 714 ! CF_CUSTGRP    ACME 181653
  Member Reserved$[2]                  : Item 718 ! 
  Member 1%,PreventMassDelete1         : Item 720 ! C14[0]
  Member 1%,SortInvlineSlsctgy         : Item 722 ! C14[1]        0=N,1=Y
  Member 2%,LpPpGrpCust                : Item 724 ! LPPPCUST      BURKE190785
  Member PermPrcUpdate$[1]             : Item 728 ! PPU$[1]       BURKE191642
  Member BlktPoType$[1]                : Item 729 ! PPU$[2,2]     B/D
  Member BudgDateType$[1]              : Item 730 ! PPU$[3,3]     MQSAC
  Member SpareNotused$[3]              : Item 731 ! PPU$[4,6]
  Member BlanketPo$[20]                : Item 734 ! BPO$          LPC201662
  Member 3%,Budget                     : Item 754 ! BUDG[0]       LPC 201662
  Member 3%,BudgetUsed                 : Item 760 ! BUDG[1]       LPC 201662
  Member 2%,DateBPStart                : Item 766 ! BUDGD[0]      YYMMDD
  Member 2%,DateBPEnd                  : Item 770 ! BUDGD[1]      YYMMDD
  Member BlankForKey$[1]               : Item 774 ! 
  Member SpareReserved$[25]            : Item 775 ! 
End Def
!
! ----------------------------------------
!
! external lib statements
!
External Lib "libfilecust.lib"
declare external function filegetcust,fileupdatecust
declare external sub filedroplistcust