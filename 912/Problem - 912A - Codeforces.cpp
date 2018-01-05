#include <iostream>
#include <algorithm>
#define ll long long


using namespace std;
int main(int argc, char const *argv[])
{
    int _;
    ll A, B;
    cin >> A >> B;
    ll x, y, z;
    cin >> x >> y >> z;
    ll result = -1;
    ll rA, rB;
    int ___[3][2] = {{2, 0}, {1, 1}, {0, 3}};
    int ____[3] = {0, 1, 2};
    rA = x * ___[____[0]][0] + y * ___[____[1]][0] + z * ___[____[2]][0] - A;
    if (rA < 0)
        rA = 0;
    rB = x * ___[____[0]][1] + y * ___[____[1]][1] + z * ___[____[2]][1] - B;
    if (rB < 0)
        rB = 0;
    result = rA + rB;
    cout << result;
    return 0;
}
