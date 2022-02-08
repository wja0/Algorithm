#include <iostream>
using namespace std;
// 내가 생각한 D[n] = max(D[n-1] + P1, P4)
// 해설
// 다음에 올 카드는 알 수 없다.
// D[n] = max(D[n-i] + pi) 1 <= i < n
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int P[1002] = {0};
    int D[1002] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i];
        // 카드팩의 최대 수 X 카드팩의 최대가격 = 1000*10000;
        // -1로 초기화하고 조건에
        D[i] = P[i];
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = j; i >= 0; i--)
        {
            // if(D[j]>0){
            //     break;
            // }
            int temp;
            temp = D[j - i] + P[i];
            if (D[j] > temp)
            {
                D[j] = temp;
            };
        }
    }
    cout << D[n];

    return 0;
}