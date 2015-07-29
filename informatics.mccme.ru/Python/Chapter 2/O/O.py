n = int(input())
n = n % (60 * 60 * 24)
res = str(n // (60 * 60))
res = res + ':'
n = n % (60 * 60)
m = n // 60
n = n % 60
res = res + str(m // 10)
res = res + str(m % 10)
res = res + ':'
res = res + str(n // 10)
res = res + str(n % 10)
print(res)
 
