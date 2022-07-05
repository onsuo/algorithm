/* 
 * 좌표 정렬하기 2 (https://www.acmicpc.net/problem/11651)
 * 
 * 2차원 평면 위의 점 N개가 주어진다. 
 * 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 
 * 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. 
 * (-100,000 ≤ xi, yi ≤ 100,000) 
 * 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
 * 
 * -출력-
 * 첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
 */

#include <iostream>
#include <algorithm>
#include <array>


namespace ouun
{
    bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
} // namespace ouun


int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::array<std::pair<int, int>, 100000> coordinates;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> coordinates[i].first >> coordinates[i].second;
    }

    std::sort(coordinates.begin(), coordinates.begin() + N, ouun::cmp);
    for (int i = 0 ; i < N ; i++) {
        std::cout << coordinates[i].first << " " << coordinates[i].second << "\n";
    }
}