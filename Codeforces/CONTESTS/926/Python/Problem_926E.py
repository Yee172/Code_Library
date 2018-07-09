input()
a, b = map(int, input().split()), []
for x in a:
    while b and x == b[-1]:
        x += 1
        b.pop()
    else:
        b.append(x)
print(len(b))
print(*b)
