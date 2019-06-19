# The Golomb's self-describing sequence {G(n)} is the
# only nondecreasing sequence of natural numbers such
# that n appears exactly G(n) times in the sequence.
# Find \sum G(n^{3}) for 1 \leq n < 10^{6}.
# ----------------------------------------------------
# Analysis: dynamic programming
#           Hint: https://oeis.org/A001462
#                 g(n) = 1 + g(n - g(g(n - 1)))
#                 \sum_{i = 1}^{n} g(i) represents the largest number that appears n times
#                 \sum_{i = 1}^{n} i * g(i) represents the largest index of the largest number that appears n times

target = 10 ** 6
MAXN = target ** 3

g = [0, 1]
g_upperbound = 0
i = 2
while True:
    g.append(1 + g[i - g[g[i - 1]]])
    g_upperbound += i * g[i]
    if g_upperbound > MAXN:
        break
    i += 1

res = 0
g_index = 0
g_start = 0
g_upperbound = 0
for n in range(1, target):
    k = n ** 3
    while g_upperbound + g_index * g[g_index] < k:
        g_start += g[g_index]
        g_upperbound += g_index * g[g_index]
        g_index += 1
    res += g_start + 1 + (k - g_upperbound - 1) // g_index

print(res)
