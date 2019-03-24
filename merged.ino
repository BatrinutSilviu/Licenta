#include <SPI.h>  
#include <Pixy.h>

#define TimpMediu "T500"
#define TimpMic "T350"
#define DelayMic 500
#define DelayMare 1000
#define DelayAsteptare 4000

Pixy pixy;

void setup() 
{
  Serial.begin(115200);
  pixy.init();
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  Serial.flush();
  pozitieInitiala();
  delay(DelayMare);
  Serial.flush();
  dans();
}

void loop() 
{
  if(digitalRead(2) ==HIGH)
  { 
    if( digitalRead(3) == HIGH)
    {
      mersSpate();
      pozitieInitiala();
    }
    if(digitalRead(4) == HIGH)
    {
      miscareInFata();
      pozitieInitiala();
    }
    if(digitalRead(5) == HIGH)
    {
       intoarcereStanga();
       delay(DelayMare);
       PasDupaIntoarcereStanga();
       pozitieInitiala();
    }
    if(digitalRead(6) == HIGH)
    {
      intoarcereDreapta();
      delay(DelayMare);
      PasDupaIntoarcereDreapta();
      pozitieInitiala();
    }
    if(digitalRead(7) == HIGH)
    {
      sutDreptu();
      delay(DelayMare);
      pozitieInitiala();
    }
    if(digitalRead(8) == HIGH)
    {
      sutStangu();
      delay(DelayMare);
      pozitieInitiala();
    }
  }
  else
  {
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
          if(pixy.blocks[0].x < 106 )
          {
            intoarcereStanga();
            delay(DelayMare);
            PasDupaIntoarcereStanga();
            delay(DelayMare);
            pozitieInitiala();
            searchCounter = 0;
           } 
           else 
           {
            if(pixy.blocks[0].x >= 106 && pixy.blocks[0].x < 213)
            {
              if(pixy.blocks[0].y > 175 && pixy.blocks[0].x >= 155)
              {
                miscareInFata();
                miscareInFata();
                pozitieInitiala();
                delay(DelayMare);
                sutDreptu();
                delay(DelayMare);
                pozitieInitiala();
                delay(DelayAsteptare);
                searchCounter = 0;
              }
              else
              {
                if(pixy.blocks[0].y > 175 && pixy.blocks[0].x < 155)
                {
                  miscareInFata();
                  miscareInFata();
                  pozitieInitiala();
                  delay(DelayMare);
                  sutStangu();
                  delay(DelayMare);
                  pozitieInitiala();
                  delay(DelayAsteptare);
                  searchCounter = 0;
                }
                else
                {
                  miscareInFata();
                  pozitieInitiala();
                  searchCounter = 0;
                }
              }
            }
            else
            {
                intoarcereDreapta();
                delay(DelayMare);
                PasDupaIntoarcereDreapta();
                delay(DelayMare);
                pozitieInitiala();
                searchCounter = 0;
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
          delay(DelayMare);
        }
        if(searchCounter == 2)
        {
          intoarcereMareStanga(); 
          searchCounter = 0;
        }
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
  Serial.println((String)"#0 P1900 "+TimpMediu);
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
