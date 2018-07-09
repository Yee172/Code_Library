n = int(input())
print('\n'.join(['1 2\n1 3\n1 4', *['2 ' + str(i) for i in range(5, n + 1)]]) if n > 5 else -1, '\n'.join('1 ' + str(i) for i in range(2, n + 1)), sep='\n')
