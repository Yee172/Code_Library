f = lambda s: f(s.replace('xxx', 'xx')) if 'xxx' in s else s
print(int(input()) - len(f(input())))
