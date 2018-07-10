n = int(input())
for _ in range(n):
    a = int(input())
    if a % 2 is 1:
        print(0)
        continue
    if a is 2:
        print(33)
    else:
        print(7 * a * a + 4 * a + 1)
