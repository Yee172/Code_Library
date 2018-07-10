W = 'ago'
T = int(raw_input())


def f(s, flag, r):
    a, t = [0, 0, 0], []
    for _ in s:
        if r is flag:
            break
        for i in xrange(3):
            if _ == W[i]:
                if a[i] is 0:
                    t.append(_)
                if t and t[-1] != _ and a[i]:
                    r -= 1
                a[i] += 1
                if a[i] is 3:
                    t.remove(_)
    return 1 if r is flag else 0


for _____ in xrange(T):
    s = raw_input()
    if f(s, 2, 3):
        if sum(f(s.replace(W[_], ''), 1, 2) for _ in xrange(3)) is 3:
            print(1)
        else:
            print(2)
    else:
        print(3)
