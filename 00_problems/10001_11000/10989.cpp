/* 
 * 수 정렬하기 3 (https://www.acmicpc.net/problem/10989)
 * 
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 
 * 둘째 줄부터 N개의 줄에는 수가 주어진다. 
 * 이 수는 10,000보다 작거나 같은 자연수이다.
 * 
 * -출력-
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */

#include <iostream>
#include <array>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::array<int, 10001> count;
    count.fill(0);
    for (int i = 0 ; i < N ; i++) {
        int temp;
        std::cin >> temp;
        count[temp]++;
    }

    for (int i = 1 ; i < 10001 ; i++) {
        for (int j = 0 ; j < count[i] ; j++) {
            std::cout << i << "\n";
        }
    }
}