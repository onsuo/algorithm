/* 
 * 2xn 타일링 2 (https://www.acmicpc.net/problem/11727)
 * 
 * 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
 * 아래 그림은 2×17 직사각형을 채운 한가지 예이다.
 * 
 * -입력-
 * 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
 * 
 * -출력-
 * 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
 */

#include <iostream>

int dp(int x);
int d[1001];

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::cout << dp(n);
}

int dp(int x) {
    if (x == 1) return 1;
    if (x == 2) return 3;
    if (d[x] != 0) return d[x];
    return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}