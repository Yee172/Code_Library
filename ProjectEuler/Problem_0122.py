# We shall define m(k) to be the minimum number of
# multiplications to compute n^{k}.
# for example m(15) = 5.
# For 1 \leq k \leq 200, find \sum m(k).
# ----------------------------------------------------
# Analysis: brute force

import numba as nb

@nb.njit
def bfs(n):
    if n < 2:
        return 0
    q = [(1, -1)]
    head = 0
    while head < len(q):
        value = q[head][0]
        previous = head
        while not previous == -1:
            next_value = value + q[previous][0]
            if next_value == n:
                count = 0
                previous = head
                while previous != -1:
                    previous = q[previous][1]
                    count += 1
                return count
            if next_value < n:
                q.append((next_value, head))
            previous = q[previous][1]
        head += 1

print(sum(map(bfs, range(201))))
