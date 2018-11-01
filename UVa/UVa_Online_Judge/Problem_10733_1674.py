while 1:
    n = int(input())
    if not n:
        break
    print((n ** 6 + 3 * n ** 4 + 12 * n ** 3 + 8 * n ** 2) // 24)
