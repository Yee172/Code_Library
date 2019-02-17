# By listing the set of reduced proper fractions for
# d \leq 1000000 in ascending order of size, find the
# numerator of the fraction immediately to the left
# of 3 / 7.
# ----------------------------------------------------
# Analysis: brute force

print('Generating partition number...')
MAXN = 200

def pentagon_number(n):
    return 3 * n * n - n >> 1

pentagon = [0] * MAXN;
dp_add = [False] * MAXN;
partition_number = [0] * MAXN;
pentagon[0] = 0
dp_add[0] = False
i, j, k = 1, 1, 2
while True:
    pentagon[j] = pentagon_number(i)
    pentagon[k] = pentagon[j] + i;
    dp_add[k] = dp_add[j] = i & 1;
    if pentagon[k] > MAXN:
        break
    i += 1
    j += 2
    k += 2
partition_number[0] = 1
for i in range(1, MAXN):
    j = 1
    while True:
        if pentagon[j] > i:
            break
        if dp_add[j]:
            partition_number[i] += partition_number[i - pentagon[j]]
        else:
            partition_number[i] -= partition_number[i - pentagon[j]]
        j += 1
print('Partition number generated successfully.')

print(partition_number[100] - 1)
