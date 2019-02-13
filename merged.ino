#include <SPI.h>  
#include <Pixy.h>

#define TimpMediu "T500"
#define TimpMic "T350"
#define DelayMic 500
#define DelayMare 1000

Pixy pixy;

void setup() 
{
  Serial.begin(115200);
  pixy.init();
  Serial.flush();
  pozInitial();
  delay(DelayMare);
  Serial.flush();
}

void loop() 
{
  static uint16_t blockFrameCounter = 0;
  static uint16_t noBlockFrameCounter = 0;
  uint8_t blockIterator;
  uint8_t blocks;
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
          delay(DelayMare);
          PasDupaTurnStanga();
          delay(DelayMare);
          pozInitial();
         } 
         else 
         {
          if(pixy.blocks[blockIterator].x >= 106 && pixy.blocks[blockIterator].x < 213)
          {
            if(pixy.blocks[blockIterator].y > 125)
            {
              miscatiHoitu();
              miscatiHoitu();
              sutDreptu();
              delay(DelayMare);
              pozInitial();
              continue;
            }
            miscatiHoitu();
            pozInitial();
          }
          else
          {
              turnDreapta();
              delay(DelayMare);
              PasDupaTurnDreapta();
              delay(DelayMare);
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
  Serial.println((String)"#0 P1620 "+TimpMediu);
  Serial.println((String)"#16 P1575 "+TimpMediu);
  delay(DelayMic);
  //primu pas
  Serial.println((String)"#1 P1400 "+TimpMediu);
  Serial.println((String)"#2 P1350 "+TimpMediu);
  Serial.println((String)"#17 P1200 "+TimpMediu);
  Serial.println((String)"#18 P1400 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);
  //al doilea pas
  Serial.println((String)"#0 P1460 "+TimpMediu);  //1420
  Serial.println((String)"#16 P1375 "+TimpMediu);
  delay(DelayMic);
  Serial.println((String)"#1 P1700 "+TimpMediu);
  Serial.println((String)"#2 P1650 "+TimpMediu);
  Serial.println((String)"#17 P1500 "+TimpMediu);
  Serial.println((String)"#18 P1700 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);
}

void pozInitial()
{
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  Serial.println((String)"#1 P1550 "+TimpMediu);
  Serial.println((String)"#2 P1500 "+TimpMediu);
  Serial.println((String)"#17 P1350 "+TimpMediu);
  Serial.println((String)"#18 P1550 "+TimpMediu);
}
//Modificat parametri !!!! nu mai merge ca s-a schimbat greutatea
void sutDreptu()
{
  Serial.println((String)"#17 P1350 "+TimpMediu);
  Serial.println((String)"#18 P1550 "+TimpMediu);
  Serial.println((String)"#16 P1650 "+TimpMediu);
  Serial.println((String)"#0 P1800 "+TimpMediu);
  delay(DelayMare);

  Serial.println((String)"#1 P1750 "+TimpMediu);
  Serial.println((String)"#2 P2000 "+TimpMic);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  delay(DelayMare);

  Serial.println((String)"#1 P1750 "+TimpMediu);
  Serial.println((String)"#2 P1000 "+TimpMic);
  delay(DelayMic);
  Serial.println((String)"#1 P1550 "+TimpMediu);
  Serial.println((String)"#2 P1500 "+TimpMediu);
}

void turnDreapta()
{
  Serial.println((String)"#16 P1475 "+TimpMediu);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  
  Serial.println((String)"#18 P1350 "+TimpMediu);     //de aici putem intoarce mai mult sau mai putin,astea 4 comenzi
  Serial.println((String)"#17 P1050 "+TimpMediu);     
  
  Serial.println((String)"#1 P1250 "+TimpMediu);
  Serial.println((String)"#2 P1200 "+TimpMic);
}

void turnStanga()
{
  Serial.println((String)"#16 P1475 "+TimpMediu);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  
  Serial.println((String)"#18 P1750 "+TimpMediu);     //de aici putem intoarce mai mult sau mai putin,astea 4 comenzi
  Serial.println((String)"#17 P1650 "+TimpMediu);     
  
  Serial.println((String)"#1 P1850 "+TimpMediu);
  Serial.println((String)"#2 P1800 "+TimpMic);
}

void PasDupaTurnStanga()
{
  Serial.println((String)"#0 P1620 "+TimpMediu);
  Serial.println((String)"#16 P1575 "+TimpMediu);
  delay(DelayMic);
  
  Serial.println((String)"#1 P1400 "+TimpMediu);
  Serial.println((String)"#2 P1350 "+TimpMediu);
  Serial.println((String)"#17 P1200 "+TimpMediu);
  Serial.println((String)"#18 P1400 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);
}

void PasDupaTurnDreapta()
{
  Serial.println((String)"#0 P1420 "+TimpMediu);
  Serial.println((String)"#16 P1375 "+TimpMediu);
  delay(DelayMic);

  Serial.println((String)"#1 P1700 "+TimpMediu);
  Serial.println((String)"#2 P1550 "+TimpMediu);
  Serial.println((String)"#17 P1500 "+TimpMediu);
  Serial.println((String)"#18 P1700 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);
}

void PasMare()
{
  turnStanga();
  delay(DelayMare);
  PasDupaTurnStanga();
  delay(DelayMare);
  
  turnStanga();
  delay(DelayMare);
  PasDupaTurnStanga();
  delay(DelayMare);
  
  turnStanga();
  delay(DelayMare);
  PasDupaTurnStanga();
  delay(DelayMare);
  
  pozInitial();  
}
