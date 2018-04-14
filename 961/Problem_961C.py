rd = lambda: map(int, input())
def f(n, t):
    a = sum(i + j & 1 == x for i in range(n) for j, x in enumerate(rd()))
    if t < 3:
        rd()
    return a
n = int(input())
m = sorted([f(n, i) for i in range(4)])
print(2 * n * n + m[0] + m[1] - m[2] - m[3])
