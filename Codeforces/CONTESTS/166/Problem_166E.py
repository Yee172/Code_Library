M = 0x3b9aca07
n = int(input())
print((pow(3, n, M) + [3, -3][n & 1]) * 0xee6b282 % M)

