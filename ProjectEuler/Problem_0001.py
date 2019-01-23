# Find the sum of all the multiples
# of 3 or 5 below 1000.
# ----------------------------------------------------
# Analysis: inclusion-exclusion principle

MAXN = 999

def cal(x):
    n = MAXN // x
    return (n * (n + 1) >> 1) * x

print(cal(3) + cal(5) - cal(15))
