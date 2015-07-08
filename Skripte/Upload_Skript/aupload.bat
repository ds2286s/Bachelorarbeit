@echo off
setlocal EnableDelayedExpansion
REM     aupload.bat  -  Don Cross  -  http://cosinekitty.com
rem		(some slight modifications for 0011 by raptorofaxys)

set rc=1

REM ---------------------------------------------------------------------------
   
if "%1" == "" (
    echo.
    echo.Usage  -  aupload hexfile
    echo.
    echo.Uploads the given hexfile [e.g. "mysketch.hex"] to your Arduino board.
    echo.If hexfile is an asterisk [*], aupload will search in .\obj for a .hex
    echo.file, and if exactly one such .hex file is found, that will be uploaded.
    echo.
    echo.This batch file was released on September 10, 2008.
    echo.
	echo. Modified on November 13, 2014 for new Arduino Yun-Board by Dennis Stolp
    goto end
)

 if "%2" == "" (
 	echo. Angabe für COM-Port fehlt.
 	goto end
 	)

if "%3" == "" (
 	echo. Angabe des Bootloader COM-Ports fehlt.
 	goto end
 )

if "%1" == "*" (
    set hexcount=0
    for %%f in (obj\*.hex) do (
        set hexfile=%1
        echo.Found !hexfile!
        set /a hexcount+=1
    )
    
    if !hexcount! == 1 (
        REM   Unique file was found.  We are happy.
    ) else (
        if !hexcount! == 0 (
            echo.
            echo.aupload.bat:  No hex files were found in obj\*.hex
            echo.
        ) else (
            echo.
            echo.aupload.bat:  Found !hexcount! hex files.  
            echo.Please specify which should be uploaded, or delete all but one of them.
            echo.
        )
        goto end
    )                  
) else (
    set hexfile=%1
    if not exist !hexfile! (
        echo.aupload.bat:  File !hexfile! does not exist.
        goto end
    )
)

call agetpref.bat agetpref_internal
if not !errorlevel! == 0 (
    goto end
)
	
echo. !hexfile!
echo. %2
REM Übegebe dem Python-Skript den COM-PORT
start !python!\python.exe PortReset.py %2
echo. starte Python-Skript
echo. ...
REM Gebe dem Bootloader 2(3-1) Sekunden um zu starten
ping -n 2 127.0.0.1 >NUL
REM %3 ist der verwendete Bootloader für den Upload.

set cmd="!arduino_path!\hardware\tools\avr\bin\avrdude" -C "!arduino_path!\hardware\tools\avr\etc\avrdude.conf" -p !arduino_mcu! -P %3 -c !arduino_programmer! -b !arduino_burnrate! -D -U"flash:w:!hexfile!":i

!abuild_report! !cmd!
!cmd!	
set rc=!errorlevel!
goto end

REM ---------------------------------------------------------------------------

:end

echo.aupload.bat:  exiting with return code !rc!
exit /b !rc!