read = lambda: map(int, input().split())
n, m = read(); r = [0, 1]
for index, key in enumerate(read()): r = [(key - 1) // m, index + 1] if (key - 1) // m >= r[0] else r
print(r[1])
