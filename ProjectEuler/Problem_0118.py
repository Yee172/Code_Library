# Using all of the digits 1 through 9 and concatenating
# them freely to form decimal integers, different sets
# can be formed. Interestingly with the set {2,5,47,89,631},
# all of the elements belonging to it are prime.
# How many distinct sets containing each of the digits one
# through nine exactly once contain only prime elements?
# ----------------------------------------------------
# Analysis: brute force

from itertools import permutations
from lib.prime_sieve import prime_sieve

is_prime, _ = prime_sieve(10 ** 7, False, function_is_prime=True)
set_counter = [0] * 10
p = ()

def dfs(index, current_number, number_counter):
    current_number = current_number * 10 + p[index]
    index += 1
    if index == 9:
        set_counter[number_counter] += is_prime(current_number)
    else:
        dfs(index, current_number, number_counter)
        if is_prime(current_number):
            dfs(index, 0, number_counter + 1)

for p in permutations([i for i in range(1, 10)]):
    dfs(0, 0, 1)

result = 0
multiple = 1
for i in range(1, 10):
    multiple *= i
    result += set_counter[i] // multiple

print(result)
