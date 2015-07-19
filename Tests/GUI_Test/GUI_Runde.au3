$dc =Run("C:\Users\Dennis\Google Drive\SynchroArbeit_Studium\BachelorThesisCI\DropControl\Applikation\DropControl.exe")


Local $string ="0"

Sleep(2000)
Local $hWnd = WinWait("[CLASS:WindowsForms10.Window.8.app.0.2bf8098_r11_ad1]", "", 5)
;WinMove ( "DropControl", "text", 500, 500)
WinMove($hWnd, "", 0, 0, 768, 592)

;Deactivate Vsync and F2=F1
MouseClick("left", 222, 143, 1)
MouseClick("left", 337, 213, 1)


MouseClick("left", 230, 420, 2)
Send("-1")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:11]")
If $tmp = "1" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(8)
 EndIf


 MouseClick("left", 230, 420, 2)
Send("1")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:11]")
If $tmp = "1" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(8)
 EndIf


MouseClick("left", 230, 420, 2)
Send("251")
MouseClick("left", 452, 184, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:11]")
If $tmp = "250" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(8)
 EndIf