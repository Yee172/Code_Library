x, y = map(int, input().split())
print('No' if x - y < -1 or (x - y) & 1 is 0 or y is 0 or y is 1 and x else 'Yes')
