/**
 * 통계학
 * 
 * 수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 
 * 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 
 * 단, N은 홀수라고 가정하자.
 * 산술평균 : N개의 수들의 합을 N으로 나눈 값
 * 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
 * 최빈값 : N개의 수들 중 가장 많이 나타나는 값
 * 범위 : N개의 수들 중 최댓값과 최솟값의 차이
 * N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.
 * 
 * 
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
 * 단, N은 홀수이다. 
 * 그 다음 N개의 줄에는 정수들이 주어진다. 
 * 입력되는 정수의 절댓값은 4,000을 넘지 않는다.
 * 
 * 
 * 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
 * 둘째 줄에는 중앙값을 출력한다.
 * 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
 * 넷째 줄에는 범위를 출력한다.
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    int data[500001]; // 영역 외 접근 방지
    for (int i = 0 ; i < N ; i++) {
        std::cin >> data[i];
        data[i] += 4000; // 음수 정렬 안됨 -> 양수로 바꿔서 정렬 후 되돌림
    }
    std::sort(data, data + N);
    for (int i = 0 ; i < N ; i++) {
        data[i] -= 4000;
    }
    int sum = 0;
    int count = 0;
    int maxCount = 0;
    int listCount = 0;
    std::array<int, 500000> list;
    for (int i = 0 ; i < N ; i++) {
        sum += data[i];
        if (data[i] == data[i + 1] && i + 1 < N) { // 영역 외 접근 차단
            count++;
        } else {
            if (count > maxCount) {
                list.fill(0);
                listCount = 0;
                maxCount = count;
                list[0] = data[i];
                listCount++;
            } else if (count == maxCount) {
                list[listCount] = data[i];
                listCount++;
            }
            count = 0;
        }
    }
    std::cout << (int)std::round((float)sum / N) << "\n";
    std::cout << data[(N - 1) / 2] << "\n";
    if (listCount == 1) {
        std::cout << list[0] << "\n";
    } else {
        std::cout << list[1] << "\n";
    }
    std::cout << data[N - 1] - data[0] << "\n";
}