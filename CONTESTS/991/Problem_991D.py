l, r = 0, 0
for x in map(lambda x: x.count('0'), zip(input(), input())):
    l, r = [[x, r], [x == l, r + 1]][l + x > 2]
print(r)
