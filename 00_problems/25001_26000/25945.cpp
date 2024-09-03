/* 
 * 컨테이너 재배치 (https://www.acmicpc.net/problem/25945)
 * 
 * 항구의 컨테이너 하치장 바닥에는 컨테이너를 쌓을 수 있는 칸이 일렬로 총 n개가 그려져 있고, 현재 하치장에는 총 m개의 컨테이너가 쌓여 있다. 
 * 개별 컨테이너의 높이는 모두 1로 동일하며, 각 칸에 쌓을 수 있는 컨테이너의 개수에는 제한이 없다. 
 * 즉, a_i (1 ≤ i ≤ n)가 현재 i번째 칸에 쌓여있는 컨테이너의 개수를 나타내면, m = \sum_{i=1}^{n}{a_i}의 관계가 만족된다.
 * 
 * 현재와 같이 높이에 아무 제한이 없이 컨테이너가 쌓여 있을 경우 
 * 각 칸별로 쌓여있는 컨테이너의 개수의 차이가 심하여 안전상 문제점을 유발할 수 있기 때문에, 
 * 일부 컨테이너를 크레인을 이용하여 다른 칸으로 옮겨서 각 칸의 높이 차이가 1이하가 되도록 재배치하고자 한다. 
 * 즉, 임의의 i, j에 대해 |a_i - a_j| ≤ 1 이 만족되어야 한다. 
 * 컨테이너는 한번에 한 개씩만 옮길 수 있고 옮기는 거리에 따른 추가 비용은 없다고 가정한다.
 * 
 * 예를 들어 그림 1 과 같이 35개의 컨테이너가 8개의 칸에 쌓여 있을 경우 m = 35, n = 8 에 해당한다. 
 * 이를 높이 차이가 1이하가 되도록 재배치하면 그림 2 와 같은 결과를 얻을 수 있고, 이경우 5개의 컨테이너를 옮겨야 한다.
 * 
 * 입력으로 각 칸에 초기에 쌓여 있는 컨테이너의 높이 a_1, a_2, ... , a_n이 주어질 때, 
 * 임의의 i, j에 대해 |a_i - a_j| ≤ 1 조건을 만족하기 위해 옮겨야 하는 컨테이너의 최소 개수를 출력하는 프로그램을 작성하시오. 
 * 
 * -입력-
 * 입력은 표준입력을 사용한다. 첫 번째 줄에 컨테이너를 쌓을 수 있는 칸의 개수를 나타내는 양의 정수 n (1 ≤ n ≤ 10^6)이 주어진다. 
 * 다음 줄에는 현재 각 칸에 쌓여 있는 컨테이너의 개수 a_i를 나타내는 n개의 0이상의 정수들이 주어지고, 
 * 컨테이너의 총 개수 m 은 1 ≤ m ≤ 2 * 10^9 으로 제한한다.
 * 
 * -출력-
 * 출력은 표준출력을 사용한다. 문제의 조건을 만족하기 위해 옮겨야 하는 컨테이너의 최소 개수를 한 줄에 출력한다.
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    // 초기 컨테이너 세팅
    std::vector<std::pair<int, int>> box;
    box.reserve(1000000);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> box[i].first; // 컨테이너 개수 저장
        box[i].second = i; // 초기 위치 저장
        sum += box[i].first;
    }

    // 컨테이너 개수가 많은 칸 순으로 원본 정렬
    std::sort(box.begin(), box.begin() + n, [&](const auto a, const auto b) {
        return a.first > b.first;
    });

    std::vector<int> new_box;
    new_box.reserve(1000000);
    // 평균의 내림 값을 모두 분배
    for (int i = 0; i < n; i++) {
        new_box[i] = sum / n;
    }
    // 원본에서 평균보다 개수가 많았던 위치에 나머지 분배
    for (int i = 0; i < sum % n; i++) {
        new_box[box[i].second]++;
    }

    // 원본 컨테이너 배열 원상 복구
    std::sort(box.begin(), box.begin() + n, [&](const auto a, const auto b) {
        return a.second < b.second;
    });

    // 최종 배열과 원본 배열을 비교하여 컨테이너 이동 횟수 계산
    int move = 0;
    for (int i = 0; i < n; i++) {
        int temp = box[i].first - new_box[i];
        if (temp > 0) move += temp;
    }

    std::cout << move;
}