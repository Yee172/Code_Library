k = int(input())
N = 9
a = [0] * (N + 1)
i = N
while 1:
    if a[i] > 9:
        a[i] = 0
        i -= 1
        a[i] += 1
        continue
    s = sum(a)
    if s is 10:
        k -= 1
    if s < 10:
        i = N
    if s > 10:
        a[i] = 0
        i -= 1
    if not k:
        break
    a[i] += 1
print(int(''.join(map(str,a))))
