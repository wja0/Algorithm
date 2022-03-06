#include <iostream>
using namespace std;
int D[12];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    int n;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        for (int i = 4; i <= n; i++)
        {
            D[i] = D[i - 1] + D[i - 2] + D[i - 3];
        }
        cout << D[n] << '\n';
    }
    return 0;
}