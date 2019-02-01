int Giocatore = 0;
int PunteggioTOT = 0;
int Stato = 1;
int backup = 0;
int Meta;
int Giocata;
int Caso00 [7] = {0, 1, 2, 3, 4, 5, 6};
int Caso17 [6] = {1, 2, 3, 4, 5, 6};
int Caso16 [4] = {2, 3, 4, 5};
int Caso25 [4] = {1, 3, 4, 6};
int Caso34 [4] = {1, 2, 5, 6};


void setup() {
  Serial.begin(9600);
}


void MetaSelezionabile()
{ if (Meta == 0) {
    Serial.println("Inserisci valore tra 30 e 99");
    while (Serial.available() == 0) {}
    Meta = Serial.parseInt();
    if (Meta > 99) {
      Serial.println("Meta non disponibile, MetaMAX 99");
      Meta = 0;
    }

    else if (Meta < 30 ) {
      while (Serial.available() == 0) {}
      Serial.println("Meta non disponibile, MetaMIN 30");
      Meta = 0;
    }

    if (Meta > 30 && Meta < 99) {
      Stato = 2;
    }
  }
}

void Giocata0(){
    for (int i = 0; i < 7 ; i++) {
      if (Giocata == Caso00 [i]) {Serial.println(Giocata);
      PunteggioTOT = PunteggioTOT + Giocata; 
         backup = Giocata;
         Serial.println(PunteggioTOT);
      }
      }
    }
    
  void Giocata17(){

    for (int i = 0; i <= 6 ; i++) {
      if (Giocata == Caso17 [i]) {
        Serial.println(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata; 
        Serial.println(PunteggioTOT);
      }
    }
  }

void Giocata1(){

    for (int i = 0; i <= 4 ; i++) {
      if (Giocata != Caso16 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata; 
        Serial.println(PunteggioTOT);
      }
    }
  }

void Giocata2(){

    for (int i = 0; i < 4 ; i++) {
      if (Giocata != Caso25 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata;
        Serial.println(PunteggioTOT);
      }
    }
  }
void Giocata3(){
    for (int i = 0; i < 4 ; i++) {
      if (Giocata != Caso34 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata;
        Serial.println(PunteggioTOT);
      }
    }
  }



void ValoreSelezionabile(){ 
  
  if (Meta == PunteggioTOT || Meta < PunteggioTOT) {
  Stato = 3;}
  else {
       if (Giocata == 0){Giocata0();}
  else if (Giocatore == 1 && backup == 0){Giocata17();}
  else if (Giocata != backup && backup != 1 && backup != 6){Giocata1();}
  else if (Giocata != backup && backup != 2 && backup != 5){Giocata2();}
  else if (Giocata != backup && backup != 3 && backup != 4){Giocata3();}
  else {Gioco();}
  }
  }

void Gioco() {
  if(Giocatore == 0){
  Serial.println("Seleziona un numero da 0 a 6"); 
  while (Serial.available() == 0) {}
  Giocata = Serial.parseInt(); Giocata0();Giocatore = 1;}
  else if (Giocatore > 0){Serial.println("Seleziona un numero da 1 a 6");
  while(Serial.available() == 0) {}
  Giocata = Serial.parseInt();
  Serial.println(Giocata);
  ValoreSelezionabile();Giocatore++;}
} 
  
  

void FinePartita()
{
  if (PunteggioTOT == Meta) {
    if(Giocatore % 2 == 0){
    Serial.println("Ha vinto il giocatore Giocatore1");} else {Serial.print("Ha vinto il giocatore2");}
  }
  if (PunteggioTOT > Meta) {
    if(Giocatore % 2 == 0){
    Serial.println("Ha perso il giocatore Giocatore1");} else {Serial.print("Ha perso il giocatore2");}
  }
  Stato = 1;
}


void loop() {
    if (Stato == 1){MetaSelezionabile();}
    if(Stato == 2){Gioco();}
    if(Stato == 3){FinePartita();}
  }
