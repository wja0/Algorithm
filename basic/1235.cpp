#include <iostream>
#include <string>
using namespace std;
string a[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s = a[0].size() - 1;
    for (int j = s; j >= 0; j--)
    {
        bool flag = true;
        for (int k = 0; k < n; k++)
        {
            for (int i = k + 1; i < n; i++)
            {
                if (i == k)
                    continue;
                if (a[i].substr(j) == a[k].substr(j))
                {
                    flag = false;
                }
            }
        }
        if (flag == true)
        {
            cout << (s + 1) - j;
            return 0;
        }
    }
    return 0;
}