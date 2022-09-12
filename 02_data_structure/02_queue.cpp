/**
 * std::queue
 * https://en.cppreference.com/w/cpp/container/queue
 */

// first in first out (FIFO)

#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;
    q.push(1);
    q.push(3);
    q.push(8);
    q.pop();
    q.push(4);
    q.pop();
    while (!q.empty()) {
        std::cout << q.front() << "\n";
        q.pop();
    }
}