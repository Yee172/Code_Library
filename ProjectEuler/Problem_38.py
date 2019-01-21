# What is the largest 1 to 9 pandigital 9-digit number
# that can be formed as the concatenated product of an
# integer with (1, 2, \ldots, n) where n > 1?
# ----------------------------------------------------
# Analysis: brute force

def f(x):
    i = x
    s = list()
    cnt = 0
    while cnt < 9:
        j = str(i)
        if len(set(j)) < len(j) or '0' in j:
            break
        f = 0
        for p in j:
            if p in s:
                f = 1
        if f:
            break
        cnt += len(j)
        for p in j:
            s.append(p)
        i += x
    if cnt != 9:
        return 0
    return int(''.join(s))

print(max(f(i) for i in range(10, 100000)))
