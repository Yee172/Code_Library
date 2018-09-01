n, k = map(int, input().split())
s, i = input(), n - 1
while s[-i:] != s[:i]:
    i -= 1
print(s[:i] + s[i:] * k)
