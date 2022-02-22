#include <iostream>
#include <algorithm>
using namespace std;
// D[i] = D[j] + A[i] (j<i) i번째 이하의 수 중 A[i]보다 작은 수들의 합의 최대값
int A[1002], D[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i == 0)
        {
            D[0] = A[0];
        }
        else
        {
            int max = A[i];
            for (int j = 0; j < i; j++)
            {

                if (A[j] < A[i])
                {
                    if (max < D[j] + A[i])
                    {
                        max = D[j] + A[i];
                    }
                }
            }
            D[i] = max;
        }
    }
    sort(D, D + n);
    cout << D[n - 1];
    return 0;
}