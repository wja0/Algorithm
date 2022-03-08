#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    int m = n.size();
    int res = 9;
    int nine = 0;
    if (m == 1)
    {
        cout << n;
        return 0;
    }
    for (int i = 2; i <= m; i++)
    {
        if (i == m)
        {
            nine = pow(10, i - 1) - 1;
            res += (stoi(n) - nine) * m;
        }
        else
        {
            res += 9 * pow(10, i - 1) * i;
        }
    }
    cout << res;
    return 0;
}