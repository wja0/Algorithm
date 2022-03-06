#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// d[i] = i번쩨에서 끝나는 연속합
// d2[i] = i번재에서 시작하는 연속합
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> d(n);
    vector<int> d2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        d[i] = A[i];
        d2[i] = A[i];
    }
    // i번째에서 끝날때 최대값 (왼쪽부터)
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && A[i] + d[i - 1] > d[i])
        {
            d[i] = A[i] + d[i - 1];
        }
    }
    // i번재에서 시작할때 최대값 (오른쪽부터)
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && A[i] + d2[i + 1] > d2[i])
        {
            d2[i] = A[i] + d2[i + 1];
        }
    }
    // - 도 있으니깐 0으로 max를 두면 안됨
    int max = d[0];
    // 삭제 안함
    for (int i = 0; i < n; i++)
    {
        if (max < d[i])
            max = d[i];
    }
    // 삭제 한다면 해당 i빼고 앞뒤
    for (int i = 1; i < n - 1; i++)
    {
        if (max < d[i - 1] + d2[i + 1])
            max = d[i - 1] + d2[i + 1];
    }
    cout << max;
    return 0;
}