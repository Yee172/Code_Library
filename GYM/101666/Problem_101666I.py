p, q = map(int, input().split())
print(p % 2 * [2 * (q > p), 1][q & 1])
