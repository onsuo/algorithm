/* 
 * 타일 채우기 (https://www.acmicpc.net/problem/2133)
 * 
 * 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
 * 
 * -입력-
 * 첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.
 * 
 * -출력-
 * 첫째 줄에 경우의 수를 출력한다.
 */

#include <iostream>

int dp(int x);
int d[31];

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    
    std::cout << dp(N);
}

int dp(int x) {
    if (x == 0) return 1;
    if (x == 1) return 0;
    if (x == 2) return 3;
    if (d[x] != 0) return d[x];

    int result = 3 * dp(x - 2);
    for (int i = 4; i <= x; i += 2) {
        result += 2 * dp(x - i);
    }
    return d[x] = result;
}