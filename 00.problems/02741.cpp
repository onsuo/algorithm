/* 
 * N 찍기 (https://www.acmicpc.net/problem/2741)
 * 
 * 자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.
 * 
 * -출력-
 * 첫째 줄부터 N번째 줄 까지 차례대로 출력한다.
 */

#include <iostream>

int main()
{
    int N;
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;
    for(int i = 1; i < N + 1; i++) {
        std::cout << i << "\n";
    }
}