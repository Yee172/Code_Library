x, y = map(int, input().split())
print([x - y, x, y, y - x, -x, -y][int(input()) % 6] % 0x3b9aca07)
