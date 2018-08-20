import serial 
import time
import numpy as np
import scipy.io.wavfile as wav
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq, fftshift

arduino = serial.Serial('/dev/tty.usbmodem1421', 9600)

rate ,data = wav.read('g_tdd_120_01.wav')  
nframe = data.shape[0] 	

T = 1/rate	
dt = 0.05
nsamp = int((dt)/T)   
for i in np.arange(0,nframe,nsamp):	
	d = data[i:(i+nsamp)]	
	f = fftfreq(nsamp, T)     
	Y = fft(d)
	Y = fftshift(Y)		
	f = fftshift(f)
	Y = np.abs(Y)    
	X = np.abs(f)
	
def freq_div():
 for X in np.arange(0,nframe,nsamp):
  if X in range (0, 1378):
    time.sleep(1)
    arduino.write(b'0')
  if X in range (1378, 2*1378):
    time.sleep(1)
    arduino.write(b'1') 
  if X in range (2*1378, 3*1378):
    time.sleep(1)
    arduino.write(b'2') 
  if X in range (3*1378, 4*1378):
    time.sleep(1)
    arduino.write(b'3')
  if X in range (4*1378, 5*1378):
    time.sleep(1)
    arduino.write(b'4')
  if X in range (5*1378, 6*1378):
    time.sleep(1)
    arduino.write(b'5')
  if X in range (6*1378, 7*1378):
    time.sleep(1)
    arduino.write(b'6')
  if X in range (7*1378, 8*1378):
    time.sleep(1)
    arduino.write(b'7')
  if X in range (8*1378, 9*1378):
    time.sleep(1)
    arduino.write(b'8')
  if X in range (9*1378, 10*1378):
    time.sleep(1)
    arduino.write(b'9')
  if X in range (10*1378, 11*1378):
    time.sleep(1)
    arduino.write(b'10')
  if X in range (11*1378, 12*1378):
    time.sleep(1)
    arduino.write(b'11')
  if X in range (12*1378, 13*1378):
    time.sleep(1)
    arduino.write(b'12')
  if X in range (13*1378, 14*1378):
    time.sleep(1)
    arduino.write(b'13')
  if X in range (14*1378, 15*1378):
    time.sleep(1)
    arduino.write(b'14')
    
		
time.sleep(2)

freq_div()
