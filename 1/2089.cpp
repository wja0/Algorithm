#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool check[1000001] = {};
int s[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    check[0] = true;
    check[1] = true;
    int idx = 0;
    for (int i = 2; i < 1000001; i++)
    {
        if (!check[i])
        {
            for (int j = i + i; j < 1000001; j += i) // i와 j의 곱하기로 하면 안나옴
            // 1000001 * 1000001 = 1,000,002,000,001 (int는 20억만 담을 수 있음)
            {
                check[j] = true;
            }
            s[idx] = i;
            idx++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        int T;
        cin >> T;
        for (int j = 0; j < idx; j++)
        {
            if ((T / 2) >= s[j] && !check[T - s[j]])
            {
                res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}