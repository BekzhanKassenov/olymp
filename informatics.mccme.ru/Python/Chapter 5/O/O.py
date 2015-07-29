n = int(input())
x = float(input())
ans = 0
cur = 1

for i in range (n + 1):
    ans += cur
    cur *= x

print(ans) 