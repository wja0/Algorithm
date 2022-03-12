#include <iostream>
using namespace std;
// 중복 없이 M개 고르기
bool c[10];
int a[10];
void go(int idx, int n, int m)
{
    if (idx == m)
    {
        int j = 0;
        while (a[j] > 0)
        {
            cout << a[j] << " ";
            j++;
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
            continue;
        c[i] = true;
        // 불가능하게 가둬두고 그 다음 숫자들 다시 뽑으러 함수 호출
        if (a[idx - 1] < i)
        {
            a[idx] = i;
            go(idx + 1, n, m);
        }
        // 다시 가능하게 열어주기
        c[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int m;
    cin >> n;
    cin >> m;
    go(0, n, m);

    return 0;
}