!myreports.inc shiplist file structure
	Def Struct MYReports
		! 6/myreports#
		! Dir 1= UUUUUUUUYYYYMMDDhhmmssBBB
		! userid,blockid,date,time
		Member userid$[8] : Item 0
		Member datetime$[14] : Item 8
		Member blockid$[3]  : Item 22
		Member fname$[100]  : Item 25
	End Def 
