/* 
 * 좌표 압축 (https://www.acmicpc.net/problem/18870)
 * 
 * 수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 
 * 이 좌표에 좌표 압축을 적용하려고 한다.
 * 
 * Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
 * 
 * X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.
 * 
 * -입력-
 * 첫째 줄에 N이 주어진다.
 * 둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.
 * 
 * -출력-
 * 첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.
 * 
 * -제한-
 * 1 ≤ N ≤ 1,000,000
 * -109 ≤ Xi ≤ 109
 */

#include <iostream>
#include <algorithm>
#include <array>


namespace ouun
{
    struct Dot {
        int number;
        int coordinate;
        int condensed;
    };

    bool cmpCoordinate(const ouun::Dot &a, const ouun::Dot &b) {
        return a.coordinate < b.coordinate;
    }

    bool cmpNumber(const ouun::Dot &a, const ouun::Dot &b) {
        return a.number < b.number;
    }
} // namespace ouun


int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::array<ouun::Dot, 1000000> dots;
    for (int i = 0 ; i < N ; i++) {
        dots[i].number = i;
        std::cin >> dots[i].coordinate;
    }

    std::sort(dots.begin(), dots.begin() + N, ouun::cmpCoordinate);
    dots[0].condensed = 0;
    for (int i = 1 ; i < N ; i++) {
        if (dots[i].coordinate == dots[i - 1].coordinate) {
            dots[i].condensed = dots[i - 1].condensed;
        } else {
            dots[i].condensed = dots[i - 1].condensed + 1;
        }
    }
    std::sort(dots.begin(), dots.begin() + N, ouun::cmpNumber);
    for (int i = 0 ; i < N ; i++) {
        std::cout << dots[i].condensed << " ";
    }
}