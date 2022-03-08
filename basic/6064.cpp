#include <iostream>
using namespace std;
// 모든 경우가 4만번 => 16억 가지 => 16초
// 0부터 시작하고, M 또는 N이 되는 순간 0이된다면
// i번째 값 = (i%M, i%N)
// M이 되는 순간 0이되어서 나누어떨어진다고 생각할 수 있음
//
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        x -= 1;
        y -= 1;
        // (0, 0)이라고 생각
        bool ok = false;
        for (int k = x; k < (N * M); k += M)
        {
            if (k % N == y)
            {
                cout << k + 1 << '\n';
                // 뺏던거 다시 더하기
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}