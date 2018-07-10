while 1:
    n, k = map(int, input().split())
    if n and k:
        k -= 1
        n += k
        r = 1
        for i in range(k):
            r *= n
            r //= i + 1
            n -= 1
        print(r % 10 ** 6)
    else:
        break
