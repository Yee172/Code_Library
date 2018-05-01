n, a, b = map(int, input().split())
c = [a, b]
f, r = b > a, 0
for x in input():
    if x == '.':
        if c[f] == 0:
            f ^= 1
            continue
        c[f] -= 1
        r += 1
        f ^= 1
    if x == '*':
        f = c[1] > c[0]
print(r)
