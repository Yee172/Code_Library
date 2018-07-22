from queue import Queue
from collections import defaultdict
adjacent = ((1, 2, 4, 8),
            (0, 3, 5, 9),
            (0, 3, 6, 10),
            (1, 2, 7, 11),
            (0, 5, 6, 12),
            (1, 4, 7, 13),
            (2, 4, 7, 14),
            (3, 5, 6, 15),
            (0, 9, 10, 12),
            (1, 8, 11, 13),
            (2, 8, 11, 14),
            (3, 9, 10, 15),
            (4, 8, 13, 14),
            (5, 9, 12, 15),
            (6, 10, 12, 15),
            (7, 11, 13, 14))
step = defaultdict(int)
start_condition = 0b11111111 << 8
q = Queue()
q.put((start_condition, 0))
while not q.empty():
    now_condition, now_step = q.get()
    if now_step > 3:
        break
    if now_condition in step:
        continue
    step[now_condition] = now_step
    for i in range(16):
        state_i = (now_condition >> i) & 1
        for j in range(4):
            state_j = (now_condition >> adjacent[i][j]) & 1
            if state_i ^ state_j:
                next_condition = now_condition ^ (1 << i) ^ (1 << adjacent[i][j])
                q.put((next_condition, now_step + 1))

n = int(input())
case = 1
for l in __import__('sys').stdin.readlines():
    a = int('0b' + ''.join(l.split())[::-1], 2)
    print('Case #%d:' % case, step[a] if a in step else 'more')
    case += 1
    if case > n:
        break
