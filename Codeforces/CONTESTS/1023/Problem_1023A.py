input()
s, t = input(), input()
try:
    a, b = s.split('*')
    r = t.startswith(a) and t[len(a):].endswith(b)
except:
    r = s == t
print(['NO', 'YES'][r])
