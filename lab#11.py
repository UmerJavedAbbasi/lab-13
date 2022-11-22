import random
class DOS_Prevention_Protocol:
    allowed_clients=[]
    client_ip=''
    def __init__(self):
        self.client_ip='127.0.0.1'
    def SetClientIP(self,ip):
        self.client_ip=ip

    def GetClientIp(self):
        return self.client_ip
    def AddAllowedclient(self,ip):
        self.allowed_clients.append(ip)
    def GetAllowedClients(self):
        return self.allowed_clients

class UDP_Connection(DOS_Prevention_Protocol):
    def __init__(self):
        super().__init__()
        print("UDP Connection is Established")

class Puzzleforclient(DOS_Prevention_Protocol):
    def __init__(self):
        super().__init__()   
        if(self.client_ip in self.allowed_clients):#no need of puzzle
            print("Skipping Puzzle, Create TCP Connection")
        else:#puzzle creating
            puzzle=random.randint(0,100000)
            print("Puzzle Created For Client")
    
    def Puzzle_Solved_Successfully(self):
        self.AddAllowedclient(self.client_ip)
    
class TCPSession(DOS_Prevention_Protocol):
    def __init__(self):
        super().__init__()
        if(self.client_ip in self.allowed_clients):
            print("Establishing TCP Session with Client")
        else:
            print("Solve Puzzle before Establishing TCP Session")

first_step=UDP_Connection()
#first_step.AddAllowedclient('127.0.0.1')
second_step=Puzzleforclient()
#second_step.Puzzle_Solved_Successfully()
third_step=TCPSession()

'''
README.MD
THis protocol is designed to prevent DDOS attack.First of all server will create a UDP connection with client. Then server will generate a puzzle for client
and server will share that puzzle to client.If client solve puzzle successfully then client would be added to authenticated client list and TCP connection with client would be established otherwise Client would not be able to create a TCP session.
******CONFIDENTIAL******
'''