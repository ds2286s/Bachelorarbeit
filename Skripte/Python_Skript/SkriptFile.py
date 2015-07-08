import serial
import sys

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
while 1:
    string = ser.readline().decode("utf-8");
    if(find_str(string,"start")!=-1):
        while (find_str(string,"exit"))==-1:
            string = ser.readline().decode("utf-8");
            if (string != 'exit\r\n'):
                fobj_out.write(string);
        break;

fobj_out.close();
