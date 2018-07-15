rd = lambda: list(map(int, input().split()))
r = 0
a = [0] + rd()
b = [rd() for i in range(int(input()))]
def get_go(x):
    y = [0] * 9
    i, j = 1, 1
    while i < 1 << 8:
        if x & i:
            y[j] = 1
        i <<= 1
        j += 1
    return y
def check(y):
    for c, d in b:
        if y[c] and y[d]:
            return False
    return True
def get_sum(y):
    return sum(a[i] * y[i] for i in range(9))
for x in range(1 << 8):
    y = get_go(x)
    if check(y):
        r = max(r, get_sum(y))
print(r)
