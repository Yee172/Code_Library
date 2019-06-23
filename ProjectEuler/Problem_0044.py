# Find the pair of pentagonal numbers, P_{j} and P_{k},
# for which their sum and difference are pentagonal
# and D = |P_{k} − P_{j}| is minimised.
# What is the value of D?
# ----------------------------------------------------
# Analysis: brute force
#           Assume P[j] + P[k] = P[l]
#              and P[j] - P[k] = P[i]
#           Then,  2 * P[j] = P[l] + P[i]
#              and 2 * P[k] = P[l] - P[i]
#           We want to find the minimised P[i],
#           so enumerate P[i] and P[l] to get the answer.

MAXN = 5000

P = list(map(lambda n: n * (3 * n - 1) >> 1, range(MAXN)))

def find(x):
    n = int((x * 2 / 3) ** .5) + 1
    return n * (3 * n - 1) >> 1 == x

def get_res():
    for i in range(1, MAXN):
        pm_i = P[i] & 1
        for l in range(i + 1, MAXN):
            if pm_i == P[l] & 1:
                if find(P[l] + P[i] >> 1) and find(P[l] - P[i] >> 1):
                    return P[i]

print(get_res())
