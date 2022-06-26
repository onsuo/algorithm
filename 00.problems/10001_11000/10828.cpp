/* 
 * 스택 (https://www.acmicpc.net/problem/10828)
 * 
 * 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
 * 
 * 명령은 총 다섯 가지이다.
 * 
 * push X: 정수 X를 스택에 넣는 연산이다.
 * pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 스택에 들어있는 정수의 개수를 출력한다.
 * empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
 * top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * 
 * -입력-
 * 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
 * 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
 * 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
 * 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
 * 
 * -출력-
 * 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
 */

#include <iostream>
#include <vector>
#include <string>

class Stack {
private:
    std::vector<int> m_stack;
    
public:
    void m_push(int k) {
        this -> m_stack.push_back(k);
    }

    void m_pop() {
        if (!this -> m_stack.empty()) {
            std::cout << this -> m_stack.back() << "\n";
            this -> m_stack.pop_back();
            return;
        }
        std::cout << -1 << "\n";
    }

    void m_size() {
        std::cout << this -> m_stack.size() << "\n";
    }

    void m_empty() {
        std::cout << this -> m_stack.empty() << "\n";
    }

    void m_top() {
        if (!this -> m_stack.empty()) {
            std::cout << this -> m_stack.back() << "\n";
            return;
        }
        std::cout << -1 << "\n";
    }
};

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    Stack stack;
    for (int i = 0 ; i < N ; i++) {
        std::string command;
        std::cin >> command;
        if (command == "push") {
            int input;
            std::cin >> input;
            stack.m_push(input);
        }
        else if (command == "pop") {
            stack.m_pop();
        }
        else if (command == "size") {
            stack.m_size();
        }
        else if (command == "empty") {
            stack.m_empty();
        }
        else if (command == "top") {
            stack.m_top();
        }
    }
}