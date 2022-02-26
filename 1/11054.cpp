#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// d(n) A[n]까지 증가하는 수열의 최대 길이
// d2(n) A[n]까지 감소하는 수열의 최대 길이
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> d(n);
    vector<int> d2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        d[i] = 1;
        d2[i] = 1;
    }
    // 증가하는 수열
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (A[j] < A[i])
            {
                if (d[i] < d[j] + 1)
                    d[i] = d[j] + 1;
            }
        }
    }
    // 감소하는 수열
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (A[j] < A[i])
            {
                if (d2[i] < d2[j] + 1)
                    d2[i] = d2[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < d[i] + d2[i] - 1)
            max = d[i] + d2[i] - 1;
    }
    cout << max;
    return 0;
}