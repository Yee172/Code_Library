n = int(input())
a = sorted(map(int, input().split()))
s, i = sum(a) - n * 4.5, 0
while s < 0:
    s += 5 - a[i]
    i += 1
print(i)
