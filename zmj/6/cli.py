import socket 

s = socket.socket()         # Create a socket object
host = socket.gethostname() # Get local machine name
port = 12345

s.connect((host, port))
print (s.recv(1024))
s.close()                