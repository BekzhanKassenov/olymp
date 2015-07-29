n = int(input())
k = int(input())

if (k < n - k):
    k = n - k

ans = 1
for i in range(k + 1, n + 1):
    ans *= i

for i in range(1, n - k + 1):
    ans //= i

print(ans)