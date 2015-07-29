n = int(input())

ans = 2

print('1*2', end='')

for i in range (2, n):
    print('+', i, '*', i + 1, sep = '', end = '')
    ans += i * (i + 1)

print('=', ans, sep = '')
