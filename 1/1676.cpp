#include <iostream>
using namespace std;
// 팩토리얼로 구하면 시간초과
// int fac(int a)
// {
//     if (a == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return a * fac(a - 1);
//     }
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    // 0의 개수를 구하는 방법 : 해당 숫자의 소인수 분해시 5의 개수 (그 숫자까지 5가 몇개나 있나)
    // 조합은 2의 개수가 더 많을 수도 있음
    cin >> n;
    int p;
    cin >> p;
    // int f;
    // f = fac(n);
    // int res = 0;
    // while (f % 10 == 0)
    // {
    //     res += 1;
    //     f = f / 10;
    // }
    // cout << res;
    long long res = 0;
    // n까지의 모든 수들의 5의 총 개수가 1개일때, 2개일때 (25의 배수가 몇개인지도), 3개일때......
    // 2도 나눠서 5와 2중 최소값으로 해야함
    // int의 크기  2,147,483,647
    for (long long i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }
    for (long long i = 5; i <= n - p; i *= 5)
    {
        res -= (n - p) / i;
    }
    for (long long i = 5; i <= p; i *= 5)
    {
        res -= p / i;
    }
    long long res2 = 0;
    for (long long i = 2; i <= n; i *= 2)
    {
        res2 += n / i;
    }
    for (long long i = 2; i <= n - p; i *= 2)
    {
        res2 -= (n - p) / i;
    }
    for (long long i = 2; i <= p; i *= 2)
    {
        res2 -= p / i;
    }
    if (res < res2)
    {
        cout << res << '\n';
    }
    else
    {
        cout << res2 << '\n';
    }

    return 0;
}