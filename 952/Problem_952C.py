print('NO' if (lambda n, a: any(abs(a[i + 1] - a[i]) > 1 for i in range(n - 1)))(int(input()), list(map(int, input().split()))) else 'YES')
