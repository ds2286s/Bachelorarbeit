@ECHO off
set /A counter=0
start 	 %1
:LOOP

IF ERRORLEVEL %2 (
  ECHO Error
) ELSE (
	 set /A counter=%counter%+1
	if %counter%  gtr 15 (
		GOTO exit
	)
  ECHO ...
  SLEEP 1
  GOTO LOOP
)

:exit
