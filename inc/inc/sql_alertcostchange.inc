! Generated by SQLToDL4.pl program on 8/14/2013
!
! supporting library for MySQL access
!
include "src/inc/mysql_lib.inc"
!
DEF STRUCT SQL_alertcostchange
	MEMBER ProductID$[12]		: ITEM "ProductID"
	MEMBER %1,Warehouse		: ITEM "Warehouse"
	MEMBER %3,AddedWhen#		: ITEM "AddedWhen"
	MEMBER AddedWho$[60]		: ITEM "AddedWho"
	MEMBER %14,OldLoadedCost	: ITEM "OldLoadedCost"
	MEMBER %14,NewLoadedCost	: ITEM "NewLoadedCost"
	MEMBER %14,OldLoaded2Cost	: ITEM "OldLoaded2Cost"
	MEMBER %14,NewLoaded2Cost	: ITEM "NewLoaded2Cost"
	MEMBER %14,OldPOCost		: ITEM "OldPOCost"
	MEMBER %14,NewPOCost		: ITEM "NewPOCost"
	MEMBER %14,OldNetPOCost		: ITEM "OldNetPOCost"
	MEMBER %14,NewNetPOCost		: ITEM "NewNetPOCost"
	MEMBER %14,OldBaseCost		: ITEM "OldBaseCost"
	MEMBER %14,NewBaseCost		: ITEM "NewBaseCost"
	MEMBER %14,OldAvgCost		: ITEM "OldAvgCost"
	MEMBER %14,NewAvgCost		: ITEM "NewAvgCost"
	MEMBER %14,OldLoadTable		: ITEM "OldLoadTable"
	MEMBER %14,NewLoadTable		: ITEM "NewLoadTable"
	MEMBER %14,OldLoad2Table	: ITEM "OldLoad2Table"
	MEMBER %14,NewLoad2Table	: ITEM "NewLoad2Table"
END DEF
!
! ----------------------------------------
!
! external lib statements
!
External Lib "sql_alertcostchange.lib"
declare external function alertcostchange_SQLGet
declare external function alertcostchange_SQLInsert
declare external function alertcostchange_SQLUpdate
declare external function alertcostchange_SQLDelete
declare external function alertcostchange_SQLAddUpdate