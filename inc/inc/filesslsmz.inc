Def Struct sslsm ! SALESMAN  generated by dfcreatestruct on 03/06/08
  Member Name$[30]                     : Item 0 ! S1$[1,30]
  Member Address$[30]                  : Item 30 ! S1$[31,60]
  Member City$[30]                     : Item 60 ! S1$[61,90]
  Member Phone$[15]                    : Item 90 ! S1$[91,105]
  Member State$[2]                     : Item 105 ! S1$[106,107]
  Member ZipCode$[8]                   : Item 107 ! S1$[108,115]
  Member SlsmNum$[3]                   : Item 115 ! S1$[116,118]
  Member 3%,CommPct                    : Item 118 ! S1[0]
  Member 3%,SlsmType                   : Item 124 ! S1[1]         see below
  Member 3%,CommMtd                    : Item 130 ! S1[2]
  Member 3%,CommYtd                    : Item 136 ! S1[3]
  Member 3%,CatSales[19,5]             : Item 142 ! S2[19,5]
  Member 3%,MinGP                      : Item 862 ! S3[0]
  Member 3%,RecNum                     : Item 868 ! S3[1]         for iq links
  Member 3%,Div                        : Item 874 ! S3[2]         SPICERS
  Member 3%,Wh                         : Item 880 ! S3[3]         ADD ON 1/18/05
  Member 3%,MoCommFlag                 : Item 886 ! S3[4]         Spicer186501
  Member 3%,NotUsed                    : Item 892 ! S3[5]
  Member 3%,NotUsed1                   : Item 898 ! S3[6]
  Member 3%,NotUsed2                   : Item 904 ! S3[7]
  Member 3%,PdaFlag                    : Item 910 ! S3[8]
  Member 3%,SalesGrp                   : Item 916 ! S3[9]         ADDED ??
  Member EmailAddress$[50]             : Item 922 ! S2$[1,50]     ADDED 01/20/03
  Member EmailAddress2$[50]            : Item 972 ! 
  Member 1%,SalesSecGroup              : Item 1022 ! 
  Member 3%,InvoiceMTD                 : Item 1024 ! 
  Member 3%,InvoiceYTD                 : Item 1030 ! 
  Member 3%,CreditsMTD                 : Item 1036 ! 
  Member 3%,CreditsYTD                 : Item 1042 ! 
  Member 3%,LoadTable                  : Item 1048 ! 
  Member 1%,AllowBonus                 : Item 1054 ! 
  Member 3%,DrawAmount                 : Item 1056 ! 
  Member 4%,FAXNUM                     : Item 1062 !
  Member 1%,VIATYPE                    : Item 1070 !
  Member NotUsed$[151]                 : Item 1072 ! 
End Def
!
! ----------------------------------------
!
! external lib statements
!
External Lib "libfilesslsmz.lib"
declare external function filegetsslsmz,fileupdatesslsmz
declare external sub filedroplistsslsmz