/* 
 * 별 찍기 - 1 (https://www.acmicpc.net/problem/2438)
 * 
 * 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
 * 
 * -입력-
 * 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
 * 
 * -출력-
 * 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
 */

#include <iostream>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    for(int i = 1; i < N + 1; i++)
    {
        std::string stars;
        for(int j = 0; j < i; j++)
        {
            stars += "*";
        }
        std::cout << stars << "\n";
    }
}