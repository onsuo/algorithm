/* 
 * 양팔저울 (https://www.acmicpc.net/problem/25943)
 * 
 * 1부터 n까지 번호가 매겨진 n개의 자갈이 있다. 이 자갈들을 다음 절차에 따라 양팔저울에 올려놓는다. 
 * 
 * 1. 1번 자갈을 왼쪽, 2번 자갈을 오른쪽에 올려놓는다.
 * 2. i = 3, ... , n번 자갈 각각에 대해서 차례로 다음 과정 중 하나를 수행한다.
 *      A. 만약 양팔저울이 평형을 이루는 경우, i번 자갈을 왼쪽에 올려 놓는다.
 *      B. 만약 양팔저울이 평형을 이루지 않는 경우, i번 자갈을 가벼운 쪽에 올려 놓는다.
 * 
 * 모든 자갈을 위의 규칙에 따라 올려 놓은 후에도 양팔저울은 평형을 이루지 않을 수 있다. 
 * 이경우 가벼운 쪽에 무게추를 올려서 균형을 맞추려고 한다. 
 * 무게추는 1g, 2g, 5g, 10g, 20g, 50g, 100g 7종류가 있고, 무게추의 개수에는 제한이 없다.
 * 
 * 입력 받은 자갈을 위 규칙에 따라 양팔저울에 올렸을 때, 
 * 최종적으로 평형을 맞추는데 추가적으로 필요한 무게추의 최소 개수를 구하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 입력은 표준입력을 사용한다. 
 * 첫 번째 줄에 자갈 개수를 나타내는 양의 정수 n (2 ≤ n ≤ 10,000)이 주어진다. 
 * 다음 줄에 n 개의 수들이 주어지는데, 이들은 번호 순서대로 자갈의 무게이다. 
 * 자갈의 무게는 각각 1이상이며, 모든 자갈의 무게의 총합은 10,000,000이하이다.
 * 
 * -출력-
 * 출력은 표준출력을 사용한다. 
 * 최종적으로 평형을 맞추는데 추가적으로 필요한 무게추의 최소 개수를 한 줄에 출력한다.
 */

#include <iostream>
#include <array>
// #include <algorithm>
#include <cmath>

// 양팔저울 객체
typedef struct Balance {
private:
    int left = 0;
    int right = 0;
public:
    // 양팔저울의 무게 차이
    int diff() {
        return std::abs(this->left - this->right);
    }
    // 규칙에 따라 양팔저울에 무게 추가
    void add(int rock) {
        if (this->left <= this->right) this->left += rock;
        else this->right += rock;
    }
} Balance;

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    Balance b;

    // 초기 돌 분배
    for (int i = 0; i < n; i++) {
        int t_rock;
        std::cin >> t_rock;
        b.add(t_rock);
    }

    // 무게추 종류 설정
    std::array<int, 7> weights = { 100, 50, 20, 10, 5, 2, 1 };

    int add_cnt = 0;
    // 무게추 분배
    // 오류: 양쪽에 어디든 무게추 추가하는 경우로 생각함
    // while (true) {
    //     int diff = b.diff();
    //     if (diff == 0) break;
    //     std::sort(weights.begin(), weights.end(), [&](const auto a, const auto b) {
    //         int t_a = std::abs(diff - a);
    //         int t_b = std::abs(diff - b);
    //         return t_a < t_b;
    //     });
    //     b.add(weights[0]);
    //     add_cnt++;
    // }
    // 성공: 자갈 분배 후 가벼운 쪽에만 무게추 추가 -> 1, 2, 5, 10, 20, 50, 100 으로 모든 자연수 만들기
    int diff = b.diff();
    for (int i = 0; i < 7; i++) {
        add_cnt += diff / weights[i];
        diff = diff % weights[i];
    }

    std::cout << add_cnt;
}