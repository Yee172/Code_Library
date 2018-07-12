input()
for line in __import__('sys').stdin.readlines():
    if line.split():
        x = int(line) * 10 ** 30
        l = 0
        r = x
        while l < r:
            m = l + r + 1 >> 1
            if m ** 3 <= x:
                l = m
            else:
                r = m - 1
        print(sum(map(int, str(l))) % 10, '%d.%010d' % (divmod(l, 10 ** 10)))
