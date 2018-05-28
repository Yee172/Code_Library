from math import gcd
from functools import reduce
n = int(input())
a = list(map(int, input().split()))
a.sort()
b = [a[i + 1] - a[i] for i in range(n - 1)]
print(sum(b) // reduce(gcd, b) - n + 1)
