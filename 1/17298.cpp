#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int num[n];
    int nge[n];
    stack<int> yet;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        while (!yet.empty() && num[i] > num[yet.top()])
        {
            nge[yet.top()] = num[i];
            yet.pop();
        }
        yet.push(i);
        if (i == n - 1)
        {
            yet.pop();
            nge[n - 1] = -1;
        }
    }
    while (!yet.empty())
    {
        nge[yet.top()] = -1;
        yet.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }

    return 0;
}