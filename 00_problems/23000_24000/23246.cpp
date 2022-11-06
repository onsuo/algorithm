/* 
 * Sports Climbing Combined (https://www.acmicpc.net/problem/23246)
 * 
 * 스포츠 클라이밍은 1986 년에 시작된 실내 암벽 등반 스포츠이다. 
 * 선수들은 원래 리드 클라이밍 종목에서만 겨루었는데, 1989 년에 스피드 클라이밍이 추가되었고, 10 년 후인 1999 년에 볼더링 종목이 추가되었다. 
 * 올림픽 게임에서는 금, 은, 동메달을 결정하기 위하여 선수들은 세 종목에서 겨루어 종합 순위를 매긴다. 
 * 종합 순위는 세 종목에서 거둔 순위를 곱한 점수로 결정된다. 
 * 예를 들어, 어떤 선수가 리드에서 1 위, 스피드에서 5 위, 볼더링에서 2 위를 했다면 점수는 10 점이 된다. 
 * 곱한 점수가 낮은 선수가 종합 순위에서 앞선다.
 * 
 * 선수 n명의 등번호와 이들이 세 종목에서 거둔 순위가 주어질 때, 금, 은, 동메달을 받을 선수를 결정하는 프로그램을 작성하시오. 
 * 두 선수의 곱한 점수가 같을 수도 있다. 
 * 이 경우, 세 종목 순위의 합산 점수가 낮은 선수가 이긴다. 
 * 두 선수의 곱한 점수와 합산 점수가 모두 같으면 등번호가 낮은 선수가 이긴다.
 * 
 * -입력-
 * 입력은 표준입력을 사용한다. 
 * 첫째 줄에 선수의 명수를 나타내는 양의 정수 n (3≤n≤100이 주어진다. 
 * 이어 n개의 줄 각각에 네 정수 bi, pi, qi, ri가 주어지는데, 
 * bi는 i번째 선수의 등번호이고, pi, qi, ri는 각각 그 선수가 리드, 스피드, 볼더링 종목에서 거둔 순위를 나타낸다. 
 * 선수들의 등번호는 서로 다르고 999이하인 양의 정수이다. 
 * 또한, 각 종목에서 선수의 순위는 1과 n사이의 정수이다. 
 * 각 종목에서 두 선수의 순위가 같을 수도 있다.
 * 
 * -출력-
 * 표준출력을 사용한다. 
 * 금, 은, 동메달을 받을 선수의 등번호를 나타내는 세 정수를 순서대로 한 줄에 출력한다.
 */

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::array<int, 6>> player;
    player.reserve(100);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> player[i][j];
        }
        player[i][4] = player[i][1] * player[i][2] * player[i][3];
        player[i][5] = player[i][1] + player[i][2] + player[i][3];
    }

    std::sort(player.begin(), player.begin() + n, [&](const auto a, const auto b) {
        if (a[4] != b[4]) {
            return a[4] < b[4];
        }
        else if (a[5] != b[5]) {
            return a[5] < b[5];
        }
        else {
            return a[0] < b[0];
        }
    });

    for (int i = 0; i < 3; i++) {
        std::cout << player[i][0] << " ";
    }
}