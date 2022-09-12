/**
 * std::stack
 * https://en.cppreference.com/w/cpp/container/stack
 */

// last in first out (LIFO)

#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s;
    s.push(1);
    s.push(3);
    s.push(8);
    s.pop();
    s.push(4);
    s.pop();
    while (!s.empty()) {
        std::cout << s.top() << "\n";
        s.pop();
    }
}