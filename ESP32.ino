#include <WiFi.h>

const char* ssid     = "BanatRobot";
const char* password = "diferential2016";
WiFiServer server(80);
String header;
short pini[7]={2, 15, 5, 18 ,23, 19, 22};

void checkRequestForPin(short pin)
{
	if(pin == 2)
	{
		if (header.indexOf("GET /2/on") >= 0) 
		{
			Serial.println("GPIO 2 on");
			digitalWrite(2, HIGH);
		} 
		if (header.indexOf("GET /2/off") >= 0) 
		{
			Serial.println("GPIO 2 off");
			digitalWrite(2, LOW);
		} 
	}
	else
	{
		if (header.indexOf("GET /"+(String)pin+"/on") >= 0) 
		{
			Serial.println("GPIO "+(String)pin+"on");
			digitalWrite(pin, HIGH);
			if(pin == 19 || pin == 22)
			{
				delay(3500);
			}
			else
			{
				delay(5000);
			}
			digitalWrite(pin, LOW);
		} 
	}
}

void setup() 
{
	Serial.begin(115200);
	for(short iterator = 0;iterator < 7;iterator++)
	{
		pinMode(pini[iterator], OUTPUT);
		digitalWrite(pini[iterator], LOW);
	}
	Serial.print("Se conecteaza la ");
	Serial.println(ssid);
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) 
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("Conectat");
	Serial.println("Adresa IP: ");
	Serial.println(WiFi.localIP());
	server.begin();
}

void loop()
{
	WiFiClient client = server.available();

	if (client) 
	{
		Serial.println("Client nou");
		String currentLine = "";
		while (client.connected()) 
		{
			if (client.available()) 
			{
				char readByte = client.read();
				Serial.write(readByte);
				header += readByte;
				if (readByte == '\n') 
				{
					if (currentLine.length() == 0) 
					{
						for(short iterator = 0;iterator < 7;iterator++)
						{
							checkRequestForPin(pini[iterator]);
						}
						break;
					}
					else 
					{
						currentLine = "";
					}
				} 
				else if (readByte != '\r') 
				{
					currentLine += readByte;
				}
			}
		}

		header = "";
		client.stop();
		Serial.println("Client deconectat");
		Serial.println("");
	}
}