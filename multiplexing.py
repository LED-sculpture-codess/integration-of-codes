import serial
import time

arduino = serial.Serial('/dev/tty.usbmodem14201', 9600)

def byte(data):
  for i in range(0,4) :
    a = (1 << (i+4)) | (15 & ~(data[i]))
    print(a)
    for j in range(0,8):
      if a & 1<<j :
        arduino.write(b'H')
        print(b'H') 
      else :
        arduino.write(b'L')
        print(b'L')   
      time.sleep(0.002)
data = [0b0001,0b0011,0b0111,0b1111]


byte(data)

  
