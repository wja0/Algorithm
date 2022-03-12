#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    if (n > m)
    {
        cout << '>';
    }
    else if (n < m)
    {
        cout << '<';
    }
    else if (n == m)
    {
        cout << "==";
    }
    return 0;
}