n = int(input())
MOD = 0x3b800001
inv = [1, 1]
a, b = 1, 1
for i in range(2, n + 1):
    inv.append((MOD - MOD // i) * inv[MOD % i] % MOD)
    a, b = ((6 * i - 9) * a - (i - 3) * b) * inv[i] % MOD, a
print(a)
