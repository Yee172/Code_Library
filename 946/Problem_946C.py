s = list(input())
i = 97
for j in range(len(s)):
    x = s[j]
    if x <= chr(i):
        s[j] = chr(i)
        i += 1
    if i == 123:
        print(''.join(s))
        exit()
print(-1)
