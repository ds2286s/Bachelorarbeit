$dc =Run("C:\Users\Dennis\Google Drive\SynchroArbeit_Studium\BachelorThesisCI\DropControl\Applikation\DropControl.exe")


Local $string ="0"

Sleep(2000)
Local $hWnd = WinWait("[CLASS:WindowsForms10.Window.8.app.0.2bf8098_r11_ad1]", "", 5)
;WinMove ( "DropControl", "text", 500, 500)
WinMove($hWnd, "", 0, 0, 768, 592)

ControlSetText("DropControl", "", "[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:7]","-1")
MouseClick("left", 679, 108, 2)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:7]")
If $tmp = "0" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(1)
 EndIf


 ControlSetText("DropControl", "", "[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:7]","1")
MouseClick("left", 679, 108, 2)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:7]")
If $tmp = "1" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(1)
 EndIf


ControlSetText("DropControl", "", "[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:7]","16")
MouseClick("left", 679, 108, 2)
$tmp= ControlGetText("DropControl","","[CLASS:WindowsForms10.EDIT.app.0.2bf8098_r11_ad1; INSTANCE:7]")
If $tmp = "15" Then
  MouseClick("left", 679, 108, 4)
ElseIf $tmp ="" Then
 	 Exit(1)
 EndIf