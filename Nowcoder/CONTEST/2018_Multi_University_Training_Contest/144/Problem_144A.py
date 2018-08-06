for _ in range(int(input())):
    n = int(input())
    a, b = [], []
    for i in range(1 << n):
        a.append((sorted(map(int, input().split())), i))
    while len(a) > 1:
        for i in range(0, len(a), 2):
            x0, i0 = a[i]
            x1, i1 = a[i + 1]
            index = [i0, i1][x0[-1] < x1[-1]]
            x0, x1 = sorted([x0, x1], key=lambda a: a[-1])
            for j in range(len(x1)):
                if x1[j] > x0[-1]:
                    break
            b.append((x1[:j] + x1[j + 1:], index))
        a, b = b, []
    print('Case #%d: %d' %(_ + 1, a[0][1] + 1))
