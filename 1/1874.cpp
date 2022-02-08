#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stack<int> s;
    int cnt = 1;
    string ans;
    while (n--)
    {
        int num;
        cin >> num;
        if (ans == "NO")
        {
            continue;
        }
        else if (s.empty() || s.top() < num)
        // 이미 s.empty인데 s.top이라그래서 오류 뜸. 순서 변경해서 해결
        {
            while (cnt <= num)
            {
                s.push(cnt);
                ans += "+\n";
                cnt++;
            }
            s.pop();
            ans += "-\n";
        }
        else if (s.top() == num)
        {
            s.pop();
            ans += "-\n";
        }
        else
        {
            ans = "NO";
        }
    }
    cout << ans;
    return 0;
}