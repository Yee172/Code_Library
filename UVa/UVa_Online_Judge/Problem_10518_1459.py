class Matrix():
    mod = 0x3b9aca07

    def __init__(self, n):
        self.n = n
        self.a = [[0] * n for _ in range(n)]

    def __mul__(self, b):
        res = Matrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    res.a[i][j] += self.a[i][k] * b.a[k][j] % Matrix.mod
                    res.a[i][j] %= Matrix.mod
        return res

    def __pow__(self, e):
        res = Matrix(self.n)
        for i in range(self.n):
            res.a[i][i] = 1
        tmp = self
        while e:
            if e & 1:
                res = res * tmp
            e >>= 1
            tmp = tmp * tmp
        return res

    def __str__(self):
        return str(self.a)

o = Matrix(3)
o.a[0][0] = 1
o.a[0][1] = 1
o.a[0][2] = 1
o.a[1][0] = 1
o.a[2][2] = 1
case = 1
while 1:
    n, b = map(int, input().split())
    if b:
        r = 'Case %d: %d %d ' % (case, n, b)
        case += 1
        if n < 2:
            r += '1'
            print(r)
            continue
        Matrix.mod = b
        ans = o ** (n - 1)
        r += str((ans.a[0][0] + ans.a[0][1] + ans.a[0][2]) % b)
        print(r)
    else:
        break
