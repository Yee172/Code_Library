# Using a combination of grey square tiles and oblong
# tiles chosen from: red tiles (measuring two units),
# green tiles (measuring three units), and blue tiles
# (measuring four units).
# How many ways can a row measuring fifty units in length be tiled?
# ----------------------------------------------------
# Analysis: dynamic programming

n = 50

dp = [1, 1, 2, 4]
for i in range(4, n + 1):
    dp.append(dp[-1] + dp[-2] + dp[-3] + dp[-4])

print(dp[n])
