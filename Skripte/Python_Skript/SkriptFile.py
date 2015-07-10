import serial
import sys
import time

def find_str(s, char):
    index = 0

    if char in s:
        c = char[0]
        for ch in s:
            if ch == c:
                if s[index:index+len(char)] == char:
                    return index

            index += 1

    return -1

filename = sys.argv[2]
fobj_out = open(filename,"w");
ser = serial.Serial(sys.argv[1],57600);
i=0;
timeout = time.time() + 60 
while 1:
    string = ser.readline().decode("utf-8");
    if(find_str(string,"start")!=-1):
        while (find_str(string,"exit")==-1 or time.time() < timeout):
            string = ser.readline().decode("utf-8");
            if (string != 'exit\r\n'):
                fobj_out.write(string);
        break;

fobj_out.close();
