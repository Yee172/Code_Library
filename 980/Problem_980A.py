print('NO' if (lambda s: s.count('o') and len(s) % s.count('o'))(input()) else 'YES')
