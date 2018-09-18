int clk_pin= 12;      //shift clk pin
int latch_pin = 7;   //storage clk pin
int data_pin = 11;

char glow[8];

void shift(char data){
  digitalWrite(clk_pin,LOW);
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
  digitalWrite(latch_pin,LOW);
  if (Serial.available()){
    for (int i = 0;i < 8;i++){
      glow[i] = Serial.read();
      //Serial.println(glow[i]);
      delay(2);
    }
  }
  for (int i = 0;i < 8;i++){
      shift(glow[i]);
  }
  digitalWrite(latch_pin,HIGH);
}

