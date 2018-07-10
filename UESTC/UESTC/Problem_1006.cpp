#include <iostream>
#include <cstring>
#define MAXN 1005
#define REP(start, end, step) for (int __i__ = (start); __i__ < (end); __i__ += (step))
#define fast ios::sync_with_stdio(false)
using namespace std;
int A[MAXN];
int dp[MAXN + 1];
int result[MAXN];


int main(int argc, char const *argv[])
{
    fast;
    int T;
    cin >> T;
    REP(0, T, 1)
    {
        int N;
        cin >> N;
        int i, j;
        int local_maximum;
        int maximum = 0;
        for (i = 0; i < N; i++)
        {
            cin >> A[i];
            local_maximum = 0;
            for (j = 0; j < i; j++)
                if (A[i] > A[j] && dp[j + 1] > local_maximum)
                    local_maximum = dp[j + 1];
            dp[i + 1] = local_maximum + 1;
            if (dp[i + 1] > maximum)
                maximum = dp[i + 1];
        }
        cout << maximum << " ";
        j = maximum;
        i = N - 1;
        while (j > 0)
        {
            if (dp[i + 1] == j)
            {
                result[j - 1] = A[i];
                j--;
            }
            i--;
        }
        for (j = 0; j < maximum; j++)
            cout << result[j] << " ";
        cout << endl;
    }
    return 0;
}
