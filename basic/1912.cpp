#include <iostream>
using namespace std;
// D[i] : 연속 합
long long A[100002], D[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        D[i] = A[i];
        if (i - 1 >= 0)
        {
            long long temp;
            temp = D[i - 1] + D[i];
            if (temp > D[i])
            {
                D[i] = temp;
            }
        }
    }
    long long max;
    max = -1001;
    for (int i = 0; i < n; i++)
    {
        if (max < D[i])
        {
            max = D[i];
        }
    }
    cout << max;
    return 0;
}
// O(N);