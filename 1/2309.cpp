#include <iostream>
#include <algorithm>
using namespace std;
// brute force
// 처음부터 끝까지 다하는거기 때문에 경우의 수가 많아선 안된다.
// 일단 시간 제한을 확인해야한다.
// 1) 문제의 가능한 경우의 수를 계산
// 2) 모든 방법을 다 만들어 보기
// 3) 각 방법으로 답 구해보기
int a[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    bool flag = true;
    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < i; k++)
        {
            int ans = sum;
            if (i == k)
                continue;
            ans = ans - a[i] - a[k];
            if (ans == 100)
            {
                a[i] = 101;
                a[k] = 101;
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    sort(a, a + 9);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << '\n';
    }
    return 0;
}