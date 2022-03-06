#include <iostream>
using namespace std;
// 1로 만들기
// 3으로 나누고 2로 나누고 1로 빼서 1로 만든다.
// 3으로 나누느게 수를 빠르게 작게 만든다.
// 우선순위 3--->2--->(-1)
// but 이러면 10 --> 5 --> 4 --> 2 --> 1
// 실제 빠르게 만들기 위해선 10 --> 9 --> 3 --> 1

// 작게 만든다? => DP로
// 점화식 구하기 (점화식 : 어떤 수열의 일반항을 그 이전의 항들을 이용하여 정의한 식)
// 목표 : N을 1로 만드는 최소 연산 횟수 = D[N]
// 1. x가 3으로 나누어 떨어지면, 3으로 나눈다 => N을 N/3으로 만들기 ==> 1로 만들기
//                                              1번   +        D[N/3] (재귀로 보내버려)
// 2. X가 2로 나누어 떨어지면, 2로 나눈다 => N을 N/2로 만들기 ==> 1로 만들기
//                                              1번   +   D[N/2]
// 3. 1을 뺀다 => N을 N-1로 만들기 ==> 1로 만들기
//                     1번   +  D[N-1]
// 각각 최소를 구해서 더한다
// D[N] = min(D[N/3], D[N/2], D[N-1]) + 1
// 결론 : 재귀로 돌리면서 모든 경우에 D[N]의 값을 메모 해두고 최소가 나오면 바꿔준다.
int check[1000001];
int fun(int a)
{
    if (a == 1)
        return 0; //1이 아니라 0을 리턴해야지,,, 1만들기 성공이자너
    // fun(a)을 굳이 여러번 반복해서 구할 필요 없으니깐 메모
    // 한번 fun(a)에 들어오면 1,2,3 풀이 한번에 다해봄
    // 나중에 다시 fun(a)에 들어왔을때 이전에 한값으로 바로 출력되게 하기
    if (check[a] > 0)
        return check[a];
    // 한번은 계산되어야 0이 아님
    int temp = fun(a - 1) + 1;
    check[a] = temp;
    if (a % 2 == 0)
    {
        int temp = fun(a / 2) + 1;
        if (temp < check[a])
            check[a] = temp;
    }
    if (a % 3 == 0)
    {
        int temp = fun(a / 3) + 1;
        if (temp < check[a])
            check[a] = temp;
    }
    return check[a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    cout << fun(n);

    return 0;
}
// 시간복잡도 :함수의 호출 횟수 X 함수의 시간복잡도
//            문제의 개수 X 문제 1개를 푸는데 걸리는 시간
// Top-down 방식임
// Bottom-up 방식도 있음