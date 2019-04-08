for _ in range(int(input())):
    n = input().strip()
    if len(n) < 2:
        if n == '5':
            a = '2'
            b = '3'
        else:
            a = '1'
            b = str(int(n) - 1)
    else:
        if n[0] == '1':
            if n[1] == '5':
                a = '2'
                b = '13'
            else:
                a = '1'
                b = str(int(n[:2]) - 1)
        else:
            if n[0] == '5':
                a = '2'
                b = '3'
            else:
                a = '1'
                b = str(int(n[0]) - 1)
            if n[1] == '4':
                a += '1'
                b += '3'
            else:
                a += '0'
                b += n[1]
        for c in n[2:]:
            if c == '4':
                a += '1'
                b += '3'
            else:
                a += '0'
                b += c
    print('Case #%d: %s %s' % (_ + 1, a, b))
