# Dave is doing his homework on the balcony and, preparing
# a presentation about Pythagorean triangles, has just cut
# out a triangle with side lengths 30cm, 40cm and 50cm from
# some cardboard, when a gust of wind blows the triangle
# down into the garden.
# Another gust blows a small ant straight onto this triangle.
# The poor ant is completely disoriented and starts to crawl
# straight ahead in random direction in order to get back
# into the grass.
# Assuming that all possible positions of the ant within
# the triangle and all possible directions of moving on
# are equiprobable, what is the probability that the ant
# leaves the triangle along its longest side?
# Give your answer rounded to 10 digits after the decimal point.
# ----------------------------------------------------
# Analysis: integral
#             \frac{\int_{0}^{leg2} \int_{0}^{leg1 - \frac{leg1}{leg2} * y} 2 * \pi - (\frac{\pi}{2} + \arctan(\frac{leg2 - y}{x}) + \arctan(\frac{leg1 - x}{y})) dx dy}{leg1 * leg2 * \pi}
#           = \frac{3}{4} - \frac{(leg1^{2} + leg2^{2}) * \ln(leg1^{2} + leg2^{2}) + 2 * leg1 * leg2 * (\arctan(\frac{leg1}{leg2}) + \arctan(\frac{leg2}{leg1})) - 2 * (leg1^{2} * \ln(leg1) + leg2^{2} * \ln(leg2))}{4 * leg1 * leg2 * \pi}

from math import log, atan, pi

leg1 = 30
leg2 = 40

alpha1 = (leg1 ** 2 * log(leg1 ** 2 + leg2 ** 2) + 2 * leg1 * leg2 * atan(leg1 / leg2) - 2 * leg1 ** 2 * log(leg1)) / 4
alpha2 = (leg2 ** 2 * log(leg1 ** 2 + leg2 ** 2) + 2 * leg1 * leg2 * atan(leg2 / leg1) - 2 * leg2 ** 2 * log(leg2)) / 4

print(round(0.75 - (alpha1 + alpha2) / (leg1 * leg2 * pi), 10))
