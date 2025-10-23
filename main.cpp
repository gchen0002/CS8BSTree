#include "BSTree.h"
#include "AVLTree.h"
#include <iostream>
int print(int &data) {
    std::cout << data << " ";
    return 0;
}
void printV(int &data) {
    std::cout << data << " ";
}
int main() {
    // BSTree<int> tree;
    // tree.push(10);
    // tree.push(5);
    // tree.push(15);
    // tree.inorder(&print);
    // std::cout << std::endl;
    // tree.preorder(&print);
    // std::cout << std::endl;
    // tree.postorder(&print);

    AVLTree<int> avlTree;
    avlTree.push(21);
    avlTree.push(86);
    avlTree.push(12);
    avlTree.push(4);
    avlTree.push(-1);
    avlTree.push(5);
    avlTree.push(19);
    // avlTree.inorder(&print);
    // std::cout << std::endl;
    // avlTree.preorder(&print);
    // std::cout << std::endl;
    avlTree.postorder(&print);
    std::cout << std::endl;
    avlTree.BFS(&printV);
    std::cout << std::endl;
    return 0;
}