void setup() {
 Serial.begin(115200);
 Serial.flush();
 
}

void loop() {
  RFootForward();
  Serial.flush();
  PozInitiala();
  Serial.flush();
}

//mere in fata incepand cu dreptu
void RFootForward()                 
{
  //se inclina in dreapta
  Serial.println("#17 P1500 T750");
  Serial.println("#18 P2250 T750");
  Serial.println("#16 P1650 T750");
  Serial.println("#0 P1650 T750");
  delay(1000);

  //duce dreptu in fata
  Serial.println("#1 P1750 T750");
  Serial.println("#2 P1250 T750");
  //De facut :de inclinat inapoi talpa dreapta
  delay(1000);

  //lasa picioru drept jos
  Serial.println("#16 P1250 T750");
  Serial.println("#0 P1350 T750");
  delay(1000);

  //urmatoru pas
  //Serial.println("#16 P1500 T1000");
  Serial.println("#1 P1500 T750");
  Serial.println("#2 P750 T750");
  Serial.println("#17 P1050 T750");
  Serial.println("#18 P1850 T750");
  delay(1000);
}

void PozInitiala()
{
  Serial.println("#0 P1520 T750");
  Serial.println("#1 P1500 T750");
  Serial.println("#2 P750 T750");
  Serial.println("#16 P1500 T750");
  Serial.println("#17 P1400 T750");
  Serial.println("#18 P2250 T750");
  delay(1000);
}

void sutDreptu()
{
  Serial.println("#17 P1500 T1000");
  Serial.println("#18 P2250 T1000");
  Serial.println("#16 P1650 T1000");
  Serial.println("#0 P1650 T1000");
  delay(1000);

  Serial.println("#1 P1750 T500");
  Serial.println("#2 P1250 T400");
  delay(1000);
}


//void LFootForward()
//{
// //blocare picior drept
// Serial.println("#0 P1500 T500");
// Serial.println("#1 P1500 T500");
// Serial.println("#2 P750 T500");
// Serial.println("#16 P1500 T500");
// delay(2500);
// //miscare picior stang
// Serial.println("#17 P1000 T500");
// Serial.println("#18 P1750 T500");
// Serial.println("#0 P1250 T500");
// delay(2500);
// //miscare picior drept
// Serial.println("#1 P2000 T500");
// Serial.println("#18 P20000 T500");
// Serial.println("#17 P1500 T500");
// Serial.println("#2 P1250 T500");
// delay(2500);
//}
