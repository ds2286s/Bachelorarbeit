#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.12.0
 Author:         myName

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start - Add your code below here
#include <MsgBoxConstants.au3>
$dc =Run("C:\Users\Dennis\Google Drive\SynchroArbeit_Studium\BachelorThesisCI\DropControl\Applikation\DropControl.exe")


Local $string ="0"

Sleep(2000)
Local $hWnd = WinWait("[CLASS:WindowsForms10.Window.8.app.0.2bf8098_r11_ad1]", "", 5)
;WinMove ( "DropControl", "text", 500, 500)
WinMove($hWnd, "", 0, 0, 768, 592)
;Deactivate Vsync and F2=F1
MouseClick("left", 222, 143, 1)
MouseClick("left", 337, 213, 1)


;Valve 1 Länge 1ms
MouseClick("left", 491, 120, 1)
MouseClick("left", 485, 135, 1)
MouseClick("left", 679, 108, 1)
$select ="2"
$tmp = "2"
Local $tmp = GUICtrlRead("ID:1001")

MouseClick("left", 480, 112, 2)
Send("-1")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:Edit; INSTANCE:14]")
If $tmp = "-" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(2)
EndIf

MouseClick("left", 480, 112, 2)
Send("0")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:Edit; INSTANCE:14]")
If $tmp = "-" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(2)
EndIf

MouseClick("left", 480, 112, 2)
Send("1")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:Edit; INSTANCE:14]")
If $tmp = "1" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(2)
EndIf


MouseClick("left", 480, 112, 2)
Send("8")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:Edit; INSTANCE:14]")
If $tmp = "-" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(2)
 EndIf

