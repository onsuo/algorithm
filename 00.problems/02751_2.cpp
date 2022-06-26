/* 
 * 수 정렬하기 2 (https://www.acmicpc.net/problem/2751)
 * 
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 
 * 둘째 줄부터 N개의 줄에는 수가 주어진다. 
 * 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 
 * 수는 중복되지 않는다.
 * 
 * -출력-
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */

#include <iostream>
#include <algorithm>

namespace ouun {

void quickSort(int* data, int start, int end) {
    if (start >= end) { return; }

    int bigI = start + 1;
    int smallI = end;
    while (1) {
        while (data[bigI] <= data[start] && bigI <= end) { bigI++; }
        while (data[smallI] >= data[start] && smallI >= start + 1) { smallI--; }
        if (bigI <= smallI) {
            int temp = data[bigI];
            data[bigI] = data[smallI];
            data[smallI] = temp;
        } else {
            int temp = data[start];
            data[start] = data[smallI];
            data[smallI] = temp;
            break;
        }
    }

    ouun::quickSort(data, start, smallI - 1);
    ouun::quickSort(data, smallI + 1, end);
}

}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    int nums[1000000];
    for (int i = 0 ; i < N ; i++) {
        std::cin >> nums[i];
    }
    std::random_shuffle(nums, nums + N);
    ouun::quickSort(nums, 0, N - 1);
    for (int i = 0 ; i < N ; i++) {
        std::cout << nums[i] << "\n";
    }
}