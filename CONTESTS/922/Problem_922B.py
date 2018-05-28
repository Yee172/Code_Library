print(sum(c - b < b ^ c < b for c in range(1, int(input()) + 1) for b in range(c // 2, c)))
