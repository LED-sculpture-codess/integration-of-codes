int clk_pin= 12;      //shift clk pin
int latch_pin = 7;   //storage clk pin
int data_pin = 11;

char glow[48];

void shift(char data){
  digitalWrite(clk_pin,LOW);
  Serial.println(data);
  if (data == 'H'){
    digitalWrite(data_pin,HIGH);  
  } else if (data == 'L'){
    digitalWrite(data_pin,LOW);  
  }
  digitalWrite(clk_pin,HIGH);
}


void setup(){
  pinMode(clk_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  Serial.begin(9600);
}


void loop(){
  
  if (Serial.available()){
    for (int i = 0;i < 48;i++){
      glow[i] = Serial.read();
      delay(5);
    }
  
  }
  for (int i = 0;i < 4;i++){
   digitalWrite(latch_pin,LOW);
   for(int k = 0;k < 4;k++)
      shift('L') ;
    for(int j = 0;j<12;j++)
      shift(glow[j+12*i]);
    digitalWrite(latch_pin,HIGH);
  }

}
