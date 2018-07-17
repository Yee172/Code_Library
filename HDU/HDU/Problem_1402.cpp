#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define square(x) ((x) * (x))

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

namespace FFT
{
    typedef int TYPE;
    typedef long double db;
    const db PI = acosl(-1.0);

    struct cp
    {
        db real, image;
        cp() { real = image = 0.0; }
        cp(db real, db image) : real(real), image(image) {}
    };

    inline cp operator+(cp a, cp b) { return cp(a.real + b.real, a.image + b.image); }
    inline cp operator-(cp a, cp b) { return cp(a.real - b.real, a.image - b.image); }
    inline cp operator*(cp a, cp b)
    { return cp(a.real * b.real - a.image * b.image, a.real * b.image + a.image * b.real); }
    inline cp conjugate(cp a) { return cp(a.real, -a.image); }

    int base = 1;
    vector<cp> roots = {{0, 0}, {1, 0}};
    vector<int> rev = {0, 1};

    inline void set_base(int new_base)
    {
        if (new_base <= base) return;
        rev.resize(static_cast<unsigned long>(1 << new_base));
        roots.resize(static_cast<unsigned long>(1 << new_base));
        for (int i = 0; i < (1 << new_base); i++)
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << new_base - 1);
        while (base < new_base)
        {
            db theta = 2 * PI / (1 << base + 1);
            for (int i = 1 << base - 1; i < (1 << base); i++)
            {
                roots[i << 1] = roots[i];
                db theta_i = theta * (2 * i + 1 - (1 << base));
                roots[i << 1 | 1] = cp(cosl(theta_i), sinl(theta_i));
            }
            base++;
        }
    }

    inline void fft(vector<cp> &a, int size = -1)
    {
        if (size < 0) size = static_cast<int>(a.size());
        assert((size & size - 1) == 0);
        int zeros = __builtin_ctz(size);
        set_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < size; i++)
            if (i < (rev[i] >> shift))
                swap(a[i], a[rev[i] >> shift]);
        for (int k = 1; k < size; k <<= 1)
            for (int i = 0; i < size; i += 2 * k)
                for (int j = 0; j < k; j++)
                {
                    cp z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
    }

    vector<cp> fa;

    inline vector<TYPE> multiply(vector<TYPE> &a, vector<TYPE> &b)
    {
        int need = static_cast<int>(a.size() + b.size() - 1);
        int new_base = 0;
        for (; (1 << new_base) < need; new_base++);
        set_base(new_base);
        int size = 1 << new_base;
        if (size > static_cast<int>(fa.size())) fa.resize(static_cast<unsigned long>(size));
        for (int i = 0; i < size; i++)
        {
            db real = static_cast<db>(i < static_cast<int>(a.size()) ? a[i] : 0);
            db image = static_cast<db>(i < static_cast<int>(b.size()) ? b[i] : 0);
            fa[i] = cp(real, image);
        }
        fft(fa, size);
        cp r(0, -0.25 / size);
        for (int i = 0; i <= (size >> 1); i++)
        {
            int j = size - i & size - 1;
            cp z = (fa[j] * fa[j] - conjugate(fa[i] * fa[i])) * r;
            if (i != j) fa[j] = (fa[i] * fa[i] - conjugate(fa[j] * fa[j])) * r;
            fa[i] = z;
        }
        fft(fa, size);
        vector<TYPE> res(static_cast<unsigned long>(need));
        for (int i = 0; i < need; i++) res[i] = static_cast<TYPE>(fa[i].real + 0.5);
        return res;
    }
};

#define MAXN 50050
char s1[MAXN], s2[MAXN];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~ scanf("%s%s", s1, s2))
    {
        unsigned long l1 = strlen(s1), l2 = strlen(s2);
        vector<int> x(l1), y(l2);
        rep(i, l1) x[i] = s1[l1 - i - 1] - '0';
        rep(i, l2) y[i] = s2[l2 - i - 1] - '0';
        vector<int> res = FFT::multiply(x, y);
        int len = static_cast<int>(res.size());
        res.pb(0);
        rep(i, len) res[i + 1] += res[i] / 10, res[i] %= 10;
        for (; len >= 0 && !res[len]; len--);
        if (len < 0) puts("0");
        else
        {
            for (; ~len; len--) printf("%d", res[len]);
            puts("");
        }
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}
