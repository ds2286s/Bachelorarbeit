import serial
import sys
fobj_out = open("Test.txt","w");
ser = serial.Serial(sys.argv[1],57600);
i=0;
while 1:
    string = ser.readline().decode("utf-8");
    if(string == 'start\r\n'):
        while string != 'exit\r\n':
            string = ser.readline().decode("utf-8");
            if (string != 'exit\r\n'):
                fobj_out.write(string);
        break;

fobj_out.close();
