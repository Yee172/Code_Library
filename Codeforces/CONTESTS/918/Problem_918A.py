F = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987]
n = int(input())
print(''.join('O' if _ in F else 'o' for _ in range(1, n + 1)))
