read = lambda: map(int, input().split())
input()
a = list(read())
b = {}
for _ in a:
    b[_] = (b.get(_, 0) + 1) % 2
for _ in b.values():
    if _ is 1:
        print('Conan')
        exit(0)
print('Agasa')
