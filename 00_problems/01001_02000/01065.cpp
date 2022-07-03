/* 
 * 한수 (https://www.acmicpc.net/problem/1065)
 * 
 * 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
 * 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
 * N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
 * 
 * -입력-
 * 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.
 * 
 * -출력-
 * 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
 */

#include <iostream>
#include <array>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    int count = 0;
    for (int i = 1; i < N + 1; i++)
    {
        std::array<int, 4> nums;
        nums.fill(-1);
        int temp = i;
        for (int j = 0; j < 4 && temp; j++)
        {
            nums[j] = temp % 10;
            temp /= 10;
        }
        int isAnswer = true;
        for (int j = 0; nums[j + 2] != -1; j++)
        {
            if (nums[j] + nums[j + 2] != 2 * nums[j + 1])
                isAnswer = false;
        }
        if (isAnswer)
            count++;
    }
    std::cout << count << "\n";
}