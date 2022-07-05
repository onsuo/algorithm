#include <iostream>

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
    
    for (int i = 0 ; i < N - 1 ; i++) {
        int min = nums[i];
        int index = i;
        for (int j = i + 1 ; j < N ; j++) {
            if (min > nums[j]) {
                min = nums[j];
                index = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;
    }

    std::cout << "{ ";
    for (int i = 0 ; i < N ; i++) {
        std::cout << nums[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";
}