while 1:
    n = int(input())
    if not n:
        break
    i, s = 0, 0
    while s < n:
        j = 10 ** (i >> 1)
        s += 9 * j
        i += 1
    s = n - s + 9 * j
    r = str((s // j + 1) * j + s % j - 1)
    print(r + r[:i >> 1][::-1])
