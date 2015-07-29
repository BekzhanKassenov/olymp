a = int(input())
b = int(input())
ans = (a % b == 0)
a, b = b, a
ans = ans or (a % b == 0)
print(int(ans))
