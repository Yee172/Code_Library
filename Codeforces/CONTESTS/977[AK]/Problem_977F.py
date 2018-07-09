input()
a = list(map(int, input().split()))
dp = {}
for x in a:
    dp[x] = dp.get(x - 1, 0) + 1
r = max(dp, key=dp.get)
s = r - dp[r] + 1
print(dp[r])
r = []
for i, x in enumerate(a):
    if x == s:
        r.append(i + 1)
        s += 1
print(*r)
