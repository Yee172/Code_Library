from math import gcd


def binomial(n, k):
    if k > n:
        return 0
    res = 1
    for i in range(k):
        res *= n - i
        res //= i + 1
    return res


dp = [[0] * 1001 for i in range(1001)]
diagonal_num = [[0] * 1001 for i in range(1001)]
for i in range(1, 1001):
    dp[i][i] = 2 * dp[i - 1][i] - dp[i - 1][i - 1] + (i - 1)
    for j in range(i + 1, 1001):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (gcd(i, j) - 1)
for i in range(1, 1001):
    diagonal_num[i][i] = 2 * diagonal_num[i - 1][i] - diagonal_num[i - 1][i - 1] + dp[i][i]
    for j in range(i + 1, 1001):
        diagonal_num[i][j] = diagonal_num[i - 1][j] + diagonal_num[i][j - 1] - diagonal_num[i - 1][j - 1] + dp[i][j]
case = 1
for l in __import__('sys').stdin.readlines():
    m, n = map(int, l.split())
    if not any([m, n]):
        break
    if m > n:
        m ^= n
        n ^= m
        m ^= n
    res = binomial((m + 1) * (n + 1), 3) - (m + 1) * binomial(n + 1, 3) - (n + 1) * binomial(m + 1, 3) - 2 * diagonal_num[m][n]
    print('Case %d: %d' % (case, res))
    case += 1
