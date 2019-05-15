import socket
from time import sleep
from netHelp import *

WELCOME_MESSAGE = """
-----------------------------------------------------------------------
|    Welcome to Loan Payment Calculator by TrentApps                  |
|    Please visit http://TrentApps.com for contact information.       |
|                                                                     |
|    This command line program was made to calculate how much         |
|    loan payments would be for each month and each year.             |
|                                                                     |
|                      Getting Started                                |
|    Enter 'Cal <server_address> <principle_in_$> <years_financed>    |
|    <interest_rate>' to run the program. Please note: when using     |
|    this command you should use only numbers. Interest rate should   |
|    be in decimal form. Please see the example Below for more help.  |
|                                                                     |
|    For the purpose of this assignment, localhost will be used as    |
|    the server.                                                      |
|                                                                     |
|                          Example                                    |
|    If you wish to calculate monthly and yearly payments             |
|    for a loan of $30,000 over 30 years with an interest rate of     |
|    %13, please enter 'Cal localhost 30000 30 .13' without quotes.   |
|                                                                     |
|    Enjoy.                                                           |
-----------------------------------------------------------------------
"""

print(WELCOME_MESSAGE) #print welcome only when the client is launched.

TCP_IP = "localhost"
TCP_PORT = 13777
MESSAGE = ""

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_STREAM) # UDP



COMMANDS = ["Cal", "help"]

serverFails = 0 #counter if for counting how many times server failed

NOT_CONNECTED = True



#def connect():
    #if NOT_CONNECTED:
sock.connect((TCP_IP, TCP_PORT))
        #NOT_CONNECTED = False
        
def send(MESSAGE, serverFails):
    try:
        #connect()
        sock.send(MESSAGE)
        sock.settimeout(3)
        data = sock.recv(1025)
        
        print(data.decode("utf-8"))
    except:
        print("Server not responding. Retrying in 3 seconds...")
        sleep(3)
        serverFails = serverFails + 1
        if (serverFails < 3):
            send(MESSAGE, serverFails)
        else:
            print("Host is either down of not responding.")

while (True):
    MESSAGE_TXT = input(">> ")
    if MESSAGE_TXT == "exit":
        break #break if the string exit is entered. 
    elif MESSAGE_TXT == "":
        continue #do nothing if nothing is entered
    
    MESSAGE_TXT = MESSAGE_TXT.split()
        
    try: 
        FUNCTION = MESSAGE_TXT[0]

        if FUNCTION == "help":
            try:
                msgTxt = MESSAGE_TXT[1]
                if (msgTxt not in COMMANDS):
                    print("\n{} is not a command. Try again. \n".format(msgTxt))
                    continue
                netHelp(msgTxt)  #help function for help   
            except:
                netHelp(MESSAGE_TXT[0])                                  
            continue    #continue to next iteration of loop

        UDP_IP_SERVER = MESSAGE_TXT[1]
        DATA = (MESSAGE_TXT[2] + " " + MESSAGE_TXT[3] + " " +
                MESSAGE_TXT[4])
        MESSAGE = bytearray(DATA, "utf-8")
        send(MESSAGE, serverFails)
    except:
        if ((FUNCTION not in COMMANDS)):
            print("\nCommand not recognized\n")
        elif (FUNCTION in COMMANDS):
            print("\n{} is a command. But something went wrong. " 
                  "\n If the problem continues, please type " 
                  "\'help {}\'\n".format(FUNCTION, FUNCTION))

sock.shutdown(1)
sock.close()

