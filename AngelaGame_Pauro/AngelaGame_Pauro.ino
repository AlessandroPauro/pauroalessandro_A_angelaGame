void setup() {
  // put your setup code here, to run once:
  int Giocatore = 0;
  int PunteggioTOT = 0;
  int Meta = 30;  
}
  void AumentaMeta()
{
 if(Meta == 99){Serial.print("Non puoi aumentare la Meta");}
 else{Meta++;}
}
  void DiminuisciMeta()
{
 if(Meta == 30 ){Serial.print("Non puoi diminuire la Meta");}
 else{Meta--;}
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
