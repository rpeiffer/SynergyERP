!"rtn.pmupgrade.i

!"Author:  Nate 4/27/98

!"Purpose: To make standard functions available to an upgrade program
!"         being run by pmupgrader.

do_write_log: !----------------------------------------------------------------+
! Print a message to the log file                                              |
!                                                                              |
! Inbound: logmsg$ = A message to record in the log file                       |
!          ch_log = The channel which is open to the log file; -1 deactivates. |
!                                                                              |
!------------------------------------------------------------------------------+
dim tm$[30] !"scratch variable
if ch_log<>-1
	call time(tm$)
	print #ch_log;tm$;": ";logmsg$
endif
return

display_progress: !------------------------------------------------------------+
! Display a on screen progress message                                         |
!                                                                              |
! Inbound: rec     = current record count                                      |
!          actrecs = total [active] records                                    |
!          col,row = coordinates at which to display the progress message      |
!------------------------------------------------------------------------------+
if not(fromUpgrade)
	print @col,row; rec;"/";actrecs;
	if actrecs print using "(####.###% DONE)";(rec/actrecs*100);
	print 'cl';
else
	if ch_log<>-1
		logmsg$ = str$(rec)+"/"+str$(actrecs)
		if actrecs
			logmsg$ = logmsg$ + (rec/actrecs*100) using " (####.###% DONE)"
		end if
		gosub do_write_log:
	end if
end if
return

get_active_recs: !-------------------------------------------------------------+
! Get the active number of records for the given file                          |
!                                                                              |
! Inbound: ch = The channel number of the given file to query. Must be already |
!               open.                                                          |
!                                                                              |
! Outbound: actrecs = Total active records of the given file.                  |
!------------------------------------------------------------------------------+
dim kgar$[100] !"scratch variable
let e=7 \ search #ch,1,0;kgar$,actrecs,e \ if e error 11000
return
