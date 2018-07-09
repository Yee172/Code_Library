rd = lambda: list(map(int, input().split()))
n, k = rd()
a = rd()
r = 0
s = [0]
for x in a:
    s.append(s[-1] + x)
for i in range(n - k + 1):
    for j in range(i + k, min(n + 1, i + 2 * k)):
        r = max(r, (s[j] - s[i]) / (j - i))
print(r)
