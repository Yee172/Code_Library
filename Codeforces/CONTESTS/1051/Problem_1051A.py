for _ in range(int(input())):
    s = input()
    r = ''
    a, b, c = [0] * 3
    for x in s:
        a += x.isdigit()
        b += x.islower()
        c += x.isupper()
    if a and b and c:
        r = s
    if a and b and not c:
        A, B = 0, 0
        for i, x in enumerate(s):
            if x.isdigit():
                A += 1
            else:
                B += 1
            if A > 1 or B > 1:
                r += 'A'
                r += s[i + 1:]
                break
            r += x
    if a and c and not b:
        A, C = 0, 0
        for i, x in enumerate(s):
            if x.isdigit():
                A += 1
            else:
                C += 1
            if A > 1 or C > 1:
                r += 'a'
                r += s[i + 1:]
                break
            r += x
    if b and c and not a:
        B, C = 0, 0
        for i, x in enumerate(s):
            if x.islower():
                B += 1
            else:
                C += 1
            if B > 1 or C > 1:
                r += '1'
                r += s[i + 1:]
                break
            r += x
    if a and not any([b, c]):
        r = 'aA' + s[2:]
    if b and not any([a, c]):
        r = '1A' + s[2:]
    if c and not any([a, b]):
        r = '1a' + s[2:]
    print(r)
