# If p is the perimeter of a right angle triangle with
# integral length sides, {a, b, c}, there are exactly
# three solutions for p = 120.
# {20, 48, 52}, {24, 45, 51}, {30, 40, 50}
# For which value of p \leq 1000, is the number of
# solutions maximised?
# ----------------------------------------------------
# Analysis:    a^{2} + b^{2} = c^{2}
#              a + b + c = p
#           => (a - b)^{2} = c^{2} - p^{2} + 2pc := d^{2}
#              ,where d > 0
#           => a = (p - c - d) / 2
#              b = (p - c + d) / 2
#              c = c
#           Then we enumerate c and p is ok.
#           Since a + b > c, we get c < p / 2

def f(p):
    cnt = 0
    for c in range(1, p // 2):
        d = c * c - p * p + 2 * p * c
        if d < 0 or int(d ** .5) ** 2 != d:
            continue
        d = int(d ** .5)
        a2 = p - c - d
        if a2 <= 0 or a2 & 1:
            continue
        cnt += 1
    return cnt

print(max(range(1, 1001), key=lambda x: f(x)))
