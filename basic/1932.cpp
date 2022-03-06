#include <iostream>
#include <algorithm>
using namespace std;
int A[502][502], D[502][502];
// D[i][j] = i행 j열이 선택되었을 때, 최대 합
// D[i][j] = max(D[i-1][j], D[i-1][j-1])+A[i][j]
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> A[i][j];
        }
    }
    int max;
    D[0][0] = A[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            max = D[i - 1][j];
            if (j - 1 >= 0)
            {
                if (max < D[i - 1][j - 1])
                {
                    max = D[i - 1][j - 1];
                }
            }
            D[i][j] = max + A[i][j];
        }
    }
    sort(D[n - 1], D[n - 1] + n);
    cout << D[n - 1][n - 1];
    return 0;
}