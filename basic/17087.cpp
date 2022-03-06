#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    int b = 0;
    stack<int> res;
    int k = 0;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] == '1')
        {
            b += pow(2, k);
        }
        if (k == 2)
        {
            k = -1;
            res.push(b);
            b = 0;
        }
        else if (i == 0)
        {
            res.push(b);
        }
        k++;
    }
    while (!res.empty())
    {
        cout << res.top();
        res.pop();
    }

    return 0;
}