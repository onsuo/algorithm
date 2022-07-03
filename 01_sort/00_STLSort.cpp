#include <iostream>
#include <algorithm>
#include <vector>

namespace ouun {

    bool cmp(const int &a, const int &b) {
        return a > b;
    }

    class Student {
    private:
        std::string m_name;
        int m_score;

    public:
        Student(std::string name, int score) 
        : m_name(name), m_score(score)
        {
        }

        std::string getName() {
            return this->m_name;
        }

        bool operator<(ouun::Student &student) {
            return this->m_score < student.m_score;
        }
    };

}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int data[10] = { 3, 4, 5, 6, 10, 1, 4, 35, 7, 9 };

    std::sort(data, data + 10);
    for (int i = 0 ; i < 10 ; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    std::sort(data, data + 10, ouun::cmp);
    for (int i = 0 ; i < 10 ; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    std::sort(data, data + 10, [&](int a, int b) {
        return a > b;
    });
    for (int i = 0 ; i < 10 ; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    ouun::Student student[5] = {
        ouun::Student("A", 100), 
        ouun::Student("B", 85), 
        ouun::Student("C", 94), 
        ouun::Student("D", 85), 
        ouun::Student("E", 97)
    };
    std::sort(student, student + 5);
    for (int i = 0 ; i < 5 ; i++) {
        std::cout << student[i].getName() << " ";
    }
    std::cout << "\n";

    std::vector<std::pair<std::string, int>> v1;
    v1.push_back(std::pair<std::string, int>("A", 100));
    v1.push_back(std::pair<std::string, int>("B", 85));
    v1.push_back(std::pair<std::string, int>("C", 94));
    v1.push_back(std::pair<std::string, int>("D", 85));
    v1.push_back(std::pair<std::string, int>("E", 97));
    std::sort(v1.begin(), v1.end(), [&](auto a, auto b) { // default는 first 우선
        return a.second > b.second;
    });
    for (int i = 0 ; i < (int)v1.size() ; i++) {
        std::cout << v1[i].first << " ";
    }
    std::cout << "\n";

    std::vector<std::pair<std::string, std::pair<int, int>>> v2;
    v2.push_back(std::pair<std::string, std::pair<int, int>>("A", std::pair<int, int>(100, 20220319)));
    v2.push_back(std::pair<std::string, std::pair<int, int>>("B", std::pair<int, int>(85, 20221205)));
    v2.push_back(std::pair<std::string, std::pair<int, int>>("C", std::pair<int, int>(94, 20220423)));
    v2.push_back(std::pair<std::string, std::pair<int, int>>("D", std::pair<int, int>(85, 20220617)));
    v2.push_back(std::pair<std::string, std::pair<int, int>>("E", std::pair<int, int>(97, 20220804)));
    std::sort(v2.begin(), v2.end(), [&](auto a, auto b) {
        if (a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        } else {
            return a.second.first < b.second.first;
        }
    });
    for (int i = 0 ; i < (int)v2.size() ; i++) {
        std::cout << v2[i].first << " ";
    }
    std::cout << "\n";
}