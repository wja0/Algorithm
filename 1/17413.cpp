#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    getline(cin, str);
    str += '\n';
    stack<char> word;
    string out;
    bool Flag = false;
    for (char ch : str)
    {
        if (ch == '<')
        {
            while (!word.empty())
            {
                out += word.top();
                word.pop();
            }
            out += ch;
            Flag = true;
        }
        else if (ch == ' ' || ch == '\n')
        {
            while (!word.empty())
            {
                out += word.top();
                word.pop();
            }
            out += ch;
        }
        else if (Flag)
        {
            if (ch == '>')
            {
                Flag = false;
            }
            out += ch;
        }
        else
        {
            word.push(ch);
        }
    }
    cout << out;
    return 0;
}