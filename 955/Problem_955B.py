s = input()
a = set(s)
l = len(a)
c = [s.count(x) > 1 for x in a]
print('Yes' if l == 2 and all(c) or l == 3 and any(c) or l == 4 else 'No')
