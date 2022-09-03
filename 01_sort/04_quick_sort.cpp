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

    std::random_shuffle(nums, nums + N); // 시간복잡도가 O(N^2) 가 되는 경우를 만들지 않도록 shuffle
    ouun::quickSort(nums, 0, N - 1);
    
    std::cout << "{ ";
    for (int i = 0 ; i < N ; i++) {
        std::cout << nums[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";
}