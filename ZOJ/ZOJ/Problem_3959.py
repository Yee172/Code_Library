t = input()
for _ in xrange(t):
    n = input()
    ok = 1
    if 9 < n < 14:
        a = list(map(int, raw_input().split()))
        a.sort()
        num1 = 0
        for i in xrange(n - 2):
            if a[i] < 1:
                ok = 0
                break
            if a[i] == 1:
                num1 += 1
            if a[i + 1] - a[i] > 2:
                ok = 0
                break
        if num1 < 2:
            ok = 0
        print('Yes' if ok else 'No')
    else:
        raw_input()
        print('No')
