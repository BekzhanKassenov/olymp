n = int(input())
x = float(input())
fact = 1
ans = 1
num = 1

for i in range(1, n + 1):
    fact *= i
    num *= x
    ans += num / fact

print(ans)