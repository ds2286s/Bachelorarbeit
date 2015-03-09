import serial
import sys
ser = serial.Serial('COM9',9600)
while (ser.readable()):
	text=ser.read(3)
	print(text)