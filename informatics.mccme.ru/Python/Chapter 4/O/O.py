a = int(input())
b = int(input())
c = int(input())
d = int(input())

for i in range(0, 1001):
    if (a * i ** 3 + b * i ** 2 + c * i + d == 0):
        print(i, end = ' ')
         