#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Giocatore = 0;
int PunteggioTOT = 0;

int Stato = 1;
int backup = 0;
int Meta;
int MetaIn = 30;
int Giocata;
int Caso00 [7] = {0, 1, 2, 3, 4, 5, 6};
int Caso17 [6] = {1, 2, 3, 4, 5, 6};
int Caso16 [4] = {2, 3, 4, 5};
int Caso25 [4] = {1, 3, 4, 6};
int Caso34 [4] = {1, 2, 5, 6};
/*
const int buttonPin1 = 7;
const int buttonPin2 = 8;
const int buttonPin3 = 9;*/

   
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
   pinMode(22, INPUT_PULLUP);
   pinMode(24, INPUT_PULLUP);
   pinMode(26, INPUT_PULLUP);
}



void MetaSelezionabile()
{   
  
    lcd.print("Inserisci valore");
    lcd.setCursor(2,1);
    lcd.print("tra 30 e 99");
    delay(3000);
    lcd.clear();
    lcd.print(MetaIn);
    delay(3000);
    lcd.clear();
    while (24 != LOW)
     {
      lcd.print(MetaIn);  
      delay(100);
      if(22 == LOW){MetaIn++;}
      if(26 == LOW){MetaIn--;}
      lcd.clear();
      Serial.print(digitalRead(22));
     }
  lcd.print("fuori"); 
   if(24 == LOW)
    {
      ContolloMeta();
    }

  }

void ContolloMeta(){    
  if(MetaIn < 30){lcd.print("Valore troppo basso");MetaIn = 30;}
  else{if(MetaIn>99){lcd.print("Valore troppo alto");MetaIn = 99;}}
  if(MetaIn >30 && MetaIn <99){Stato = 2;}} 



void Giocata0(){
    for (int i = 0; i < 7 ; i++) {
      if (Giocata == Caso00 [i]) {lcd.print(Giocata);
      PunteggioTOT = PunteggioTOT + Giocata; 
         backup = Giocata;
        lcd.print("Punteggio: "+ PunteggioTOT);
      }
      }
    }
    
void Giocata17(){
    for (int i = 0; i <= 6 ; i++) {
      if (Giocata == Caso17 [i]) {
       lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata; 
        lcd.print("Punteggio: ") + PunteggioTOT;
      }
    }
  }

void Giocata1(){
    for (int i = 0; i <= 4 ; i++) {
      if (Giocata != Caso16 [i]) {
        lcd.print("Giocata non valida");
      } else {
       lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata; 
       lcd.print("Punteggio: ") + PunteggioTOT;
      }
    }
  }

void Giocata2(){
    for (int i = 0; i < 4 ; i++) {
      if (Giocata != Caso25 [i]) {
        lcd.print("Giocata non valida");
      } else {
        lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata;
        lcd.print("Punteggio: ") + PunteggioTOT;  
      }
    }
  }
void Giocata3(){
    for (int i = 0; i < 4 ; i++) {
      if (Giocata != Caso34 [i]) {
        lcd.print("Giocata non valida");
      } else {
        lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata;
        lcd.print("Punteggio: ") + PunteggioTOT;
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
  lcd.print("Seleziona un numero da 0 a 6"); 
  Giocata0();Giocatore = 1;}
  else if (Giocatore > 0){lcd.print("Seleziona un numero da 1 a 6");
  lcd.print(Giocata);
  ValoreSelezionabile();Giocatore++;}
} 
  
  

void FinePartita()
{
  if (PunteggioTOT == Meta) {
    if(Giocatore % 2 == 0){
    lcd.print("Ha vinto il giocatore Giocatore1");} else {lcd.print("Ha vinto il giocatore2");}
  }
  if (PunteggioTOT > Meta) {
    if(Giocatore % 2 == 0){
    lcd.print("Ha perso il giocatore Giocatore1");} else {lcd.print("Ha perso il giocatore2");}
  }
  Stato = 1;
}


void loop() {
    if(Stato == 1){MetaSelezionabile();}
    if(Stato == 2){Gioco();}
    if(Stato == 3){FinePartita();}
  }
