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
    BSTree<int> tree;
    tree.push(10);
    tree.push(5);
    tree.push(15);
    tree.push(3);
    tree.push(7);
    tree.push(1200);
    tree.push(-1111);
    tree.inorder(&print);
    std::cout << std::endl;
    tree.preorder(&print);
    std::cout << std::endl;
    tree.postorder(&print);
    std::cout << std::endl;
    std::cout << "testing remove and clear" << std::endl;
    tree.remove(5);
    tree.inorder(&print);
    std::cout << std::endl;
    tree.clear();
    tree.inorder(&print);
    std::cout << std::endl;
}