/* 
 * A+B - 4 (https://www.acmicpc.net/problem/10951)
 * 
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 입력은 여러 개의 테스트 케이스로 이루어져 있다.
 * 
 * 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. 
 * (0 < A, B < 10)
 * 
 * -출력-
 * 각 테스트 케이스마다 A+B를 출력한다.
 */

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int A, B;
    while(true)
    {
        std::cin >> A >> B;
        if (std::cin.eof())
            break;
        std::cout << A + B << "\n";
    }
}