# Working from left-to-right if no digit is exceeded by
# the digit to its left it is called an increasing number;
#    for example, 134468.
# Similarly, we define decreasing number.
# We shall call a positive integer that is neither
# increasing nor decreasing a "bouncy" number;
#    for example, 155349.
# Find the least number for which the proportion of bouncy
# numbers is exactly 99%.
# ----------------------------------------------------
# Analysis: brute force

res = bouncy_cnt = 0
while 100 * bouncy_cnt != 99 * res or not res:
    res += 1
    s = str(res)
    q = ''.join(sorted(s))
    if q != s and q != s[::-1]:
        bouncy_cnt += 1

print(res)
