/* 
 * 큰 수 A+B (https://www.acmicpc.net/problem/10757)
 * 
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)
 * 
 * -출력-
 * 첫째 줄에 A+B를 출력한다.
 */

#include <iostream>
#include <string>
#include <array>
#include <cmath>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    std::string strA, strB;
    std::cin >> strA >> strB;
    std::array<int, 10001> numA, numB;
    numA.fill(0);
    numB.fill(0);
    for (int i = 0; i < (int)strA.length(); i++) {
        numA[i] = strA[strA.length() - 1 - i] - '0';
    }
    for (int i = 0; i < (int)strB.length(); i++) {
        numB[i] = strB[strB.length() - 1 - i] - '0';
    }
    std::array<int, 10001> result;
    result.fill(0);
    int add = 0;
    for (int i = 0; i < std::max(strA.length(), strB.length()); i++) {
    /* 
     * Main.cc: In function ‘int main()’:
     * Main.cc:25:23: warning: comparison of integer expressions of different signedness: ‘int’ and ‘const long unsigned int’ [-Wsign-compare]
     *    25 |     for (int i = 0; i < std::max(strA.length(), strB.length()); i++) {
     *       |                     ~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     */
        int temp = numA[i] + numB[i] + add;
        result[i] = temp % 10;
        add = temp / 10;
    }
    result[std::max(strA.length(), strB.length())] = add;
    if (add != 0) {
        std::cout << add;
    }
    for (int i = 0; i < std::max(strA.length(), strB.length()); i++) {
    /* 
     * Main.cc: In function ‘int main()’:
     * Main.cc:34:23: warning: comparison of integer expressions of different signedness: ‘int’ and ‘const long unsigned int’ [-Wsign-compare]
     *    34 |     for (int i = 0; i < std::max(strA.length(), strB.length()); i++) {
     *       |                     ~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     */
        std::cout << result[std::max(strA.length(), strB.length()) - 1 - i];
    }
}