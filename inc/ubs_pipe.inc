!*********************************************************************************
!*- Universal Business Systems
!*- 
!*- ubs_pipe.inc
!*- 
!*- Include file for all programs that wish to use the bidirectional pipe
!*- handling routines in UBS_Pipe.lib.  The structures and libraries are
!*- used to execute external programs, gather output from, and send input
!*- to those routines.
!*- 
!*- Both binary and text based pipes are supported and there are rudimentary
!*- "expect" and "send" calls for pipes.
!*- 
!*- Text pipes handle input and output 1 line at a time and expect all I/O
!*- to be terminated with a new line.  The downside here is expect routines
!*- search only the current line read (meaning it will not remember what was
!*- last read and try to find a string that crosses a buffer read) or if
!*- we are trying to find a string so we can send a response to an input
!*- statement where the prompt does not do a new line before doing input
!*- the expect send process will hang.  Binary solves this problem, but the
!*- concept of "line by line" input is really lost.
!*- 
!*- In general, text based pipes should be used for parsing programs that do
!*- not have prompts that we need to answer that are not new line terminated.
!*- Many system utilities or programs that just return a status line that need
!*- to be parsed would be great examples.  Use binary based for programs that
!*- have prompts that need to be answered that are not new line terminated.
!*- 
!*********************************************************************************

!*
!* Pipe structure used by all UBS_Pipe routines
!*
Def Struct UBS_Pipe
	Member %1,Chan			! open channel to process
	Member %1,Status		! 0 = not open, 1 = open
	Member 1%,Binary		! 1=Pipe is in Binary Mode, 0 = text
	Member %2,ReadTimeout		! TENTHS of a second to wait for 
					! individual reads
	Member %2,RTBeforeFailure	! # of consective read timeouts before
					! we conclude that the process is
					! hung up or waiting on input
	Member %1,RWError		! Last Read/write results
					! 0 = No Error read:
					!     text - buffer contains line of data
					!     binary - buffer is full
					! 1 = read: timeout hit
					!     text - buffer empty, binary, whatever
					!     data has been gathered is in buffer
					! 2 = read: pipe closed - text: buffer empty
					!      binary, whatever data has been gathered
					!      is in buffer
					! 99 = general error
	Member Buffer$[256]		! read buffer - on good read contents
					! read in placed here
	Member LastLines$[3,256]	! last 4 lines read in - will even
					! attempt to do this for binary
					! pipes
	Member 1%,LastFullLine		! last full line (index 0-3) put in
					! the buffer.  once we get through 3
					! the next line shifts everything up
					! losing the first elements contents
	! text pipe only parameters
	Member %1,IgnoreBlanks		! 1 = ignore blank lines on reads (text mode only)
	Member %1,IgnoreUnibasic	! 1 = try to ignore Unibasic Startup (text only)
	! binary pipe only parameters
	Member 2%,BufferEnd		! index of last character successfully
					! placed in the buffer
	Member ExpectBuffer$[256]	! Used for "UBS_Expect" for binaries.
					! When searching for a string, may not
					! have gone through all string data on last
					! read.  Expect will move the area of the
					! buffer after the last match to this area.
					! Next call to expect will search here
					! first, then read to find the search string
	Member %2,EBufferEnd		! index of last charcter in ExpectBuffer
	Member %1,LastFullLineCompleted	! is the last full line I'm working
					! on completed? (see LastFullLine)
End Def

!*
!* Intrinsics needed by programs in UBS_Pipe library routines
!*
Declare Intrinsic Function findchannel,fmtof
Declare Intrinsic Sub findf
!*
!* UBS_Pipe library core routine declarations
!*
Declare External Function UBS_OpenPipe,UBS_ReadPipe,UBS_WritePipe,UBS_ClosePipe
Declare External Function UBS_FlushPipe
Declare External Function UBS_Expect,UBS_Send
Declare External Function UBS_ReadPipeBinary,UBS_ExpectBinary
!*
!* UBS_Pipe Utilities
!*
Declare External Function Process_Expect_Send