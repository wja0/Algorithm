#include <iostream>
using namespace std;
// D[n] : 2Xn 직사각형을 채우는 방법
// 1) D[n-1] : 맨 마지막에 1X2이 1개인 경우
// 2) D[n-2] : 맨 마지막에 2X1이 2개인 경우
// D[n] = D[n-1](2X1 놓고 끝) + D[n-2](1X2 2개 놓고 끝)
// 최대한 반복되는 계산이 들어가고 그걸 메모해서 한번만 계산하게
int check[1001];
int fun(int a)
{
    // 2까지는 미리 정의
    if (a == 1)
        return 1;
    if (a == 0)
        return 1;
    if (check[a] > 0)
        return check[a];
    // 오버플로우 나니깐 두번 미리
    check[a] = fun(a - 1) % 10007 + fun(a - 2) % 10007;
    return check[a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // 이거까지 해야만 하네;;;
    cout << fun(n) % 10007;
    //cin.ignore();
    return 0;
}