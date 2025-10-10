#include "BSTree.h"
#include <iostream>
int print(int &data) {
    std::cout << data << " ";
    return 0;
}
int main() {
    BSTree<int> tree;
    tree.push(10);
    tree.push(5);
    tree.push(15);
    tree.inorder(&print);
    return 0;
}