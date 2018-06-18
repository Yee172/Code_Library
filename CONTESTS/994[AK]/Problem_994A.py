rd = lambda: list(map(int, input().split()))
rd()
a, b = rd(), rd()
print(*[x for x in a if x in b])
