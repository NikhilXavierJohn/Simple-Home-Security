import serial
from firebase import firebase
arduino=serial.Serial('com3',9600)
firebase = firebase.FirebaseApplication('https://aegis-c7d5b.firebaseio.com/', None)
while(True):
    data=arduino.readline()
    data=data.decode('utf-8')
    data=data.replace("\r\n","")
    datas=data.split(',')
    print(datas)
    if(datas==0):
        print("error")
    else:
        brightness=datas[0]
        humidity=datas[1]
        temp=datas[2]
        UID=datas[3]
        LOG=datas[4]
        door=datas[5]
        alert=datas[6]
          
        data =  { 'Brightness': brightness,
                  'Temp': temp,
                  'Humidity': humidity,
                  'UID':UID,
                  'LOG':LOG,
                  'Door':door,
                  'Alert':alert
                  }
        result = firebase.put('/','data',data)
        ##print(result) 
