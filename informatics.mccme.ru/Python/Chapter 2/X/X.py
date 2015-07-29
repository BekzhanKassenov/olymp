n = int(input())
a = n % 10
n //= 10
b = n % 10
n //= 10
c = n % 10
n //= 10
d = n
ans = ((a == d) and (b == c))
ans = int(ans)
print(ans)
