#include <iostream>
using namespace std;
#define MOD 1000000000
long long D[102][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    D[1][1] = D[1][2] = D[1][3] = D[1][4] = D[1][5] = D[1][6] = D[1][7] = D[1][8] = D[1][9] = 1;
    for (int i = 2; i <= n; i++)
    {
        D[i][0] = (D[i - 1][1]) % MOD;
        D[i][1] = (D[i - 1][0] + D[i - 1][2]) % MOD;
        D[i][2] = (D[i - 1][1] + D[i - 1][3]) % MOD;
        D[i][3] = (D[i - 1][2] + D[i - 1][4]) % MOD;
        D[i][4] = (D[i - 1][3] + D[i - 1][5]) % MOD;
        D[i][5] = (D[i - 1][4] + D[i - 1][6]) % MOD;
        D[i][6] = (D[i - 1][5] + D[i - 1][7]) % MOD;
        D[i][7] = (D[i - 1][6] + D[i - 1][8]) % MOD;
        D[i][8] = (D[i - 1][7] + D[i - 1][9]) % MOD;
        D[i][9] = (D[i - 1][8]) % MOD;
    }
    cout << (D[n][0] + D[n][1] + D[n][2] + D[n][3] + D[n][4] + D[n][5] + D[n][6] + D[n][7] + D[n][8] + D[n][9]) % MOD;
    return 0;
}
// 혼자 성공

// 해설
// D[n][L] = 길이가 N인 계단수, 마지막 수 L
// 인접한 수 : 연속한 수를 의미
// N번째 수가 L인 계단수의 N-1번째에 들어갈 수는 L-1과 L+1임
// 예외 : L = 0인 경우와 L = 9경우는 1 또는 8로 하나씩만 인접해서 들어올 수 있음
