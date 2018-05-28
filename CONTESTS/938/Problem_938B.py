input()
print(max(min(x - 1, 1000000 - x) for x in map(int, input().split())))
