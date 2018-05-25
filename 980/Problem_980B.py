n, k = map(int, input().split())
a = ['.' * n for i in 'iiii']
if k > n - 2:
    a[1] = '.' + '#' * (n - 2) + '.'
    k -= n - 2
a[2] = '.' + '#' * (k >> 1) + '.' * (n - 2 - k >> 1)
a[2] = a[2] + ('#' if k & 1 else '.') + a[2][::-1]
print('YES')
print('\n'.join(a))
