#include "BSTree.h"
#ifndef AVLTREE_H
#define AVLTREE_H

template <typename T>
class AVLTree : public BSTree<T>{
public:
    void push(const T& data);
private:
    void balance(Node<T>*& node);
    int getHeight(Node<T>* node) const;
    int getBalancingFactor(Node<T>* node) const;
    void rotateLeft(Node<T>*& node);
    void rotateRight(Node<T>*& node);
};

#include "AVLTree.cpp"

#endif