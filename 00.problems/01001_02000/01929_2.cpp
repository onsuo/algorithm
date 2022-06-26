/* 
 * 소수 구하기 (https://www.acmicpc.net/problem/1929)
 * 
 * M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. 
 * (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
 * 
 * -출력-
 * 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 */

#include <iostream>
#include <array>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int M, N;
    std::cin >> M >> N;

    std::array<bool, 1000001> isPrimeNum;
    isPrimeNum.fill(1);
    isPrimeNum[0] = 0;
    isPrimeNum[1] = 0;
    for (int i = 2 ; i <= N ; i++) {
        if (isPrimeNum[i] == 0) { continue; }
        else {
            for (int j = 2 ; i * j <= N ; j++) {
                isPrimeNum[i * j] = 0;
            }
            if (i >= M) { std::cout << i << "\n"; }
        }
    }
}