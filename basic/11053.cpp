#include <iostream>
#include <algorithm>
using namespace std;
// 가장 긴 증가하는 부분 수열
// LIS : Longest Increasing Subsequence
// 수열 A에서 LIS 구하기
// 수열 A = {10, 20, 10, 30, 20, 50}
// 부분 수열 A = {10, 20, 30, 50}       길이 = 4
// D[i] : LIS의 길이
// 추가되는 숫자의 앞에 올 수 있는 숫자들을 생각하면서 D[i] 값을 갱신
// ex)   1   2   3   4
// A[i]  10  20  10  30
// D[i]  1 (10 앞에 숫자 없음)
//           2 (20 앞 숫자 10 가능, 10의 D[i] +1)
//                1 (10 앞에 올 수 있는 숫자 없음)
//                    2 (30 앞에 10(3) 가능, 10의 D[i] +1)
//                    3 (30 앞에 20 가능, 20의 D[i] +1) --> MAX로 선택
//                    2 (30 앞에 10(1) 가능, 10의 D[i] +1)
int A[1001];
int D[1001];
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
                }
            }
        }
    }
    // 가장 긴 LIS를 출력!!
    sort(D, D + n);
    cout << D[n - 1];
    return 0;
}

// O(N^2)