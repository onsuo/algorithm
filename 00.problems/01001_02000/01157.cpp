/* 
 * 단어 공부 (https://www.acmicpc.net/problem/1157)
 * 
 * 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
 * 단, 대문자와 소문자를 구분하지 않는다.
 * 
 * -입력-
 * 첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 
 * 주어지는 단어의 길이는 1,000,000을 넘지 않는다.
 * 
 * -출력-
 * 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 
 * 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
 */

#include <iostream>
#include <string>
#include <array>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    std::string word;
    std::cin >> word;
    
    std::array<int, 26> alphabet;
    alphabet.fill(0);
    for (char c : word) 
    {
        if (c - 'a' >= 0)
            alphabet[c - 'a']++;
        else
            alphabet[c - 'A']++;
    }
    
    int max = 0;
    char maxchar;
    /*
     * Main.cc: In function ‘int main()’:
     * Main.cc:24:10: warning: ‘maxchar’ may be used uninitialized in this function [-Wmaybe-uninitialized]
     *    24 |     char maxchar;
     *       |          ^~~~~~~
     */
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > max)
        {
            max = alphabet[i];
            maxchar = 'A' + i;
        }
        else if (alphabet[i] == max)
        {
            max = alphabet[i];
            maxchar = '?';
        }
    }
    std::cout << maxchar << '\n';
}