# Consider quadratic Diophantine equations of the form:
#    x^{2} - D y^{2} = 1
# Find the value of D \leq 1000 in minimal solutions of
# x for which the largest value of x is obtained.
# ----------------------------------------------------
# Analysis: Pell equation
#           Related with Problem_0064

def get_minimum_positive_solution_of_Pell_equation(D):
    s = D ** .5
    p = 1
    q = int(s)
    if q ** 2 == D:
        return (1, 0)
    x, y, last_x, last_y = q, 1, 1, 0
    while True:
        t = int(p / (s - q))
        p, q = q, (D - q ** 2) // p
        p, q = q, q * t - p
        x, y, last_x, last_y = t * x + last_x, t * y + last_y, x, y
        if x ** 2 - D * y ** 2 == 1:
            break
    return (x, y)

print(max(range(2, 1001), key=get_minimum_positive_solution_of_Pell_equation))
