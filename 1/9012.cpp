#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore(); // 이게 없으면 입력 받을 줄에 빈칸을 getline 하게 됨
    while (n--)
    {
        string str;
        getline(cin, str); // str에 입력받음
        str += '\n';
        stack<char> s; // stack s 호출
        for (char ch : str)
        { // str 입력받은 한 줄, 한 글자씩 ch로 가져옴
            if (ch == '(')
            {
                s.push(ch); // '('' 넣기
            }
            else if (ch == ')')
            {
                if (s.empty())
                {
                    cout << "NO\n";
                    break; // break 하나를 기억못해서 오래걸림;;;;
                }
                else if (s.top() == '(')
                {
                    s.pop();
                }
            }
            else if (ch == '\n')
            {
                if (s.empty())
                {
                    cout << "YES\n";
                }
                else if (!s.empty())
                {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}