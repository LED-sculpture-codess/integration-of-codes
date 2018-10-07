int clockPin= 12;      //shift clk pin
int latchPin = 7;   //storage clk pin
int dataPin = 11;

//looping variables
byte i;
byte j;

//storage variable
byte dataToSend;
char glow[16];

//storage for led states, 4 bytes


void setup() {
  //set pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   if (Serial.available()){
     for (int i = 0;i < 4;i++){
       glow[i] = Serial.read();
       Serial.println(glow[i]);
     }
       
   }
  for (i=0;i<4;i++){
    
    //send data from ledData to each row, one at a time
    byte dataToSend = (1 << (i+4)) | (15 & ~glow[i]);
      
    // setlatch pin low so the LEDs don't change while sending in bits
    digitalWrite(latchPin, LOW);
    
//    // shift out the bits of dataToSend to the 74HC595
//    shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
// the code below is the equivalent of the two lines above
    for (j=0;j<8;j++){
      digitalWrite(clockPin,LOW);
      digitalWrite(dataPin,((dataToSend>>j)&1));
      digitalWrite(clockPin,HIGH);
    }


    //set latch pin high- this sends data to outputs so the LEDs will light up
    digitalWrite(latchPin, HIGH);
      

  }
}




