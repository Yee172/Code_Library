# For this problem we shall allow the 6 or 9 to be
# turned upside-down.
# Rule:
#    {1, 2, 3, 4, 5, 6} is equivalent to {3, 6, 4, 1, 2, 5}
#    {1, 2, 3, 4, 5, 6} is distinct from {1, 2, 3, 4, 5, 9}
# How many distinct arrangements of the two cubes allow
# for all of the square numbers to be displayed?
# ----------------------------------------------------
# Analysis: brute force
#           Obviously, two same cubes are not possible

from itertools import combinations

need = ['01', '04', '09', '16', '25', '36', '49', '64', '81']

def check(cubes):
    for i, cube in enumerate(cubes):
        cube = set(cube)
        if '6' in cube or '9' in cube:
            cube.add('6')
            cube.add('9')
        cubes[i] = cube
    a, b = cubes
    for nd in need:
        x, y = nd
        if not (x in a and y in b or x in b and y in a):
            return False
    return True

print(sum(check([a, b]) for a, b in combinations(combinations('0123456789', 6), 2)))
