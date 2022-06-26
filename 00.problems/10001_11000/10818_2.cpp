/* 
 * 최소, 최대 (https://www.acmicpc.net/problem/)
 * 
 * N개의 정수가 주어진다. 
 * 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 
 * 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 
 * 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
 * 
 * -출력-
 * 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
 */

#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    std::array<int, 1000000> data;
    for (int i = 0 ; i < N ; i++) {
        int inputValue;
        std::cin >> inputValue;
        data[i] = inputValue;
    }
    std::sort(data.begin(), data.begin() + N);
    std::cout << data[0] << " " << data[N - 1] << "\n";
}