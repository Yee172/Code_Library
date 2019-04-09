for _ in range(int(input())):
    n = int(input())
    Lydia = input().strip()
    print('Case #%d: %s' % (_ + 1, ''.join(('S', 'E')[c == 'S'] for c in Lydia)))
