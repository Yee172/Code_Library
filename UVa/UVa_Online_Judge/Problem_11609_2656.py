mod = 10 ** 9 + 7
t = int(input())
for _ in range(t):
    n = int(input())
    print('Case #%d: %d' % (_ + 1, n * pow(2, n - 1, mod) % mod))
