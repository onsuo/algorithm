/* 
 * 수 정렬하기 (https://www.acmicpc.net/problem/2750)
 * 
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 
 * 둘째 줄부터 N개의 줄에는 수 주어진다. 
 * 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 
 * 수는 중복되지 않는다.
 * 
 * -출력-
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */

#include <iostream>
#include <array>

namespace ouun {
    void swap(int& a, int& b) {
        int temp = b;
        b = a;
        a = temp;
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    std::array<int, 1000> nums;
    for (int i = 0 ; i < N ; i++) {
        int temp;
        std::cin >> temp;
        nums[i] = temp;
    }
    for (int i = N - 1 ; i > 0 ; i--) {
        for (int j = 0 ; j < i ; j++) {
            if (nums[j] > nums[j + 1])
                ouun::swap(nums[j], nums[j + 1]);
        }
    }
    for (int i = 0 ; i < N ; i++) {
        std::cout << nums[i] << "\n";
    }
}