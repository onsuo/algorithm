/* 
 * 소트인사이드 (https://www.acmicpc.net/problem/1427)
 * 
 * 배열을 정렬하는 것은 쉽다. 
 * 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
 * 
 * -입력-
 * 첫째 줄에 정렬하려고 하는 수 N이 주어진다. 
 * N은 1,000,000,000보다 작거나 같은 자연수이다.
 * 
 * -출력-
 * 첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::vector<int> nums;
    for ( ; N ; N /= 10) {
        nums.push_back(N % 10);
    }
    std::sort(nums.begin(), nums.end(), [&](const int a, const int b) {
        return a > b;
    });
    for (int i : nums ) {
        std::cout << i;
    }
}