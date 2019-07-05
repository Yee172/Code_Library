from extended_gcd import inverse
from context_manager_lib import timer

class LinearRecursion:
    '''linear recursion
    
    Berlekamp Massey Algorithm implement
    
    Variables:
        EPS {number} -- epsilon
    '''
    class Polynomial:
        '''polynomial
        
        specific polynomial class set for the linear recursion
        '''

        RECURSION = []
        MODULO = 0

        def __init__(self, polynomial):
            self.polynomial = polynomial
            self.n = len(polynomial)

        def __getitem__(self, item):
            return self.polynomial[item]

        def __mul__(self, another):
            if LinearRecursion.Polynomial.MODULO:
                return self.__mul_modulo(another)
            else:
                return self.__mul_normal(another)

        def __mul_normal(self, another):
            r = [0] * (self.n + another.n - 1)
            for i, x in enumerate(self.polynomial):
                if x:
                    for j, y in enumerate(another.polynomial):
                        r[i + j] += x * y
            for i in range(self.n + another.n - 2, self.n - 1, -1):
                if r[i]:
                    for j in range(self.n - 1, -1, -1):
                        r[i - j - 1] += r[i] * LinearRecursion.Polynomial.RECURSION[j]
            return LinearRecursion.Polynomial(r[:self.n])

        def __mul_modulo(self, another):
            r = [0] * (self.n + another.n - 1)
            for i, x in enumerate(self.polynomial):
                if x:
                    for j, y in enumerate(another.polynomial):
                        r[i + j] += x * y
                        r[i + j] %= LinearRecursion.Polynomial.MODULO
            for i in range(self.n + another.n - 2, self.n - 1, -1):
                if r[i]:
                    for j in range(self.n - 1, -1, -1):
                        r[i - j - 1] += r[i] * LinearRecursion.Polynomial.RECURSION[j]
                        r[i - j - 1] %= LinearRecursion.Polynomial.MODULO
            return LinearRecursion.Polynomial(r[:self.n])

        def __str__(self):
            return str(self.polynomial)

    EPS = 1e-8

    def __init__(self, initial_value, **kwargs):
        self.initial_value = initial_value
        self.recursion = []
        self.modulo = kwargs.get('modulo', 0)
        self.is_processed = False

    def __getitem__(self, item):
        return self.__get_value_by_index(item)

    def get_recursion(self):
        if self.modulo:
            return self.__get_recursion_modulo()
        else:
            return self.__get_recursion_normal()

    def __get_recursion_normal(self):
        last_fail_state = []
        for i in range(len(self.initial_value)):
            expectation_delta = -self.initial_value[i]
            for j, r in enumerate(self.recursion):
                expectation_delta += self.initial_value[i - j - 1] * r
            if -LinearRecursion.EPS < expectation_delta < LinearRecursion.EPS:
                continue
            if not len(self.recursion):
                self.recursion = [0] * (i + 1)
                fail = i
                delta = expectation_delta
                continue
            multiple = -expectation_delta / delta
            change = [0] * (i - fail - 1) + [-multiple]
            for r in last_fail_state:
                addition = r * multiple
                change.append(addition)
            if len(change) < len(self.recursion):
                change += [0] * (len(self.recursion) - len(change))
            for j, r in enumerate(self.recursion):
                change[j] += r
            if i - fail + len(last_fail_state) >= len(self.recursion):
                last_fail_state = self.recursion
                fail = i
                delta = expectation_delta
            self.recursion = change
        self.is_processed = True
        return self.recursion

    def __get_recursion_modulo(self):
        last_fail_state = []
        for i in range(len(self.initial_value)):
            expectation_delta = -self.initial_value[i] % self.modulo
            for j, r in enumerate(self.recursion):
                expectation_delta += self.initial_value[i - j - 1] * r
                expectation_delta %= self.modulo
            if not expectation_delta:
                continue
            if not len(self.recursion):
                self.recursion = [0] * (i + 1)
                fail = i
                delta = expectation_delta
                continue
            multiple = -expectation_delta * inverse(delta, self.modulo) % self.modulo
            change = [0] * (i - fail - 1) + [-multiple]
            for r in last_fail_state:
                addition = r * multiple % self.modulo
                change.append(addition)
            if len(change) < len(self.recursion):
                change += [0] * (len(self.recursion) - len(change))
            for j, r in enumerate(self.recursion):
                change[j] += r
                change[j] %= self.modulo
            if i - fail + len(last_fail_state) >= len(self.recursion):
                last_fail_state = self.recursion
                fail = i
                delta = expectation_delta
            self.recursion = change
        self.is_processed = True
        return self.recursion

    def __get_value_by_index(self, index):
        if not self.is_processed:
            self.get_recursion()
        n = len(self.recursion)
        r, t = [0] * n, [0] * n
        r[0] = 1
        if n == 1:
            t[0] = R[0]
        else:
            t[1] = 1
        LinearRecursion.Polynomial.RECURSION = self.recursion
        LinearRecursion.Polynomial.MODULO = self.modulo
        with timer():
            r, t = LinearRecursion.Polynomial(r), LinearRecursion.Polynomial(t)
            while index:
                print(index)
                if index & 1:
                    r *= t
                t *= t
                index >>= 1
        result = sum(map(lambda i: r[i] * self.initial_value[i], range(len(self.recursion))))
        if self.modulo:
            result %= self.modulo
        return result
