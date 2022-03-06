#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int e, s, m;
    cin >> e >> s >> m;
    int cnt = 1;
    int i = 1;
    int j = 1;
    int k = 1;
    while (1)
    {
        // 다시 1로
        if (i == 16)
            i = 1;
        if (j == 29)
            j = 1;
        if (k == 20)
            k = 1;
        if (i == e and j == s and k == m)
        {
            cout << cnt;
            return 0;
        }
        // i, j, k 증가
        i++;
        j++;
        k++;
        cnt++;
    }

    return 0;
}
// 해설
// 몇개의 방법이 있는지 확인 필요 : 15 * 28 * 19 = 7980 가지의 방법 존재
// year mod 15 == E
// year mod 28 == S
// year mod 19 == M
