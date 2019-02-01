int Giocatore = 0;
int PunteggioTOT = 0;
int Stato = 1;
int Meta;
int Giocata;
int Caso00 [7] = {0, 1, 2, 3, 4, 5, 6};
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



void loop() {
  if (Stato == 1) {
    MetaSelezionabile();
  } else if (Stato == 2) {
    Gioco();
  } else if (Stato == 3) {
    FinePartita();
  }
}
void Gioco() {
  Serial.println("Seleziona un numero da 0 a 6");
  while (Serial.available() == 0) {}
  if (Giocata < 6 && Giocatore == 0) {
    ValoreSelezionabile();
  }
  else {}
}
void ValoreSelezionabile() {
  Giocata = Serial.parseInt();
  if (Giocata == 0) {
    for (int i = 0; i < 7 ; i++) {
      if (Giocata != Caso00 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Giocata == 1) {
    for (int i = 0; i <= 5 ; i++) {
      if (Giocata != Caso16 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Giocata == 2) {
    for (int i = 0; i <= 6 ; i++) {
      if (Giocata != Caso25 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Giocata == 3) {
    for (int i = 0; i <= 6 ; i++) {
      if (Giocata != Caso34 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Giocata == 4) {
    for (int i = 0; i <= 6 ; i++) {
      if (Giocata != Caso34 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Giocata == 5) {
    for (int i = 0; i <= 6 ; i++) {
      if (Giocata != Caso25 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Giocata == 6) {
    for (int i = 0; i <= 5 ; i++) {
      if (Giocata != Caso16 [i]) {
        Serial.println("Giocata non valida");
      } else {
        Serial.println(Giocata);
        Giocatore++, PunteggioTOT = PunteggioTOT + Giocata;
      }
    }
  }
  if (Meta == PunteggioTOT || Meta > PunteggioTOT) {
    Stato = 3;
  }
}

void FinePartita()
{
  if (PunteggioTOT == Meta) {
    Serial.println("Ha vinto il giocatore " + (Giocatore % 2 == 0) ? "Giocatore1" : "Giocatore2");
  }
  else if (PunteggioTOT > Meta) {
    Serial.println("Ha perso il giocatore " + (Giocatore % 2 == 0) ? "Giocatore1" : "Giocatore2");
  }
  Stato = 1;
}
