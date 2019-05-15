import socket
from time import sleep

UDP_IP = "localhost"
UDP_PORT = 9999

sock = socket.socket(socket.AF_INET, #internet
                     socket.SOCK_DGRAM) #UDP
sock.bind((UDP_IP, UDP_PORT))

def loanCalc(princ, years, rate):
    monthlyPayment_top = princ * (rate / 12)
    monthlyPayment_bottom = 1 - (1/(1+(rate/12)))**(years*12)
    monthlyPayment = monthlyPayment_top / monthlyPayment_bottom
    #do the math above this. 

    MESSAGE = "${:0,.2f} loan\nmonthly payment is ${:0,.2f}\ntotal payment is ${:0,.2f}"
    MESSAGE = MESSAGE.format(princ, monthlyPayment, monthlyPayment*12)
    #format above string with variables. 
    
    return MESSAGE

while True:
    try:
        data, addr = sock.recvfrom(1024)  #receive 1024 bytes
        data = data.split()
        
        try: #make sure data is correct, fail if not. 
            princ = float(data[0])
            years = float(data[1])
            rate = float(data[2])
            MESSAGE = loanCalc(princ, years, rate) 
        except:
            MESSAGE = "\nInvalid data was sent to the server."
            MESSAGE = MESSAGE + "\nPlease type 'help Cal' for more information.\n"

        print("Connection Request From {}".format(addr[0]))
        MESSAGE = bytearray(MESSAGE, "utf-8")
        sock.sendto(MESSAGE, (addr[0], addr[1])) #(Client IP, Client Port)
    except:
        print("TrentApps ServerOS encountered a problem. Restarting in 3 seconds... ")
        sleep(3)
        continue
