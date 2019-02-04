#include <SPI.h>  
#include <Pixy.h>
#include <LiquidCrystal.h>

#define TimpMediu "T500"

Pixy pixy;

void setup() 
{
  Serial.begin(115200);
  pixy.init();
  Serial.flush();
  pozInitial();
  delay(1000);
  Serial.flush();
}

void loop() 
{
  static int blockFrameCounter = 0;
  static int noBlockFrameCounter = 0;
  int blockIterator;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks!
  blocks = pixy.getBlocks();
  // If there are detect blocks, print them!
  if (blocks)
  {
    blockFrameCounter++;
    noBlockFrameCounter=0;
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (blockFrameCounter % 50 == 0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      for (blockIterator = 0; blockIterator < blocks; blockIterator++)
      {
        sprintf(buf, "  block %d: ", blockIterator);
        //Serial.println(buf);
        //pixy.blocks[blockIterator].print();         // in for u asta putem accesa x,y si altele prin pixy.blocks[j]
        if(pixy.blocks[blockIterator].x < 106 )
        {
          turnStanga();
          delay(1000);
          PasDupaTurnStanga();
          delay(1000);
          pozInitial();
         } 
         else 
         {
          if(pixy.blocks[blockIterator].x >= 106 && pixy.blocks[blockIterator].x < 213)
          {
            miscatiHoitu();
            pozInitial();
          }
          else
          {
              turnDreapta();
              delay(1000);
              PasDupaTurnDreapta();
              delay(1000);
              pozInitial();
          }
         }
      }
    }
  }
  else
  {
    noBlockFrameCounter++;
    if(noBlockFrameCounter > 10000)
    {
      noBlockFrameCounter = 0;
      PasMare(); 
    }
  } 
}

void miscatiHoitu()
{
  //inclinare talpii
  Serial.println("#0 P1620 T500");
  Serial.println("#16 P1575 T500");
  delay(500);
  //primu pas
  Serial.println("#1 P1400 T500");
  Serial.println("#2 P1350 T500");
  Serial.println("#17 P1200 T500");
  Serial.println("#18 P1400 T500");
  delay(1000);
  Serial.println("#0 P1520 T500");
  Serial.println("#16 P1475 T500");
  delay(1000);
  //al doilea pas
  Serial.println("#0 P1460 T500");  //1420
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

void turnDreapta()
{
  Serial.println("#16 P1475 T500");
  Serial.println("#0 P1520 T500");
  
  Serial.println("#18 P1350 T500");     //de aici putem intoarce mai mult sau mai putin,astea 4 comenzi
  Serial.println("#17 P1050 T500");     
  
  Serial.println("#1 P1250 T500");
  Serial.println("#2 P1200 T350");
}

void turnStanga()
{
  Serial.println("#16 P1475 T500");
  Serial.println("#0 P1520 T500");
  
  Serial.println("#18 P1750 T500");     //de aici putem intoarce mai mult sau mai putin,astea 4 comenzi
  Serial.println("#17 P1650 T500");     
  
  Serial.println("#1 P1850 T500");
  Serial.println("#2 P1800 T350");
}

void PasDupaTurnStanga()
{
  Serial.println("#0 P1620 T500");
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
}

void PasDupaTurnDreapta()
{
  Serial.println("#0 P1420 T500");
  Serial.println("#16 P1375 T500");
  delay(500);

  Serial.println("#1 P1700 T500");
  Serial.println("#2 P1550 T500");
  Serial.println("#17 P1500 T500");
  Serial.println("#18 P1700 T500");
  delay(1000);
  Serial.println("#0 P1520 T500");
  Serial.println("#16 P1475 T500");
  delay(1000);
}

void PasMare()
{
  turnStanga();
  delay(1000);
  PasDupaTurnStanga();
  delay(1000);
  
  turnStanga();
  delay(1000);
  PasDupaTurnStanga();
  delay(1000);
  
  turnStanga();
  delay(1000);
  PasDupaTurnStanga();
  delay(1000);
  
  pozInitial();  
}
