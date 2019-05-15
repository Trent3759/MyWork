Trenton D Scott			
Scott031@live.missouristate.edu
CSC656 Computer Networking	
10/06/2016


Files Submitted ------------------------------------------------------------------------------------
									   
netHelp:								     
netHelp.py contains a help program to assist you in using both of my main    
client programs. It is intended to make my program more user friendly. 	   
									     
TCPclient:								   
TCPclient.py is used to simulate a client computer that is connecting to      
a server using a TCP connection. For assignment and testing purposes,        
it takes use of the server localhost.                                        
                                                                             
TCPserver:								    
TCPserver.py is the program I used to create a server to wait for incoming    
connections. For this assignment, it receives information from a client       
on a predetermined port, calculates the result of the information provided,  
and sends the result back to the client using a TCP connection.              
									     
UDPclient:                                                                 
UDPclient.py is used to simulate a client computer that is connecting to    
a server using a UDP connection. For assignment and testing purposes,     
it takes use of the server localhost.                                     
 									     
UDPserver:								     
UDPserver.py is the program I used to create a server to wait for incoming    
connections. For this assignment, it receives information from a client	      
on a predetermined port, calculates the result of the information provided,   
and sends the result back to the clinet using a UDP connection.

Sample_Output:
Sample_Output.txt includes sample output when you run the program. 
                                                                           
Instructions-----------------------------------------------------------------------------------------------


***IMPORTANT***

Please note: The computer running this program must have Python 3.4
or above installed to succesfully utilize this programs features. 

Previous versions of Python do not support functions used in this program. 

For more information regarding Python, please visit: https://www.python.org/

****************


Command Line (Windows):
	1. Navigate to the folder containing python files
	2. In the address bar, type "cmd" without quotes
	3. Enter "python UDPclient.py" or "python TCPclient.py"
	    (depending on which protocol you would like to test. )
	4. Repeat step 1 and 2 for a second command window. 
	5. Enter "python UDPserver.py" or "python TCPserver.py"
	   *please note: if you use UDPclient, you must use UDPserver*
	6. Navigate back to the Command Line window of the client side program. 
	7. Read welcome message and try program. 

IDLE:
	1. Navigate to the folder containing the python files
	2. Right click "UDPclient.py" or "TCPclient.py"
	3. Click "edit with IDLE" and open the file in edit mode. 
	4. Repeat step 1
	5. Right click "UDPclient.py" or "TCPclient.py"
	6. Repeat step 3
	7. From the edit window in IDLE, click "run" and "run module"
	8. Repeat step 7 for the other opened IDLE window
	9. Read instructions on client side and begin using program

_____________________________________________________________________

-----------------------------------------------------Protocol--------------------------------------------------

Error and Exception Handling:
	Errors and Exceptions in this set of programs are dealt with using 
	try - except statements. If an exception or error is thrown inside 
	one of these statements, the user should be notified of the failure
	and the program should attempt to correct itself.

	Requests to the server:
	In the event that a request to the server fails, whether it be from lack
	of response or the inability to connect to the server, the program 
	should retry the connection. Once the program has retried the connection
	3 times, it should then notify the user that the server is not responding. 
	For stability, 3 seconds should ellapse in between each connection attemp. 
	

Program Termination:
	The client program should never terminate because of an error in the
	program.  If and/or when they with to exit, they may do so by typing
	the command "exit" and pressing enter. 

Program Use:
	The user should find the program fairly easy to use. Though, in the event
	that the user cannot navigate or forgets the command they should enter,
	they will be able to either just type help (for information on how to use
	the help function) or they can type help Cal for information on how to 
	use the Cal function. To keep program code clutter free, the help function 
	is kept in netHelp.py. 



































