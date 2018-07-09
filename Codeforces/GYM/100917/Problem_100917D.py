rd = lambda: map(int, input().split())
n, w = rd()
a = rd()
bit = 0
d = [0] * (n << 2)
def build(n):
    global bit
    bit = 1
    while bit <= n + 1:
        bit <<= 1
    for i in range(bit + 1, bit + n + 1):
        d[i] = next(a)
    for i in range(bit - 1, 0, -1):
        d[i] = max(d[i << 1], d[i << 1 | 1])
        d[i << 1] -= d[i]
        d[i << 1 | 1] -= d[i]
def query(l, r):
    lans = 0
    rans = 0
    if l == r:
        l += bit
        while l:
            lans += d[l]
            l >>= 1
        return lans
    l += bit
    r += bit
    while l ^ r ^ 1:
        lans += d[l]
        rans += d[r]
        if ~ l & 1:
            lans = max(lans, d[l ^ 1])
        if r & 1:
            rans = max(rans, d[r ^ 1])
        l >>= 1
        r >>= 1
    lans += d[l]
    rans += d[r]
    ans = max(lans, rans)
    while l > 1:
        l >>= 1
        ans += d[l]
    return ans
build(n)
for i in range(1, n + 1):
    ans = 0
    ok = 1
    for j in range(1, n + 1, i):
        ans += query(j, min(j + i - 1, n))
        if ans > w:
            break
    ans += (n - 1) // i
    if ans > w:
        ok = 0
    if not ok:
        continue
    print(i)
    break
