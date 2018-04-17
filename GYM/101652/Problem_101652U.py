a = list(map(float, input().split()))
print('%.3f' % abs((3.5 - sum(map(lambda x: x[0] * x[1], zip(a, range(1, 7))))) / max(a)))
