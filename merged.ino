#include <SPI.h>  
#include <Pixy.h>

#define TimpMediu "T500"
#define TimpMic "T350"
#define DelayMic 500
#define DelayMare 1000
#define DelayAsteptare 2000

Pixy pixy;

void setup() 
{
  Serial.begin(115200);
  pixy.init();
  Serial.flush();
  pozitieInitiala();
  delay(DelayMare);
  Serial.flush();
  dans();
}

void loop() 
{
  uint8_t blockIterator;
  uint8_t blocks;
  static uint16_t blockFrameCounter = 0;
  static uint16_t noBlockFrameCounter = 0;
  static uint8_t searchCounter = 0;
  
  blocks = pixy.getBlocks();
  if (blocks)
  {
    blockFrameCounter++;
    noBlockFrameCounter = 0;
    if (blockFrameCounter % 50 == 0)
    {
      for (blockIterator = 0; blockIterator < blocks; blockIterator++)
      {
        //pixy.blocks[blockIterator].print();         // in for u asta putem accesa x,y si altele prin pixy.blocks[j]
        if(pixy.blocks[blockIterator].x < 106 )
        {
          intoarcereStanga();
          delay(DelayMare);
          PasDupaIntoarcereStanga();
          delay(DelayMare);
          pozitieInitiala();
         } 
         else 
         {
          if(pixy.blocks[blockIterator].x >= 106 && pixy.blocks[blockIterator].x < 213)
          {
            if(pixy.blocks[blockIterator].y > 150 && pixy.blocks[blockIterator].x >= 155 )
            {
              miscareInFata();
              miscareInFata();
              sutDreptu();
              delay(DelayMare);
              pozitieInitiala();
              delay(DelayAsteptare);
              continue;
            }
            if(pixy.blocks[blockIterator].y > 150 && pixy.blocks[blockIterator].x < 155)
            {
              miscareInFata();
              miscareInFata();
              sutStangu();
              delay(DelayMare);
              pozitieInitiala();
              delay(DelayAsteptare);
              continue;
            }
            miscareInFata();
            pozitieInitiala();
          }
          else
          {
              intoarcereDreapta();
              delay(DelayMare);
              PasDupaIntoarcereDreapta();
              delay(DelayMare);
              pozitieInitiala();
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
      searchCounter++;
      noBlockFrameCounter = 0;
      if(searchCounter == 1)
      {
        mersSpate();
        mersSpate();
        pozitieInitiala();
        delay(DelayAsteptare);
      }
      if(searchCounter == 2)
      {
        intoarcereMareStanga(); 
        searchCounter = 0;
      }
    }
  } 
}

void miscareInFata()
{
  //inclinare talpii
  Serial.println((String)"#0 P1700 "+TimpMediu);
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
  Serial.println((String)"#0 P1400 "+TimpMediu);  //1420
  Serial.println((String)"#16 P1300 "+TimpMediu);
  delay(DelayMic);
  Serial.println((String)"#1 P1700 "+TimpMediu);
  Serial.println((String)"#2 P1650 "+TimpMediu);
  Serial.println((String)"#17 P1500 "+TimpMediu);
  Serial.println((String)"#18 P1700 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);
  Serial.flush();
}

void mersSpate()
{
  //inclinare talpii
  Serial.println((String)"#0 P1620 "+TimpMediu);
  Serial.println((String)"#16 P1575 "+TimpMediu);
  delay(DelayMic);
  Serial.println((String)"#1 P1750 "+TimpMediu);
  Serial.println((String)"#2 P1700 "+TimpMediu);
  Serial.println((String)"#17 P1500 "+TimpMediu);
  Serial.println((String)"#18 P1700 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);    
  //al doilea pas
  Serial.println((String)"#0 P1400 "+TimpMediu);
  Serial.println((String)"#16 P1375 "+TimpMediu);
  delay(DelayMic);
  Serial.println((String)"#1 P1400 "+TimpMediu);
  Serial.println((String)"#2 P1350 "+TimpMediu);
  Serial.println((String)"#17 P1200 "+TimpMediu);
  Serial.println((String)"#18 P1400 "+TimpMediu);
  delay(DelayMare);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);
  Serial.flush();
}

void pozitieInitiala()
{
  Serial.println((String)"#0 P1520 "+TimpMediu);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  Serial.println((String)"#1 P1550 "+TimpMediu);
  Serial.println((String)"#2 P1500 "+TimpMediu);
  Serial.println((String)"#17 P1350 "+TimpMediu);
  Serial.println((String)"#18 P1550 "+TimpMediu);
  Serial.flush();
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
  Serial.flush();
}

void sutStangu()
{
  Serial.println((String)"#2 P1500 "+TimpMediu);
  Serial.println((String)"#1 P1550 "+TimpMediu);
  Serial.println((String)"#16 P1150 "+TimpMediu);
  Serial.println((String)"#0 P1300 "+TimpMediu);
  delay(DelayMare);

  Serial.println((String)"#17 P1150 "+TimpMediu);
  Serial.println((String)"#18 P1050 "+TimpMic);
  Serial.println((String)"#16 P1475 "+TimpMediu);
  delay(DelayMare);

  Serial.println((String)"#17 P1150 "+TimpMediu);
  Serial.println((String)"#18 P2050 "+TimpMic);
  delay(DelayMic);
  Serial.println((String)"#17 P1350 "+TimpMediu);
  Serial.println((String)"#18 P1550 "+TimpMediu);
  Serial.flush();
}

void intoarcereDreapta()
{
  Serial.println((String)"#16 P1475 "+TimpMediu);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  
  Serial.println((String)"#18 P1350 "+TimpMediu);     //de aici putem intoarce mai mult sau mai putin,astea 4 comenzi
  Serial.println((String)"#17 P1050 "+TimpMediu);     
  
  Serial.println((String)"#1 P1250 "+TimpMediu);
  Serial.println((String)"#2 P1200 "+TimpMic);
  Serial.flush();
}

void intoarcereStanga()
{
  Serial.println((String)"#16 P1475 "+TimpMediu);
  Serial.println((String)"#0 P1520 "+TimpMediu);
  
  Serial.println((String)"#18 P1750 "+TimpMediu);     //de aici putem intoarce mai mult sau mai putin,astea 4 comenzi
  Serial.println((String)"#17 P1650 "+TimpMediu);     
  
  Serial.println((String)"#1 P1850 "+TimpMediu);
  Serial.println((String)"#2 P1800 "+TimpMic);
  Serial.flush();
}

void PasDupaIntoarcereStanga()
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
  Serial.flush();
}

void PasDupaIntoarcereDreapta()
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
  Serial.flush();
}

void intoarcereMareStanga()
{
  for(uint8_t iterator = 0;iterator < 3;iterator++)
  {
      intoarcereStanga();
      delay(DelayMare);
      PasDupaIntoarcereStanga();
      delay(DelayMare);
  }
  pozitieInitiala();  
}

void inchinare()
{
  Serial.println((String)"#1 P2250 "+TimpMediu);
  Serial.println((String)"#17 P750 "+TimpMediu);
  Serial.flush();
}

void dans()
{
  intoarcereStanga();
  delay(DelayMare);
  intoarcereDreapta();
  delay(DelayMare);
  pozitieInitiala();
  delay(DelayMare);
  inchinare();
  delay(DelayMare);
  pozitieInitiala();
  delay(DelayMare);
}
