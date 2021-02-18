
import serial
import time
x=input('Enter size:'+'\n'+'a.Small'+'\t\t'+'b.Big'+'\t\t')
y=input('Enter color:'+'\n'+'a.Blue'+'\t\t'+'b.Red'+'\t\t')
ser = serial.Serial('COM3', baudrate = 9600, timeout = 1)
time.sleep(3)
data=['1','2','3','4']
if ((x=='Small'or x=='small' or x=='SMALL') and (y=='Blue' or y=='blue' or y=='BLUE')):
     ser.write(data[0].encode())
     time.sleep(1)
elif (x=='Small'or x=='small' or x=='SMALL') and (y=='Red'or y=='red' or y=='RED'):
     ser.write(data[1].encode())
     time.sleep(1)
elif (x=='Big'or x=='big' or x=='BIG') and (y=='Blue' or y=='blue' or y=='BLUE'):
     ser.write(data[2].encode())
     time.sleep(1)
elif (x=='Big'or x=='big' or x=='BIG') and (y=='Red' or y=='red' or y=='RED'):
     ser.write(data[3].encode())
     time.sleep(1) 
