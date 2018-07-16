from queue import Queue
move = [[-2, -1], [-2, 1], [-1, -2], [-1, 2], [2, 1], [2, -1], [1, 2], [1, -2]]
for l in __import__('sys').stdin.readlines():
    st, ed = map(lambda s: (ord(s[0]) - 96, int(s[1])), l.split())
    q = Queue()
    vis = [[0] * 9 for i in range(9)]
    q.put((*st, 0))
    while not q.empty():
        x, y, t = q.get()
        if x == ed[0] and y == ed[1]:
            break
        if vis[x][y]:
            continue
        vis[x][y] = 1
        for dx, dy in move:
            if 0 < x + dx < 9 and 0 < y + dy < 9:
                q.put((x + dx, y + dy, t + 1))
    print('To get from %s to %s takes %d knight moves.' % (*l.split(), t))
