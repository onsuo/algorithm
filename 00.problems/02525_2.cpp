/* 
 * 오븐 시계 (https://www.acmicpc.net/problem/2525)
 * 
 * KOI 전자에서는 건강에 좋고 맛있는 훈제오리구이 요리를 간편하게 만드는 인공지능 오븐을 개발하려고 한다. 
 * 인공지능 오븐을 사용하는 방법은 적당한 양의 오리 훈제 재료를 인공지능 오븐에 넣으면 된다. 
 * 그러면 인공지능 오븐은 오븐구이가 끝나는 시간을 분 단위로 자동적으로 계산한다. 
 * 
 * 또한, KOI 전자의 인공지능 오븐 앞면에는 사용자에게 훈제오리구이 요리가 끝나는 시각을 알려 주는 디지털 시계가 있다. 
 * 훈제오리구이를 시작하는 시각과 오븐구이를 하는 데 필요한 시간이 분단위로 주어졌을 때, 오븐구이가 끝나는 시각을 계산하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에는 현재 시각이 나온다. 
 * 현재 시각은 시 A (0 ≤ A ≤ 23) 와 분 B (0 ≤ B ≤ 59)가 정수로 빈칸을 사이에 두고 순서대로 주어진다. 
 * 두 번째 줄에는 요리하는 데 필요한 시간 C (0 ≤ C ≤ 1,000)가 분 단위로 주어진다. 
 * 
 * -출력-
 * 첫째 줄에 종료되는 시각의 시와 분을 공백을 사이에 두고 출력한다. 
 * (단, 시는 0부터 23까지의 정수, 분은 0부터 59까지의 정수이다. 
 * 디지털 시계는 23시 59분에서 1분이 지나면 0시 0분이 된다.)
 */

#include <iostream>

class Time
{
private:
    int m_Hour, m_Minute;
    
public:
    Time(const int& Hour, const int& Minute)
        : m_Hour(Hour), m_Minute(Minute)
    {
    }
    
    void add(const int& Minute)
    {
        int t_Minute = m_Minute + Minute;
        m_Minute = (t_Minute) % 60;
        m_Hour = (m_Hour + t_Minute / 60) % 24;
        if(m_Minute < 0)
        {
            /*
             * t_Minute = -75 인 경우 t_Minute % 60 = -15, t_Minute / 60 = -1 이므로
             * 나머지는 45로, 몫은 -2로 보정하여 나머지를 양수로 만들어야 함
             */
            m_Minute += 60;
            m_Hour -= 1;
            if(m_Hour < 0)
                m_Hour += 24;
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, Time time);
};

std::ostream& operator<<(std::ostream& stream, Time time)
{
    stream << time.m_Hour << " " << time.m_Minute;
    return stream;
}

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;
    
    Time oven_time(A, B);
    oven_time.add(C);
    
    std::cout << oven_time << std::endl;
}