# Given that L is the length of the wire, for
# how many values of L \leq 1500000 can exactly one
# integer sided right angle triangle be formed?
# ----------------------------------------------------
# Analysis: tree of primitive Pythagorean triples
#           https://en.wikipedia.org/wiki/Tree_of_primitive_Pythagorean_triples

MAXN = 1500000

vis = [0] * MAXN

def dfs(a, b, c):
    p = a + b + c
    if p >= MAXN:
        return
    for x in range(p, MAXN, p):
        vis[x] += 1
    dfs(a - 2 * b + 2 * c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c)
    dfs(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c)
    dfs(-a + 2 * b + 2 * c, -2 * a + b + 2 * c, -2 * a + 2 * b + 3 * c)

dfs(3, 4, 5)

print(vis.count(1))
