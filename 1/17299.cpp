#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// int F[1000001] = {
//     0,
// }; // 헐;; 엥 크기 1 더 키우고, 전역에 두니깐 돌아가는데,,? 왜지?

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // vector<int> A(n, 0), NGF(n, 0);
    int A[n];
    int NGF[n];
    int F[1000] = {
        0,
    }; // 헐;; 엥 크기 1 더 키우고, 전역에 두니깐 돌아가는데,,? 왜지?
    // 지역변수는 자동 초기화가 안된다. 전역변수는 자동 초기화 가능.
    //
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        F[A[i]] += 1;
    }
    stack<int> yet;
    yet.push(0);
    for (int i = 1; i < n; i++)
    {
        if (yet.empty()) // 빼먹음
        {
            yet.push(i);
        }
        while (!yet.empty() && F[A[yet.top()]] < F[A[i]])
        {
            NGF[yet.top()] = A[i];
            yet.pop();
        }
        yet.push(i);
    }
    while (!yet.empty())
    {
        NGF[yet.top()] = -1;
        yet.pop(); // 빼먹음
    }
    for (int i = 0; i < n; i++)
    {
        cout << NGF[i] << " ";
    }
    return 0;
}