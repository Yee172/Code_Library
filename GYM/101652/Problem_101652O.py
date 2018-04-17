
while 1:
    try:
        n = int(input())
    except:
        break
    a = []
    isLatin = 1
    isreduced = 0
    char = dict(zip('0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ', range(36)))
    for i in range(n):
        a.append(list(map(lambda x: char[x], input())))
    for i in range(n):
        temp1 = [0] * n
        temp2 = [0] * n
        for j in range(n):
            if a[i][j] >= n:
                isLatin = 0
                break
            temp1[a[i][j]] = 1
            temp2[a[j][i]] = 1
        if not (all(temp1) and all(temp2)):
            isLatin = 0
        if not isLatin:
            break
    if not isLatin:
        print('No')
    else:
        isreduced = 1
        for i in range(n - 1):
            if a[0][i] > a[0][i + 1] or a[i][0] > a[i + 1][0]:
                isreduced = 0
                break
        if isreduced:
            print('Reduced')
        else:
            print('Not Reduced')
