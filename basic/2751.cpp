#include <iostream>
using namespace std;
#include <algorithm>
int D[11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int i = 0;
    while (n)
    {
        D[i++] = n % 10; // 3
        n = n / 10;      // 214
    }
    sort(D, D + i);
    for (int j = i - 1; j >= 0; j--)
    {
        cout << D[j];
    }

    return 0;
}