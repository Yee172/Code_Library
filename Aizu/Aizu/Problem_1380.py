rd = lambda: map(int, input().split())
n, t = rd()
last = 0
lastsum = 0
ma = 0
lastans = 0x3f3f3f3f3f3f3f3f
for i in range(n):
    nowsb = int(input())
    lastsum += nowsb
    time = t - lastsum
    ma = max(ma, nowsb)
    lastans = max(time // ma + 2, 1)
    print(lastans)
