# Find the third triangle number that is also
# pentagonal and hexagonal.
# (Fisrt is 1, second is 40755)
# ----------------------------------------------------
# Analysis: brute force

def find(x):
    n = int((x * 2 / 3) ** .5) + 1
    if not n * (3 * n - 1) >> 1 == x:
        return False
    n = int((x << 1) ** .5)
    return n * (n + 1) >> 1 == x

def get_ans():
    n = 1
    cnt = 0
    while cnt < 3:
        h = n * (2 * n - 1)
        if find(h):
            print(n, h)
            cnt += 1
        n += 1

get_ans()
