$dc =Run("C:\Users\Dennis\Google Drive\SynchroArbeit_Studium\BachelorThesisCI\DropControl\Applikation\DropControl.exe")


Local $string ="0"

Sleep(2000)
Local $hWnd = WinWait("[CLASS:WindowsForms10.Window.8.app.0.2bf8098_r11_ad1]", "", 5)
;WinMove ( "DropControl", "text", 500, 500)
WinMove($hWnd, "", 0, 0, 768, 592)
; Finished!
;Deactivate Vsync and F2=F1
MouseClick("left", 222, 143, 1)
MouseClick("left", 337, 213, 1)


MouseClick("left", 230, 257, 2)
Send("-1")
 MouseClick("left", 679, 108, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:2]")
If $tmp = "0" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(7)
 EndIf


  MouseClick("left", 230, 257, 2)
Send("1")
 MouseClick("left", 679, 108, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:2]")
If $tmp = "1" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(7)
 EndIf

 MouseClick("left", 230, 257, 2)
Send("10001")
 MouseClick("left", 679, 108, 1)
  MouseClick("left", 378, 333, 1)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:2]")
If $tmp = "10.000" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(7)
 EndIf