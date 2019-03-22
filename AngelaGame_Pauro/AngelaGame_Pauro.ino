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

const int buttonPin1 = 22;
const int buttonPin2 = 24;
const int buttonPin3 = 26;

   
void setup() {
  lcd.begin(16, 2);
   pinMode(buttonPin1, INPUT_PULLUP);
   pinMode(buttonPin2, INPUT_PULLUP);
   pinMode(buttonPin3, INPUT_PULLUP);
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
    SelezionaConBottone();
    ControlloMeta();
  }

void SelezionaConBottone(){    while (digitalRead(buttonPin2) != LOW)
     {
      lcd.print(MetaIn); 
      delay(100); 
      if(digitalRead(buttonPin1) == LOW){MetaIn++;}
      if(digitalRead(buttonPin3) == LOW){MetaIn--;}
      lcd.clear();
     }}


void ControlloMeta(){    
  if(MetaIn < 30){lcd.print("Valore troppo ");  lcd.setCursor(2,1);
    lcd.print("basso");delay(3000);lcd.clear();}
  else if(MetaIn>99){lcd.print("Valore troppo "); lcd.setCursor(2,1);
    lcd.print("alto");delay(3000);lcd.clear();}
  if(MetaIn >= 30 && MetaIn <= 99){lcd.print("FATTO");delay(2000);lcd.clear();Stato=2; MetaIn=Meta;MetaIn=NULL;}} 


void Giocata0(){
  MetaIn=0;
  Giocata = MetaIn;
  SelezionaConBottone();
  MetaIn = Giocata;
  lcd.print(Giocata);delay(3000);
    for (int i = 0; i < 7 ; i++) {
      if (Giocata == Caso00 [i]) {lcd.print(Giocata);lcd.clear();
      PunteggioTOT = PunteggioTOT + Giocata; 
         backup = Giocata;
        lcd.print("Punteggio: "); lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(2000);lcd.clear();
      }
      }
    }
    
void Giocata17(){
  Giocata = MetaIn;
  SelezionaConBottone();
  MetaIn = Giocata;
  lcd.print(Giocata);delay(3000);
    for (int i = 0; i <= 6 ; i++) {
      if (Giocata == Caso17 [i]) {
       lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata; 
        lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(2000);lcd.clear();
      }
    }
  }

void Giocata1(){
  Giocata = MetaIn;
  SelezionaConBottone();
  MetaIn = Giocata;
  lcd.print(Giocata);delay(3000);
    for (int i = 0; i <= 4 ; i++) {
      if (Giocata != Caso16 [i]) {
        lcd.print("Giocata non valida");delay(2000);lcd.clear();
      } else {
       lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata; 
       lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(2000);lcd.clear();
      }
    }
  }

void Giocata2(){
  Giocata = MetaIn;
  SelezionaConBottone();
  MetaIn = Giocata;
    for (int i = 0; i < 4 ; i++) {
      if (Giocata != Caso25 [i]) {
        lcd.print("Giocata non valida");delay(2000);lcd.clear();
      } else {
        lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata;
        lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT); delay(2000);lcd.clear(); 
      }
    }
  }
void Giocata3(){  
  Giocata = MetaIn;
  SelezionaConBottone();
  MetaIn = Giocata;
    for (int i = 0; i < 4 ; i++) {
      if (Giocata != Caso34 [i]) {
        lcd.print("Giocata non valida");delay(2000);lcd.clear();
      } else {
        lcd.print(Giocata);
        backup = Giocata;
        PunteggioTOT = PunteggioTOT + Giocata;
        lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(2000);lcd.clear();
      }
    }
  }



void ValoreSelezionabile(){ 
  if (Meta == PunteggioTOT || PunteggioTOT > Meta) {
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
  lcd.clear();
  lcd.print("GIOCA");delay(1000);lcd.clear();
  if(Giocatore == 0)
  {
  lcd.print("Seleziona un ");lcd.setCursor(2,1);
  lcd.print("tra 0 e 6");delay(2000);lcd.clear();
  Giocata0();
  Giocatore = 1;
  }
  lcd.clear();
  lcd.print("GIOCA 2");delay(1000);lcd.clear();
if (Giocatore > 0){lcd.print("Seleziona un numero ");lcd.setCursor(2,1);
    lcd.print("tra 1 e 6");delay(2000);lcd.clear();}
  lcd.print(Giocata);delay(2000);lcd.clear();
  ValoreSelezionabile();Giocatore++;}

  
void FinePartita()
{
  if (PunteggioTOT == Meta) {
    if(Giocatore % 2 == 0){
    lcd.print("Ha vinto ");lcd.setCursor(2,1);
    lcd.print("Giocatore 1");delay(2000);lcd.clear();} 
    else {lcd.print("Ha vinto ");lcd.setCursor(2,1);
    lcd.print("Giocatore 2");delay(2000);lcd.clear();}
    lcd.print("Fine della");lcd.setCursor(3,1);
    lcd.print("partita");delay(2000);lcd.clear();}
else{
  if (PunteggioTOT > Meta) {
    if(Giocatore % 2 == 0){
    lcd.print("Ha perso ");lcd.setCursor(2,1);
    lcd.print("Giocatore 1");delay(2000);lcd.clear();}} 
    else {lcd.print("Ha perso ");lcd.setCursor(2,1);
    lcd.print("Giocatore 2");delay(2000);lcd.clear();}
    lcd.print("Fine della");lcd.setCursor(3,1);
    lcd.print("partita");delay(2000);lcd.clear();}
  
  Stato = 1;
}


void loop() {
    if(Stato == 1){MetaSelezionabile();}
    if(Stato == 2){Gioco();}
    if(Stato == 3){FinePartita();}
  }
