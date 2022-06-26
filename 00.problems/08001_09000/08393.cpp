/* 
 * 합 (https://www.acmicpc.net/problem/8393)
 * 
 * n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.
 * 
 * -출력-
 * 1부터 n까지 합을 출력한다.
 */

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += i + 1;
    }
    
    std::cout << sum << std::endl;
}