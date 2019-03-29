#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Giocatore = 0;
int PunteggioTOT = 0;

int Stato = 1;
int backup = 0;
int Meta = 0;
int MetaIn = 30;
int Giocata;
int Caso00 [7] = {0, 1, 2, 3, 4, 5, 6};
int Caso17 [6] = {1, 2, 3, 4, 5, 6};
int Partita = 1;

const int buttonPin1 = 22;
const int buttonPin2 = 24;
const int buttonPin3 = 26;

   
void setup() {
  lcd.begin(16, 2);
   pinMode(buttonPin1, INPUT_PULLUP);
   pinMode(buttonPin2, INPUT_PULLUP);
   pinMode(buttonPin3, INPUT_PULLUP);
   lcd.setCursor(2,0);lcd.print("Benvenuto in");lcd.setCursor(2,1);
   lcd.print("Angela Game");delay(3000);lcd.clear();
}



void MetaSelezionabile()
{   
    lcd.print("Inserisci valore");
    lcd.setCursor(2,1);
    lcd.print("tra 30 e 99");
    delay(2000);
    lcd.clear();
    SelezionaConBottone();
    ControlloMeta();
  }

void SelezionaConBottone(){while (digitalRead(buttonPin2)!= LOW)
     {
      lcd.print("Seleziona valore");
      lcd.setCursor(1,2);lcd.print("<-");lcd.setCursor(13,2);lcd.print("+>");lcd.setCursor(7,2);lcd.print(MetaIn); 
      delay(100); 
      if(digitalRead(buttonPin1) == LOW){MetaIn++;}
      if(digitalRead(buttonPin3) == LOW){MetaIn--;}
      lcd.clear();
     }
     return MetaIn;
     }


void ControlloMeta(){    
  if(MetaIn < 30){lcd.print("Valore troppo ");  lcd.setCursor(2,1);
    lcd.print("basso");delay(3000);lcd.clear();}
  else if(MetaIn>99){lcd.print("Valore troppo "); lcd.setCursor(2,1);
    lcd.print("alto");delay(3000);lcd.clear();}
  if(MetaIn >= 30 && MetaIn <= 99){lcd.print("   Confermato");delay(2000);lcd.clear();Stato=2; Meta = MetaIn;MetaIn=NULL;}} 


void Giocata0(){
  lcd.print(Giocata);delay(1500);lcd.clear();
    for (int i = 0; i <= 7 ; i++) {
      if (Giocata == Caso00 [i]) 
      {
      lcd.print(Giocata);lcd.clear();
      PunteggioTOT = PunteggioTOT + Giocata; backup = Giocata;     
      lcd.print("Punteggio: "); lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(1000);lcd.clear();Giocatore++;Gioco();}    
      }
    }
    
void Giocata17(){
  lcd.print(Giocata);delay(1500);lcd.clear();
      if (Giocata > 0 && Giocata < 7)
      {
       lcd.print(Giocata);lcd.clear();backup = Giocata;PunteggioTOT = PunteggioTOT + Giocata; 
       lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(2000);lcd.clear();
       Giocatore++;Gioco(); 
      }
       else
       { 
       lcd.print("Errore di"); lcd.setCursor(2,1);lcd.print("selezione");delay(1000);lcd.clear();Gioco();
       }
    }
  

void Giocata1(){
 if (Giocata == 1 || Giocata == 6) 
      {
        lcd.print("Errore di"); lcd.setCursor(2,1);lcd.print("selezione");delay(1000);lcd.clear();Gioco();
       }
 else {
       lcd.print(Giocata);lcd.clear();backup = Giocata;PunteggioTOT = PunteggioTOT + Giocata; 
       lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(1000);lcd.clear();Giocatore++;Gioco();}
     
   }
  
  

void Giocata2(){
 if (Giocata == 2 || Giocata == 5) {
        lcd.print("Errore di"); lcd.setCursor(2,1);lcd.print("selezione");delay(1000);lcd.clear();Gioco();
 }
 else {
       lcd.print(Giocata);lcd.clear();backup = Giocata;PunteggioTOT = PunteggioTOT + Giocata; 
       lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(1000);lcd.clear();Giocatore++;Gioco();}
      }
    
  
void Giocata3(){  
 if (Giocata == 3 || Giocata == 4){
        lcd.print("Errore di"); lcd.setCursor(2,1);lcd.print("selezione");delay(1000);lcd.clear();Gioco();
      }
       else {
        lcd.print(Giocata);lcd.clear();backup = Giocata;PunteggioTOT = PunteggioTOT + Giocata; 
        lcd.print("Punteggio: ");lcd.setCursor(2,1);lcd.print(PunteggioTOT);delay(1000);lcd.clear();Giocatore++;Gioco();}
    }
  



void ValoreSelezionabile(){ 
  MetaIn = 0;
  SelezionaConBottone();
  Giocata = MetaIn; 
  if (Giocatore == 1 && backup == 0){Giocata17();}
  else if(Giocata == backup||Giocata==0||Giocata<0||Giocata>6){lcd.print("valore errato");delay(2000);lcd.clear();Gioco();}
  else if (backup == 1 || backup == 6){Giocata1();}
  else if (backup == 2 || backup == 5){Giocata2();}
  else if (backup == 3 || backup == 4){Giocata3();}
  }
  
  

  
  
void Gioco() {
  lcd.clear();
  if(Giocatore == 0 && PunteggioTOT == 0)
  {
  lcd.print("     GIOCA");delay(1000);lcd.clear();
  lcd.print("Seleziona valore ");lcd.setCursor(2,1);
  lcd.print("tra 0 e 6");delay(2000);lcd.clear();
  MetaIn = 0;
  SelezionaConBottone();
  Giocata = MetaIn; 
  Giocata0();
  Giocatore = 1;
  }
  else
  {
  lcd.clear();  
  if (PunteggioTOT==Meta||PunteggioTOT > Meta) {FinePartita();}
  if(Giocatore % 2 == 0 && Stato==2){lcd.print("    GIOCA G1");delay(1000);lcd.clear();
  lcd.print("Seleziona valore ");lcd.setCursor(2,1);
  lcd.print("tra 1 e 6");delay(2000);lcd.clear();
  ValoreSelezionabile();
  }
  else if(Giocatore % 2 == 1 && Stato==2){lcd.print("    GIOCA G2");delay(1000);lcd.clear();
  lcd.print("Seleziona valore ");lcd.setCursor(2,1);
  lcd.print("tra 1 e 6");delay(2000);lcd.clear();
  ValoreSelezionabile();
  }
  }
}
//Conclusione Partita  
void FinePartita()
{
  if (PunteggioTOT == Meta) {
    if(Giocatore % 2 == 0){
    lcd.print("Ha vinto ");lcd.setCursor(2,1);
    lcd.print("Giocatore 2");delay(2000);lcd.clear();} 
    else {lcd.print("Ha vinto ");lcd.setCursor(2,1);
    lcd.print("Giocatore 1");delay(2000);lcd.clear();}
    lcd.print("Fine della");lcd.setCursor(3,1);
    lcd.print("partita");delay(2000);lcd.clear();}
else{
  if (PunteggioTOT > Meta) {
    if(Giocatore % 2 == 0){
    lcd.print("Ha perso ");lcd.setCursor(2,1);
    lcd.print("Giocatore 2");delay(2000);lcd.clear();}} 
    else {lcd.print("Ha perso ");lcd.setCursor(2,1);
    lcd.print("Giocatore 1");delay(2000);lcd.clear();}
    lcd.print("Fine della");lcd.setCursor(3,1);
    lcd.print("partita");delay(2000);lcd.clear();}
    Partita++; 
    lcd.print("Partita N " + String(Partita));delay(2000);lcd.clear();
    MetaSelezionabile();  
}


void loop() {
    if(Stato == 1){MetaSelezionabile();}
    if(Stato == 2){Gioco();}
    if(Stato == 3){FinePartita();}
  }
