#include <iostream>
using namespace std;
int D[42];
int zero[42], one[42];
// N번째 피보나치를 구하는데 1과 0이 호출되는 횟수
// D[n] = D[n-1] + D[n-2];
// one[n]
int fibonacci(int n)
{
    if (n == 0)
    {
        zero[n] += 1;
        return 0;
    }
    else if (n == 1)
    {
        one[n] += 1;
        return 1;
    }
    if (D[n])
    {
        return 4;
    }
    else
    {
        int first;
        first = fibonacci(n - 1);
        if (first == 1)
        {
            one[n] += one[n - 1] + 1;
        }
        else if (first == 0)
        {
            zero[n] += zero[n - 1] + 1;
        }
        int second;
        second = fibonacci(n - 2);
        if (second == 1)
        {
            one[n] += one[n - 2] + 1;
        }
        else if (second == 0)
        {
            zero[n] += zero[n - 2] + 1;
        }
        D[n] = first + second;
        return 2;
    }
    return 3;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        fibonacci(m);
        cout << zero[m - 1] << " " << one[m - 1] << '\n';
    }
    return 0;
}