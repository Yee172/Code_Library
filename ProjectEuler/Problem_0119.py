# The number 512 is interesting because it is equal to
# the sum of its digits raised to some power:
#    5 + 1 + 2 = 8, and 8^{3} = 512.
# We shall define a_{n} to be the nth term of this sequence
# and insist that a number must contain at least two
# digits to have a sum.
# You are given that a_{2} = 512.
# Find a_{30}. 
# ----------------------------------------------------
# Analysis: brute force

target = 30
buffer_size = target * 2
res = set()
base = 2
while len(res) < buffer_size:
    p = 1
    while True:
        p *= base
        s = str(p)
        if len(s) < 2:
            continue
        if len(s) > base:
            break
        if sum(map(int, s)) == base:
            res.add(p)
    base += 1
            
print(sorted(res)[target - 1])
