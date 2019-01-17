#define TimpMediu "T1000"

void setup() {
 Serial.begin(115200);
 Serial.flush();
 PozInitiala();
 delay(1000);
 RFootForward();
 PozInitiala();
 delay(1000);
 sutDreptu();
}

void loop() {
 
}

//mere in fata incepand cu dreptu
void RFootForward()                 
{
  //se inclina in dreapta
  Serial.println((String)"#17 P1500 "+TimpMediu);
  Serial.println((String)"#18 P2250 "+TimpMediu);
  Serial.println((String)"#16 P1650 "+TimpMediu);
  Serial.println((String)"#0 P1800 "+TimpMediu);
  delay(1000);

  //duce dreptu in fata
  Serial.println((String)"#1 P1750 "+TimpMediu);
  Serial.println((String)"#2 P1250 "+TimpMediu);
  //De facut :de inclinat inapoi talpa dreapta
  delay(1000);

  //lasa picioru drept jos
  Serial.println((String)"#16 P1250 "+TimpMediu);
  Serial.println((String)"#0 P1350 "+TimpMediu);
  delay(1000);

  //urmatoru pas
  Serial.println((String)"#1 P1500 "+TimpMediu);
  Serial.println((String)"#2 P750 "+TimpMediu);
  Serial.println((String)"#16 P1500 "+TimpMediu);
  Serial.println((String)"#17 P1050 "+TimpMediu);
  Serial.println((String)"#18 P1850 "+TimpMediu);
  delay(1000);
}

void PozInitiala()
{
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#1 P1500 "+TimpMediu);
  Serial.println((String)"#2 P750 "+TimpMediu);
  Serial.println((String)"#16 P1500 "+TimpMediu);
  Serial.println((String)"#17 P1400 "+TimpMediu);
  Serial.println((String)"#18 P2250 "+TimpMediu);
}

void sutDreptu()
{
  Serial.println((String)"#17 P1500 "+TimpMediu);
  Serial.println((String)"#18 P2250 "+TimpMediu);
  Serial.println("#16 P1650 T500");
  Serial.println("#0 P1800 T500");
  delay(1000);

  Serial.println("#1 P1750 T500");
  Serial.println("#2 P1250 T400");
  Serial.println("#0 P1500 T500");
}
