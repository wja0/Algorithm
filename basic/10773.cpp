#include <iostream>
using namespace std;
#include <stack>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stack<long long> s;
    int r;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m == 0)
        {
            r -= s.top();
            s.pop();
        }
        else
        {
            r += m;
            s.push(m);
        }
    }
    cout << r;
    return 0;
}