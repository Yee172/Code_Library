n = int(input())
o = sum(map(lambda x: int(x) & 1, input().split()))
e = min(n - o, o)
o -= e
print(e + o // 3)
