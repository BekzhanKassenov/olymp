import time

now = time.time()
while time.time() < (now+0.987): pass
for i in sorted(list(map(lambda x : int(x), input().split()))[1:]): print(i, end=" ")
