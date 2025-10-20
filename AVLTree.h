#include "BSTree.h"
#ifndef AVLTREE_H
#define AVLTREE_H

template <typename T>
class AVLTree : protected BSTree{
private:
    void balance(Node<T>* node);
    int getHeight(Node<T>* node) const;
    int getBalancingFactor(Node<T>* node) const;
    void rotateLeft(Node<T>*& node, Node<T>*& heavyChild);
    void rotateRight(Node<T>*& node, Node<T>*& heavyChild);
};



#endif