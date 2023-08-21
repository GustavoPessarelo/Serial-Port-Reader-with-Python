import csv
import serial
from datetime import datetime

#.csv file name
name = input('Insert file name: ')
fileName = name + '.csv'

#Serial port
port = 'COM5'
rate = 9600

#Time counter
counter = 0
timeSec = int(input('Insert the duration: '))
n = timeSec

#Serial port data (in order)
header = ['Speed', 'Humidity', 'Temperature', 'Distance', 'Time']

#Check if the connection with the serial port was successful (in this case, the Arduino is sending the data to the serial port)
while True:
    try:
        arduino = serial.Serial(port, rate)
        print('Arduino connected')
        print()
        break
    except:
        pass



#Read the serial port and store the data in a .csv file
with open(fileName, 'a', encoding='UTF8', newline='') as file:
    writer = csv.writer(file)
    
    while counter<=n:
            
        msg = str(arduino.readline())
        msg = msg[2:-5]
        
                
        dt = datetime.now()
        
        writer.writerow([msg.split(',')[0],msg.split(',')[1],msg.split(',')[2], msg.split(',')[3], dt])
        
        print(counter, 'Seconds - ', msg.split(','))
        
        arduino.flush()
        
        counter+=1
file.close()    

col = n+1

print('Elapsed time: %s seconds' %timeSec)