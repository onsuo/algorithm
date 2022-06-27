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

#define MAX_SIZE 1000000

namespace ouun {

    void mergeSort(int* data, int start, int end) {
        if (start == end) {
            return;
        }
        
        int start1 = start;
        int end1 = start + (end - start) / 2;
        int start2 = end1 + 1;
        int end2 = end;
        ouun::mergeSort(data, start1, end1);
        ouun::mergeSort(data, start2, end2);

        static int sortedT[MAX_SIZE];
        int index = start;
        for ( ; start1 <= end1 && start2 <= end2 ; index++) {
            if (data[start1] < data[start2]) {
                sortedT[index] = data[start1];
                start1++;
            } else {
                sortedT[index] = data[start2];
                start2++;
            }
        }
        if (start1 > end1) {
            for ( ; start2 <= end2 ; start2++, index++) {
                sortedT[index] = data[start2];
            }
        } else {
            for ( ; start1 <= end1 ; start1++, index++) {
                sortedT[index] = data[start1];
            }
        }
        for ( ; start <= end ; start++) {
            data[start] = sortedT[start];
        }
    }

}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    int data[MAX_SIZE];
    for (int i = 0 ; i < N ; i++) {
        std::cin >> data[i];
    }

    ouun::mergeSort(data, 0, N - 1);

    for (int i = 0 ; i < N ; i++) {
        std::cout << data[i] << "\n";
    }
}