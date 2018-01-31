def delete_p(s):
    i = 0
    f = 0
    l = len(s)
    while i < l - 1:
        if s[i + 1] != s[i]:
            f = 1
            del s[i: i + 2]
            l -= 2
        else:
            i += 1
    return f
s = list(input())
count = 0
while delete_p(s):
    count += 1
    # print(''.join(s))
print(count)
