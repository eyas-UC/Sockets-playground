
import socket
HOST = socket.gethostbyname(socket.gethostname())
PORT = 8090  # The port used by the server

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print(f"before connection... port is {PORT}, host is {HOST}")
s.connect((HOST, PORT))
print("connection ok")
while True:
    data = input("enter data to send, send 'exit' or ctrl +c to close connection\n")
    s.sendall(bytes(data,"utf-8"))
