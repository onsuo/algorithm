/* 
 * 기찍 N (https://www.acmicpc.net/problem/2742)
 * 
 * 자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
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
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    for(int i = N; i > 0; i--) {
        std::cout << i << "\n";
    }
}