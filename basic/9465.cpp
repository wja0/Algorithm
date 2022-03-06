#include <iostream>
#include <algorithm>
using namespace std;
int A[100002][3], D[100002][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> A[j][1];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> A[j][2];
        }
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                D[j][1] = A[j][1];
                D[j][2] = A[j][2];
            }
            else
            {
                D[j][0] = max({D[j - 1][0], D[j - 1][1], D[j - 1][2]});
                D[j][1] = max(D[j - 1][0], D[j - 1][2]) + A[j][1];
                D[j][2] = max(D[j - 1][0], D[j - 1][1]) + A[j][2];
            }
        }
        cout << max({D[m - 1][0], D[m - 1][1], D[m - 1][2]}) << '\n';
    }
    return 0;
}