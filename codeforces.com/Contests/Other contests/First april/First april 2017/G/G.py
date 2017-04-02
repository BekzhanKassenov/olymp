a = str(eval(input()))
print("+" * ord(a[0]), end="")
print(".", end="")

for i in range(1, len(a)):
    print(">", "+" * ord(a[i]), ".", end="")