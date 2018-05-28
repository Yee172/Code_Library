print((lambda n, a: min(sum(abs(x - i) for i, x in zip(range(s, n + 1, 2), a)) for s in [1,2]))(int(input()), sorted(map(int, input().split()))))
