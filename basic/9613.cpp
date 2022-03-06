#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    //cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<int> in(m, 0);
        long long int res = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> in[j];
            for (int k = 0; k < j; k++)
            {
                res += gcd(in[j], in[k]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}