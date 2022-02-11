#include <iostream>
using namespace std;
#define MOD 1000000007
long long D[1002][1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    D[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i - 1 > 0)
            {
                D[i][j] += D[i - 1][j] % MOD;
            }
            if (j - 1 > 0)
            {
                D[i][j] += D[i][j - 1] % MOD;
            }
            if (i - 1 > 0 && j - 1 > 0)
            {
                D[i][j] += D[i - 1][j - 1] % MOD;
            }
        }
    }
    cout << D[n][m] % MOD;
    return 0;
}