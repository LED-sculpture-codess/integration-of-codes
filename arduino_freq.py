int clk_pin= 12;      //shift clk pin
int latch_pin = 11;   //storage clk pin
int data_pin = 10;

char glow[16];

void shift(char data){
  if (data == 'h'){
    digitalWrite(data_pin,HIGH);  
  } else if (data == 'l'){
    digitalWrite(data_pin,LOW);  
  }
  digitalWrite(clk_pin,LOW);
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
    for (int i = 0;i < 16;i++){
      glow[i] = Serial.read();
    }
  }
  for (int i = 0;i < 16;i++){
      shift(glow[i]);
  }
  digitalWrite(latch_pin,LOW);
  digitalWrite(latch_pin,HIGH);
}
