input()
for l in __import__('sys').stdin.readlines():
    a, b = map(int, l.split())
    print(a * b)
