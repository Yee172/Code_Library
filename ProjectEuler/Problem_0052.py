# Find the smallest positive integer, x, such that 2x,
# 3x, 4x, 5x, and 6x, contain the same digits.
# ----------------------------------------------------
# Analysis: brute force
#           It is easy to associate this problem with 1 / 7,
#           which means the up limit is 142857 definitely.

for i in range(11, 142857):
    s = sorted(str(i))
    flag = True
    for j in range(2, 7):
        flag &= sorted(str(i * j)) == s
    if flag:
        print(i)
        break
else:
    print(142857)
