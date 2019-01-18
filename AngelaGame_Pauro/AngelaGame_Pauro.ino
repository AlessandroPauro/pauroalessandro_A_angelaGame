void setup() {
  // put your setup code here, to run once:
  int Giocatore = 0;
  int PunteggioTOT = 0;
  int Meta = 30;  
  int Giocate[] = {1, 2, 3, 4, 5, 6};
  int Giocata = 1;
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

void ValoreSelezionabile()
{
  switch (Giocata)
  {
    case 1 || 6: 
    Giocate [] = {2, 3, 4, 5};

    case 2 || 5:
    Giocate [] = {1, 3, 4, 6};
    
    case 3 || 4:
    Giocate [] = {1, 2, 5, 6};   
  } 
  }

void loop() {
  // put your main code here, to run repeatedly:
  
}
