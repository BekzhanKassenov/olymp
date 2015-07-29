a = int(input())
b = int(input())
ans = (a - b >= 0) * a + (b - a > 0) * b
print(ans)
