import serial
import cv2
import numpy as np
import serial
import time

ser = serial.Serial('COM5', 9600, timeout=1)
cap = cv2.VideoCapture(1)

frameWidth = 300
frameHeight = 180
cap.set(3, frameWidth)
cap.set(4, frameHeight)

def colordetect():
    _, frame = cap.read()
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    # Red color
    low_red = np.array([161, 155, 84])
    high_red = np.array([179, 255, 255])
    red_mask = cv2.inRange(hsv_frame, low_red, high_red)
    redm = cv2.bitwise_and(frame, frame, mask=red_mask)
    # Blue color
    low_blue = np.array([94, 80, 2])
    high_blue = np.array([126, 255, 255])
    blue_mask = cv2.inRange(hsv_frame, low_blue, high_blue)
    bluem = cv2.bitwise_and(frame, frame, mask=blue_mask)
    #for normal
    red = np.linalg.norm(redm)
    blue = np.linalg.norm(bluem)
    #for display
    cv2.imshow('Frame', frame)
    cv2.imshow('Red', redm)
    cv2.imshow('Blue', bluem)
    print("Red = ", red)
    print("Blue = ", blue)
    if (red > 10000) or (blue > 10000):
        if (red <= 20000) and (red > blue):
            return "rs"
        elif (red > 20000) and (red > blue):
            return "rb"
        elif (blue <= 20000) and (red < blue):
            return "bs"
        elif (blue > 20000) and (red < blue):
            return "bb"
    elif (red < 9000) and (blue < 9000):
        return "null"

while True:
    user_input = colordetect()
    if user_input == "rs":
        #colordetect()
        ser.write(b'B')
        time.sleep(30)
    elif user_input == "rb":
        #colordetect()
        ser.write(b'D')
        time.sleep(30)
    elif user_input == "bs":
        #colordetect()
        ser.write(b'A')
        time.sleep(30)
    elif user_input == "bb":
        #colordetect()
        ser.write(b'C')
        time.sleep(30)
    key = cv2.waitKey(1)
    if key == 27:
        break
