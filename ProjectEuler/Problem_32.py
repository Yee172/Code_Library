# Find the sum of all products whose
# multiplicand/multiplier/product identity can be
# written as a 1 through 9 pandigital.
# ----------------------------------------------------
# Analysis: brute force

print(sum(set(a * b for a in range(2, 50) for b in range(2, 2000) if ''.join(sorted(str(a) + str(b) + str(a * b))) == '123456789')))
