for l in __import__('sys').stdin.readlines():
    x = float(l)
    if x:
        r = 0
        i = 2
        while r < x:
            r += 1 / i
            i += 1
        print(i - 2, 'card(s)')
