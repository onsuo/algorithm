#include <iostream>

typedef struct tag_node *tree_pointer;
typedef struct tag_node {
    int data;
    tree_pointer left_child, right_child;
} node;

/**
 * @brief 전위 순회 구현
 * 
 * @param ptr 특정 노드를 가리키는 포인터. 순회 시작점(root). 
 */
void preorder(tree_pointer ptr) {
    if (ptr) {
        std::cout << ptr->data << ' ';
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

/**
 * @brief 중위 순회 구현
 * 
 * @param ptr 특정 노드를 가리키는 포인터
 */
void inorder(tree_pointer ptr) {
    if (ptr) {
        inorder(ptr->left_child);
        std::cout << ptr->data << ' ';
        inorder(ptr->right_child);
    }
}

/**
 * @brief 후위 순회 구현
 * 
 * @param ptr 특정 노드를 가리키는 포인터
 */
void postorder(tree_pointer ptr) {
    if (ptr) {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        std::cout << ptr->data << ' ';
    }
}

int main()
{
    int num = 15;

    node nodes[num + 1];
    for (int i = 1; i <= num; i++) {
        nodes[i].data = i;
        nodes[i].left_child = NULL;
        nodes[i].right_child = NULL;
    }
    for (int i = 2; i <= num; i++) {
        if (i % 2 == 0) {
            nodes[i / 2].left_child = &nodes[i];
        }
        else {
            nodes[i / 2].right_child = &nodes[i];
        }
    }

    preorder(&nodes[0]);
    std::cout << '\n';
    inorder(&nodes[0]);
    std::cout << '\n';
    postorder(&nodes[0]);
    std::cout << '\n';
}