/* 
 * 새싹 (https://www.acmicpc.net/problem/25083)
 * 
 * 아래 예제와 같이 새싹을 출력하시오.
 * 
 *          ,r'"7
 * r`-_   ,'  ,/
 *  \. ". L_r'
 *    `~\/
 *       |
 *       |
 * 
 * -입력-
 * 입력은 없다.
 * 
 * -출력-
 * 새싹을 출력한다.
 */

#include <iostream>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    std::string image = R"DEL(         ,r'"7
r`-_   ,'  ,/
 \. ". L_r'
   `~\/
      |
      |)DEL";
    
    std::cout << image;
}