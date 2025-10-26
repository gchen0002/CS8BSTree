#include "BSTree.h"
#ifndef AVLTREE_H
#define AVLTREE_H

template <typename T>
class AVLTree : public BSTree<T>{
public:
    // big 3 
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree<T>& other);
    AVLTree<T> operator=(const AVLTree<T>& other);

    void push(const T& data);
    void remove(const T& data);
    void clear();
    void copyTree(Node<T>*& thisNode, Node<T>* otherNode);
private:
    void balance(Node<T>*& node);
    int getHeight(Node<T>* node) const;
    int getBalancingFactor(Node<T>* node) const;
    void rotateLeft(Node<T>*& node);
    void rotateRight(Node<T>*& node);
};

#include "AVLTree.cpp"

#endif