#include <SPI.h>  
#include <Pixy.h>

#define TimpMediu "T500"

Pixy pixy;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Starting Pixy...");
  pixy.init();
  Serial.flush();
  pozInitial();

  Serial.flush();
}

void loop() 
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks!
  blocks = pixy.getBlocks();
  
  // If there are detect blocks, print them!
  if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      //Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        //Serial.println(buf);
        //pixy.blocks[j].print();         // in for u asta putem accesa x,y si altele prin pixy.blocks[j]
        if(pixy.blocks[j].x < 160 )
        {
          sutDreptu();
            delay(500);
          pozInitial();
          } 
          else
          {
            miscatiHoitu();
            pozInitial();
            }
      }
    }
  } 
  
  //miscatiHoitu();
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

void checkPixy()
{
  
}
