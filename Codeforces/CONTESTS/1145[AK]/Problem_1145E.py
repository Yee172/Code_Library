print(*[int((min(i, 25) + i) % (2 + i % 3) > 0) for i in range(21, 51)], sep='\n')
