#include <iostream>
#define ll long long


using namespace std;
int main(int argc, char const *argv[])
{
    ll n, k, result = 1;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n << endl;
        return 0;
    }
    else
    {
        while (n != 1)
        {
            n /= 2;
            result *= 2;
        }
        cout << result * 2 - 1 << endl;
    }
    return 0;
}
