import serial
import time
serdev = '/dev/ttyUSB0'
s = serial.Serial(serdev, 9600)

s.write(bytes("/park/run 0 1 0\r", 'UTF-8'))
 