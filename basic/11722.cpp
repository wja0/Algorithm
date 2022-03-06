#include <iostream>
#include <algorithm>
using namespace std;
// D[i] = D[j] + 1 (j<i) i번째 이하의 수 중 A[i]보다 큰 수들의 길이
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
        D[i] = 1;

        if (i > 0)
        {
            for (int j = 0; j < i; j++)
            {

                if (A[j] > A[i])
                {
                    if (D[i] < D[j] + 1)
                        D[i] = D[j] + 1;
                }
            }
        }
    }
    sort(D, D + n);
    cout << D[n - 1];
    return 0;
}