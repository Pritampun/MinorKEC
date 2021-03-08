
import serial
import time

x = (input('Enter size:'+'\n'+'a.Small'+'\t\t'+'b.Big'+'\t\t')).lower()
y = (input('Enter color:'+'\n'+'a.green'+'\t\t'+'b.Red'+'\t\t')).lower()
ser = serial.Serial('COM5', 9600, timeout=1)
time.sleep(3)
if(x == "small" and y == "blue"):
    ser.write(b'A')
    time.sleep(1)
elif(x == "small" and y == "red"):
    ser.write(b'B')
    time.sleep(1)
elif(x =="big" and y=="blue"):
    ser.write(b'C')
    time.sleep(1)
elif(x == "big" and y == "red"):
    ser.write(b'D')
    time.sleep(1)

