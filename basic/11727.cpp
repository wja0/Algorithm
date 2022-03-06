#include <iostream>
using namespace std;
// D[n] = D[n-1] + D[n-2] + D[n-2];
int d[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        // 이것도 다 나눠줘야함
        d[i] = d[i - 1] % 10007 + d[i - 2] % 10007 + d[i - 2] % 10007;
    }
    cout << d[n] % 10007;
    return 0;
}