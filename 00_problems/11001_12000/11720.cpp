/* 
 * 숫자의 합 (https://www.acmicpc.net/problem/11720)
 * 
 * N개의 숫자가 공백 없이 쓰여있다. 
 * 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 
 * 둘째 줄에 숫자 N개가 공백없이 주어진다.
 * 
 * -출력-
 * 입력으로 주어진 숫자 N개의 합을 출력한다.
 */

#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N;
    std::string nums;
    std::cin >> nums;
    int sum = 0;
    for (int i = 0; i < nums.length(); i++)
    /* 
     * Main.cc: In function ‘int main()’:
     * Main.cc:11:23: warning: comparison of integer expressions of different signedness: ‘int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
     *    11 |     for (int i = 0; i < nums.length(); i++)
     *       |                     ~~^~~~~~~~~~~~~~~
     */
    {
        sum += nums[i] - '0';
    }
    std::cout << sum;
}