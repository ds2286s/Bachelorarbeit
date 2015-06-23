import serial
import sys
ser = serial.Serial('COM4',9600)
ser.setTimeout(5)
fout = open("Output.txt","w")
while (ser.readable()):
	text=ser.readline()
	print(text.decode("utf-8"))
	fout.write(text.decode("utf-8"))
	
print("out")
fout.close()
ser.close()
        
