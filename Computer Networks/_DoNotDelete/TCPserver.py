import socket
from time import sleep

TCP_IP = "localhost"
TCP_PORT = 13777
sock = socket.socket(socket.AF_INET, #internet
                socket.SOCK_STREAM) #TCP
sock.bind((TCP_IP, TCP_PORT))
sock.listen(1)

conn, addr = sock.accept()

def restart():
    conn, addr = sock.accept()

def loanCalc(princ, years, rate):
    monthlyPayment_top = princ * (rate / 12)
    monthlyPayment_bottom = 1 - (1/(1+(rate/12)))**(years*12)
    monthlyPayment = monthlyPayment_top / monthlyPayment_bottom

    MESSAGE = "\n${:0,.2f} loan\nmonthly payment is ${:0,.2f}\ntotal payment is ${:0,.2f}\n"
    MESSAGE = MESSAGE.format(princ, monthlyPayment, monthlyPayment*12)

    return MESSAGE

while True:
    try:

        data = conn.recv(50) #set to lower for fast reply
        data = data.split()
        
        try: #make sure data is correct 
            princ = float(data[0])
            years = float(data[1])
            rate = float(data[2])
            MESSAGE = loanCalc(princ, years, rate) 
        except:
            MESSAGE = "\nInvalid data was sent to the server."
            MESSAGE = MESSAGE + "\nPlease type 'help Cal' for more information.\n"

        print("Connection Request From {}".format(addr[0]))
        MESSAGE = bytearray(MESSAGE, "utf-8")
        conn.send(MESSAGE) #(Client IP, Client Port)
        
    except:
        sock.shutdown(1)
        sock.close()
        restart()
        #print("TrentApps ServerOS encountered a problem. Restarting in 3 seconds... ")
        #sleep(3)
        continue




