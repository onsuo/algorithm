/* 
 * 고양이 (https://www.acmicpc.net/problem/10171)
 * 
 * 아래 예제와 같이 고양이를 출력하시오.
 * 
 * \    /\
 *  )  ( ')
 * (  /  )
 *  \(__)|
 * 
 * -입력-
 * 없음.
 * 
 * -출력-
 * 고양이를 출력한다.
 */

#include <iostream>
#include <string>

int main()
{
    std::string example = R"(\    /\
 )  ( ')
(  /  )
 \(__)|)";
    std::cout << example << std::endl;
}