#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //cin.ignore();
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * i;
    }
    cout << res;
    return 0;
}