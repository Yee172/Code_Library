from itertools import groupby

QUERY = [('0' * (1 << i) + '1' * (1 << i)) * (1024 >> i + 1) for i in range(5)]

for _ in range(int(input())):
    N, B, F = map(int, input().split())
    a = [input(QUERY[i][:N] + '\n').strip() for i in range(5)]
    missing = []
    gp = [len(list(group)) for key, group in groupby(a[4])]
    if len(gp) != (N - 1) // 16 + 1:
        gp.append(0)
    for index, x in enumerate(gp):
        l = len(QUERY[4][:N][index * 16:index * 16 + 16])
        if x != l:
            missing.append((index, l, x))
    for i in range(3, -1, -1):
        j = 1 << i
        shift = 0
        new_missing = []
        for index, length, have in missing:
            k = j * 2 * index - shift
            shift += length - have
            piece = a[i][k:k + have]
            zeros = piece.count('0')
            ones = have - zeros
            l = j if length > j else length
            if zeros != l:
                new_missing.append((index << 1, l, zeros))
            l = length - l
            if ones != l:
                new_missing.append((index << 1 | 1, l, ones))
        missing = new_missing

    print(*[index for index, length, have in missing])
    input()
