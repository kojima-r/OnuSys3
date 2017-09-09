import socket
from contextlib import closing
import numpy as np
import time

h=("127.0.0.1",1112)
d=("127.0.0.1",1113)
n=37
#arr=np.array([0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8],dtype=np.float32)
arr=np.zeros((n,),dtype=np.float32)

sock=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
with closing(sock):
	#sock.bind(h)
	while True:
		temp=np.random.rand(n)
		arr[:]=temp
		data=memoryview(arr)
		sock.sendto(data,d)
		print(arr)
		#print(sock.recv(128))
		time.sleep(1)


