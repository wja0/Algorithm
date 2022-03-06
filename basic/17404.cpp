#include <iostream>
using namespace std;
// 첫집과 마지막집도 이웃 : 원형 문제 => 직선으로 해결한 뒤 원형으로 해결 시도
// D[i][j] = i번 집을 색 j로 칠했을 때, 1~i번 집을 칠하는 비용의 최소값
// j = 0 Red / j = 1 Green / j = 2 Blue
// 원형 : 첫집과 마지막집에 문제 존재.
// 1번집의 색을 고정하고 문제를 푼다.
// 6가지 경우 존재 (R,G / R,B / G,R / G,B / B,R / B,G)
int a[1002][4];
int d[1002][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int ans = 1000 * 1000 + 1;
    // D[i][j] = i번 집을 색 j로 칠했을 때, 1~i번 집을 칠하는 비용의 최소값
    for (int k = 0; k <= 2; k++) // 첫 집 고정
    {
        for (int j = 0; j <= 2; j++)
        {
            if (j == k)
            {
                // 1번집 색상 고정 초기화 (시작 부분)
                d[1][j] = a[1][j]; // R, G, B
            }
            else
            {
                d[1][j] = 1000 * 1000 + 1;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            // R일때 내 앞에 있는 집에 올 수 있는 색들 중 비용 최소값
            // + 이번 집을 칠할 때 사용하는 비용값
            d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
            // G일때
            d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
            // B일때
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
        }
        // n 번째 집에 칠할 때 빨강 파랑 초록 중에 뭐가 제일 최소인가
        for (int j = 0; j <= 2; j++)
        {
            // 이때 1번집과 달라야 한다.
            if (j == k)
                continue;
            ans = min(ans, d[n][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}