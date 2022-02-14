#include <iostream>
using namespace std;
// 합분해
// 문제에서 정해야하는 것 그대로 옮겨서 점화식 정의가 구해지는 경우가 많음
// D[K][N] = 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
// 마지막에 온 수가 L인 경우 (N-L의 합)(k-1개) + L = N
// D[K][N] = add(D[K-1][N-L])
// N까지 K개의 합 == (N-L까지 K-1개의 합) L이 N개까지 고려
// 0 <= L <= N (0부터 N까지의 정수)
// 시간 복잡도 : O(KN)XN = O(KN^2) (L의 경우의 수는 N)
#define MOD 1000000000;
long long D[202][202];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            for (int l = 0; l <= j; l++) // n까지하면 j-l이 음수가 될 수 도 있음
            {
                if (i == 1)
                {
                    D[i][j] = 1ll;
                }
                else
                {
                    D[i][j] += D[i - 1][j - l];
                    D[i][j] %= MOD;

                    // n-l이 아니라 j-l이여야 j까지의 합이 되는 경우만 구하지
                }
                // for 문이 2개면 3개 이상의 정수를 합할때 0만 더한다.
            }
        }
    }
    cout << D[k][n] % MOD;
    return 0;
}