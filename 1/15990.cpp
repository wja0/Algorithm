#include <iostream>
using namespace std;
// 연속 : 앞에 있는 수를 제외하고 사용
// D[i][j] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 j
// D[i][1] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 1
// ==> 바로 전에 사용할 수 있는 수는 2, 3 = D[i-1][2] + D[i-1][3]
// 예외처리 i == 1 || 2 || 3 이면 1, i < 1 || 2 || 3 이면 0
int D[100001][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    return 0;
}