n = int(input())
a = list(map(int, input().split()))
s = sum(a)
if n > 1:
    for i in range(n):
        if 2 * a[i] != s:
            print(1)
            print(i + 1)
            exit()
print(-1)
