def bits_sum(n):
    return sum(n >> i & 1 for i in range(21))
mod = pow(2, 20)
def next(x):
    x = 487237 * x + 1011807
    x %= mod
    return x
def gen(x):
    return 2 * (bits_sum(x) & 1) - 1
y = [gen(i) for i in range(mod)]
possible = [i for i in range(mod)]
last = 160
nok = 1
while 1:
    money = int(input())
    if money == -1:
        break
    if nok:
        det = money - last
        if det:
            possible = [next(x) for x in possible if y[x] == det]
        if len(possible) == 1:
            nok = 0
            x = possible[0]
        print(1)
        last = money
        continue
    x = next(x)
    if gen(x) == 1:
        print(min(money, 200 - money))
    else:
        print(1)
        