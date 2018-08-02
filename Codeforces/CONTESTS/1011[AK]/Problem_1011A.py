n, k = map(int, input().split())
a = sorted(map(ord, input()))
r = a[:1]
for x in a[1:]:
    if x - r[-1] > 1:
       r.append(x) 
print([sum(r[:k]) - 96 * k, -1][len(r) < k])
