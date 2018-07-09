t = int(input())
for i in range(t):
    print(['abdullah', 'hasan'][any(map(lambda x: int(x) & 1, input().split()))])
