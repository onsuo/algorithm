#include <iostream>
#include <queue>
#include <vector>

template<typename T>
void bfs(const std::vector<T>& data, const int& start);

int main()
{
    std::vector<std::vector<int>> adjacent_nodes;
    adjacent_nodes.reserve(7);

    //         0
    //       /   \ 
    //     1 ----- 2
    //   / |       | \ 
    // 3 - 4       5 - 6
    
    adjacent_nodes[0].push_back(1);
    adjacent_nodes[1].push_back(0);

    adjacent_nodes[0].push_back(2);
    adjacent_nodes[2].push_back(0);

    adjacent_nodes[1].push_back(2);
    adjacent_nodes[2].push_back(1);
    
    adjacent_nodes[1].push_back(3);
    adjacent_nodes[3].push_back(1);

    adjacent_nodes[1].push_back(4);
    adjacent_nodes[4].push_back(1);

    adjacent_nodes[3].push_back(4);
    adjacent_nodes[4].push_back(3);

    adjacent_nodes[2].push_back(5);
    adjacent_nodes[5].push_back(2);

    adjacent_nodes[2].push_back(6);
    adjacent_nodes[6].push_back(2);

    adjacent_nodes[5].push_back(6);
    adjacent_nodes[6].push_back(5);

    bfs(adjacent_nodes, 0);
}


/**
 * @brief 전달된 데이터에 대해 너비우선탐색 실시
 * 
 * @tparam T 인접한 노드의 목록
 * @param data 인접한 노드의 목록을 담은 vector
 * @param start 탐색을 시작할 위치를 의미함
 */
template<typename T>
void bfs(const std::vector<T>& data, const int& start) {
    std::queue<int> reserve;
    bool visited[data.size()];

    reserve.push(start);
    visited[start] = true;

    while (!reserve.empty()) {
        int x = reserve.front();
        reserve.pop();
        std::cout << x << '\n';
        for (int i = 0; i < data[x].size(); i++) {
            int y = data[x][i];
            if (!visited[y]) {
                reserve.push(y);
                visited[y] = true;
            }
        }
    }
}
