#include <SPI.h>
#include <SD.h>

int data_pin = 7;
int clk_pin = 8;
int latch_pin = 9;

File my_file;      // file object
char chnk[4][8];   // chunk of data to store part of data 

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  while(!Serial){
    ; //waiting for establishment
  }
  if(!SD.begin()){
    Serial.println("Inistialsation failed!");
    return;
  }
  Serial.println("Inistialsation done!");
  
  pinMode(clk_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  
}

my_file = SD.open("design.txt");  // creating a file object 

void loop() {  
  
  if(my_file){
    while(my_file.available()){
      for(int i = 0;i< 4;i++){
      my_file.read(chnk,32);
      }
    }
  }
  
  for(int k = 0;k < 10;k++){
    for(int j = 0;j < 4;j++){
      shiftOut(data_pin,clk_pin,LSBFIRST,1<<(j+4))   //Sending cathode bits into shift with intial zeros
      for(int l = 0;l < 8;l++){
        shift(chnk[j]);    //Sending anode chunk
      }
    }
  }
  
}
//function to shift one bit to shift register
void shift(char data){
  if (data == 0){
    digitalWrite(clk_pin,LOW);
    digitalWrite(data_pin,LOW);
    digitalWrite(clk_pin,HIGH);  
  }else if (data == 1){
    digitalWrite(clk_pin,LOW);
    digitalWrite(data_pin,HIGH);
    digitalWrite(clk_pin,HIGH);  
  }else{
    Serial.println('error');
  }
}
