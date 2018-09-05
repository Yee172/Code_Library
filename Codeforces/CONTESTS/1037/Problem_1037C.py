input()
r, l = 0, 0
for x, y in zip(input(), input()):
    l = y != x != l
    r += l
    l *= y
print(r)
