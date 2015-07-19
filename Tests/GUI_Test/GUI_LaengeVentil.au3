$dc =Run("C:\Users\Dennis\Google Drive\SynchroArbeit_Studium\BachelorThesisCI\DropControl\Applikation\DropControl.exe")


Local $string ="0"

Sleep(2000)
Local $hWnd = WinWait("[CLASS:WindowsForms10.Window.8.app.0.2bf8098_r11_ad1]", "", 5)
;WinMove ( "DropControl", "text", 500, 500)
WinMove($hWnd, "", 0, 0, 768, 592)

;Deactivate Vsync and F2=F1
MouseClick("left", 222, 143, 1)
MouseClick("left", 337, 213, 1)


MouseClick("left", 655, 108, 2)
Send("-1")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:69]")
If $tmp = "0" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(4)
 EndIf


 MouseClick("left", 655, 108, 2)
Send("5")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:69]")
If $tmp = "5" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(4)
 EndIf


MouseClick("left", 655, 108, 2)
Send("256")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:69]")
If $tmp = "255" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
	MouseClick("left", 679, 108, 1)
 	Exit(4)
EndIf