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
        for (int j = 0 ; j < (N - i) - 1 ; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
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