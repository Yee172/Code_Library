# A hexagonal orchard of order n is a triangular lattice
# made up of points within a regular hexagon with side n.
# The following is an example of a hexagonal orchard of order 5:
#                 . . . . . .
#                . . . . . . .
#               . . . . . . . .
#              . . . . . . . . .
#             . . . . . . . . . .
#            . . . . . . . . . . .
#             . . . . . . . . . .
#              . . . . . . . . .
#               . . . . . . . .
#                . . . . . . .
#                 . . . . . .
# Let H(n) be the number of points hidden from the center
# in a hexagonal orchard of order n.
# Find H(100000000).
# ----------------------------------------------------
# Analysis: sieve of Dujiao
#           Hint: Take one sixth of the hexagon
#                              .
#                            .  .
#                          .  .\ .
#                        .  .\ .\ .
#                      .  .\ .\ .\ .
#           center ->.  .\ .\ .\ .\ .
#                        1  2  3  4  5
#           Then we get
#                                              .
#                                         .   1/5
#                                    .   1/4\  2/5
#                               .   1/3\  2/4\  3/5
#                          .   1/2\  2/3\  3/4\  4/5
#           center -> .   1/1\  2/2\  3/3\  4/4\  5/5
#           Obviously, the visible points can be counted by the summation of phi function

from lib.phi_sum import phi_sum

target = 10 ** 8
print(6 * (target * (target + 1) // 2 - phi_sum(target)))
