a = int(input())
b = int(input())

incr = 1 * (b >= a) + -1 * (b < a)

for i in range(a, b + incr, incr):
    print(i, end = ' ')
