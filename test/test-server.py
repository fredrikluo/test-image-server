import socket
import sys
import threading
from datetime import datetime

server_address = ('localhost', 8080)
NUM_THREAD = 3000
result = []

def worker():
    start = datetime.now()
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(server_address)

    try:
        # Send data
        getall_cmd ='GETALL\r'
        sock.sendall(getall_cmd)

        # Look for the response
        amount = 0
        while True:
            data = sock.recv(4096)
            if not data:
                break

            amount += len(data)
    finally:
        sock.close()

    result.append((datetime.now() - start).total_seconds())

threads = []
for i in xrange(NUM_THREAD):
    t = threading.Thread(target=worker)
    threads.append(t)
    t.start()

for t in threads:
    t.join()

print "avg time in sec:", sum(result)/len(result)
print "max time in sec:", max(result)

