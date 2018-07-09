n = int(input()) - 1
s = input()
m = 0
r = 0
for i in range(n):
    m += 1 if s[i] == 'U' else -1
    if m == 0 and s[i] == s[i + 1]: r += 1
print(r)
