#include <iostream>
using namespace std;
int D[9];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    cout << m % 10;        // 3
    cout << " " << m / 10; // 214
    return 0;
}