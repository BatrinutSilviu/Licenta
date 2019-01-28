#define TimpMediu "T500"

void setup() {
Serial.begin(115200);
Serial.flush();
pozInitial();
delay(500);
Serial.flush();
miscatiHoitu();
Serial.flush();
sutDreptu();
delay(1000);
pozInitial();
}

void loop() {
  
}

void miscatiHoitu()
{
  //sta tapan+ inclinare talpii
  Serial.println("#0 P1645 T500");
  Serial.println("#16 P1575 T500");
  delay(500);
  Serial.println("#1 P1400 T500");
  Serial.println("#2 P1350 T500");
  Serial.println("#17 P1200 T500");
  Serial.println("#18 P1400 T500");
  delay(1000);
  Serial.println("#0 P1520 T500");
  Serial.println("#16 P1475 T500");
  delay(1000);
  //al doilea pas
  Serial.println("#0 P1420 T500");
  Serial.println("#16 P1375 T500");
  delay(500);
  Serial.println("#1 P1700 T500");
  Serial.println("#2 P1650 T500");
  Serial.println("#17 P1500 T500");
  Serial.println("#18 P1700 T500");
  delay(1000);
  Serial.println("#0 P1520 T500");
  Serial.println("#16 P1475 T500");
  delay(1000);
}

void pozInitial()
{
  Serial.println("#0 P1520 T500");
  Serial.println("#16 P1475 T500");
  Serial.println("#1 P1550 T500");
  Serial.println("#2 P1500 T500");
  Serial.println("#17 P1350 T500");
  Serial.println("#18 P1550 T500");
}

void sutDreptu()
{
  Serial.println("#17 P1350 T500");
  Serial.println("#18 P1550 T500");
  Serial.println("#16 P1650 T500");
  Serial.println("#0 P1800 T500");
  delay(1000);

  Serial.println("#1 P1750 T500");
  Serial.println("#2 P2000 T350");
  Serial.println("#0 P1520 T500");
  delay(1000);

  Serial.println("#1 P1750 T500");
  Serial.println("#2 P1000 T350");
  delay(500);
  Serial.println("#1 P1550 T500");
  Serial.println("#2 P1500 T500");
}
