for i in range(int(input())):
    n, k, m = map(int, input().split())
    t = 0
    while n * k <= m:
        t += 1
        n *= k
    print(t)
