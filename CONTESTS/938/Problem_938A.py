input()
s = input()
f = 0
i = 0
while i < len(s):
    if s[i] in 'aeiouy':
        if f:
            s = s[:i] + s[i + 1:]
            continue
        else:
            f = 1
    else:
        f = 0
    i += 1
print(s)
