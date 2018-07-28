for _ in range(int(input())):
    n = int(input())
    if n == 0 or n & 1:
        print("impossible")
    else:
        print("possible")
        k = n >> 1
        a = [[0] * n for i in range(n)]
        for i in range(n):
            for j in range(k):
                a[i][j] = -1
                a[i][j + k] = 1
        for i in range(k):
            for j in range(i + 1):
                a[i + k][k - j - 1] = 0
        for i in range(k - 1):
            for j in range(i + 1):
                a[i + 1][n - 2 - j] = 0
        print('\n'.join(' '.join(map(str, x)) for x in a))
