#include <iostream>
using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     int result = 0;
//     while (n)
//     {
//         for (int i = n; i > 0; i--)
//         {
//             if (n >= i * i)
//             {
//                 n = n - i * i;
//                 result += 1;
//                 break;
//             }
//         }
//         if (n == 1)
//         {
//             result += 1;
//             n -= 1;
//         }
//     }
//     cout << result;
//     return 0;
// }

// 풀이
// 마지막에 들어올 수 있는 수에 집중한다.
// 마지막에  i^2 들어오면 그 앞에는 (N-i^2)이 들어옴
// N = N-i^2 + i^2
// D[N] = N가지의 제곱수의 항의 수
//      = "N-i^2 까지의 제곱수의 합의 수" 중 가장 적은 것에 + 1 (마지막에 i^2가 들어올 테니깐)
// D[N] = min(D[N-i^2]) + 1 (1^2 <= i^2 < N)
int D[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        D[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            if (D[i] > D[i - j * j] + 1)
            {
                D[i] = D[i - j * j] + 1;
            }
        }
    }
    cout << D[n];
    return 0;
}