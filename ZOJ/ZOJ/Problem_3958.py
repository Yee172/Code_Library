t = input()
for _ in xrange(t):
    input()
    a = list(map(int, raw_input().split()))
    k = a.count(1) + a.count(3) - a.count(4)
    t = a.count(2) + a.count(3) - a.count(4)
    print("Kobayashi" if k > t else "Tohru" if t > k else "Draw")
