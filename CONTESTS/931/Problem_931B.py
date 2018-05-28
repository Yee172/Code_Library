n, a, b = map(int, input().split())
m = len(bin((a - 1) ^ (b - 1))) - 2
print('Final!' if m == len(bin(n)) - 3 else m)
