#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<char> left, right;
    for (int i = 0; i < str.size(); i++)
    {
        left.push(str[i]);
    }
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string cmd;
        getline(cin, cmd);
        cmd += '\n';
        char cmd1 = cmd[0];
        if (cmd1 == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop(); // top을 넣고 따로 pop해야함.
            }
        }
        else if (cmd1 == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd1 == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        else if (cmd1 == 'P')
        {
            char cmd2 = cmd[2];
            left.push(cmd2); // empty에도 넣을 수 있음
        }
    }
    while (!left.empty())
    {
        right.push(left.top()); // 빠져나올 때는 거꾸로 넣어주기
        left.pop();
    }
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
    return 0;
}