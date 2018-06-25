n = int(input())
s = input()
for i in range(2, n + 1):
    if not n % i:
        s = s[:i][::-1] + s[i:]
print(s)
