/**
 * std::set
 * https://en.cppreference.com/w/cpp/container/set
 */

#include <iostream>
#include <set>
#include <array>
#include <utility>

struct IntCmp {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        return lhs.second < rhs.second;
    }
};

int main()
{
    std::array<int, 10> a = { 1, 43, 4, 6, 2, 5, 7, 4, 3, 43 };

    std::set<int> s1;
    s1.insert(5);
    s1.insert(3);
    std::cout << "size : " << s1.size() << std::endl;
    for (auto& i : s1) {
        std::cout << i << std::endl;
    }
    std::set<int> s2(a.begin(), a.end());
    std::cout << "size : " << s2.size() << std::endl;
    for (auto& i : s2) {
        std::cout << i << std::endl;
    }
    std::set<int> s3 = { 2, 5, 6, 24, 5 };
    std::cout << "size : " << s3.size() << std::endl;
    for (auto& i : s3) {
        std::cout << i << std::endl;
    }
    std::set<int> s4(s1);
    std::cout << "size : " << s4.size() << std::endl;
    for (auto& i : s4) {
        std::cout << i << std::endl;
    }
    std::set<std::pair<int, int>, IntCmp> s5 = { {3, 5}, {2, 7}, {5, 2}, {3, 4} };
    std::cout << "size : " << s5.size() << std::endl;
    for (auto& i : s5) {
        std::cout << "{" << i.first << ", " << i.second << "}" << std::endl;
    }
}