import serial
import sys
port = sys.argv[1]
ser = serial.Serial(port,57600)
ser.close()
#ser.open()
#ser.close()
ser.setBaudrate(1200)
ser.open()
ser.close()
#ser2 =serial.Serial(port,57600);
#while 1:
#sys.stdout.write(ser2.readline())