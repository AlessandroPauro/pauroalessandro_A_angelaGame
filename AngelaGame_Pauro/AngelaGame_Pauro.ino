int Giocatore = 0;
int PunteggioTOT = 0;
int Meta;
int Giocata;
int Caso00 [6] = {1, 2, 3, 4, 5, 6};
int Caso16 [4] = {2, 3, 4, 5};
int Caso25 [4] = {1, 3, 4, 6};
int Caso34 [4] = {1, 2, 5, 6};

void setup() {
}
void MetaSelezionabile()
{
  Meta = Serial.parseInt();
  if (Meta > 99) {
    Serial.print("Meta non disponibile, MetaMAX 99");
    Meta = 99;
  } 
  
  else if (Meta < 30 ) {
    Serial.print("Meta non disponibile, MetaMIN 30");
    Meta = 30;
  }  
}


void loop() { 
  while(Serial.available() == 0){}
  if (Giocata > 6){Serial.print("Seleziona un numero da 0 a 6");}
  else{ValoreSelezionabile();}
}
   void  ValoreSelezionabile(){
   Giocata = Serial.parseInt();   
   switch (Giocata){
       case 0: Caso00;  break;
       case 1: Caso16;  break;
       case 2: Caso25;  break;
       case 3: Caso34;  break;
       case 4: Caso34;  break;
       case 5: Caso25;  break;
       case 6: Caso16;  break;
    }
}


void FinePartita()
{
  if (PunteggioTOT == Meta){Serial.print("Ha vinto il giocatore " + Giocatore)}
  else if (PunteggioTOT > Meta){Serial.print("Ha perso il giocatore " + Giocatore)}
}
