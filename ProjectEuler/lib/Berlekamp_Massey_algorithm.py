MOD = 0x3b9aca07

def Berlekamp_Massey_algorithm(x, **kwargs):
    modulo = kwargs.get('modulo', 0)
    recursion = []
    last_fail_state = []
    for i in range(len(x)):
        expectation_delta = -x[i]
        if modulo:
            expectation_delta %= modulo
        for j, r in enumerate(recursion):
            expectation_delta += x[i - j - 1] * r
            if modulo:
                expectation_delta %= modulo
        if -1e-8 < expectation_delta < 1e-8:
            continue
        if not len(recursion):
            recursion = [0] * (i + 1)
            fail = i
            delta = expectation_delta
            continue
        if modulo:
            multiple = -expectation_delta * pow(delta, modulo - 2, modulo) % modulo
        else:
            multiple = -expectation_delta / delta
        change = [0] * (i - fail - 1) + [-multiple]
        for r in last_fail_state:
            addition = r * multiple
            if modulo:
                addition %= modulo
            change.append(addition)
        if len(change) < len(recursion):
            change += [0] * (len(recursion) - len(change))
        for j, r in enumerate(recursion):
            change[j] += r
            if modulo:
                change[j] %= modulo
        if i - fail + len(last_fail_state) >= len(recursion):
            last_fail_state = recursion
            fail = i
            delta = expectation_delta
        recursion = change
    return recursion
