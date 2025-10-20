#include "BSTree.h"
#include "AVLTree.h"
#include <iostream>
int print(int &data) {
    std::cout << data << " ";
    return 0;
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
    avlTree.push(10);
    avlTree.push(5);
    avlTree.push(15);
    avlTree.inorder(&print);
    std::cout << std::endl;
    avlTree.preorder(&print);
    std::cout << std::endl;
    avlTree.postorder(&print);
    std::cout << std::endl;
    return 0;
}