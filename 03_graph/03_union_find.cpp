#include <iostream>

int get_parent(int parent[], int x);
void unite_parent(int parent[], int a, int b);
bool find_parent(int parent[], int a, int b);

int main()
{
    int parent[11];
    for (int i = 0; i < 11; i++) {
        parent[i] = i;
    }

    unite_parent(parent, 1, 2);
    unite_parent(parent, 2, 3);
    unite_parent(parent, 3, 4);
    unite_parent(parent, 5, 6);
    unite_parent(parent, 6, 7);
    unite_parent(parent, 7, 8);

    printf("1과 5는 연결되어 있나요? %d\n", find_parent(parent, 1, 5));

    unite_parent(parent, 2, 8);

    printf("1과 5는 연결되어 있나요? %d\n", find_parent(parent, 1, 5));
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
bool find_parent(int parent[], int a, int b) {
    a = get_parent(parent, a);
    b = get_parent(parent, b);
    if (a == b) {
        return true;
    }
    return false;
}