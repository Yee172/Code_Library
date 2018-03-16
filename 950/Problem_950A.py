print((lambda l, r, a: 2 * max(min(l + i, r + a - i) for i in range(a + 1)))(*map(int, input().split())))
