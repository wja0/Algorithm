#include <iostream>
#include <string>
using namespace std;
int a[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    for (int i = 0; i < n.size(); i++)
    {
        if (a[(int)n[i] - 97] > 0)
            continue;
        a[(int)n[i] - 97] = i + 1;
    }
    for (int i = 0; i <= 25; i++)
    {
        cout << a[i] - 1 << ' ';
    }
    return 0;
}