#include <iostream>
using namespace std;
int check[46];
int zero;
int one;
int fun(int a)
{
    if (a <= 1)
    {
        if (a == 1)
        {
            one += 1;
            return 1;
        }
        else
        {
            zero += 1;
            return 0;
        }
    }
    else
    {
        if (check[a] > 0)
        {
            return check[a];
        }
        else
        {
            check[a] = fun(a - 1) + fun(a - 2);
            return check[a];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int w;
        zero = 0;
        one = 0;
        w = fun(n);
        cout << zero << ' ' << one << "\n";
    }

    return 0;
}