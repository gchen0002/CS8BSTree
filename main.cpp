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
    // tree.push(3);
    // tree.push(7);
    // tree.push(1200);
    // tree.push(-1111);
    // tree.inorder(&print);
    // std::cout << std::endl;
    // tree.preorder(&print);
    // std::cout << std::endl;
    // tree.postorder(&print);
    // std::cout << std::endl;
    // std::cout << "testing remove and clear" << std::endl;
    // tree.remove(5);
    // tree.inorder(&print);
    // std::cout << std::endl;
    // tree.clear();
    // tree.inorder(&print);
    // std::cout << std::endl;
    AVLTree<int> avlTree;
    avlTree.push(10);
    avlTree.push(21);
    avlTree.push(86);
    avlTree.push(12);
    avlTree.push(4);
    avlTree.push(-1);
    avlTree.push(5);
    avlTree.push(15);
    avlTree.traverse(BSTree<int>::POSTORDER, &print);
    std::cout << std::endl;
    avlTree.traverse(BSTree<int>::INORDER, &print);
    std::cout << std::endl;
    avlTree.traverse(BSTree<int>::PREORDER, &print);
    std::cout << std::endl;
    avlTree.traverse(BSTree<int>::BREADTHFIRST, &print);
    std::cout << std::endl;

    std::cout << "removing 10" << std::endl;
    avlTree.remove(10);
    avlTree.traverse(BSTree<int>::INORDER, &print);
    std::cout << std::endl;

    AVLTree<int> avlTree2;
    avlTree2 = avlTree; // copy assignment
    std::cout << "avlTree2 (copy of avlTree): ";
    avlTree2.traverse(BSTree<int>::INORDER, &print);
    std::cout << std::endl;

    AVLTree<int> avlTree3(avlTree); // copy constructor
    std::cout << "avlTree3 (copy of avlTree): ";
    avlTree3.traverse(BSTree<int>::INORDER, &print);
    std::cout << std::endl;

    std::cout << "clearing avlTree" << std::endl;
    avlTree.clear();
    avlTree.traverse(BSTree<int>::INORDER, &print);
    std::cout << std::endl;

    return 0;
}