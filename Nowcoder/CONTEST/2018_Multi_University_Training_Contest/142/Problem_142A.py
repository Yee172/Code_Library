def Mod(x, y):
    return x if x < y else x % y + y
gao = [1000000007, 1000000006, 500000002, 243900800, 79872000, 19660800, 5242880]
i = 1 << 21
while i >= 2:
    gao.append(i)
    i >>= 1
def gen(i):
    return gao[i] if i < 28 else 1
t = int(input())
for _ in range(t):
    s = input()
    n = 0
    p = 0
    for x in s:
        if x == '2':
            p += 1
    for x in s:
        if x == '0':
            n = (n + 1) % gen(p)
        elif x == '1':
            n = 2 * (n + 1) % gen(p)
        else:
            p -= 1
            mod = gen(p)
            n = (3 * pow(2, Mod(n + 1, gen(p + 1)), mod) - 3) % mod
    print(n)
