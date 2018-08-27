import re
for _ in range(int(input())):
    s = input()
    r = ''
    if re.match(r'R\d+C', s):
        x = s.find('C')
        a = int(s[x + 1:])
        while a:
            r += chr(65 + (a - 1) % 26)
            a = (a - 1) // 26
        r = r[::-1] + s[1 : x]
    else:
        p = 0
        for i in range(len(s)):
            if s[i].isalpha():
                p = p * 26 + ord(s[i]) - 64
            else:
                break
        r = 'R' + s[i:] + 'C' + str(p)
    print(r)
