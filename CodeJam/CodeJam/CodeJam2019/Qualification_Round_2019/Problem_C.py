from math import gcd

CHAR = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for _ in range(int(input())):
    input()
    a = list(map(int, input().split()))
    l = len(a)
    message = [0] * (l + 1)
    for i in range(l - 1):
        if a[i] != a[i + 1]:
            break
    g = gcd(a[i], a[i + 1])
    message[i] = a[i] // g
    message[i + 1] = g
    message[i + 2] = a[i + 1] // g
    for j in range(i - 1, -1, -1):
        message[j] = a[j] // message[j + 1]
    for j in range(i + 2, l + 1):
        message[j] = a[j - 1] // message[j - 1]
    letter = sorted(list(set(message)))
    d = {x: i for i, x in enumerate(letter)}
    print('Case #%d: %s' % (_ + 1, ''.join(CHAR[d[x]] for x in message)))
