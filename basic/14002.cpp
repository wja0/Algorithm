#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
// ex)   1   2   3   4
// A[i]  10  20  10  30
// D[i]  1 (10 앞에 숫자 없음)
//           2 (20 앞 숫자 10 가능, 10의 D[i] +1)
//                1 (10 앞에 올 수 있는 숫자 없음)
//                    2 (30 앞에 10(3) 가능, 10의 D[i] +1)
//                    3 (30 앞에 20 가능, 20의 D[i] +1) --> MAX로 선택
//                    2 (30 앞에 10(1) 가능, 10의 D[i] +1)

// 역 추적 필요
// V[i] = A[i]의 앞에 와야하는 수의 인덱스.
// 즉, A[i]의 앞에는 A[V[i]]가 와야 길이가 가장 길다
int A[1001];
int D[1001];
int V[1001];
int go(int i)
{
    if (i == -1)
    {
        return -1;
    }
    if (go(V[i]) != -1)
    {
        cout << A[V[i]] << " ";
    }
    return i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        D[i] = 1;
        V[i] = -1;
        // 전체 1로 초기화 반례 : 5 / 5 1 2 3 4
        for (int j = i - 1; j >= 0; j--)
        {
            // j는 i보다 앞에 들어온 애들
            if (A[i] > A[j])
            {
                int tmp = D[j] + 1;
                if (D[i] < tmp)
                {
                    D[i] = tmp;
                    V[i] = j;
                }
            }
        }
    }
    // 가장 긴 LIS를 출력!!
    int max = 0, idx;
    for (int i = 0; i < n; i++)
    {
        if (max < D[i])
        {
            max = D[i];
            idx = i;
        }
    }
    cout << max << '\n';
    cout << A[go(idx)];
    return 0;
}
