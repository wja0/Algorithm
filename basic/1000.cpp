#include <iostream>
#include <string>
using namespace std;
char D[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char input[102];
    cin >> input;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m += (int)input[i] - '0';
    }
    cout << m;
    return 0;
}