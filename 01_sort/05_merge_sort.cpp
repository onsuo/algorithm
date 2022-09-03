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

    std::cout << "{ ";
    for (int i = 0 ; i < N ; i++) {
        std::cout << data[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";
}