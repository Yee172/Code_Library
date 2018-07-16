for i in range(int(input())):
    H, A = map(int, input().split())
    delta = H * H - 4 * A
    if delta < 0:
        print(-1)
        continue
    delta **= .5
    Delta = (H * H + 4 * A) ** .5
    print((Delta - delta) / 2, (Delta + delta) / 2, H)
