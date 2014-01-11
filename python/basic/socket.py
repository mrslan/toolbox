import threading
from threading import Thread, Lock
from time import sleep
import socket

mainport = 12344

class ClientThread(threading.Thread):
    def run(self):
        print self.__class__.__name__, ": started"
        self.active = True
        
        while self.active:
            try:
                s = socket.socket()
                host = socket.gethostname()
                port = mainport
                s.connect((host, port))
                print self.__class__.__name__, ":", s.recv(1024)
                s.close()
            except:
                print self.__class__.__name__, ": Failure to open socket"
                break

            sleep(1)
            
        print self.__class__.__name__, ": closed"
        
    def stop(self):
        if not self.active:
            return
       
        self.active = False
        self.join()

class ServerThread(threading.Thread):
    def run(self):
        try:
            print self.__class__.__name__, ": started"
            
            self.c = None
            self.active = False
            self.s = socket.socket()
            self.s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            host = socket.gethostname()
            port = mainport
            self.s.bind((host, port))
            
            self.s.listen(1)
            self.active = True
            
            while self.active:
                try:
#                     print 'Server: Accepting connection'
                    c, addr = self.s.accept()
                    c.send('Thank you for connecting')
                
                except:
                    print self.__class__.__name__, ': something wrong'
                    break

                finally:
                    c.close()
        finally:
            self.s.close()
                
        
        print self.__class__.__name__, ": exited"
        
    def stop(self):
        if not self.active:
            return
        
        self.active = False
        self.s.close()
        self.join()

print "Start"
# Create Client Thread
client_thread = ClientThread()

# Create Server Thread
server_thread = ServerThread()

server_thread.start()
client_thread.start()

sleep(3)

server_thread.stop()
client_thread.stop()

print "Exit"
