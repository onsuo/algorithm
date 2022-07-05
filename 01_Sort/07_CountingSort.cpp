#include <iostream>
#include <array>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    int data[10000000];
    for (int i = 0 ; i < N ; i++) {
        std::cin >> data[i];
    }

    std::array<int, 10001> count;
    count.fill(0);
    for (int i = 0 ; i < N ;i++) {
        count[data[i]]++;
    }

    std::cout << "{ ";
    for (int i = 1 ; i < 10001 ; i++) {
        for (int j = 0 ; j < count[i] ; j++) {
            std::cout << i;
            if (i < N - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << " }\n";
}