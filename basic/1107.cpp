#include <iostream>
using namespace std;
// +나 -를 누르다가 숫자를 누르면 의미가 없어진다.
// 중복이 있으면 안됨. +와 -가 반복해서 왔다갔다하면 안된다.
// 숫자 버튼 먼저 => + 나 - 누르기
// 채널 500000개 => 최대 버튼을 누르는 방법이 50만 가지
// +만 50만번 누르기 & -만 50만번 누르기 => 총 100만 가지 방법 ( - 채널도 가능? )
bool broken[10];
int possible(int c)
{
    if (c == 0)
    {
        if (broken[0])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int len = 0;
    while (c > 0)
    {
        if (broken[c % 10])
        {
            return 0;
        }
        len += 1;
        c /= 10;
    }
    return len;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        broken[x] = true;
    }
    int ans = n - 100;
    if (ans < 0)
    {
        ans = -ans;
    }
    for (int i = 0; i <= 1000000; i++)
    {
        int c = i;
        int len = possible(c);
        if (len > 0)
        {
            int press = c - n;
            if (press < 0)
            {
                press = -press;
            }
            if (ans > len + press)
            {
                ans = len + press;
            }
        }
    }
    cout << ans;
    return 0;
}