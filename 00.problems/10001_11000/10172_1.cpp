/* 
 * 개 (https://www.acmicpc.net/problem/10172)
 * 
 * 아래 예제와 같이 개를 출력하시오.
 * 
 * |\_/|
 * |q p|   /}
 * ( 0 )"""\
 * |"^"`    |
 * ||_/=\\__|
 * 
 * -입력-
 * 없음.
 * 
 * -출력-
 * 개를 출력한다.
 */

#include <iostream>
#include <string>

int main()
{
    std::string dog = 
    "|\\_/|\n"
    "|q p|   /}\n"
    "( 0 )\"\"\"\\\n"
    "|\"^\"`    |\n"
    "||_/=\\\\__|";
    std::cout << dog << std::endl;
}