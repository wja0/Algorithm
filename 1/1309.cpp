#include <iostream>
using namespace std;
int D[100001][3];
// D[i] = i번째 줄에 배치
// D[i][0] = 한 마리도 배치하지 않는 경우
// D[i][1] = 1번줄에 배치
// D[i][2] = 2번줄에 배치
#define MOD 9901
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    D[0][0] = 1;
    D[0][1] = 1;
    D[0][2] = 1;
    for (int i = 1; i < n; i++)
    {
        D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % MOD;
        D[i][1] = (D[i - 1][0] + D[i - 1][2]) % MOD;
        D[i][2] = (D[i - 1][0] + D[i - 1][1]) % MOD;
    }
    cout << (D[n - 1][0] + D[n - 1][1] + D[n - 1][2]) % MOD;

    return 0;
}