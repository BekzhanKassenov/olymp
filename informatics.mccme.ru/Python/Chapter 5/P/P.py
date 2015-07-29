n = int(input())
ans = 0
den = 1
mul = 1

for i in range(n + 1):
    ans += mul * 1 / den
    den += 2
    mul *= -1

ans *= 4
print(ans)