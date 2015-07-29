n = int(input())
ans = 0
for i in range(1, n + 1):
    ans += 1 / i ** 2
print(ans)