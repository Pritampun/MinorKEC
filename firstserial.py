import serial                                                # for serial communication
import time                                                  #to able to use delay(i.e. time .sleep function )

ser = serial.Serial('COM3', baudrate = 9600, timeout = 1)
time.sleep(3)                                                #jsut a delay of 3 sec.
userInput = input('Do you want to give datas to arduino?''\n''a.YES''\t''b.NO''\t''\t''\t') 
if userInput =='YES' or userInput =='yes':                   #Give data to arduino only if user type YES
    Num = input('Enter how many LED?''\t''\t')               #enter how many leds or sensors are attached
    Num = int (Num)                                          #input values gives str so to convert str to int
    dataList = [0]*Num                                       #just creat list with size of led attached
    for i in range (0,Num):
         dataList[i]=input('Enter which one to on?''\n''1.a''\t''2.b''\t''3.c''\t''\t')
         ser.write(dataList[i].encode())
         time.sleep(1)                 
elif userInput =='NO' or userInput =='no':
     print('Ok no LED will blink')
else:
    print(' error!!!   '+ userInput +'   is not recognize!!!')
