int Giocatore = 0;
int PunteggioTOT = 0;
int Meta = 30;
int Giocata = 1;
int PrimaGiocata[7] = {0, 1, 2, 3, 4, 5, 6};
int Giocate[4];

void setup() {
  // put your setup code here, to run once
}
void AumentaMeta()
{
  if (Meta == 99) {
    Serial.print("Non puoi aumentare la Meta");
  }
  else {
    Meta++;
  }
}
void DiminuisciMeta()
{
  if (Meta == 30 ) {
    Serial.print("Non puoi diminuire la Meta");
  }
  else {
    Meta--;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ValoreSelezionabile();
}

  void  ValoreSelezionabile(){
    switch (Giocata){
       case 0: Giocatore = 1;

   }
}
