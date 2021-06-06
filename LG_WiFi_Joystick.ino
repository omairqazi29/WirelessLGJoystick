#include <SoftwareSerial.h>
#define DEBUG true
#define RX 2
#define TX 3
SoftwareSerial esp8266(RX,TX);

//CHANGE THESE NETWORK SETTINGS
String HOST = "192.168.31.224";
String AP = "omair";
String PASS = "omair8143";

//BUTTONS
int bRT = 4;
int bUR = 5;
int bUP = 6;
int bUL = 7;
int bLT = 8;
int bDR = 9;
int bDW = 10;
int bDL = 11;
int bZI = 12;
int bZO = 13;

int bsRT = 0; 
int bsUR = 0;
int bsUP = 0;
int bsUL = 0;
int bsLT = 0;
int bsDR = 0; 
int bsDW = 0;
int bsDL = 0;
int bsZI = 0;
int bsZO = 0;

//PROCESSING VARIABLES
String req="";
int countTrueCommand;
int countTimeCommand;
boolean found = false;

void setup() {
  Serial.begin(9600);
  
  //BUTTONS
  pinMode(bLT, INPUT);
  pinMode(bUL, INPUT);
  pinMode(bUP, INPUT);
  pinMode(bUR, INPUT);
  pinMode(bRT, INPUT);
  pinMode(bDL, INPUT);
  pinMode(bDW, INPUT);
  pinMode(bDR, INPUT);
  pinMode(bZI, INPUT);
  pinMode(bZO, INPUT);
  
  digitalWrite(bLT, HIGH);
  digitalWrite(bUL, HIGH);
  digitalWrite(bUP, HIGH);
  digitalWrite(bUR, HIGH);
  digitalWrite(bRT, HIGH);
  digitalWrite(bDL, HIGH);
  digitalWrite(bDW, HIGH);
  digitalWrite(bDR, HIGH);
  digitalWrite(bZI, HIGH);
  digitalWrite(bZO, HIGH);
  
  //ESTABLISH CONNECTION WITH MASTER
  esp8266.begin(115200);
  espCommand("AT",5,"OK");
  espCommand("AT+CWMODE=1",5,"OK");
  espCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",15,"OK");
  espCommand("AT",10,"OK");
  espCommand("AT+CIPSTART=\"UDP\",\""+ HOST +"\",8085",1,"OK");
  espCommand("AT+CIPSEND=2",1,">");
}
void loop() {

  //BUTTONS
  bsRT = digitalRead(bRT);
  bsUR = digitalRead(bUR);
  bsUP = digitalRead(bUP);
  bsUL = digitalRead(bUL);
  bsLT = digitalRead(bLT);
  bsDR = digitalRead(bDR);
  bsDW = digitalRead(bDW);
  bsDL = digitalRead(bDL);
  bsZI = digitalRead(bZI);
  bsZO = digitalRead(bZO);
  
//SENDING UDP MESSAGES  
  if (bsRT == LOW) {
    lg("RT");
  }
  
  else if (bsUR== LOW) {
    lg("UR");
  }

  else if (bsUP == LOW) {
    lg("UP");
  }

  else if (bsUL == LOW) {
    lg("UL");
  }
  
  else if (bsLT == LOW) {
    lg("LT");
  }
  
  else if (bsDR== LOW) {
    lg("DR");
  }

  else if (bsDW == LOW) {
    lg("DW");
  }

  else if (bsDL == LOW) {
    lg("DL");
  }
  
  else if (bsZI == LOW) {
    lg("ZI");
  }

  else if (bsZO == LOW) {
    lg("ZO");
  }
  else{
    lg("ST");
  }
}

//SENDING UDP MESSAGES TO MASTER SERVER
void lg(String place){
  esp8266.println("AT+CIPSEND=2");
  delay(50);
  //espCommand("AT+CIPSEND=2",1,">");
  esp8266.println(place);
  delay(50);
}

//SENDING COMMANDS TO ESP8266
void espCommand(String command, int maxTime, char readReplay[]) {

Serial.print(countTrueCommand);
Serial.print(". at command => ");
Serial.print(command);
Serial.print(" ");
while(countTimeCommand < (maxTime*1))

{

esp8266.println(command);//at+cipsend
if(esp8266.find(readReplay))//ok
{

found = true;
break;

}
countTimeCommand++;

}
if(found == true)
{

Serial.println("PASS");

countTrueCommand++;
countTimeCommand = 0;

}
if(found == false)
{

Serial.println("Fail");
countTrueCommand = 0;
countTimeCommand = 0;

}
found = false;

}
