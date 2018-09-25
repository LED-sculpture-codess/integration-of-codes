import matplotlib.pyplot as plt
from time import sleep,time 
import numpy as np
import scipy.io.wavfile as wav
from scipy.fftpack import fft, fftfreq, fftshift
import serial

arduino = serial.Serial('/dev/ttyACM0',9600)
sleep(2)
print('connection established')

def max_in(fmin , fmax, data) :
	d = { }
	for i in np.arange(fmin,fmax+1,20) :
		d[i] = data[i]
	v = list(d.values())
	max_value = max(v)
	return 	max_value
								
rate ,data = wav.read('WhatsApp Audio 2018-09-22 at 11.40.29 AM.wav')    #reading the data using scipy.io.wavfile module

nframe = data.shape[0] 		#no of frames in the audio file
T = 1/rate	        	#time diff between two samples
dt = 0.05       		#sample timewidth for window of shortFFT
nsamp = int((dt)/T)     	#no of sample taken in one window
ymax = max(fft(data))

x = np.arange(0,20020,20)
a = np.split(x,[2,5,9,16,28,47,79,131,225,374,613])

glob_b =[]   #for storing the frames continuosly in an array
array = []   #for storing the frames in form of array in another array
'''to find the array of the frequency strength in the given data'''
for i in np.arange(0,nframe,nsamp) : 
	d = data[i:(i+nsamp)]	
	f = fftfreq(nsamp,T)     #creates discrete freqranging from -20,000 to 20,000
	f = fftfreq(nsamp,T)     #creates discrete freqranging from -20,000 to 20,000
	Y = fft(d)       #creates fft with 40000 values
	Y = fftshift(Y)
	f = fftshift(f)
	Y = np.abs(Y)     #from data it is removing imaginary part of the data
	sound_data = dict(zip(f,Y))
	b = [] 
	for j in np.arange(12) :
		lo = len(a[j])
		max_str = max_in(min(a[j]), max(a[j]), sound_data)
		b.append(max_str)
		glob_b.append(max_str)
	array.append(b)	

glob_max_stre = max(glob_b)

total_frame = len(array)

'''using the data found above plotting the graph'''
for i in np.arange(total_frame) :
	x = np.arange(12)
	plt.clf()
	plt.hold(True)
	plt.bar(x, array[i]) 
	plt.hold(False)
	plt.ylim(0,glob_max_stre)
	plt.pause(0.00001)
	continue
	
#linear division of the data vertivcally
step = glob_max_str/8

for i in np.arange(total_frame) :
	b = array[i]
	for j in np.arange(12) :
		if b[j] < step :
			arduino.write(b'1')
		elif b[j] < 2*step :
			arduino.write(b'2')
		elif b[j] < 3*step :
			arduino.write(b'3')
		elif b[j] < 4*step :
			arduino.write(b'4')
		elif b[j] < 5*step :
			arduino.write(b'5')
		elif b[j] < 6*step :
			arduino.write(b'6')	
		elif b[j] < 7*step :
			arduino.write(b'7')
		elif b[j] < 8*step :
			arduino.write(b'8')
