print(1 - int(input()) + (lambda a: max(a) - min(a))(list(map(int, input().split()))))
