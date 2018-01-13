#include <iostream>
#include <iomanip>
#include <algorithm>
#define ll long long


using namespace std;
int main(int argc, char const *argv[])
{
    ll _, __;
    ll n, m, r, k;
    cin >> n >> m >> r >> k;
    if (n == 1 || m == 1)
    {
        cout << setprecision(12) << (k / (double)(n * m)) << endl;
        return 0;
    }
    double div = (double)((n - r + 1) * (m - r + 1));
    ll fac = 0;
    ll start = (r - 1) * (r - 1);
    ll corner = 4 * start;
    ll contour = ((n - 2 * r + 2) + (m - 2 * r + 2)) * 2;
    contour = contour > 0 ? contour : 0;
    ll inside = n * m - corner - contour;
    inside = inside > 0 ? inside : 0;
    if (corner > n * m)
    {
        corner = n * m;
        start = corner / 4;
    }
    if (inside >= k)
    {
        fac += k * r * r;
        k = 0;
    }
    else
    {
        fac += inside * r * r;
        k -= inside;
        if (contour >= k)
        {
            __ = r - 1;
            for (_ = contour / (r - 1); _ > 0; _--)
            {
                if (contour >= k)
                {
                    fac += k * r * __;
                    k = 0;
                    break;
                }
                else
                {
                    fac += _ * r * __;
                    k -= _;
                    __--;
                }
            }
        }
        else
        {
            fac += contour * r * r / 2;
            k -= contour;
            int * c = new int[(r - 1) * (r - 1)];
            for (_ = 0; _ < r - 1; _++)
                c[_] = (int)_ + 1;
            for (_ = 0; _ < r - 1; _++)
                for (__ = 0; __ < r - 1; __++)
                    c[r * _ + __] = (int)(_ + 1) * c[__];
            sort(c, c + (r - 1) * (r - 1));
            __ = start - 1;
            while (k >= 4)
            {
                fac += 4 * c[__];
                k -= 4;
                __--;
            }
            fac += k * c[__];
        }
    }
    cout << setprecision(12) << fac / div << endl;

    return 0;
}
