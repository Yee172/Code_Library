# If a box contains twenty-one coloured discs, composed
# of fifteen blue discs and six red discs, and two discs
# were taken at random, it can be seen that the probability
# of taking two blue discs,
#    P(BB) = (15 / 21) \times (14 / 20) = 1 / 2.
# By finding the first arrangement to contain over 10^{12} 
# discs in total, determine the number of blue discs
# that the box would contain.
# ----------------------------------------------------
# Analysis: brute force
#           A011900 - OEIS and A046090 - OEIS

LOWER_BOUND = 10 ** 12

a, b, c, d = 1, 3, 1, 4
while d <= LOWER_BOUND:
    a, b, c, d = b, 6 * b - a - 2, d, 6 * d - c - 2

print(b)
