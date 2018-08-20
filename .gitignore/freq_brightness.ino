
int ledPin = 9;// LED connected to digital pin 9;
int fadeValue;

void setup()  { 
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
} 

void loop()  { 
     if (Serial.available()) {
        char serialListener = Serial.read();
        if (serialListener == '0'){
            analogWrite(ledPin, 0);
        }         
        else if(serialListener == '1'){
            analogWrite(ledPin, 15);
        }
        else if(serialListener == '2'){
            analogWrite(ledPin, 31);
        }                                    
        else if(serialListener == '3'){
            analogWrite(ledPin, 46);
        }            
        else if(serialListener == '4'){
            analogWrite(ledPin, 61);
        }  
        else if(serialListener == '5'){
            analogWrite(ledPin, 76);
        }
        else if(serialListener == '6'){
            analogWrite(ledPin, 91);
        }                           
        else if(serialListener == '7'){
            analogWrite(ledPin, 106);
        }
        else if(serialListener == '8'){
            analogWrite(ledPin, 135);
        }
        else if(serialListener == '9'){
            analogWrite(ledPin, 165 );
        }
        else if(serialListener == '10'){
            analogWrite(ledPin, 195);
        }        
        else if(serialListener == '11'){
            analogWrite(ledPin, 210);
        }
        else if(serialListener == '12'){
            analogWrite(ledPin, 225);
        }
        else if(serialListener == '13'){
            analogWrite(ledPin, 240);
        }
        else if(serialListener == '14'){
            analogWrite(ledPin, 255);
        }
 
    }

}
