/*
 * Wheels (https://www.acmicpc.net/problem/10505)
 * 
 * A very important and complicated machine consists of n wheels, numbered 1, 2, . . . , n. 
 * They are actually cogwheels, but the cogs are so small that we can model them as circles on the plane. 
 * Every wheel can spin around its center.
 * 
 * Two wheels cannot overlap (they do not have common interior points), but they can touch. 
 * If two wheels touch each other and one of them rotates, the other one spins as well, as their micro-cogs are locked together.
 * 
 * A force is put to wheel 1 (and to no other wheel), making it rotate at the rate of exactly one turn per minute, clockwise. 
 * Compute the rates of other wheels’ movement. 
 * You may assume that the machine is not jammed (the movement is physically possible).
 * 
 * -입력-
 * The first line of input contains the number of test cases T. 
 * The descriptions of the test cases follow:
 * Each test case consists of one line containing the number of wheels n (1 ≤ n ≤ 1000). 
 * Each of the following lines contain three integers x, y and r (−10,000 ≤ x, y ≤ 10,000; 1 ≤ r ≤ 10,000) where (x, y) denote the Cartesian coordinates of the wheel’s center and r is its radius.
 * 
 * -출력-
 * For each test case, output n lines, each describing the movement of one wheel, in the same order as in the input. 
 * For every wheel, output either p/q clockwise or p/q counterclockwise, where the irreducible fraction p/q is the number of wheel turns per minute. 
 * If q is 1, output just p as an integer. 
 * If a wheel is standing still, output not moving
 */

#include <iostream>
#include <array>
#include <cmath>

struct wheel {
    int x, y, r;
    int p, q;
    bool isClockwise;
    bool isPowered;
    bool isRotating;

    wheel() {
        p = 0;
        q = 0;
        isPowered = 0;
        isRotating = 0;
    }
};

namespace ouun {
    
    void setRotation(wheel& wheel1, wheel& wheel2) {
        bool isaAdjoinedTo = pow(wheel1.x - wheel2.x, 2) + pow(wheel1.y - wheel2.y, 2) == pow(wheel1.r + wheel2.r, 2);
        bool isLocked = (wheel1.isPowered && !wheel1.isRotating) || (wheel2.isPowered && !wheel2.isRotating);
        if (!isaAdjoinedTo) { return; }
        else if (isLocked) {
            wheel1.isPowered = 1;
            wheel2.isPowered = 1;
            wheel1.isRotating = 0;
            wheel2.isRotating = 0;
        }
        else if (wheel1.isPowered && wheel2.isPowered) {
            if (wheel1.isClockwise == wheel2.isClockwise) {
                wheel1.isRotating = 0;
                wheel2.isRotating = 0;
            }
        }
        else if (wheel1.isPowered && wheel1.isRotating) {
            int t_p = wheel1.p * wheel1.r;
            int t_q = wheel1.q * wheel2.r;
            int t_gcd = 1;
            for (int i = std::min(t_p, t_q) ; i > 0 ; i--) {
                if (t_p % i == 0 && t_q % i == 0) {
                    t_gcd = i;
                    break;
                }
            }
            wheel2.p = t_p / t_gcd;
            wheel2.q = t_q / t_gcd;
            wheel2.isPowered = 1;
            wheel2.isRotating = 1;
            wheel2.isClockwise = !wheel1.isClockwise;
        }
        else if (wheel2.isPowered && wheel2.isRotating) {
            int t_p = wheel2.p * wheel2.r;
            int t_q = wheel2.q * wheel1.r;
            int t_gcd = 1;
            for (int i = std::min(t_p, t_q) ; i > 0 ; i--) {
                if (t_p % i == 0 && t_q % i == 0) {
                    t_gcd = i;
                    break;
                }
            }
            wheel1.p = t_p / t_gcd;
            wheel1.q = t_q / t_gcd;
            wheel1.isPowered = 1;
            wheel1.isRotating = 1;
            wheel1.isClockwise = !wheel2.isClockwise;
        }
        return;
    }

}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    // 테스트케이스 루프
    int T;
    std::cin >> T;
    for (int i = 0 ; i < T ; i++) {
        // 바퀴 위치, 반지름 초기화
        int n;
        std::cin >> n;
        std::array<wheel, 1000> wheelsList;
        for (int j = 0 ; j < n ; j++) {
            std::cin >> wheelsList[j].x >> wheelsList[j].y >> wheelsList[j].r;
        }
        // 초기 조건 : 0번
        wheelsList[0].p = 1;
        wheelsList[0].q = 1;
        wheelsList[0].isClockwise = 1;
        wheelsList[0].isPowered = 1;
        wheelsList[0].isRotating = 1;
        /*
         * 회전 여부 판단, 회전 속도와 방향 계산
         * 0번, 또는 회전하는 바퀴와 인접한 경우 회전 가능, 인접한 대상은 서로 반대로 회전
         * 바퀴 홀수 개가 서로 고리를 이루어 인접한 경우 회전 X
         */
        for (int j = 0 ; j < n / 2 + 1; j++) {
            for (int k = 0 ; k < n - 1 ; k++) {
                for (int l = k + 1 ; l < n ; l++) {
                    ouun::setRotation(wheelsList[k], wheelsList[l]);
                }
            }
        }

        // 출력
        for (int j = 0 ; j < n ; j++) {
            if (!wheelsList[j].isRotating) {
                std::cout << "not moving" << '\n';
                continue;
            }
            std::cout << wheelsList[j].p;
            if (wheelsList[j].q != 1) {
                std::cout << "/" << wheelsList[j].q;
            }
            std::cout << " ";
            if (wheelsList[j].isClockwise == 1) {
                std::cout << "clockwise";
            }
            else if (wheelsList[j].isClockwise == 0) {
                std::cout << "counterclockwise";
            }
            std::cout << "\n";
        }
    }
}