def f(n, op):
    if n == 2:
        return op + 2
    x = n + 1 >> 1
    return f((1 + 2 * (n & 1)) * x - (n & 1), op + 2 * x) 
print(f(int(input()), 0))
