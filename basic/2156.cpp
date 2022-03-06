#include <iostream>
#include <algorithm>
using namespace std;
int A[10001];
int D[10001];
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
            D[i] = A[i];
        }
        else
        {
            D[i] = A[i - 1] + A[i];
        }
    }
    for (int i = 1; i < n; i++)
    {
        int temp;
        temp = A[i] + A[i + 1];
        if (D[i] < temp)
        {
            D[i] = temp;
        }
    }
    int max = 0;
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