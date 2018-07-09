n = int(input())
r = 0
for x in [100, 20, 10, 5, 1]:
    r += n // x
    n %= x
print(r)
