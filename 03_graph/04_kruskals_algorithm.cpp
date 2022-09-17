#include <iostream>
#include <vector>
#include <algorithm>

int get_parent(int parent[], int x);
void unite_parent(int parent[], int a, int b);
bool check_share_parent(int parent[], int a, int b);

/** @brief 간선 객체 */
class Edge {
private:
    int node[2];
    int distance;
public:
    Edge(int a, int b, int distance)
    : node{a, b}, distance(distance)
    {
    }

    bool operator<(Edge &edge) {
        return this->distance < edge.distance;
    }

    int get_node_first() {
        return this->node[0];
    }

    int get_node_second() {
        return this->node[1];
    }

    int get_distance() {
        return this->distance;
    }
};

int main()
{
    int n = 7;
    int e = 11;

    std::vector<Edge> edges;
    edges.reserve(e);
    edges.push_back(Edge(0, 6, 12));
    edges.push_back(Edge(0, 3, 28));
    edges.push_back(Edge(0, 1, 67));
    edges.push_back(Edge(0, 4, 17));
    edges.push_back(Edge(1, 3, 24));
    edges.push_back(Edge(1, 4, 62));
    edges.push_back(Edge(2, 4, 20));
    edges.push_back(Edge(2, 5, 37));
    edges.push_back(Edge(3, 6, 13));
    edges.push_back(Edge(4, 5, 45));
    edges.push_back(Edge(4, 6, 73));

    std::sort(edges.begin(), edges.end());
    
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (check_share_parent(parent, edges[i].get_node_first(), edges[i].get_node_second())) {
            continue;
        }
        sum += edges[i].get_distance();
        unite_parent(parent, edges[i].get_node_first(), edges[i].get_node_second());
    }

    std::cout << sum << '\n';
}


/**
 * @brief Get the parent object
 * 
 * @param parent parent node list
 * @param x node number
 * @return int 
 */
int get_parent(int parent[], int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = get_parent(parent, parent[x]);
}

/**
 * @brief unite two nodes
 * 
 * @param parent parent node list
 * @param a first node number
 * @param b second node number
 */
void unite_parent(int parent[], int a, int b) {
    a = get_parent(parent, a);
    b = get_parent(parent, b);
    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

/**
 * @brief check if two nodes share a single parent
 * 
 * @param parent parent node list
 * @param a first node number
 * @param b second node number
 * @return true 
 * @return false 
 */
bool check_share_parent(int parent[], int a, int b) {
    a = get_parent(parent, a);
    b = get_parent(parent, b);
    if (a == b) {
        return true;
    }
    return false;
}
