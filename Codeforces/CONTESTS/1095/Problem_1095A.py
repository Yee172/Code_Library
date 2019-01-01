input()
s = input()
i = 1
r = ''
while s:
    r += s[0]
    s = s[i:]
    i += 1
print(r)
