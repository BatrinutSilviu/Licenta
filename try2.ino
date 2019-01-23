void setup() {
  Serial.begin(115200);
  Serial.flush();
miscatiHoitu();
Serial.flush();
pozInitial();
}

void loop() {
  miscatiHoitu();
}

void miscatiHoitu()
{
  //sta tapan+ inclinare talpi
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
  Serial.println("#0 P1395 T500");
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
