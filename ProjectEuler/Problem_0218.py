# We will call a right angled triangle perfect if
#    1. it is a primitive right angled triangle
#    2. its hypotenuse is a perfect square
# We will call a right angled triangle super-perfect if
#    1. it is a perfect right angled triangle and
#    2. its area is a multiple of the perfect numbers 6 and 28
# How many perfect right-angled triangles with c \leq 10^{16}
# exist that are not super-perfect?
# ----------------------------------------------------
# Analysis: Euclid's formula
#           a = m^{2} - n^{2}, b = 2 m n, c = m^{2} + n^{2}
#           form a Pythagorean triple, where m > n > 0
#           The triple generated by Euclid's formula is primitive
#           if and only if m and n are coprime and not both odd
#           Since c should be a perfect square, we know that
#           m^{2} + n^{2} = k^{2}, which formed another primitive
#           Pythagorean triple
#           Let m = x^{2} - y^{2}, n = 2 x y, where x > y > 0,
#           x and y are coprime and not both odd
#           Thus, the area of a perfect right angled triangle has
#           the form of S = a b / 2 = 2 x y (x^{2} - y^{2}) (x^{4} + y^{4} - 6 x^{2} y^{2})
#           If we want S is a multiple of 6 and 28, we only need
#           S % 3 = 0, S % 4 = 0 and S % 7 = 0
#           Since x and y are not both odd, we can easily see that
#           S % 3 = 0 and S % 4 = 0
#           Now we only need to check whether S % 7 = 0
#           x \ y  1  2  3  4  5
#             2    0
#             3    0  0
#             4    0  0  0
#             5    0  0  0  0
#             6    0  0  0  0  0
#           Therefore, all perfect right angled triangles are super-perfect right angled triangles

print(0)