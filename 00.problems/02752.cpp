/* 
 * 세수정렬 (https://www.acmicpc.net/problem/2752)
 * 
 * 동규는 세수를 하다가 정렬이 하고싶어졌다.
 * 
 * 숫자 세 개를 생각한 뒤에, 이를 오름차순으로 정렬하고 싶어 졌다.
 * 
 * 숫자 세 개가 주어졌을 때, 가장 작은 수, 그 다음 수, 가장 큰 수를 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 숫자 세 개가 주어진다. 
 * 이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다. 
 * 이 숫자는 모두 다르다.
 * 
 * -출력-
 * 제일 작은 수, 그 다음 수, 제일 큰 수를 차례대로 출력한다.
 */

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int data[3];
    for (int i = 0 ; i < 3 ; i++) {
        std::cin >> data[i];
    }
    for (int i = 0 ; i < 2 ; i++) {
        int min = data[i];
        int index = i;
        for (int j = i + 1 ; j < 3 ; j++) {
            if (data[j] < min) {
                min = data[j];
                index = j;
            }
        }
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
    for (int i = 0 ; i < 3 ; i++) {
        std::cout << data[i] << " ";
    }
}