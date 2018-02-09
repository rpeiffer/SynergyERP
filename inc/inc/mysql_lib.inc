
External Lib "mysql_lib.lib"

! NOTE: when dealing with structures or variables that have 
! date types associated with them USE SQLSNDT$, NOT SQLNV$ and
! SQLDT$, not SQLV$.
!
! From the readme.txt:
!
! A new intrinsic function, SQLDT$(), has been added for use with SQL
!     drivers such as the "MySQL SQL" or "Oracle SQL" driver.  The SQLDT$()
!     function is identical to the SQLV$() function except that it tells SQL
!     drivers to format all 1% precision date/time variable values as date only
!     values.  Date values with 2% or 3% precision are formatted as date and
!     time values.
! 
! A new intrinsic function, SQLSNDT$(), has been added for use with SQL
!     drivers such as the "MySQL SQL" or "Oracle SQL" driver.  The SQLSNDT$()
!     function is identical to the SQLSNV$() function except that it tells
!     SQL drivers to format all 1% precision date/time variable values as date
!     only values.  Date values with 2% or 3% precision are formatted as date
!     and time values.

Declare Intrinsic Function SQLV$,SQLDT$,SQLN$,SQLNV$,SQLSNDT$
Declare Intrinsic Function IsSQLNULL,SQLNULL,SQLNULL#,SQLNULL$

Declare External Function MySQLOpen
Declare External Sub MySQLDateToDL4,MySQLNumToDL4,MySQLStrToDL4
Declare External Sub DL4DateToMySQL,DL4NumToMySQL,DL4StrToMySQL
Declare External Function MySQLTimeToDL4,MySQLSetRIE,MySQLTableRows