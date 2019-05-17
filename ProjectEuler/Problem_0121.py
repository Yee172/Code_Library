# A bag contains one red disc and one blue disc.
# In a game of chance a player takes a disc at random
# and its colour is noted. After each turn the disc is
# returned to the bag, an extra red disc is added, and
# another disc is taken at random.
# The player pays £1 to play and wins if they have taken
# more blue discs than red discs at the end of the game.
# If the game is played for four turns, the probability
# of a player winning is exactly 11 / 120, and so the
# maximum prize fund the banker should allocate for winning
# in this game would be £10 before they would expect to
# incur a loss.
# Find the maximum prize fund that should be allocated
# to a single game in which fifteen turns are played.
# ----------------------------------------------------
# Analysis: dynamic programming

MAXN = 15
p, q = 0, 1
dp = [0] * (MAXN + 1)
dp[0] = 1

for i in range(1, MAXN + 1):
    q *= i + 1
    tmp = 0
    for j in range(i):
        dp[j], tmp = tmp + dp[j] * i, dp[j]
    dp[i] = 1

for j in range(MAXN // 2 + 1, MAXN + 1):
    p += dp[j]

print(q // p)
