n = int(input())
x = float(input())

ans = 1
num = 1
fact = 1
mul = 1

for i in range(1, n + 1):
    mul *= -1
    num *= x * x
    fact *= 2 * i * (2 * i - 1)
    ans += mul * num / fact

print(ans)