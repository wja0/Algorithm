#include <iostream>
using namespace std;
#include <stack>
#include <string>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string a;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == "push")
        {
            int m;
            cin >> m;
            s.push(m);
        }
        else if (a == "pop")
        {
            if (!s.empty())
            {
                cout << s.top() << '\n';
                s.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (a == "size")
        {
            cout << s.size() << '\n';
        }
        else if (a == "empty")
        {
            if (!s.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << 1 << '\n';
            }
        }
        else if (a == "top")
        {
            if (!s.empty())
            {
                cout << s.top() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}