#include <Constants.au3>

;
; AutoIt Version: 3.0
; Language:       English
; Platform:       Win9x/NT
; Author:        Dennis Stolp
;
; Script Function:
;   Plays with the calculator.
;


Run("C:\Users\Dennis\Google Drive\SynchroArbeit_Studium\BachelorThesisCI\DropControl\Applikation\DropControl.exe")

Sleep(2000)
Local $hWnd = WinWait("[CLASS:WindowsForms10.Window.8.app.0.2bf8098_r11_ad1]", "", 5)
;WinMove ( "DropControl", "text", 500, 500)
WinMove($hWnd, "", 0, 0, 768, 592)

; Now that the calculator window is active type the values 2 x 4 x 8 x 16
; Use AutoItSetOption to slow down the typing speed so we can see it
;AutoItSetOption("SendKeyDelay", 400)
;Send("2*4*8*16=")


; Now quit by sending a "close" request to the calculator window using the classname
;WinClose("[CLASS:CalcFrame]")

; Now wait for the calculator to close before continuing
;WinWaitClose("[CLASS:CalcFrame]")

; Finished!


;Deactivate Vsync and F2=F1
MouseClick("left", 222, 143, 1)
MouseClick("left", 337, 213, 1)

;Valve 1 Länge 1ms
MouseClick("left", 491, 120, 1)
MouseClick("left", 485, 135, 1)
MouseClick("left", 679, 108, 1)

;Start Fotolag
MouseClick("left", 250, 110, 2)
Send("32")

;HB
MouseClick("left", 250, 215, 2)
Send("46")
;VB
MouseClick("left", 250, 255, 2)
Send("41")


;Connect zur DropControl
MouseClick("left",80,113,1)
MouseClick("left",680,141,1)
MouseClick("left",69,141,1)
MouseClick("left",118,112,1)
MouseClick("left",246,412,2)
;Transmit
MouseClick("left",80,530,1)
MouseClick("left",136,531,1)
