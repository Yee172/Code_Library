# If (n_{1}, n_{2}, n_{3}) indicates a Nim position
# consisting of heaps of size n_{1}, n_{2} and n_{3}
# then there is a simple function X(n_{1}, n_{2}, n_{3})
# — that you may look up or attempt to deduce for yourself
# — that returns:
#    zero if, with perfect strategy, the player about to move will eventually lose; or
#    non-zero if, with perfect strategy, the player about to move will eventually win.
# For how many positive integers n \leq 2^{30} does
# X(n, 2 n, 3 n) = 0?
# ----------------------------------------------------
# Analysis: Nim game
#           We get that X(n, 2 n, 3 n) = 0 <=> n ^ (2 n) ^ (3 ^ n) = 0
#           Notice that n ^ (2 n) ^ (3 ^ n) = 0 iff there are at least one 0 between every two 1's the binary form of n
#           Then we could find that
#              for n \in [2^{k}, 2^{k + 1}), the number of n satisfies X(n, 2 n, 3 n) = 0
#              follows the Fibonacci sequence corresponding to k
#                 Hint: think this question from the perspective of dynamic programming

a, b = 0, 1
for i in range(31):
    a, b = b, a + b

print(b)
