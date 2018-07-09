print((lambda n, k: ''.join(map(lambda a: a[0], sorted(sorted(zip(input(), range(n)))[k:], key=lambda a: a[1]))))(*map(int, input().split())))
