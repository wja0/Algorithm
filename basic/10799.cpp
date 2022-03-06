#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    getline(cin, str);
    stack<int> bar;
    int res, snum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char ch;
        ch = str[i];
        if (ch == '(')
        {
            bar.push(i + 1);
            snum += 1;
        }
        else if (str[i - 1] == '(' && ch == ')')
        {
            // 레이저
            bar.pop();
            snum -= 1;
            res += snum;
        }
        else if (ch == ')')
        {
            bar.pop();
            snum -= 1;
            res += 1;
        }
    }
    cout << res;
    return 0;
}