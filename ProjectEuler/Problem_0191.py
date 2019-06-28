# A particular school offers cash rewards to children
# with good attendance and punctuality. If they are
# absent for three consecutive days or late on more
# than one occasion then they forfeit their prize.
# During an n-day period a trinary string is formed for
# each child consisting of L's (late), O's (on time),
# and A's (absent).
# Although there are eighty-one trinary strings for a
# 4-day period that can be formed, exactly forty-three
# strings would lead to a prize:
#    OOOO OOOA OOOL OOAO ...
# How many "prize" strings exist over a 30-day period?
# ----------------------------------------------------
# Analysis: matrix multiplication
#           0 0 1 0 0 0 0  last is A  without L
#           1 0 0 0 0 0 0  last is AA without L
#           1 1 1 0 0 0 0  last is O  without L
#           1 1 1 0 0 0 0  last is L
#           0 0 0 1 0 0 1  last is A     with L
#           0 0 0 0 1 0 0  last is AA    with L
#           0 0 0 1 1 1 1  last is O     with L
#           Since the third row and the forth row are the same,
#           it also can be reduced to a 6 \times 6 matrix with
#           the last summation use 1 0 2 0 0 0 weight

from lib.matrix import Matrix

target = 30

state_transfer = Matrix(7)
state_transfer[0][2] = 1
state_transfer[1][0] = 1
state_transfer[2][0] = 1
state_transfer[2][1] = 1
state_transfer[2][2] = 1
state_transfer[3][0] = 1
state_transfer[3][1] = 1
state_transfer[3][2] = 1
state_transfer[4][3] = 1
state_transfer[4][6] = 1
state_transfer[5][4] = 1
state_transfer[6][3] = 1
state_transfer[6][4] = 1
state_transfer[6][5] = 1
state_transfer[6][6] = 1
multi_transfer = state_transfer ** target

print(sum(multi_transfer[i][2] for i in range(7)))
