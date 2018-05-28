print((lambda n, s: n - max([1] + [x for x in range((n >> 1) + 1) if s[:x] == s[x:2 * x]]) + 1)(int(input()), input()))
