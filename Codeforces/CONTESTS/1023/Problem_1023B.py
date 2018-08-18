print((lambda n, k: max(0, min(n, k - 1) - k // 2))(*map(int, input().split())))
