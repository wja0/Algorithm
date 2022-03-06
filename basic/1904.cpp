#include <iostream>
using namespace std;
// 시간초과 -> 저장 시키기
long long D[1000001];
long long fun(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (D[n])
    {
        return D[n];
    }
    D[n] = fun(n - 2) % 15746 + fun(n - 1) % 15746;
    return D[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    cout << fun(n) % 15746;
    return 0;
}