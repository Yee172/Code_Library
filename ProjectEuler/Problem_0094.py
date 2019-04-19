# We shall define an almost equilateral triangle to be
# a triangle for which two sides are equal and the third
# differs by no more than one unit.
# Find the sum of the perimeters of all almost equilateral
# triangles with integral side lengths and area and whose
# perimeters do not exceed one billion.
# ----------------------------------------------------
# Analysis: brute force
#           Consider two types of equilateral triangle: 3 a + 1 and 3 a - 1
#           Notice that 3 n^{2} - 4 = m^{2} has no integer solution
#              while 3 n^{2} + 4 = m^{2} has integer solutions
#           Hint: square of an integer % 3 = 0 or 1, but can not be 2

upper_limit = 10 ** 9
print(sum(3 * n ** 2 + 4 for n in range(2, int(((upper_limit - 4) / 3) ** .5) + 1, 2) if int((3 * n ** 2 + 4) ** .5) ** 2 == 3 * n ** 2 + 4) + sum(6 * n ** 2 - 4 for n in range(2, int(((upper_limit + 4) / 6) ** .5) + 1) if int((3 * n ** 2 - 2) ** .5) ** 2 == 3 * n ** 2 - 2))
