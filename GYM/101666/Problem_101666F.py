input()
a = sorted(map(int, input().split()))
print(*sorted([sum(a[::2]), sum(a[1::2])])[::-1])
