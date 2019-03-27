# Alice walks on a lattice grid. She can step from one
# lattice point A(a, b) to another B(a + x, b + y) providing
# distance AB = \sqrt(x^{2} + y^{2}) is a Fibonacci number
# and x \geq 0, y \geq 0.
# Let F(W, H) be the number of paths Alice can take from
# (0, 0) to (W, H).
# Find F(10000, 10000) mod 1000000007.
# ----------------------------------------------------
# Analysis: dynamic programming

MOD = 0x3b9aca07
n = 10000 + 1
m = int(2 ** .5 * n) + 1

transfer = [(1, 0), (2, 0), (0, 1), (0, 2)]

Fibonacci = [1, 2]

while Fibonacci[-1] + Fibonacci[-2] < m:
    Fibonacci.append(Fibonacci[-1] + Fibonacci[-2])
    transfer.append((Fibonacci[-1], 0))
    transfer.append((0, Fibonacci[-1]))

def dfs(a, b, c):
    if a >= n or b >= n:
        return
    x, y, z = a, b, c
    while True:
        if x >= n or y >= n:
            break
        if z in Fibonacci:
            transfer.append((x, y))
            transfer.append((y, x))
        x, y, z = x + a, y + b, z + c
    dfs(a - 2 * b + 2 * c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c)
    dfs(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c)
    dfs(-a + 2 * b + 2 * c, -2 * a + b + 2 * c, -2 * a + 2 * b + 3 * c)

dfs(3, 4, 5)

transfer.sort()

dp = [[0] * (i + 1) for i in range(n)]
dp[0][0] = 1

def get_dp(i, j):
    return dp[j][i] if j > i else dp[i][j]

for i in range(1, n):
    for j in range(i + 1):
        for x, y in transfer:
            if i >= x:
                if j >= y:
                    dp[i][j] += get_dp(i - x, j - y)
            else:
                break
        dp[i][j] %= MOD

print('Be patient')
print(dp[n - 1][n - 1])
