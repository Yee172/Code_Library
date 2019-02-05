# Find the sum of the only ordered set of six cyclic
# 4-digit numbers for which each polygonal type:
# triangle, square, pentagonal, hexagonal, heptagonal,
# and octagonal, is represented by a different number
# in the set.
# ----------------------------------------------------
# Analysis: brute force

from math import sqrt

def is_polygonal_number(n):
    x = 2 * n
    y = int(sqrt(x))
    if y * (y + 1) == x:
        yield 3
    if int(sqrt(n)) ** 2 == n:
        yield 4
    y = int(sqrt(x / 3)) + 1
    if y * (3 * y - 1) == x:
        yield 5
    y = int(sqrt(n / 2)) + 1
    if y * (2 * y - 1) == n:
        yield 6
    y = int(sqrt(x / 5)) + 1
    if y * (5 * y - 3) == x:
        yield 7
    y = int(sqrt(n / 3)) + 1
    if y * (3 * y - 2) == n:
        yield 8

polygonal_type_list = dict()
for n in range(1001, 10000):
    type_list = list(is_polygonal_number(n))
    if type_list:
        polygonal_type_list[n] = type_list

def check(cyclic_list):
    polygonal_type = list(map(lambda n: polygonal_type_list[n], cyclic_list))
    if check_dfs(polygonal_type, 0, []):
        print('cyclic set:', cyclic_list, 'sum:', sum(cyclic_list))
        exit()

def check_dfs(polygonal_type, index, existed_list):
    if index == 6:
        if len(set(existed_list)) == 6:
            return True
        return False
    return any(check_dfs(polygonal_type, index + 1, existed_list + [t]) for t in polygonal_type[index])

def dfs(cyclic_list):
    if len(cyclic_list) == 5:
        last = cyclic_list[-1] % 100 * 100 + cyclic_list[0] // 100
        if last not in cyclic_list and last in polygonal_type_list:
            cyclic_list.append(last)
            check(cyclic_list)
        return
    head = cyclic_list[-1] % 100 * 100
    for tail in range(10, 100):
        add = head + tail
        if add not in cyclic_list and add in polygonal_type_list:
            dfs(cyclic_list + [add])

for n in polygonal_type_list:
    if n % 100 > 9:
        dfs([n])
