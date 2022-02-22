#include <iostream>
using namespace std;
// D[N][i] : N자리에 온 숫자 i (0 <= i <= 9)
// D[N][0] = D[N-1][0];
// D[N][2] = D[N-1][0] + D[N-1][1] + D[N-1][2];
#define MOD 10007;
int D[1002][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0)
            {
                D[i][j] = 1;
                continue;
            }
            for (int l = 0; l <= j; l++)
            {
                D[i][j] += D[i - 1][l] % MOD;
            }
        }
    }
    cout << (D[n - 1][0] + D[n - 1][1] + D[n - 1][2] + D[n - 1][3] + D[n - 1][4] + D[n - 1][5] + D[n - 1][6] + D[n - 1][7] + D[n - 1][8] + D[n - 1][9]) % MOD;
    return 0;
}