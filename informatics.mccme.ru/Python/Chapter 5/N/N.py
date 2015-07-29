n = int(input())
mul = 1
ans = 0

for i in range(1, n + 1):
    ans += mul * 1 / i
    mul *= -1

print(ans)