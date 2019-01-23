# Find the sum of all numbers which are equal to the
# sum of the factorial of their digits.
# ----------------------------------------------------
# Analysis: brute force

factorial = [1]
for i in range(1, 10):
    factorial += [factorial[-1] * i]

print(sum(i for i in range(10, 50000) if sum(map(lambda x: factorial[int(x)], str(i))) == i))
